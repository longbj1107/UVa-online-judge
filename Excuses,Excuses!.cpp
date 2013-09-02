#include <stdio.h>
#include <string.h>

char keywords[20][25];
char excuses[20][75];
int K,E;

int search(char *s)
{
    int i,j,num=0,flag;
    char p[72];
    char *q=s;
    while(*s!='\0')
    {
        if(((*s<='z')&&(*s>='a'))||((*s<='z')&&(*s>='A')))
        {
            i=0;
            q=s;
            while(((*q<='z')&&(*q>='a'))||((*q<='Z')&&(*q>='A')))
            {
                p[i++]=*q;
                q++;
            }
            p[i]='\0';
            for(i=0;i<K;i++)
            {
                j=0;
                flag=0;
                while(p[j]!='\0')
                {
                    if((p[j]==keywords[i][j])||((p[j]-keywords[i][j])=='A'-'a'))
                    {
                        j++;
                        continue;
                    }
                    else
                    {
                        flag=1;
                        break;
                    }
                }
                if(!flag)
                {
                    num++;
                    break;
                }
            }
            s=q;
        }
        else
        {
            s++;
        }
    }
    return num;
}

int main()
{
    int i,max,num=0;
    int flag[20]={0};
    freopen("test.txt","r",stdin);
    while(scanf("%d%d",&K,&E)!=EOF)
    {
        num++;
        max=0;
        for(i=0;i<K;i++)
        {
            scanf("%s",keywords[i]);
        }
        getchar();
        for(i=0;i<E;i++)
        {
            fgets(excuses[i],72,stdin);
            flag[i]=search(excuses[i]);
            if(max<flag[i])
            {
                max=flag[i];
            }
        }
        printf("Excuse Set #%d\n",num);
        for(i=0;i<20;i++)
        {
            if(flag[i]==max)
            {
                printf("%s",excuses[i]);
            }
            flag[i]=0;
        }
        printf("\n");
    }
    return 0;
}