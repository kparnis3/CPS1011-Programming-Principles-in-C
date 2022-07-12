#include "question_2.h"
#include "question_2_struct.h"

int main(void)
{
    sparse_set_elem_t element;

    sparse_set_ptr ss = ss_init(4, 15);
    ss_add(ss, 13);
    ss_add(ss, 12);
    ss_add(ss, 2);
    ss_print_status(ss, false);

    ss_remove(ss, 12);
    ss_print_status(ss, false);
    ss_add(ss, 15);
    ss_print_status(ss, false);
    ss_get_elem(ss, 1, &element);
    ss_contained(ss, 11);
    ss_sort(ss);
    ss_size(ss);
    ss_print_status(ss, false);

    ss_destroy(ss);

    return 0;
}
