// KMP ALGORITHM
#include <stdio.h>
#include <string.h>
#define MAX 20
int check(char p[], int index, char c);
void KMP(char s[], char p[], int len_s, int len_p);
int no[MAX];
int main()
{
	char s[MAX], p[MAX], len_s, len_p, i, n;
	printf("\nEnter the string: ");
	gets(s);
	len_s = strlen(s);
	printf("\nEnter the pattern: ");
	gets(p);
	len_p = strlen(p);
	for (i = 0; i < len_p; i++)
	{
		n = check(p, i, p[i]);
		no[i] = n;
	}
	KMP(s, p, len_s, len_p);
	return 0;
}
void KMP(char s[], char p[], int len_s, int len_p)
{
	int i = 0, j = -1;
	while (i < len_s)
	{
		while (j < len_p)
		{
			if (s[i] == p[j + 1])
			{
				j++;
				i++;
			}
			else if (j > -1)
			{
				j = no[j];
			}
			else if (j == -1)
			{
				i++;
			}
			if (j == len_p)
			{
				printf("\nString Match");
				break;
			}
			if (j != len_p - 1 && i == len_s)
			{
				printf("\nString Not Match!");
				break;
			}
		}
	}
}
int check(char p[MAX], int index, char c)
{
	int i;
	for (i = index - 1; i >= 0; i--)
	{
		if (p[i] == c)
			return i;
	}
	return -1;
}
