#include <stdio.h>

int main(void)
{
    int i,n;
    int start = 0, end = 0, temp = 0;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int current=arr[0];
    int maxsum=arr[0];
    for(i=1;i<n;i++)
    {
        if(current+arr[i]>arr[i])
        {
            current+=arr[i];
        }
        else
        {
            current=arr[i];
            temp=i;
        }
        if(current>maxsum)
        {
            maxsum=current;
            start=temp;
            end=i;
        }
    }
    printf("max sub %d\n",maxsum);
    printf("start   %d\n",start);
    printf("end     %d\n",end);
    return 0;
}
