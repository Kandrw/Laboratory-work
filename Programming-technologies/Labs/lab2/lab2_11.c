#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){

    srand(time(NULL));
    int len = 10, i;
    int *arr = malloc(sizeof(int) * len);
    for(i = 0; i < len * len; ++i){
        *(arr + i) = rand() % 20 + 10;
    }
    int x1 = 2, y1 = 4, len2 = 2;
    *(arr + y1 * len + x1) = -999;
    int i2, i3;
    for(i2 = 0 ; i2 < len; ++i2){
        for(i3 = 0; i3 < len; ++i3){
            printf("%d ", *(arr + i2 * len + i3));
        }
        printf("\n");
    }
    //printf("\n");
    int i4,i5, sum = 0;
    for(i4 = 0; i4 < len ; ++i4){
        for(i5 = 0; i5 < len; ++i5){
            if(((i4 >= y1 && i4 < y1+len2) && (i5 >= x1 && i5 < x1 + len2))  ){
                //*(arr + i4 * len + i5) = 0;

            }
            else{
                
                sum += *(arr + i4 * len + i5);

            }

        }
        
    }
    for(i4 = 0; i4 < len ; ++i4){
        for(i5 = 0; i5 < len; ++i5){
            if(((i4 >= y1 && i4 < y1+len2) && (i5 >= x1 && i5 < x1 + len2))  ){
                *(arr + i4 * len + i5) /= sum ;

            }
            else{
                
                //sum += *(arr + i4 * len + i5);

            }

        }
        
    }


    printf("sum = %d\n",sum);

    for(i2 = 0 ; i2 < len; ++i2){
        for(i3 = 0; i3 < len; ++i3){
            printf("%d ", *(arr + i2 * len + i3));
        }
        printf("\n");
    }









}












