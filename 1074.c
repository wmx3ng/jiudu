#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int judgeBal(char *ch)
{
	char *start=ch;
	char *end=start+(strlen(ch)-1);
	while(start<end)
	{
		if(*start!=*end)
			return 0;
		start++;
		end--;
	}
	return 1;		
}

int main()
{
	int n=256;
	int i;
	char ch[256];
	for (i=0;i<256;i++)
	{
		sprintf(ch,"%d",i*i);
	        if(judgeBal(ch))
			printf("%d\n",i);
	}
	return 0;
}
