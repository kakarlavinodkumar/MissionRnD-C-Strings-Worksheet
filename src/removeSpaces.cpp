/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

char removeSpaces(char *str) {
	int index, count=0;
	if (str != "")
	{
		for (index =0; str[index] != '\0'; index++)
		{
			if (str[index] != ' ')
				str[count++] = str[index];
		}
	}
	str[count] = '\0';
	return str[0];
}