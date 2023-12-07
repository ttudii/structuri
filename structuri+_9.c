/*
 De la tastatură, se citesc datele angajaţilor unei firme: nume, prenume, data naşterii, data angajării, funcţia, număr de
telefon, salariu. La citire, efectuaţi verificările necesare pentru ca datele să fie corecte. Se cere:
a) să se afişeze angajaţii în ordinea alfabetică a funcţiei, iar în cadrul aceleiaşi funcţii în ordinea
descrescatoare a salariului;
b) să se identifice (dacă există) şi să se afişeze angajaţii care au exact aceeaşi vârstă, dar au salarii diferite;
c) să se identifice (dacă există) angajaţii cu acelaşi prenume ale căror numere de telefon încep cu exact
aceleaşi 4 cifre (se presupune ca numerele de telefon sunt formate din 10 cifre).
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct timp{
    int an;
    int luna;
    int zi;
};

struct Angajat{
    char nume[20];
    char prenume[20];
    struct timp nastere;
    struct timp angajare;
    char functie[20];
    char telefon[11];
    float salariu;
};


int main(){

    int n;
    int i,j,k;
    int corect=0;

    struct Angajat *angajat;
    struct Angajat temp;

    do{
        printf("Numar de anagajati: ");
        scanf("%d",&n);
    }while(n<0);

    printf("\n\n");

    angajat=malloc(sizeof(struct Angajat)*n);

    //verificarea datelor angajatilor

    for(i=0;i<n;i++){

        printf("Angajat nr. %d\n\n",i+1);

        nume:

        printf("Nume: ");
        scanf("%s",angajat[i].nume);
        getchar();
        printf("Prenume: ");
        scanf("%s",angajat[i].prenume);
        getchar();


        for(j=0;j<i;j++){
            if(strcmp(angajat[i].nume,angajat[j].nume)==0 && strcmp(angajat[i].prenume,angajat[j].prenume)==0)
            {
                printf("Aceasta persoana a mai fost introdusa!\n\n");
                goto nume;
            }
        }
/*
        printf("\n\n");


        //data angajarii

        printf("Data nasterii(yyyy/mm/dd):\n");
        do{
            printf("Anul(1923<an<2000): ");
            scanf("%d",&angajat[i].nastere.an);
        }while(angajat[i].nastere.an<1923 || angajat[i].nastere.an>2000);

        printf("\n");

        do{
            printf("Luna: ");
            scanf("%d",&angajat[i].nastere.luna);
        }while(angajat[i].nastere.luna<0 || angajat[i].nastere.luna>12);

        printf("\n");

        do{
            printf("Ziua: ");
            scanf("%d",&angajat[i].nastere.zi);
            //se pot face verificari pentru nr. maxim de zile dintr-o luna
        }while(angajat[i].nastere.zi<0 || angajat[i].nastere.zi>31);

        printf("\n");

        //data angajarii


        getchar();
                printf("Data angajarii(yyyy/mm/dd):\n");
        do{
            printf("Anul(2000<an<2023): ");
            scanf("%d",&angajat[i].angajare.an);
        }while(angajat[i].angajare.an<2000 || angajat[i].angajare.an>2023);

        printf("\n");

        do{
            printf("Luna: ");
            scanf("%d",&angajat[i].angajare.luna);
        }while(angajat[i].angajare.luna<0 || angajat[i].angajare.luna>12);

        printf("\n");

        do{
            printf("Ziua: ");
            scanf("%d",&angajat[i].angajare.zi);
        }while(angajat[i].angajare.zi<0 || angajat[i].angajare.zi>31);

        getchar();
*/
        printf("\n\n");

        printf("Functie: ");
        scanf("%s",angajat[i].functie);
        getchar();

        printf("\n\n");
/*
        //nr. de telefon

        telefon:

        printf("Telefon: ");
        scanf("%s",angajat[i].telefon);
        getchar();


    if(strlen(angajat[i].telefon)==10){
        for(k=0;k<strlen(angajat[i].telefon);k++){
            if((isalpha(*(angajat[i].telefon+k))))
                  break;
        }

        if(k!=strlen(angajat[i].telefon) || *(angajat[i].telefon+0)-'0'!=0 || *(angajat[i].telefon+1)-'0'!=7)
        {
            printf("Acesta nu poate fi un nr. de telefon!\n\n");
            goto telefon;
        }
    }
    else
    {
        printf("Sirul are prea putine cifre!\n\n");
        goto telefon;
    }

        printf("\n\n");
*/
        do{
            printf("Salariu: ");
            scanf("%f",&angajat[i].salariu);
        }while(angajat[i].salariu<0);

        printf("\n\n");

        }

    int comp;
    char change[20];
    int indice;

// Funcție de sortare alfabetică a funcțiilor

    for(i=0; i<n-1;i++) {
        for(j=i+1;j<n;j++) {
            if(strcmp(angajat[i].functie,angajat[j].functie)>0){
                 temp=angajat[i];
                 angajat[i]= angajat[j];
                 angajat[j]= temp;
            }
        }
    }

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(angajat[i].functie,angajat[j].functie)==0 && angajat[i].salariu<angajat[j].salariu){
                temp=angajat[i];
                angajat[i]= angajat[j];
                angajat[j]= temp;
            }

        }
    }

    for(i=0;i<n;i++) printf("%s %s %s\n",angajat[i].functie,angajat[i].nume,angajat[i].prenume);
    free(angajat);

    return 0;

}
