
#include <iostream>
#include "times.h"

using namespace std;

times::times(int h, int m){
        hour = h;
        minutes = m;
        dest();
}
times::times(int m){
        hour = 0;
        minutes = m;
        dest();
}
times::times(){

    hour = 0;
    minutes = 0;

}


void times::print(){
        cout<<hour<<":"<<minutes<<endl;
}
void times::dest(){
        if(minutes > 59){
            int r1 = minutes / 60;
            hour+=r1;
            r1 = minutes - r1 * 60;
            minutes = r1;
        }
}
int times::antidest(){
        return hour*60 + minutes;
}
times times::operator=(times t2){
        hour = t2.hour;
        minutes = t2.minutes;
        dest();

}
times times::operator+(times t2){
        return times(hour + t2.hour, minutes+t2.minutes);
}


times times::operator=(int *t2){
    hour = *(t2);
    minutes = *(t2+1);

}

