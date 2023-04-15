#include <assert.h>

#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/voidVector.h"

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 3);

    assert(v.size == 1);
    assert(v.data[0] == 3);
}

void test_pushBack_fullVector() {
    vector v = createVector(5);
    v.size = 5;
    for (int i = 0; i < v.size; i++)
        v.data[i] = i;

    pushBack(&v, 7);
    assert(v.size == 6);
    assert(v.data[5] == 7);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 5);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(3);
    v.size = 3;

    for (int i = 0; i < v.size; i++)
        v.data[i] = i;

    assert(v.data[1] == *atVector(&v, 1));
}

void test_atVector_requestToLastElement() {
    vector v = createVector(3);
    v.size = 3;

    for (int i = 0; i < v.size; i++)
        v.data[i] = i;

    assert(v.data + (v.size - 1) == atVector(&v, v.size - 1));
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    v.size = 1;
    v.data[0] = 2;

    assert(v.data == back(&v));
}

void test_front_oneElementInVector() {
    vector v = createVector(1);
    v.size = 1;
    v.data[0] = 4;

    assert(v.data == front(&v));
}

void tests() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    tests();

    vectorVoid v;

    return 0;
}