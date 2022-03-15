#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){

    srand(time(NULL));
    int len = 10, i;
    int *arr = malloc(sizeof(int) * len * len);
    for(i = 0; i < len * len; ++i){
        *(arr + i) = rand() % 20 + 10;
    }
    int x1 = 2, y1 = 4, len2 = 3;
    *(arr + y1 * len + x1) = -999;
    int i2, i3;
    for(i2 = 0 ; i2 < len; ++i2){
        for(i3 = 0; i3 < len; ++i3){
            printf("%d ", *(arr + i2 * len + i3));
        }
        printf("\n");
    }
    int i4,i5, sum = 0;
    for(i4 = 0; i4 < len ; ++i4){
        for(i5 = 0; i5 < len; ++i5){
            if(!((i4 >= y1 && i4 < y1+len2) && (i5 >= x1 && i5 < x1 + len2)))
                sum += *(arr + i4 * len + i5);
        }
    }
    for(i4 = 0; i4 < len ; ++i4){
        for(i5 = 0; i5 < len; ++i5){
            if((i4 >= y1 && i4 < y1+len2) && (i5 >= x1 && i5 < x1 + len2))
                *(arr + i4 * len + i5) /= sum;
        }
    }
    printf("sum = %d\n",sum);
    int i6, i7;
    for(i6 = 0 ; i6 < len; ++i6){
        for(i7 = 0; i7 < len; ++i7)
            printf("%d ", *(arr + i6 * len + i7));
        printf("\n");
    }
    
    //int *diag = malloc(sizeof(int) * len);
    printf("======================\n");
    int i8, i9, i10, i11, pr1, pr2;
    for(i8 = 0, i10 = len-1; i8 < len; ++i8, -- i10){
        for(i9 = 0, i11 = len-1; i9 < len; ++i9, --i11){
            if(i8 == i9){
                printf("====\n");
                printf("t1 = %d, ",*(arr + i8 * len + i9));
                printf("t2 = %d\n",*(arr + i10 * len + i11) );
                //pr1 = *(arr + i8 * len + i9);
                pr1 = *(arr + i10 * len + i11);
                pr2 = *(arr + i8 * len + i9);
                *(arr + i8 * len + i9) = pr1;
                *(arr + i10 * len + i11) = pr2;

                //*(arr + i8 * len + i9) = *(arr + i10 * len + i11);
                //*(arr + i10 * len + i11) = *(arr + i8 * len + i9);
                //*(arr + i10 * len + i11) = pr1;
                //*(arr + i8 * len + i9) = pr1;
                //printf("%d %d\n",i8, i10);

                printf("t1 = %d, ",*(arr + i8 * len + i9));
                printf("t2 = %d\n",*(arr + i10 * len + i11) );

            }
            else{
                *(arr + i8 * len + i9) = 0;
            }
        }
    }
    
    
    int i12, i13;
    for(i12 = 0 ; i12 < len; ++i12){
        for(i13 = 0; i13 < len; ++i13)
            printf("%d ", *(arr + i12 * len + i13));
        printf("\n");
    }








}












