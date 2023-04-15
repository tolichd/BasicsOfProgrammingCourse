#include "vector.h"

vector createVector(size_t n) {
    int *data;
    if (!(data = (int *) malloc(sizeof(int) * n))) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vector) {data, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;

    if (realloc(v->data, newCapacity * sizeof(int)) == NULL) {
        fprintf(stderr, "bad realloc");
        exit(2);
    }

    v->capacity = newCapacity;
    if (newCapacity < v->size)
        v->size = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->capacity = v->size;
}

void deleteVector(vector *v) {
    free(v->data);
    clear(v);
    shrinkToFit(v);
}

bool isEmpty(vector *v){
    return v->size == 0;
}

bool isFull(vector *v){
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i){
    return v->data[i];
}

void pushBack(vector *v, int x){
    if(isFull(v))
        reserve(v, v->capacity+1);

    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v){
    if(isEmpty(v)){
        fprintf(stderr, "vector is Empty");
        exit(1);
    }

    v->size--;
}