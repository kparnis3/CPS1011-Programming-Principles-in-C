#include "question_2.h"
#include "question_2_struct.h"


sparse_set_ptr ss_init(sparse_set_index_t capacity, sparse_set_elem_t max_value){

    if(max_value>capacity) {

       sparse_set_ptr spar = malloc(sizeof(struct sparse_set));

       spar->dense = (uint32_t*) calloc(capacity, sizeof(uint32_t));
       spar->sparse = (uint32_t*) calloc(max_value+1, sizeof(uint32_t));

        spar->value = max_value;
        spar->capacity = capacity;

        for(int i=0; i<(spar->capacity); i++){
            spar->dense[i] = '_';
         }

         for(int i=0; i<spar->value+1; i++){
              spar->sparse[i] = '_';
          }

        spar->ptr = 0;

        return spar;
    }
    else {
        return NULL;
    }
}

bool ss_destroy(sparse_set_ptr sparse_set){

    if (sparse_set==NULL){
        return false;
    }
    else {
        free(sparse_set);
        return true;
    }
}


bool ss_add(sparse_set_ptr sparse_set, sparse_set_elem_t element){

    if((sparse_set->ptr < sparse_set->capacity) && (element < sparse_set->value+1)){
       for(int i=0;i<sparse_set->capacity;i++) {
          if (sparse_set->dense[i]==element){
              return true;
          }
       }
       sparse_set->dense[sparse_set->ptr] = element;
       sparse_set->sparse[element]=sparse_set->ptr;
       sparse_set->ptr++;

        return true;

    }
    else {
        return false;
    }
}

bool ss_remove(sparse_set_ptr sparse_set,sparse_set_elem_t element){
    int pos;

    if(sparse_set!=NULL){
        for(int i=0;i<sparse_set->capacity;i++) {
            if (sparse_set->dense[i]==element) {
                pos = i;
                
                sparse_set->sparse[element] = '_';

                sparse_set->dense[pos] = sparse_set->dense[(sparse_set->ptr-1)];

                pos = sparse_set->dense[(sparse_set->ptr-1)];
                sparse_set->dense[(sparse_set->ptr-1)] = '_';

                sparse_set->sparse[pos]=i;

                sparse_set->ptr--;

                return true;
            }
        }
        return false;
    }
    else{
        return false;
    }

}
bool ss_contained(sparse_set_ptr sparse_set,sparse_set_elem_t element){
    if(sparse_set!=NULL)
    {
        for(int i=0; i<(sparse_set->capacity);i++){
            if(sparse_set->dense[i] == element){
                return true;
            }
        }

      return false;
    }
    else{
        return false;
    }

}
bool ss_sort(sparse_set_ptr sparse_set){
   int temp, i, j;

   if(sparse_set!=NULL) {
       for (i = 1; i < sparse_set->ptr; i++) {
           temp = sparse_set->dense[i];
           j = i - 1;

           while (j >= 0 && sparse_set->dense[j] > temp) {
               sparse_set->dense[j + 1] = sparse_set->dense[j];
               j = j - 1;
           }
           sparse_set->dense[j + 1] = temp;
       }

       for (i = 0; i < sparse_set->value + 1; i++) {
           if (sparse_set->sparse[i] != '_')
               sparse_set->sparse[i] = '_';
       }

       uint32_t temp2;

       for (i = 0; i < sparse_set->ptr; i++) {
           for (j = 0; j < sparse_set->value + 1; j++) {
               temp2 = sparse_set->dense[i];
               if (temp2 == j) {
                   sparse_set->sparse[j] = i;
               }
           }
       }
       return true;
   }
   else{
        return false;
   }

}

ssize_t ss_size(sparse_set_ptr sparse_set){
    if(sparse_set!=NULL) {
        return (sparse_set->ptr);
    }
    else{
        return -1;
    }
}

bool ss_get_elem(sparse_set_ptr sparse_set, sparse_set_index_t sparse_index, sparse_set_elem_ptr dest){
    if(sparse_set!=NULL) {
      *dest = sparse_set->dense[sparse_index];
        return true;

    } else {
        return false;
    }
}

bool ss_print_status(sparse_set_ptr sparse_set, bool print_as_chars){

    if(sparse_set!=NULL) {
       if (!print_as_chars) {
           for (int i = 0; i < sparse_set->capacity; i++) {
               if (sparse_set->dense[i] != 95) {
                   printf("%u ", sparse_set->dense[i]);
               } else
                   printf("%c ", sparse_set->dense[i]);
           }

           printf("\n");

           for (int i = 0; i < sparse_set->value + 1; i++) {
               if (sparse_set->sparse[i] != 95) {
                   printf("%u ", sparse_set->sparse[i]);
               } else
                   printf("%c ", sparse_set->sparse[i]);
           }

           printf("\n");
           return true;
       }else{
           for (int i = 0; i < sparse_set->capacity; i++) {
                   printf("%c ", sparse_set->dense[i]);
           }

           printf("\n");

           for (int i = 0; i < sparse_set->value + 1; i++) {
                   printf("%c ", sparse_set->sparse[i]);
           }

           printf("\n");
           return true;
       }

   } else {

       return false;
   }
}

bool ss_union(sparse_set_ptr a, sparse_set_ptr b, sparse_set_ptr result){
    return false;
}
bool ss_intersection(sparse_set_ptr a, sparse_set_ptr b, sparse_set_ptr result){
    return false;
}
bool ss_difference(sparse_set_ptr a, sparse_set_ptr b, sparse_set_ptr result){
    return false;
}