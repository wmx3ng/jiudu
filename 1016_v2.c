#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

int sutable[]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
int suflag;

int getdata(char *data,char **p)
{
        int tmp=0;
        int pos=0;
        while((*p!=NULL) && (**p!=','))
        {
                tmp+=(**p-'0')*((int)pow(10,pos++));
                if(*p==data)
                    *p=NULL;
                else
                    --*p;
        }
        if(*p!=NULL && (**p==','))  //must judge *p==NULL ?
            --*p;

        return tmp;
}


void getresult(char *data1,char *data2,char *result)
{
        char *d1_s=data1,*d1_e=data1+strlen(data1)-1;
        char *d2_s=data2,*d2_e=data2+strlen(data2)-1;
        char *r_s=result;
        int tmp1,tmp2,tmp3,len;
        int jinwei=0;

        while(d1_e!=NULL)
        {
            tmp1=tmp2=0;
            if(d1_e!=NULL)
                tmp1=getdata(data1,&d1_e);

            if(d2_e!=NULL)
                tmp2=getdata(data2,&d2_e);

            tmp3=tmp1+tmp2+jinwei;
            jinwei=tmp3/sutable[suflag];
            tmp3=tmp3%sutable[suflag];
            suflag++;

            len=sprintf(r_s,"%d",tmp3);
            r_s=r_s+len;
            *r_s=',';
            r_s++;
        }

        while(d2_e!=NULL)
        {
            tmp1=tmp2=0;
            if(d1_e!=NULL)
                tmp1=getdata(data1,&d1_e);
            if(d2_e!=NULL)
                tmp2=getdata(data2,&d2_e);

            tmp3=tmp1+tmp2+jinwei;
            jinwei=tmp3/sutable[suflag];
            tmp3=tmp3%sutable[suflag];
            suflag++;

            len=sprintf(r_s,"%d",tmp3);
            r_s=r_s+len;
            *r_s=',';
            r_s++;
        }
        len=sprintf(r_s,"%d",jinwei);
        r_s=r_s+len;
}

void printstr(char *data)
{
    char *p=data,*q=NULL,*tmp=NULL;
    int coun=0;
    while(*p!='\0')
        p++;
    q=p;

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
    printf("\n");
}

int main()
{
        char data1[128],data2[128],result[128];

        while(scanf("%s%s",data1,data2)==2)
        {
                memset(result,'\0',128);
                if(strcmp(data1,"0")==0&&strcmp(data2,"0")==0)
                        break;
                suflag=1;
                getresult(data1,data2,result);
                printstr(result);
        }
        return 0;
}
