#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define M1 3.5
#define M2 8.5
void arr_make(double *arr, int i){
    if(i >= 0){
        *(arr+i) = (double)rand()*(double)(15)/RAND_MAX+(double)-5;
        arr_make(arr, i-1);
    }
}
void arr_print(double *arr, int n){
    int i;
    for(i = 0; i < n; ++i){
        printf("%f ",arr[i]);
    }
    printf("\n");
}
void min_array(double *arr, int n){
    static double min = RAND_MAX;
    if(n >= 0){
        if(*(arr+n) > M1 && *(arr + n) < M2 && *(arr+n)<min){
            min = *(arr+n);
        }
        min_array(arr,n-1);
    }
    else{
        printf("min = %f\n",min);
    }
}
int main(){
    srand(time(NULL));
    int len;
    printf("len array = ");
    scanf("%d",&len);
    printf("\n");
    double *array = malloc(len * sizeof(double));
    arr_make(array,len-1);
    arr_print(array,len);
    min_array(array, len-1);
}








