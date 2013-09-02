#include <stdio.h>
#include <stdlib.h>

void compute(char *s)
{
	double I=-1,U=-1,P=-1,temp=0;
	char *p=s,*q=s;
	char a[100]={0};
	int i=0,j=0;
	while(*s!='\0')
	{
		if(*s=='=')
		{
			j++;
			p=s-1;
			q=s+1;
			while(((*q<='9')&&(*q>=0))||*q=='.')
			{
				a[i]=*q;
				i++;
				q++;
			}
			a[i]='\0';
			i=0;
			if(*q=='m')
			{
				temp=atof(a)*0.001;
			}
			else if(*q=='k')
			{
				temp=atof(a)*1000;
			}
			else if(*q=='M')
			{
				temp=atof(a)*1000000;
			}
			else
			{
				temp=atof(a);
			}
			if(*p=='P')
			{
				P=temp;
				
			}
			else if(*p=='I')
			{
				I=temp;
			}
			else
			{
				U=temp;
			}
			if(j==2)
			{
				break;
			}
			s=q++;
		}
		s++;
	}
	if(I<0)
	{
		printf("I=%.2fA\n",P/U);
	}
	if(U<0)
	{
		printf("U=%.2fV\n",P/I);
	}
	if(P<0)
	{
		printf("P=%.2fW\n",I*U);
	}
}

int main()
{
	int cases,i;
	char s[1000];
	freopen("test.txt","r",stdin);
	scanf("%d",&cases);
	getchar();
	for(i=0;i<cases;i++)
	{
		fgets(s,100,stdin);
		printf("Problem #%d\n",i+1);
		compute(s);
		printf("\n");
	}
	return 0;
}