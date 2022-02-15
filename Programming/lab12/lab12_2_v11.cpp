
#include <iostream>
#include "times.h"

#include <time.h>
//#include 


using namespace std;



void test1(){
    cout<<"TEST1"<<endl;
    times d1 = times(23,450);
    times d2 = times(450);

    cout<<"|\td1\t|"<<endl;
    d1.print();
    cout<<"|\td2\t|"<<endl;
    d2.print();
    cout<<"|\tto minutis\t|"<<endl;
    int r1 = d2.antidest();
    cout<<"r1 = "<<r1<<" d2 = ";
    d2.print();
}


void test2(){
    cout<<"TEST2"<<endl;
    times d1 = times(23,450);
    times d2 = times(450);
    times d3 = times(123);
    cout<<"|\td3 - init\t|"<<endl;
    d3 = d1+d2;
    d3.print();
    cout<<"|\td3 - not init\t|"<<endl;
    times d4 = d1 + d3;
    d4.print();
}


void test3(){
    cout<<"TEST3"<<endl;
    times d1 = times(23,450);
    times d2;
    
    d2.print();
    d2 = {12,4};
    d2.print();
    
}

void lab12(){
    srand(time(NULL));
    cout<<"Lab12"<<endl;
    int N = (rand() % 10) + 1, i, minz = RAND_MAX, index, sum = 0;

    times d1[N];

    for(i = 0; i < N; ++i){
        d1[i] = { rand() % 10, rand() % 200};
        d1[i].print();
        if(d1[i].antidest() < minz){
            minz = d1[i].antidest();
            index = i;
        }
        sum += d1[i].antidest();
    }
    cout<<"min time = ";
    d1[index].print();
    cout<<"sum["<<N<<"] = ";
    times s = times(sum);
    s.print();




}





int main(){
    
    test1();
    test2();
    test3();
    lab12();



}







