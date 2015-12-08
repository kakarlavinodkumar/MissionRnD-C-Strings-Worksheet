/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31
void xstrcpy(char **result, int len, char *str, int index)
{
	int index1;
	for (index1 = 0; str[index] != ' '&&str[index] != '\0'; index++, index1++)
		result[len][index1] = str[index];
	result[len][index1] = '\0';
}
char ** commonWords(char *str1, char *str2) {
	int index1, index2, index, index3;
	char **res;
	if (str1&&str2)
	{
		res = (char **)malloc(sizeof(char*)* 31);
		for (index = 0; index < 10; index++)
			res[index] = (char *)malloc(sizeof(char)* 31);
		for (index = index3 = 0; str1[index] != '\0'; index++)
		{
			if ((index == 0 || str1[index - 1] == ' ') && str1[index] != ' ')
			{
				for (index2 = 0, index1 = index; str2[index2] != '\0'&&str1[index1] != '\0'; index2++)
				{
					if ((str2[index2] == ' ' || str2[index2 + 1] == '\0') && ((str1[index1] == ' ' || str1[index1 + 1] == '\0') || (str1[index1] == str2[index2] && str2[index2 + 1] == '\0'&&str1[index1 + 1] == ' ')))
					{
						xstrcpy(res, index3, str1, index);
						index3++;
					}
					if (str1[index1] == str2[index2])
						index1++;
					else
						index1 = index;
				}
			}
		}
		if (index3!=0)
		return res;
		return NULL;
	}
	return NULL;
}