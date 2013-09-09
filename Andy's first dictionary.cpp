#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s[100000][201];

int cmp(const void *a,const void *b)
{
    return strcmp((char *)a,(char *)b);
}

int main()
{
    int i=0,j=0;
    char ch;
    freopen("test.txt","r",stdin);
    while(scanf("%c",&ch)!=EOF)
    {
        if(isalpha(ch))
        {
            s[i][j++]=tolower(ch);
        }
        else if(j!=0)
        {
            s[i++][j]=0;
            j=0;
        }
    }
    qsort(s,i,sizeof(s[0]),&cmp);
    printf("%s\n",s[0]);
    for(j=1;j<i;j++)   
    {
        if(strcmp(s[j],s[j-1]))
        {
            printf("%s\n",s[j]);
        }
    }
    return 0;
}