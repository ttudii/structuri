#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct lista{
    int nr;
    float nota;
};

int max_nr(struct lista *v,int dim){

    int i,indice;
    float max;
    max=v[0].nota;
    indice=0;

    for(i=1;i<dim;i++){
        if(v[i].nota>max)
        {
            max=v[i].nota;
            indice=i;
        }
    }

    return v[indice].nr;
}

int main(){

    int dim;
    int i,j;
    struct lista *v;

    do{
        printf("numar elemente de tip lista: ");
        scanf("%d",&dim);
    }while(dim<0 || dim>100);

    printf("\n\n");

    v=malloc(sizeof(struct lista)*dim);

    for(i=0;i<dim;i++){
        printf("Numarul %d: ",i+1);
        scanf("%d",&v[i].nr);
        printf("Nota %d: ",i+1);
        scanf("%f",&v[i].nota);
        printf("\n");
    }

    printf("Valoarea campului nr asociata celei mai mari valori a notei este: %d\n",max_nr(v,dim));


    return 0;

}
