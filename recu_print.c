#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>

void printstr(char *data)
{
    char *p=data,*q=NULL,*tmp=NULL;
    int coun=0;
    while(*p!='\0')
        p++;
    q=p;
    assert(*p=='\0');
    while(q!=NULL)
    {
        while((q!=data)&&(*q!=','))
            q--;

        if(*q==',')
            tmp=q+1;
        else
        {
            tmp=q;
            q=NULL;
        }

        if(coun!=0)
            printf(",");
        while(tmp<p)
        {
            if(*p=='\0')
            {
                if(*tmp!='0')
                {
                     printf("%c",*tmp);
                     coun++;
                }
                tmp++;
            }
            else
            {
                coun++;
                printf("%c",*tmp);
                tmp++;
            }
        }
        p=q;
        if(q!=NULL)
            q--;
    }
}

int main()
{
    char *data="41,0,41,1,1,41,0";
    char *data2="1,0,14,0,0,0,0,0,41";
    //printf("%s\n",data);
    printstr(data);
    printf("\n");
    printstr(data2);
    printf("\n");

    return 0;
}
