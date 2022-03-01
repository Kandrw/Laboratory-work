#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N1 20


//Структура пользователь
struct user{
    struct user *next;
    char surname[N1];
    char name[N1];
    int age;
    int year;
    char locate_work[N1];
    int car;
    int marriage;

};
//Генерация случайных строк(например Fqobhhldubac)
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
//Вывод информации о конкретном пользователе
void info_user(struct user *u1){
    printf("Name = %s\n",u1->name);
    printf("Surname = %s\n",u1->surname);
    printf("age = %d\n",u1->age);
    printf("year = %d\n",u1->year);
    printf("Locate work = %s\n",u1->locate_work);
    printf("Count car = %d\n",u1->car);
    if(u1->marriage == 0){
        printf("Not married\n");
    }
    else{
        printf("Married\n");
    }
}
//Вывод только фамилии и имени пользователей
void print_us_sn(struct user *ps){
    printf("List users:\n");
    while (ps != NULL)
    {
        printf("\tName = %s\n",ps->name);
        printf("\tSurname = %s\n",ps->surname);
        printf("--------\n");
        ps = ps->next;
    }
}
//Сравнение строк
int str_comp(char s1[], char s2[]){
    for (int i = 0; ; i++){
        if (s1[i] != s2[i]){
            return s1[i] < s2[i] ? -1 : 1;
        }
        if (s1[i] == '\0'){
            return 0;
        }
    }
}
//Поиск имени и фамилии в списке пользователей
int search_user(struct user *ps, char *n, char *s){

    while (ps != NULL){
        if(str_comp(n, ps->name) == 0 && str_comp(s, ps->surname) == 0 ){
            info_user(ps);    
            return 0;
        }
        ps = ps->next;
    }
    return 1;
}
//Удаление последнего пользователя
void del_user(struct user *ps){
    while (ps != NULL){
        if(ps->next->next == NULL){
            free(ps->next);
            ps->next = NULL;
        }
        ps = ps->next;
    }
}
struct user* init_users(struct user *usn){
    struct user *us1;
    us1 = (struct user*)malloc(sizeof(struct user));
    us1->next = usn;

    us1->age = rand() % 60 + 10;
    us1->year = 2022 - us1->age;
    if(us1->age < 18){
        us1->marriage = 0;
        us1->car = 0;
    }
    else{
        us1->marriage = rand() % 2;
        us1->car = rand() % 3;
    }
    generator_char(us1->name, 1);
    generator_char(us1->surname,1);
    generator_char(us1->locate_work,0);
    return us1;
}
int main(){
    srand(time(NULL));
    
    int CN, i;
    struct user *users;
    users = NULL;
    printf("Number of users: ");
    scanf("%d%*c",&CN);

    for(i = 0; i < CN; ++i){
        users = init_users(users);
    }
    char name[N1];
    char surname[N1];
    char input;
    int r1;

    while(1){
        printf("Input: 0(exit)/1(list name surname)\
/2(info name surname)/3(delete last user)\n");
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
            r1 = search_user(users, name, surname);
            if(r1 == 1){
                printf("User not found\n");
            }
        }
        else if(input == '3'){
            del_user(users);
            printf("Last user deleted\n");
        }
        
        else{
            printf("Command error: %c\n",input);
        }
    }
}
