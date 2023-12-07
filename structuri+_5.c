#include <stdio.h>
#include <conio.h>
#define PI 3.14

struct Dreptunghi{int latime,lungime;};

union Val{
        int raza;
        struct Dreptunghi dreptunghi;
};

struct fig_geom{

    char nume;
    union Val val;

};

float arie(struct fig_geom fig){

    float a;

    do{
        printf("numele figurii (d sau c): ");
        scanf("%c",&fig.nume);
        getchar();
    }while(tolower(fig.nume)!='d' && tolower(fig.nume)!='c');

    if(tolower(fig.nume)=='d'){
            scanf("%d%d",&fig.val.dreptunghi.latime,&fig.val.dreptunghi.lungime);
            printf("\n\n");
            a=2*fig.val.dreptunghi.latime*fig.val.dreptunghi.lungime;
    }
    else
    if(tolower(fig.nume)=='c')
    {
        scanf("%d",&fig.val.raza);
        a=2*fig.val.raza*PI;
    }


    return a;
}

int main(){

    struct fig_geom fig;

    printf("Aria figurii alese este: %3.2f\n\n",arie(fig));



    return 0;

}
