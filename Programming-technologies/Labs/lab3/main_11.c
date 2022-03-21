#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *matrix(int N){

    int *A = malloc(sizeof(int) * N * N);
    int i;
    for(i = 0; i < N*N; ++i)
        *(A+i) = rand() % 200 - 100;
    return A;
}
void print_matrix(int *A, int N){

    int i,i2, sum = 0;
    for(i = 0; i < N; ++i){
        for(i2 = 0; i2 < N; ++i2)
            printf("%3d ", *(A + i * N + i2));
        printf("\n");
    }
}
int sum_diag(int *A, int N){
    int i, sum = 0;
    for(i = 0; i < N; ++i)
        sum += *(A+i+i*N);
    return sum;
}
int count_A(int *A, int N, int sum, int *count_m){
    int i, i2;
    for(i = 0; i < N; ++i){
        for(i2 = 0; i2 < N; ++i2){
            if(*(A + i * N + i2) < sum)
                ++count_m[0];
            else if(*(A + i * N + i2) > sum)
                ++count_m[1];
        }
    }

}

int main(){
    srand(time(NULL));
    int N = 10;
    int *A = matrix(N);
    print_matrix(A,N);
    int sum = sum_diag(A,N);
    printf("sum = %d\n",sum);
    int count_m[] = {0,0};
    count_A(A,N,sum,count_m);
    printf("count < sum = %d\ncount > sum = %d\n",\
    count_m[0], count_m[1]);
}
