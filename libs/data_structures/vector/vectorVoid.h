#ifndef INC_18_VECTORVOID_H
#define INC_18_VECTORVOID_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct vectorVoid {
    void *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} vectorVoid;



#endif //INC_18_VECTORVOID_H
