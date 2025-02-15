#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double exponent(double m,int n)
{
    double x=1;
    int i;
    for(i=0;i<n;i++)
    {
        x*=m;
    }
    return x;
}

double differentiation(double (*fp)(double m),double x)
{
    double ret, dif;
    dif=fp(x+0.001)-fp(x-0.001);
    ret= dif/0.002;
    return ret;
}

double f(double x)
{
    return exp(x)+exponent(x,10)-10000;
}

double abs_value(double x)
{
    return x>=0?x:-x;
}

int main(void)
{
    double ans=-100,tem;
    int time=0;
    do
    {
        tem=f(ans);
        printf("x=%.5lf f(x)=%.7lf  time=%d\n",ans,tem,time);
        ans=ans-f(ans)/differentiation(f,ans);
        time++;
        
    } while (abs_value(tem)>0.0000001&&time<=50);
    printf("answer = %.5lf\n",ans);
    return 0;
}
