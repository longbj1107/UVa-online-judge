#include <stdio.h>
#include <string.h>

void poetry(char src[], char dst[])
{
	int start[2];
	int end[2];
	int i=0,j=0,k=0,length=0,begin=0;
	char s1[101]={0};
	char s2[101]={0};
	char s3[101]={0};
	char s4[101]={0};
	char temp[101]={0};
	while(src[i]!='\0')
	{
		if(src[i]=='<')
		{
			start[j++]=i;
		}
		if(src[i]=='>')
		{
			end[k++]=i;
		}
		i++;
	}
	length=i;
	i=0;
	while(dst[i]!='\0')
	{
		if(dst[i]=='.')
		{
			begin=i;
			break;
		}
		i++;
	}
	strncpy(s1,src+start[0]+1,end[0]-start[0]-1);
	strncpy(s2,src+end[0]+1,start[1]-end[0]-1);
	strncpy(s3,src+start[1]+1,end[1]-start[1]-1);
	strncpy(s4,src+end[1]+1,length-end[1]-1);
	strncpy(temp,src,start[0]);
	printf("%s%s%s%s%s",temp,s1,s2,s3,s4);
	strncpy(temp,dst,begin);
	temp[begin]='\0';
	printf("%s%s%s%s%s",temp,s3,s2,s1,s4);
}

int main()
{
	int num;
	char src[101]={0};
	char dst[101]={0};
	scanf("%d",&num);
	getchar();
	while(num)
	{
		fgets(src,100,stdin);
		fgets(dst,100,stdin);
		poetry(src,dst);
		num--;
	}
	return 0;
}