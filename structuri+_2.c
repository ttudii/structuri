#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct informatii{
    int cod_firma;
    int cod_produs;
    int cantitate;
};

int max_cant(struct informatii *v,int dim,int x){

    int i,indice,max=0;
    int corect=0;

    do{
        printf("Introduceti codul produsului: ");
        scanf("%d",&x);
        for(i=0;i<dim;i++){
            if(v[i].cod_produs==x)
            {
                corect=1;
                break;
            }
        }
        if(corect==0) printf("Acest cod de produs nu exista!\n\n");
    }while(!corect);

    for(i=0;i<dim;i++){
        if(v[i].cod_produs==x && max<v[i].cantitate)
        {
            max=v[i].cantitate;
            indice=i;
        }
    }


    return v[indice].cod_firma;

}

int main(){

    struct informatii *v;
    int dim;
    int x;
    int i,j;

    do{
        printf("numar de produse: ");
        scanf("%d",&dim);
    }while(dim<0 || dim>20);

    printf("\n\n");

    v=malloc(sizeof(struct informatii)*dim);

    for(i=0;i<dim;i++){

        reintrod:

        printf("Codul firmei %d: ",i+1);
        scanf("%d",&v[i].cod_firma);

        printf("Codul produsului %d: ",i+1);
        scanf("%d",&v[i].cod_produs);

        printf("Cantitate: ");
        scanf("%d",&v[i].cantitate);

        for(j=0;j<i;j++){
            if(v[i].cod_firma==v[j].cod_firma && v[i].cod_produs==v[j].cod_produs)
                {
                    printf("acest produs a mai fost introdus!\n\n");
                    goto reintrod;
                }
        }

        printf("\n\n");

    }

    printf("codul firmei care produce cea mai mare cantitate pentru produsul introdus este: %d\n\n",max_cant(v,dim,x));

    return 0;

}
