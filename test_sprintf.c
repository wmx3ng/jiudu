#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
    char data[64];
    char *p=data;
    int len;
    int tmp=10000;
    len=sprintf(p,"%d",tmp);
    p=p+len;
    *p=',';
    p++;
     len=sprintf(p,"%d",tmp);
    printf("%s %d\n",data,len);
    return 0;
}
