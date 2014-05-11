#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int getdata(char *data,char **p)
{
        int tmp=0;
        int pos=0;
        while((*p!=data) && (**p!=','))
        {
                tmp+=(**p-'0')*((int)pow(10,pos++));
                --*p;
        }

        if(*p==data)
        {
                tmp+=(**p-'0')*((int)pow(10,pos++));
        }
        else
                --*p;

        return tmp;
}


void getresult(char *data1,char *data2,char *result)
{
        char *d1_s=data1,*d1_e=data1+strlen(data1)-1;
        char *d2_s=data2,*d2_e=data2+strlen(data2)-1;
        int tmp1,tmp2,tmp3;
        while(d1_e!=d1_s)
        {
            tmp1=tmp2=0;
            if(d1_e!=d1_s)
                tmp1=getdata(data1,&d1_e);

            if(d2_e!=d2_s)
                tmp2=getdata(data2,&d2_e);
            printf("%d %d\n",tmp1,tmp2);
        }

        while(d2_e!=d2_s)
        {
            tmp1=tmp2=0;
            if(d1_e!=d1_s)
                tmp1=getdata(data1,&d1_e);
            if(d2_e!=d2_s)
                tmp2=getdata(data2,&d2_e);
            printf("%d %d\n",tmp1,tmp2);
        }
}

int main()
{
        char data1[64],data2[64],result[64];
        while(scanf("%s%s",data1,data2)==2)
        {
                if(strcmp(data1,"0")==0&&strcmp(data2,"0")==0)
                        break;
                printf("%s %s\n",data1,data2);
		getresult(data1,data2,result);
        }
        return 0;
}
