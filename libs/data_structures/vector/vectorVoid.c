#include "vectorVoid.h"

vectorVoid createVectorVoid(size_t n, size_t baseTypeSize){
    int *data;
    if (!(data = (int *) malloc(sizeof(baseTypeSize) * n))) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vectorVoid) {data, 0, n, baseTypeSize};
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;

    if (realloc(v->data, newCapacity * sizeof(v->baseTypeSize)) == NULL) {
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