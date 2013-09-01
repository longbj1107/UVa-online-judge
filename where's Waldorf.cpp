#include <stdio.h>
#include <string.h>

char table[51][51];
char str[21][51];
int line,column,cases,test;
int flag='a'-'A';

int search(char *str,int m,int n,int length,int k)
{
    int a[8]={-1, -1,  0,  1, 1, 1, 0,-1};
    int b[8]={ 0, -1, -1, -1, 0, 1, 1, 1};
    int t,xlim,ylim,sub;
    xlim=m+b[k]*(length-1);
    ylim=n+a[k]*(length-1);
    if(xlim<0||xlim>=line||ylim<0||ylim>=column)
    {
        return 0;
    }
    else
    {
	for(t=1;t<length;t++)
        {
            xlim=m+b[k]*t;
	    ylim=n+a[k]*t;
	    sub=table[xlim][ylim]-str[t];
	    if((sub==0)||(sub==flag)||(sub+flag==0))
	    {
	        continue;
	    }
	    else
	    {
	        return 0;
	    }
	}
	return 1;
    }
}

int search_word(char *str,int m,int n)
{
    int i,j,k;
    int temp,length;
    int result=0;
    length=strlen(str);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
	    temp=table[i][j]-str[0];
	    if((temp==0)||(temp==flag)||(temp+flag==0))
	    {
	        for(k=0;k<8;k++)
		{
		    result=search(str,i,j,length,k);
		    if(result)
		    {
		        printf("%d %d\n",i+1,j+1);
		        return 0;
		    }
		}
	    }
	}
    }
    printf("error\n");
    return 1;
}

int main()
{
    int i,j=0;
    scanf("%d",&cases);
    while(cases>0)
    {
        if(j)
	{
	    printf("\n");
	}
	j=1;
	scanf("%d%d",&line,&column);
	for(i=0;i<line;i++)
	{
	    scanf("%s",table[i]);
	}
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
	    scanf("%s",str[i]);
	}
	for(i=0;i<test;i++)
	{
	    search_word(str[i],line,column);
	}
	cases--;
    }
    return 0;
}