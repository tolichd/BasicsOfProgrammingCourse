#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "libs/data_structures/vector/vector.h"

void test_pushBack_emptyVector(){
    vector v = createVector(0);
    pushBack(&v, 3);

    assert(v.size == 1);
    assert(v.data[0] == 3);
}

void test_pushBack_fullVector(){
    vector v = createVector(5);
    v.size = 5;
    for(int i = 0; i < v.size; i++)
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


void tests(){
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
}

int main() {
    tests();

    return 0;
}