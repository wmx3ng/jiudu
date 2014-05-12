#include<stdlib.h>
#include<stdio.h>

int main()
{
    long t[31];
    int i,n;
    t[0]=0;
    t[1]=t[2]=1;
    for(i=3;i<=30;i++)
    {
        t[i]=t[i-1]+t[i-2];
    }
    while(scanf("%d",&n)==1)
    {
        printf("%ld\n",t[n]);
    }
    return 0;
}
