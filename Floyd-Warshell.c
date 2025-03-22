#include <stdio.h>
#include <limits.h>

#define INF 1000000
#define MAX_V 100

int dist[MAX_V][MAX_V];
int V;

void initialize(void)
{
    int i,j;
    for(i=0;i<MAX_V;i++)
    {
        for(j=0;j<MAX_V;j++)
        {
            if(i==j)
            {
                dist[i][j]=0;
            }
            else
            {
                dist[i][j]=INF;
            }
        }
    }
}

void floyd_warshall(void)
{
    int i,j,k;
    for(k=0;k<V;k++)  //mid
    {
        for(i=0;i<V;i++)  //start
        {
            for(j=0;j<V;j++)  //end
            {
                if(dist[i][k]<INF&&dist[k][j]<INF)  //there is a way
                {
                    if(dist[i][j]>dist[i][k]+dist[k][j])
                    {
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }
    }
}

int negative_cycle(void)
{
    int i;
    for(i=0;i<V;i++)
    {
        if(dist[i][i]<0)
        {
            return 1;
        }
    }
    return 0;
}

void print(void)
{
    int i,j;
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            if(dist[i][j]==INF)
            {
                printf("INF ");
            }
            else
            {
                printf("%3d ",dist[i][j]);
            }
        }
        printf("\n");
    }
}
