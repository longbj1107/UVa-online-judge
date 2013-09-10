#include <stdio.h>
#include <string.h>

char s[8][11];

int compare(char s[][11],int n)
{
    int i,j,k,len,flag=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            k=strlen(s[i]);
            len=strlen(s[j]);
            len=(k<len)?k:len;
            for(k=0;k<len;k++) 
            {
                if(s[i][k]!=s[j][k])
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
            {
                return 0;
            }
			flag=0;
        }
    }
    return 1;
}

int main()
{
    int i=0,count=1;
    freopen("test.txt","r",stdin);
    while(gets(s[i]))
    {
        if(s[i][0]=='9')
        {
            if(compare(s,i))
            {
                printf("Set %d is immediately decodable\n",count);
            }
            else
            {
                printf("Set %d is not immediately decodable\n",count);
            }
            i=0;
            count++;
        }
        else
        {
            i++;
        }
    }
    return 0;
}