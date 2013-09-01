#include <stdio.h>
#include <string.h>

void palindrome(char *s)
{
	int length=0,isp=0,ism=0;
	int i,j;
	char mirror[127]={'0'};
	mirror['A'] = 'A';mirror['E'] = '3';mirror['J'] = 'L';mirror['H'] = 'H';
	mirror['I'] = 'I';mirror['J'] = 'L';mirror['M'] = 'M';mirror['O'] = 'O';
	mirror['S'] = '2';mirror['T'] = 'T';mirror['U'] = 'U';mirror['V'] = 'V';
	mirror['W'] = 'W';mirror['X'] = 'X';mirror['Y'] = 'Y';mirror['Z'] = '5';
	mirror['1'] = '1';mirror['2'] = 'S';mirror['3'] = 'E';mirror['5'] = 'Z';
	mirror['8'] = '8';
	length=strlen(s);
	i=0,j=length-1;
	while(i<=j)
	{
		if(!isp&&!ism)
		{
			if(!isp)
			{
				if(s[i]!=s[j])
				{
					isp=1;
				}
			}
			if(!ism)
			{
				if(mirror[s[i]]!=s[j])
				{
					ism=1;
				}
			}
		}
		i++;
		j--;
	}
	if(isp&&ism)
	{
		printf("%s -- is not a palindrome.\n",s);
	}
	else if(!isp&&ism)
	{
		printf("%s -- is a regular palindrome.\n",s);
	}
	else if(isp&&!ism)
	{
		printf("%s -- is a mirrored string.\n",s);
	}
	else if(!isp&&!ism)
	{
		printf("%s -- is a mirrored palindrome.\n",s);
	}
	printf("\n");
}

int main()
{
	char s[21]={'0'};
	while(scanf("%s",s)!=EOF)
	{
		palindrome(s);
	}	
	return 0;
} 

