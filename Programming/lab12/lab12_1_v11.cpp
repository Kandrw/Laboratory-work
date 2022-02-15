#include <iostream>



using namespace std;

struct times{
    int hour;
    int minutes;
    times(int h, int m){
        hour = h;
        minutes = m;
        dest();
    }
    times(int m){
        hour = 0;
        minutes = m;
        dest();
    }
    void print(){
        cout<<hour<<":"<<minutes<<endl;
    }
    void dest(){
        if(minutes > 59){
            int r1 = minutes / 60;
            hour+=r1;
            r1 = minutes - r1 * 60;
            minutes = r1;
        }
    }
    int antidest(){
        return hour*60 + minutes;
    }
    times operator=(times t2){
        hour = t2.hour;
        minutes = t2.minutes;
        dest();

    }
    times operator+(times t2){
        return times(hour + t2.hour, minutes+t2.minutes);
    }

    
};



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






int main(){
    
    test1();
    test2();





}





