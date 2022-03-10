#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Структура элемента списка
struct unit{
    int index;//индекс в двусвызном списке
    int a;//значение
    struct unit *next;//следующий элемент
    struct unit *prev;//предыдущий элемент
};
//Структура двусвызного списка 
struct list{
    struct unit *tail;//начало
    struct unit *head;//конец
    int len;//длинна
};
//Получение конца списка
struct unit* getTail(struct unit *head){
    while(1){
        if(head->next == NULL)
            return head;
        head = head->next;
    }
}
//Получение начала списка
struct unit* getHeal(struct list *data){
    return data->head;
}
//Проверка на наличие элементов в списке
int isEmpty(struct list *data){
    if(data->head == NULL || data->tail == NULL)
        return 0;
    else
        return data->len;
}
//Выделение памяти при создание элемента списка unit
struct unit* _create_unit(struct unit *head, int el, int index){
    struct unit* d1;
    d1 = (struct unit*)malloc(sizeof(struct unit));
    d1->a = el;
    d1->index = index;
    d1->next = head;
    d1->prev = NULL;
    return d1;
}
//Создание адреса предыдущиго элемента в списке
void _create_prev(struct list *data){
    struct unit *i = data->head;
    struct unit *i2;
    while(i != NULL){
        i2 = i;
        i = i->next;
        if(i != NULL)
            i->prev = i2;
    }
}
//Создание структуры двусвязного списка
void Create(struct list *data){
    int i;
    struct unit *head = NULL;
    for(i = data->len -1 ; i >= 0; --i)
        head = _create_unit(head, (rand()%10)-0, i);
    data->head = head;
    _create_prev(data);
    data->tail = getTail(data->head);
}
//Вывод списка с начала
void print_list_head(struct list *data){
    struct unit *i = data->head;
    while(i != NULL){
        printf("%d ", i->a);
        i = i->next;
    }
    printf("\n");
}
//Вывод свиска с конца
void print_list_tail(struct list *data){
    struct unit *i = data->tail;
    while(i != NULL){
        printf("i = %d, a = %d\n", i->index, i->a);
        i = i->prev;
    }
    printf("\n");
}
//Заполение списка с клавиатуры
void fill_list(struct list *data){
    struct unit *head = data->head;
    printf("Input list: ");
    while(head != NULL){
        scanf("%d%*c", &head->a);
        head = head->next;
    }
}
//Удаление struct list
void Delete_list(struct list *data){
    struct unit *head = data->head;
    struct unit *h_next;
    while(head != NULL){
        h_next = head->next;
        free(head);
        head = h_next;
    }
    free(data);
}
//Добавление элемента
void Append(struct list *data, int el){
    struct unit *new_el = (struct unit*)malloc(sizeof(struct unit));
    new_el->a = el;
    new_el->next = NULL;
    new_el->index = data->tail->index + 1;
    data->tail->next = new_el;
    new_el->prev = data->tail;
    data->tail = new_el;
    data->len = data->len + 1; 
}
//Удаление элемента с конца
void Remove_tail(struct list *data){
    struct unit *del = data->tail;
    data->tail = data->tail->prev;
    data->tail->next = NULL;
    free(del);
    data->len = data->len - 1;
}
//Удаление элемента с начала
void Remove_head(struct list *data){
    struct unit *del = data->head;
    data->head = del->next;
    data->head->prev = NULL;
    free(del);
    data->len = data->len - 1;
    del = data->head;
    while(del != NULL){
        del->index = del->index - 1;
        del = del->next;
    }
}
//Удаление элемента по индексу
void Remove(struct list *data, int index){
    if(index == 0)
        Remove_head(data);
    else if(index == data->len-1)
        Remove_tail(data);
    else{
        struct unit *i = data->head;
        struct unit *r1 = NULL;
        int con = 0;
        while(i != NULL){
            if(i->next != NULL){
                if(i->next->index == index){
                    r1 = i->next;
                    i->next = r1->next;
                    i->next->prev = i;
                    free(r1);
                    con = 1;
                    break;
                }
            }
            i = i->next;
        }
        if(con == 1){
            i = data->head;
            con = 0;
            while(i != NULL){
                i->index = con;
                ++con;
                i = i->next;
            }
        }
        data->len = data->len - 1;
    }
}
//Получение элемента связного списка по индексу
int element(struct list *data, int index){
    struct unit *i = data->head;
    while(1){
        if(i->index == index)
            return i->a;
        i = i->next;
    }
}
//Обмен значениями между двумя элементами i и j
void swap(struct list *data, int i, int j){
    struct unit *head = data->head;
    struct unit *x1 = NULL;
    struct unit *x2 = NULL;
    while(head != NULL){
        if(head->index == i)
            x1 = head;
        if(head->index == j)
            x2 = head;
        head = head->next;
    }
    if(x1 != NULL || x2 != NULL){
        int pr = x1->a;
        x1->a = x2->a;
        x2->a = pr;
    }
    else
        printf("Error"); 
}
//Сортировка двусвызного списка
void sort_list(struct list *data, int first, int last){
    int i = first, j = last, x = element(data,(first + last)/2);
    do{
        while(element(data, i) < x)
            ++i;
        while(element(data,j) > x)
            --j;
        if(i <= j){
            if(element(data,i) > element(data,j))
                swap(data, i, j);
            ++i;
            --j;
        }
    } while(i <= j);
    if(i < last)
        sort_list(data, i, last);
    if(first < j)
        sort_list(data, first, j);
}
//Удаление дубликатов в отсортированном двусвязном списке 
void removing_duplicates(struct list *data){
    struct unit *head = data->head;
    int pr = head->a, count = 0, con = 0;
    while(head != NULL){
        if(head->index == 0)
            pr = head->a;
        else if(pr == head->a){
            ++count;
            Remove(data,head->index);
        }
        else
            pr = head->a;
        head = head->next;
    }
    printf("Removing duplicates - %d\n",count);
}
//Поиск k-го элемента с конца
int finding_tail(struct list *data, int k){
    struct unit *i = data->tail;
    while(i != NULL){
        if(i->a == k){
            printf("%d) %d\n", i->index, i->a);
            return 0;
        }
        i = i->prev;
    }
    printf("Element not found\n");
    return 1;
}
//Проверка списка является ли он палиндромом
int palindrom(struct list *data){
    struct unit *i = data->head;
    struct unit *i2 = data->tail;
    while(i != NULL && i2 != NULL){
        if( i->a != i2->a)
            return 1;
        if(i->index == i2->index || (i2->index - i->index) == 1 )
            return 0;
        i = i->next;
        i2 = i2->prev;
    }
}
int main(){
    srand(time(NULL));
    int len = 10, el;
    char con;
    printf("List length: ");
    scanf("%d%*c", &len);
    printf("\n");
    struct list *data = (struct list*)malloc(sizeof(struct list));
    data->len = len;
    Create(data);
    printf("Fill in or generate(1/2): ");
    scanf("%c%*c",&con);
    printf("\n");
    if(con == '2')
        fill_list(data);
    while(1){
        printf("Comand: exit(0)/print(1)/append(2)/\
remove(3)/is(4)/removing duplicates(5)/finding an element from the end(6)/palindrome(7)\n");
        scanf("%c%*c",&con);
        if(con == '0'){
            Delete_list(data);
            printf("Delete list\n");
            break;
        }
        else if(con == '1'){
            printf("print head:\n");
            print_list_head(data);
        }
        else if(con == '2'){
            printf("Enter the element: ");
            scanf("%d%*c", &el);
            printf("\n");
            Append(data, el);
        }
        else if(con == '3'){
            printf("Input delete index: ");
            scanf("%d%*c",&el);
            printf("\n");
            Remove(data,el);
        }
        else if(con == '4'){
            el = isEmpty(data);
            if(el == 0)
                printf("The list is empty\n");
            else
                printf("The list is not empty, len = %d\n", el);
        }
        else if(con == '5'){
            sort_list(data, 0, data->len-1);
            removing_duplicates(data);
        }
        else if(con == '6'){
            printf("Input element: ");
            scanf("%d%*c",&el);
            printf("\n");
            finding_tail(data, el);
        }
        else if (con == '7'){
            el = palindrom(data);
            if(el == 0)
                printf("Palindrome\n");
            else
                printf("Not a palindrome\n");
        }
        else
            printf("There is no such command\n");
    }
}
