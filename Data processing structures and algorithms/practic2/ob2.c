#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//Для сравнения символьных массивов
#include <string.h>


#define N1 20
#define CN 100


struct user{
    char surname[N1];
    char name[N1];
    int age;
    int year;
    char locate_work[N1];
    int car;
    int marriage;
};


void generator_char(char *data, int con){
    
    
    if(con == 1){
        int len = (rand() % 10)+4;
        data[0] = (rand() % 25) + 65;
        int i;
        for(i = 1; i < len; ++i){
            *(data+i) = (rand() % 24) + 97;
        }
        data[i] = '\0';
    }
    else{
        int len = (rand() % N1)-1;
        if(len < 4){
            data[0] = 'N'; data[1] = 'o'; 
            data[2] = 'n'; data[3] = 'e';
            data[4] = '\0';
        }
        else{
            data[0] = (rand() % 29) + 65;
            int i;
            for(i = 1; i < len; ++i){
                *(data+i) = (rand() % 25) + 97;
            }
            data[i] = '\0';
        }
    }
    

}


void people_generator(struct user *u1){

    u1->age = rand() % 60 + 10;
    u1->year = 2022 - u1->age;
    if(u1->age < 18){
        u1->marriage = 0;
        u1->car = 0;
    }
    else{
        u1->marriage = rand() % 2;
        u1->car = rand() % 3;
        generator_char(u1->name,1);
        generator_char(u1->surname,1);
        generator_char(u1->locate_work,0);
        
        
    }

    

}



void info_user(struct user u1){

    printf("Name = %s\n",u1.name);
    printf("Surname = %s\n",u1.surname);
    printf("age = %d\n",u1.age);
    printf("year = %d\n",u1.year);
    printf("Locate work = %s\n",u1.locate_work);
    printf("Count car = %d\n",u1.car);
    if(u1.marriage == 0){
        printf("Not married\n");
    }
    else{
        printf("Married\n");
    }
}


void init_users(struct user *users){

    int i;
    for(i = 0; i < CN; ++i){
        people_generator(&users[i]);
    }

}
void print_us_sn(struct user *users){
    int i;
    for(i = 0; i < CN; ++i){
        printf("%d\n",i);
        printf("\tName = %s\n",users[i].name);
        printf("\tSurname = %s\n",users[i].surname);
        
    }
}
void comp(char *name, char *surname, struct user *usn){

    int i;
    int c = 0;
    for(i = 0; i < CN; ++i){
        
        if(strcmp(name, usn[i].name) == 0 \
        && strcmp(surname,usn[i].surname) == 0){
            printf("Information:\n");
            info_user(usn[i]);
            c = 1;
            break;
        }
        
    }
    if(c == 0){
        printf("User not found\n");
    }


}


void ob1(){
    struct user us1;
    people_generator(&us1);
    info_user(us1);
    struct user users[CN];
    init_users(users);

    print_us_sn(users);
    

}


void ob2(){
    struct user users[CN];
    init_users(users);

    char name[CN];
    char surname[CN];
    char input;
    int r1;
    while(1){
        printf("Input: 0(exit)/1(list name surname)\
/2(info name surname)\n");
        scanf("%c%*c", &input);
        if(input == '0'){
            printf("Exit program\n");
            break;
        }
        else if(input == '1'){
            print_us_sn(users);
        }
        else if(input == '2'){
            printf("Input name and surname:\n");
            gets(name);
            gets(surname);
            comp(name,surname,users);
        }
        else{
            printf("Command error: %c\n",input);
        }
    }
}




int main(){
    srand(time(NULL));
    
    ob2();


}











