#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct _graph{
    int a;
    struct _graph *next1;
    struct _graph *next2;
    //struct _graph *next2;
    
} graph;
graph *ttty1(graph *head, int d1, int d2){
    
    graph *i = head;
    if(i != NULL){
        if(i->a == d1){
            graph *newgraph = (graph*)malloc(sizeof(graph));
            newgraph->next1 = NULL;
            newgraph->next2 = NULL;
            newgraph->a = d2;
            if(i->next1 == NULL){
                i->next1 = newgraph;
                return newgraph;
            }
            else if(i->next2 == NULL){
                i->next2 = newgraph;
                return newgraph;
            }
            else{
                free(newgraph);
                return NULL;
            }
        }
        else{
            graph *p = ttty1(i->next1, d1,d2);
            if(p == NULL)
                p = ttty1(i->next2, d1,d2);
            return p;
        }
    }
    return NULL;
}

graph *ttty(graph *head, int d1, int d2){
    
    graph *i = head;
    if(i != NULL){
        if(i->a == d1){
            
            graph *newgraph = (graph*)malloc(sizeof(graph));
            newgraph->next1 = NULL;
            newgraph->next2 = NULL;
            newgraph->a = d2;
            if(i->next1 == NULL){
                if(i->next2 != NULL){
                    if(d2 == i->next2->a){
                        free(newgraph);
                        return NULL;
                    }
                }
                i->next1 = newgraph;
                printf("(%d -> %d)\n",i->a,d2);
                return newgraph;
            }
            else if(i->next2 == NULL){
                if(d2 == i->next1->a){
                    free(newgraph);
                    return NULL;
                }
                i->next2 = newgraph;
                printf("(%d -> %d)\n",i->a,d2);
                return newgraph;
            }
            else{
                free(newgraph);
                return NULL;
            }
        }
        else{
            graph *p1 = ttty(i->next1, d1,d2);
            graph *p2 = ttty(i->next2, d1,d2);
            if(p1 == NULL)
                return p2;
            else
                return p1;
            
        }
    }
    return NULL;
}





graph* create_graphs(graph *data, int len){
    graph *graphhead = (graph*)malloc(sizeof(graph));
    data = graphhead;
    graphhead->a = 1;
    graphhead->next1 = NULL;
    graphhead->next2 = NULL;
    graph *p1 = graphhead;
    graph *p2 = NULL;
    int i = 0, el1, el2;
    int k1[len];
    while(i < len){
        el1 = rand() % 20+1;
        el2 = rand() % 20+1;
        while(el1 == el2)
            el2 = rand() % 20+1;
        p2 = ttty(graphhead,el1,el2);
        if(p2 != NULL){
            
            ++i;
            
        }
    }
    printf("len = %d\n",i);
    return data;
}
void print_graph(graph *data, int d1){
    if(data != NULL){
        printf("(%d -> %d)\n",d1,data->a);
        print_graph(data->next1,data->a);
        print_graph(data->next2,data->a);
    }
}
int search_route1(graph *head, int d1, int d2){
    if(head != NULL){
        if(head->a == d1){
            if(head->next1 != NULL){
                if(head->next1->a == d2)
                    return 1;
            }
            else if(head->next2 != NULL){
                if(head->next2->a == d2)
                    return 1;
            }
        }
        else if(head->a == d2){
            if(head->next1 != NULL){
                if(head->next1->a == d1)
                    return 2;
            }
            else if(head->next2 != NULL){
                if(head->next2->a == d1)
                    return 2;
            }
        }
        int p1 = search_route1(head->next1,d1,d2);
        int p2 = search_route1(head->next2,d1,d2);
        if(p1 == 0)
            return p2;
        else 
            return p1;
    }
    return 0;
}


int search_route(graph *head, int d1, int d2){
    if(head != NULL){
        if(head->a == d1){
            if(head->next1 != NULL){
                if(head->next1->a == d2)
                    return 1;
            }
            else if(head->next2 != NULL){
                if(head->next2->a == d2)
                    return 1;
            }
            return 0;
        }
        
        int p1 = search_route(head->next1,d1,d2);
        int p2 = search_route(head->next2,d1,d2);
        if(p1 == 1)
            return p1;
        else if(p2 == 1)
            return p2;
        else 
            return 0;
    }
    return 0;
}


void auto_search(graph *head, int lim){

    int i,i2,p, c1= 0, c2 = 0;
    for(i = 1; i < lim; ++i){
        for(i2 = 1; i2 < lim; ++i2){
            if(i != i2){
                int p = search_route(head,i,i2);
                if(p == 1){
                    ++c1;
                   printf("(%d -> %d)\n",i,i2);

                }
                else if(p == 2){
                    ++c2;
                    //printf("(%d <- %d)\n", i,i2);
                }
                //else

                    //printf("Not found graph: (%d,%d)\n",i,i2);
            }
        }
    }
    printf("sum = %d\nc1 = %d\nc2 = %d\n",c1+c2,c1,c2);
}

int main(){
    srand(time(NULL));
    graph *head = NULL;
    head = create_graphs(head,20);
    printf("=================\n");
    print_graph(head,0);
    printf("Created graph\n");
    int d1,d2;

    auto_search(head,21);
    
    printf("Input route: ");
    scanf("%d%d%*c",&d1,&d2);
    printf("\n");
    if(d1 == d2)
        printf("Error: (%d,%d)\n",d1,d2);
    else{
        int p = search_route(head,d1,d2);
        if(p == 1)
            printf("(%d -> %d)\n",d1,d2);
        else if(p == 2)
            printf("(%d <- %d)\n", d1,d2);
        else
            printf("Not found graph: (%d,%d)\n",d1,d2);
    }
    
}
