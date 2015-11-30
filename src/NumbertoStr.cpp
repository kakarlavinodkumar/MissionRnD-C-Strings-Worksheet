/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
void xstrrev(char *str, int index)
{
	int index1 = 0;
	char temp;
	if (str[0] == '-')
		index1 = 1;
	for (; index1 < index; index1++, index--)
	{
		temp = str[index];
		str[index] = str[index1];
		str[index1] = temp;
	}
}

void number_to_str(float number, char *str,int afterdecimal){
	int n, index = 0, power;
	if (number == 0)
		str[index++] = '0';
	else
	{
		if (number < 0)
		{
			str[index++] = '-';
			number *= -1;
		}
		for (n = number; n>0; n /= 10)
			str[index++] = n % 10 + '0';
		xstrrev(str, index - 1);
		if (afterdecimal > 0)
		{
			str[index++] = '.';
			for (number = number - (int)number, power = 10; afterdecimal > 0; afterdecimal--, power *= 10)
				str[index++] = (int(number*power)) % 10 + '0';
		}
	}
	str[index] = '\0';
	
}
