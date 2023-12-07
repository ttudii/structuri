#include <stdio.h>

struct timp{
    int ora;
    int minut;
    int secunda;
};

struct calendar{
    int zi;
    int luna;
    int an;
    struct timp moment;

};


void increm_sec(struct calendar *mom1){

    mom1->moment.secunda=mom1->moment.secunda+1;
}

void increm_zi(struct calendar *mom1){

    mom1->zi=mom1->zi+1;
}

void reuniune(struct calendar *mom1){
    increm_sec(mom1);

    printf("%d\n\n",(*mom1).moment.secunda);

    if((*mom1).moment.secunda==60)
    {
        (*mom1).moment.secunda-=60;
        (*mom1).moment.minut+=1;
    }

    if((*mom1).moment.minut==60){
        (*mom1).moment.minut-=60;
        (*mom1).moment.ora+=1;
    }

    if((*mom1).moment.ora==24)
    {
        (*mom1).moment.ora-=24;
        increm_zi(mom1);
    }

}


int main(){

    struct calendar mom1;

    mom1.zi=12;
    mom1.moment.ora=23;
    mom1.moment.minut=59;
    mom1.moment.secunda=59;

    reuniune(&mom1);

    printf("zi: %d\nora: %d\nminute: %d\nsecunde: %d\n\n",mom1.zi,mom1.moment.ora,mom1.moment.minut,mom1.moment.secunda);

    return 0;

}
