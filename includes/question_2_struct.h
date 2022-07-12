#include "question_2.h"

struct sparse_set{
    sparse_set_elem_t *dense;
    sparse_set_elem_t *sparse;
    sparse_set_elem_t capacity;
    sparse_set_elem_t value;
    ssize_t ptr;
};
