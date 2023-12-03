#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct persoana{

    char nume[30];
    char prenume[30];
    char cnp[14];

};


//presupunem ca toate persoanele au sub 100 de ani

void ord_cnp(struct persoana *pers,int dim){

    int i,j;

    struct persoana temp;

    i=0;

    while(i<dim){

    int an_i,luna_i,zi_i;

    luna_i=(*(pers[i].cnp+3)-'0')*10 +(*(pers[i].cnp+4)-'0');

    zi_i=(*(pers[i].cnp+5)-'0')*10 +(*(pers[i].cnp+6)-'0');


    if((*(pers[i].cnp+1)-'0')>2)
        an_i=1900+ (*(pers[i].cnp+1)-'0')*10 +(*(pers[i].cnp+2)-'0');
    else
        an_i=2000+ (*(pers[i].cnp+1)-'0')*10 +(*(pers[i].cnp+2)-'0');

    //printf("%d %d %d\n",an_i,luna_i,zi_i);

    j=0;

        while(j<dim){

            int an_j,luna_j,zi_j;

            luna_j=(*(pers[j].cnp+3)-'0')*10 +(*(pers[j].cnp+4)-'0');

            zi_j=(*(pers[j].cnp+5)-'0')*10 +(*(pers[j].cnp+6)-'0');


            if((*(pers[j].cnp+1)-'0')>2)
                an_j=1900+ (*(pers[j].cnp+1)-'0')*10 +(*(pers[j].cnp+2)-'0');
            else
                an_j=2000+ (*(pers[j].cnp+1)-'0')*10 +(*(pers[j].cnp+2)-'0');


            if(an_i>an_j){
                temp=pers[i];
                pers[i]=pers[j];
                pers[j]=temp;
            }

            else

            if(an_i==an_j){
                if(luna_i>luna_j){
                    temp=pers[i];
                    pers[i]=pers[j];
                    pers[j]=temp;
                }

            }

            else

            if(luna_i==luna_j){
                if(zi_i>zi_j){
                    temp=pers[i];
                    pers[i]=pers[j];
                    pers[j]=temp;
                }

            }

        //printf("%d %d\n",i,j);

        j++;


        }

    i++;

    }




}


void ord_nume(struct persoana *pers, int dim){

int i,j;

    struct persoana temp;

    i=0;

    while(i<dim){

    j=0;

        while(j<dim){

            int x1,x2;

            x1=strcmp(pers[i].nume,pers[j].nume);
            x2=strcmp(pers[i].prenume,pers[j].prenume);

            //printf("%d %d\n",x1,x2);

            if(x1<0){
                temp=pers[i];
                pers[i]=pers[j];
                pers[j]=temp;
            }

            else

            if(x1==0){
                if(x2<0){
                    temp=pers[i];
                    pers[i]=pers[j];
                    pers[j]=temp;
                }

            }

        //printf("%d %d\n",i,j);

        j++;


        }

    i++;

    }









}

int main(){

    int dim,i,j,k,q;
    int corect;
    int unic=0;

    struct persoana *pers;


    do{
        printf("Introduceti numarul de persoane: ");
        scanf("%d",&dim);
    }while(dim<0);

    printf("\n\n");

    pers=malloc(sizeof(struct persoana)*dim);

    i=0;

    while(i<dim){
        printf("introduceti nume %d: ",i+1);
        scanf("%s",pers[i].nume);
        getchar();

        printf("introduceti prenume %d: ",i+1);
        scanf("%s",pers[i].prenume);
        getchar();

        //de reglat aspectul cu cnp unic !!!

        corect=0;

        while(!corect){
            printf("introduceti CNP %d: ",i+1);
            scanf("%s",pers[i].cnp);
            getchar();
            for(j=0;j<strlen(pers[i].cnp) && !isalpha(*(pers[i].cnp+j));j++){
                            ;
            }

            if(*(pers[i].cnp+j)=='\0')
            {
                corect=1;
            }

            if(*(pers[i].cnp+j)!='\0') printf("Acest sir nu poate reprezenta un cnp.\n");

        }

        reincearca:


        unic=0;

        for(k=0;k<i && unic!=1;k++){
                if(i>0){
                     if(strcmp(pers[i].cnp,pers[k].cnp)==0)
                        unic=1;
                }
            }

            if(unic==1){
                printf("Acest cnp a mai fost introdus.\n");
                scanf("%s",pers[i].cnp);
                getchar();
                goto reincearca;
            }


        printf("\n\n");

        i++;

        }



    //ord_cnp(pers,dim);

    ord_nume(pers,dim);

    i=0;

    //printf("persoanele ordonate dupa data nasterii: \n\n");

    printf("persoanele ordonate dupa nume: \n\n");

    while(i<dim){
        printf("%s %s\n",pers[i].nume,pers[i].prenume);
        i++;
    }



    free(pers);

    return 0;

}
