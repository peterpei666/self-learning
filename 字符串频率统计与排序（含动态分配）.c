#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char word[50];
    int count;
} dictionary;

int compare(const void *a, const void *b)
{
    dictionary *wa=(dictionary*)a;
    dictionary *wb=(dictionary*)b;
    return (wb->count)-(wa->count);
}

int main(void)
{
    char w[50];
    int capacity=2,n=0,i;
    dictionary* ws=(dictionary*)malloc(capacity*sizeof(dictionary));
    FILE *fp=fopen("/Users/peiteer/Desktop/code/exercise/exercise/123.txt","r");
    if(fp==NULL)
    {
        printf("cannot open the file\n");
        return 1;
    }
    while(fscanf(fp,"%s",w)!=EOF)
    {
        int f=1;
        if(n>=capacity-1)
        {
            capacity*=2;
            ws=realloc(ws,capacity*sizeof(dictionary));
        }
        for(i=0;i<n;i++)
        {
            if(strcmp(w,ws[i].word)==0)
            {
                ws[i].count++;
                f=0;
                break;
            }
        }
        if(f)
        {
            strcpy(ws[n].word,w);
            ws[n].count=1;
            n++;
        }
    }
    qsort(ws,n,sizeof(dictionary),compare);
    for(i=0;i<n;i++)
    {
        printf("%s     %d\n",ws[i].word,ws[i].count);
    }
    free(ws);
    return 0;
}
