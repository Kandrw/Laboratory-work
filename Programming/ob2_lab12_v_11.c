#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 9


struct times{

    int hour;
    int minute;
    
};



void dest(struct times *t){
    if(t->minute>59){
        int r1 = t->minute/60;
        //printf("r1 = %d\n",r1);
        int r2 = t->minute - r1 * 60;
        t->hour = t->hour+r1;
        t->minute = r2;
    }
}

void print_time(struct times t){
    printf("%d:%d\n",t.hour,t.minute);
}

void struct_make(struct times t[]){
    int i;
    for(i = 0; i < N; ++i){
        t[i].hour = rand() % 10;
        t[i].minute = rand() % 60;
    }
}

void pr_all(struct times t[]){
    int i;
    for(i = 0; i < N; ++i){
        printf("%d ",i);
        print_time(t[i]);
    }
}

int t_to_min(struct times t){
    return t.hour*60 + t.minute;
}
void min_st_t(struct times t[], int n){
    static int min_t = RAND_MAX;
    static int index = 0;
    static int sum = 0;
    if(n >= 0){
        int pr1 = t_to_min(t[n]);
        if(pr1 < min_t){
            min_t = pr1;
            index = n;
        }
        sum += pr1;
        min_st_t(t,n-1);
    }
    else{
        printf("index = %d min = %d minutes or ",index,min_t);
        print_time(t[index]);
        struct times sumt = {0, sum};
        dest(&sumt);
        printf("sum = %d minutes or ",sum);
        print_time(sumt);
    }
}


void ob1(){
    struct times t[N];
    struct_make(t);
    pr_all(t);
    min_st_t(t,N-1);
}



int main(){
    srand(time(NULL));
    ob1();


}




