#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct informatie{
    char firma[20];
    char produs[20];
    int cantitate;
};

void cant_max(struct informatie *v){

    char prod[20];
    int i,corect;
    int max=0;
    char sir[20];
    char temp1[20],temp2[20];

    reintroducere:

    corect=0;

    printf("Introduceti numele produsului: ");
    scanf("%s",prod);
    for(i=0;i<5;i++){
        if(strcmp(strlwr(v[i].produs),strlwr(prod))==0)
            {
                corect=1;
                break;
            }

    }

    if(corect==0)
    {
        printf("Acest produs nu exista!\n\n");
        goto reintroducere;
    }

    printf("%\n\n%s\n\n",prod);

    for(i=0;i<5;i++){
        strcpy(temp1,strlwr(prod));
        strcpy(temp2,strlwr(v[i].produs));
        if(strcmp(temp1,temp2)==0 && v[i].cantitate>max)
        {
           max=v[i].cantitate;
           strcpy(sir,v[i].firma);
        }

    }

    printf("Firma care produce cea mai mare cantitate din produsul introdus este: %s\n\n",sir);


}

int main(){

    int i,j;

    struct informatie *v;

    v=malloc(sizeof(struct informatie)*5);

    for(i=0;i<5;i++){

        instructiune:

        printf("Produs %d\n",i+1);
        printf("Firma: ");
        scanf("%s",v[i].firma);
        getchar();
        printf("Produs: ");
        scanf("%s",v[i].produs);
        getchar();
        printf("Cantitate: ");
        scanf("%d",&v[i].cantitate);
        printf("\n\n");
        getchar();
        for(j=0;j<i;j++){
            if(strcmp(v[i].firma,v[j].firma)==0 && strcmp(v[i].produs,v[j].produs)==0)
                {
                    printf("Aceasta informatie a mai fost introdusa.\n");
                    goto instructiune;
                }
        }

    }

    cant_max(v);

    free(v);

    return 0;

}
