



struct times{

    int hour, minutes;

    times(int h, int m);
    times(int m);
    times();

    void print();
    void dest();
    int antidest();
    times operator=(times t2);
    times operator+(times t2);
    times operator=(int *t2);





};









