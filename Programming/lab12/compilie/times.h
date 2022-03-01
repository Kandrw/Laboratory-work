#define N 9
struct times{
    int hour;
    int minute; 
};
void dest(struct times *t);
void print_time(struct times t);
void struct_make(struct times t[]);
void pr_all(struct times t[]);
int t_to_min(struct times t);
void min_st_t(struct times t[], int n);




