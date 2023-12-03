#include <stdio.h>
#include <string.h>

struct timp{
    int ora;
    int minut;
    int secunda;
};

struct data{
    int zi;
    int luna;
    int an;
    struct timp moment;
};

int main(){

    struct data var;

    printf("Zi: ");
    scanf("%d",&var.zi);

    printf("Luna: ");
    scanf("%d",&var.luna);

    printf("An: ");
    scanf("%d",&var.an);

    printf("\n\n");

    printf("Ora: ");
    scanf("%d",&var.moment.ora);

    printf("Minute: ");
    scanf("%d",&var.moment.minut);

    printf("Secunde: ");
    scanf("%d",&var.moment.secunda);

    printf("\n\n%d %d %d %d %d %d\n\n",var.zi,var.luna,var.an,var.moment.ora,var.moment.minut,var.moment.secunda);


return 0;

}
