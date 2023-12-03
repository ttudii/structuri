#include <stdio.h>
#include <string.h>
#define DIM 20
#include <ctype.h>


struct carte{

    char titlu[20];
    int an;
    struct autor{
    char nume[30],prenume[30];
    char gen;
    }autor;

};

struct temp{
    char  nume[30];
    char prenume[30];
};

void gasit(struct carte *c, int dim){

    int i;
    int found;

    char nume1[30],prenume1[30];

    printf("Introduceti numele si prenumele autorului: ");
    scanf("%s",nume1);
    getchar();
    scanf("%s",prenume1);

    printf("Cartile scrise de acest autor sunt: \n");

    int j;
    int length1,length2;

    //length1=length2=0;

    i=0;

    while(i<dim){

        found=0;

        j=0;
        length1=0;
        while(j<strlen(nume1))
        {
            if((*c[i].autor.nume+j)==*(nume1)+j)
                length1++;
            j++;
        }
        if(length1==strlen(nume1))found++;

        j=0;
        length2=0;

        while(j<strlen(prenume1))
        {
            if((*(c[i].autor.prenume)+j)==*(prenume1)+j)
                length2++;
            j++;
        }
        if(length2==strlen(prenume1))found++;

        if(found==2) printf("%s, ",c[i].titlu);

        i++;
    }


}

void an_gen(struct carte *c, int dim){

    int an;
    char gen;
    char titlu[30];

    do{
    printf("Introduceti anul cautat: ");
    scanf("%d",&an);
    }
    while(an<0);

    getchar();

    do{
    printf("Introduceti genul cautat: ");
    scanf("%c",&gen);
    getchar();
    //printf(" %c",gen);
    }while(toupper(gen)!='C' && toupper(gen)!='D' && toupper(gen)!='T');

    int poz=0;

    while(poz<dim){
        if(c[poz].an==an && toupper(c[poz].autor.gen)==toupper(gen))
        {
            strcpy(titlu,c[poz].titlu);
            *(titlu+strlen(c[poz].titlu))='\0';
            printf("%s\n",titlu);
        }
        poz++;
    }

}

struct max_autor{
    char nume_max[30];
    char prenume_max[30];
};

struct max_autor max_carti(struct temp *q,struct carte *c, int dim){

    int i,j;

    struct max_autor maxim;

    for(i=0;i<dim;i++){
            strcpy(q[i].nume,c[i].autor.nume);
            strcpy(q[i].prenume,c[i].autor.prenume);
    }

    //i=0;

    int max=1;
    int aparitie;
    //char nume_max[30],prenume_max[30];

    for(i=0;i<dim;i++){
            aparitie=1;
        for(j=i+1;j<dim && strcmp(q[j].nume,"gasit")!=0 &&  strcmp(q[j].prenume,"gasit")!=0;j++)
        {
            int x1,x2;
            x1=strcmp(q[i].nume,q[j].nume);
            x2=strcmp(q[i].prenume,q[j].prenume);
            if(x1==0 && x2==0){
                strcpy(q[j].nume,"gasit");
                strcpy(q[j].prenume,"gasit");
                aparitie++;
            }
        }

        if(aparitie>max)
        {
            max=aparitie;
            strcpy(maxim.nume_max,q[i].nume);
            strcpy(maxim.prenume_max,q[i].prenume);
        }

    }

    return maxim;


}

void ord_lexicografica(struct carte *c,int dim){

    struct carte temp;

    int i=0;
    int j=0;

    while(i<dim){
        j=i+1;
        while(j<dim){
            if(*(c[i].titlu)>*(c[j].titlu)){
                temp=c[i];
                c[i]=c[j];
                c[j]=temp;
            }
        j++;
        }
    i++;
    }

}




int main(){

    int dim;
    int poz;

    struct carte *c;
    struct temp *q;


    do{
        printf("cate carti doriti sa introduceti?\n");
        scanf("%d",&dim);
    }while(dim<0);

    c=malloc(sizeof(struct carte)*dim);
    q=malloc(sizeof(struct temp)*dim);

    int i;
    i=0;

    //char car;

    getchar();

    while(i<dim){

        printf("titlu cartea %d:",i+1);
        gets(c[i].titlu);
        printf("Anul publicatiei: ");
        scanf("%d",&c[i].an);
        getchar();
        printf("Nume si prenume autor:\n");
        scanf("%s",c[i].autor.nume);
        getchar();
        scanf("%s",c[i].autor.prenume);
        getchar();
        do{
            printf("Gen carte:");
            c[i].autor.gen=getchar();
            getchar();
        }while(toupper(c[i].autor.gen)!='C' && toupper(c[i].autor.gen)!='D' && toupper(c[i].autor.gen)!='T');

        printf("\n\n");

        //getchar();

        i++;
    }

    //gasit(c,dim);

    struct max_autor s=max_carti(q,c,dim);

    //printf("Autorul cu cele mai multe carti este: %s %s",s.nume_max,s.prenume_max);

    //an_gen(c,dim);

    ord_lexicografica(c,dim);

    i=0;

    printf("Cartile ordonate in ordine lexicografica:\n");

    while(i<dim){
        printf("%s\n",c[i].titlu);
        i++;
    }


    free(c);

    return 0;

}
