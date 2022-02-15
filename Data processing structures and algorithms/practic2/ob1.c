#include <stdlib.h>
#include <stdio.h>



struct times{

    int hour;
    int minute;
    
} *pt1;

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

int main(){

    struct times t1 = {0,630};

    pt1 = &t1;
    print_time(t1);
    dest(pt1);
    print_time(t1);


}
