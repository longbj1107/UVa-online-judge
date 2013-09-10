#include <stdio.h>
#include <string.h>

char s[300],src[10][100],dst[10][100];

void strrpl(char *s,char *src,char *dst)
{
    char p[300]={0};
    char *temp;
    temp=strstr(s,src);
    while(temp!=NULL)
    {
        strncpy(p,s,temp-s);
        strcat(p,dst);
        strcat(p,temp+strlen(src));
        strcpy(s,p);
        temp=strstr(s,src);
        memset(p,0,sizeof(p));
    }
}

int main()
{
    int num,i;
    freopen("test.txt","r",stdin);
    scanf("%d",&num);
    getchar();
    while(num)
    {
        for(i=0;i<num;i++)
        {
            gets(src[i]);
            gets(dst[i]);
        }
        gets(s);
        for(i=0;i<num;i++)
        {
            strrpl(s,src[i],dst[i]);
        }
        printf("%s\n",s);
        scanf("%d",&num);
        getchar();
    }
    return 0;
}