#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "times.h"


int main(){
    srand(time(NULL));
    struct times t[N];
    struct_make(t);
    pr_all(t);
    min_st_t(t,N-1);
}