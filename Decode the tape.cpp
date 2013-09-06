#include <stdio.h>

int main()
{
    char temp[20];
    int i,count;
    freopen("test.txt","r",stdin);
    while(gets(temp))
    {
        if(temp[0]!='_')
        {
            i=0;
            count=0;
            while(temp[i]!='\0')
            {
                if(temp[i]=='o')
                {
                    count=count*2+1;
                }
                else if(temp[i]==' ')
                {
                    count=count*2;
                }
                i++;
            }
            printf("%c",count);
        }
    }
    return 0;
}