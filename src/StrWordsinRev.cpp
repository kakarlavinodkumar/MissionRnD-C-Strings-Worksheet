/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void xstrrev1(char *input, int index1)
{
	int index;
	char temp;
	for (index = 0; index < index1; index++, index1--)
	{
		temp = input[index];
		input[index] = input[index1];
		input[index1] = temp;
	}
}
void str_words_in_rev(char *input, int len){
	int  index, words[10], index1, index2, index3;
	char temp;
	xstrrev1(input, len - 1);
	for (index = 0, index1 = 1, words[0] = 0; input[index] != '\0'; index++)
	{
		if (input[index] == ' '&&input[index + 1] != ' ')
			words[index1++] = index + 1;
		if (input[index] != ' ' && input[index + 1] == ' ')
			words[index1++] = index;
	}
	words[index1++] = index - 1;
	for (index = 0, index2 = words[0], index3 = words[1]; index < index1;)
	{
		if (index2 < index3)
		{
			temp = input[index2];
			input[index2++] = input[index3];
			input[index3--] = temp;
		}
		else
		{
			index += 2;
			index2 = words[index];
			index3 = words[index + 1];
		}
	}
}
