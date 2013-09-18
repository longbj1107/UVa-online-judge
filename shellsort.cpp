#include <stdio.h>
#include <string.h>

char origin[201][90];
char order[201][90];

int main()
{
    int cases,num;
    int i,j,t,max,key;
    freopen("test.txt","r",stdin);
    scanf("%d",&cases);
    getchar();
    for(t=0;t<cases;t++)
    {
        scanf("%d",&num);
        getchar();
        for(i=0;i<num;i++)
        {
            gets(origin[i]);
		}
        for(i=0;i<num;i++)
        {
            gets(order[i]);
        }
        max=-1,key=-1;
        for(i=0;i<num;i++)
        {
            for(j=0;j<num;j++)
            {
                if(strcmp(origin[i],order[j])==0)
                {
                    if(j>max)
                        max=j;
                    else if(j>key)
                        key=j;
                    break;
                }
            }
        }
        while(key+1)
        {
            printf("%s\n",order[key--]);
        }
        printf("\n");
    }
    return 0;
}