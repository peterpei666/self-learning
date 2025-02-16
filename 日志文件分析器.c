#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *fp1=fopen("/Users/peiteer/Desktop/code/exercise/exercise/server_log.txt","r");
    FILE *fp2=fopen("/Users/peiteer/Desktop/code/exercise/exercise/error_log.txt","w");
    if(fp1==NULL)
    {
        printf("Fail to open the file\n");
    }
    else
    {
        char line[100];
        int count=0;
        while(fgets(line,sizeof(line),fp1)!=NULL)
        {
            
            if(strstr(line,"ERROR")!=NULL)
            {
                fprintf(fp2,"%s",line);
                printf("%s",line);
                count++;
            }
        }
        fprintf(fp2,"ERROR %d\n",count);
        printf("ERROR %d\n",count);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
