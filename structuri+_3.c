#include <stdio.h>
#include <string.h>

struct timp {
    int ora;
    int minute;
    int secunde;
};

struct timp diferenta(struct timp mom1, struct timp mom2){

    struct timp dif;

    dif.ora=mom2.ora-mom1.ora;
    dif.minute=mom2.minute-mom1.minute;
    dif.secunde=mom2.secunde-mom1.secunde;

    if(dif.secunde<0)
    {
        dif.minute--;
        dif.secunde+=60;
    }

    if(dif.minute<0)
    {
        dif.ora--;
        dif.minute+=60;
    }

    if (dif.ora < 0) {
        dif.ora += 24;
    }

    return dif;

}

int main(){

    struct timp mom1,mom2;
    struct timp d;

    printf("Moment 1:\n\n");

    printf("Ora: ");
    scanf("%d",&mom1.ora);

    printf("Minute: ");
    scanf("%d",&mom1.minute);

    printf("Secunde: ");
    scanf("%d",&mom1.secunde);

    printf("\n\n");

    printf("Moment 2:\n\n");

    printf("Ora: ");
    scanf("%d",&mom2.ora);

    printf("Minute: ");
    scanf("%d",&mom2.minute);

    printf("Secunde: ");
    scanf("%d",&mom2.secunde);

    d.ora=diferenta(mom1,mom2).ora;
    d.minute=diferenta(mom1,mom2).minute;
    d.secunde=diferenta(mom1,mom2).secunde;

    printf("diferenta celor doua interval de timp este de %d ore, %d de minute si %d de secunde.\n\n",d.ora,d.minute,d.secunde);


    return 0;

}
