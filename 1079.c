#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
    char data[128];
    char *tmp=NULL;
    int sum,prekey,currkey;
    while(scanf("%s",data)==1)
    {
        sum=0;
        prekey=-1;
        tmp=data;
        while(*tmp!='\0')
        {
            if(*tmp>'v')
            {
                if(*tmp=='z')
                {
                     currkey=7;
                     sum+=4;
                }
                else
                {
                    currkey=((*tmp-'a')-1)/3;
                    sum+=((*tmp-'a')-1)%3+1;
                }
            }
            else if(*tmp>'s')
            {
                currkey=(*tmp-'a'-1)/3;
                sum+=((*tmp-'a')-1)%3+1;

            }
            else
            {
                if(*tmp=='s')
                {
                    currkey=5;
                    sum+=4;
                }
                else
                {
                    currkey=(*tmp-'a')/3;
                    sum+=(*tmp-'a')%3+1;
                }
            }
            if(currkey!=prekey)
                prekey=currkey;
            else
                sum+=2;

            tmp++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
