#include<stdlib.h>
#include<stdio.h>
#include<math.h>
//#include<assert.h>
#include<string.h>

int sutable[30];
int suflag;

int judgesu(int n)
{
    int i;
    int mid=(int)(sqrt(n));
    for(i=2;i<=mid;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

void getsutable()
{
    int i,k=2;
    for(i=1;i<30;i++)
    {
        while(judgesu(k)==0)
            k++;
        sutable[i]=k++;
        //printf("%d ",sutable[i]);
    }
    //printf("\n");
}

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

        //printf("jinzhi: %d\n",sutable[suflag]);

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
            //printf("%d %d %d\n",tmp1,tmp2,tmp3);

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
            //printf("%d %d %d\n",tmp1,tmp2,tmp3);

            len=sprintf(r_s,"%d",tmp3);
            r_s=r_s+len;
            *r_s=',';
            r_s++;
        }

        //printf("%d jinzhi:%d\n",jinwei,sutable[suflag]);
        len=sprintf(r_s,"%d",jinwei);
        r_s=r_s+len;
        //*r_s=',';
        //r_s++;

        //printf("result: %s\n",result);

}
void printstr(char *data)
{
    char *p=data,*q=NULL,*tmp=NULL;
    int coun=0;
    while(*p!='\0')
        p++;
    q=p;
    //assert(*p=='\0');
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
        char data1[256],data2[256],result[256];
        getsutable();
        while(scanf("%s%s",data1,data2)==2)
        {
                memset(result,'\0',256);
                if(strcmp(data1,"0")==0&&strcmp(data2,"0")==0)
                        break;
                //printf("%s %s\n",data1,data2);
                suflag=1;
                getresult(data1,data2,result);
                printstr(result);
        }
        return 0;
}
