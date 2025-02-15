#include <stdio.h>
#include <stdlib.h>

int string_check(int a, char word[a+1])
{
    
    int i;
    for(i=0;i<a/2;i++)
    {
        if(word[i]!=word[a-1-i])
        {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    int a,f;
    printf("输入字符串长度：");
    scanf("%d",&a);
    printf("输入字符串：");
    char word[a+1];
    scanf("%s",word);
    f=string_check(a, word);
    if(f)
    {
        printf("%s 是回文字符串\n",word);
    }
    else
    {
        printf("%s 不是回文字符串\n",word);
    }
    return 0;
}
