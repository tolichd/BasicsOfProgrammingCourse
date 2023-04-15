#include "vectorVoid.h"

vectorVoid createVectorVoid(size_t n, size_t baseTypeSize){
    int *data;
    if (!(data = (int *) malloc(baseTypeSize * n))) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vectorVoid) {data, 0, n, baseTypeSize};
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;

    if (realloc(v->data, newCapacity * v->baseTypeSize) == NULL) {
        fprintf(stderr, "bad realloc");
        exit(1);
    }

    v->capacity = newCapacity;
    if (newCapacity < v->size)
        v->size = newCapacity;
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void shrinkToFitV(vectorVoid *v) {
    v->capacity = v->size;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    clearV(v);
    shrinkToFitV(v);
}

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination){
    if (index >= v->size) {
        fprintf(stderr, "IndexError: v->data[%lld] is not exists", index);
        exit(1);
    }

    char *source = (char *) v->data + (index * v->baseTypeSize);
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source){
    if (index >= v->size) {
        fprintf(stderr, "IndexError: v->data[%lld] is not exists", index);
        exit(1);
    }

    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(source, destination, v->baseTypeSize);
}

void pushBackV(vectorVoid *v, void *source) {
    if (isFullV(v))
        reserveV(v, v->capacity + 1);

    char *destination = (char *) v->data + (v->size) * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
    v->size++;
}

void popBackV(vectorVoid *v) {
    if (isEmptyV(v)) {
        fprintf(stderr, "Error: vector is Empty");
        exit(1);
    }

    v->size--;
}