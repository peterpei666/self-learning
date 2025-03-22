#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define MAX_V 1000
#define MAX_E 10000

typedef struct
{
    int u;  //start
    int v;  //end
    int w;  //weight
} edge;

edge edges[MAX_E];
int dist[MAX_V];
int V,E;

int bellman_ford(int source)
{
    int i,j,u,v,w;
    for(i=0;i<V;i++)
    {
        dist[i]=INF;
    }
    dist[source]=0;
    for(i=0;i<V-1;i++)
    {
        for(j=0;j<E;j++)
        {
            u=edges[j].u;
            v=edges[j].v;
            w=edges[j].w;
            if(dist[u]!=INF&&dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
            }
        }
    }
    for(j=0;j<E;j++)
    {
        u=edges[j].u;
        v=edges[j].v;
        w=edges[j].w;
        if(dist[u]!=INF&&dist[u]+w<dist[v])
        {
            return 0;
        }
    }
    return 1;
}
