#ifndef INC_18_VOIDVECTOR_H
#define INC_18_VOIDVECTOR_H

#include <limits.h>

typedef struct vectorVoid {
    void *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} vectorVoid;



#endif //INC_18_VOIDVECTOR_H
