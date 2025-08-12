#include <string.h>
#include <ctype.h>
#include <stdio.h>

// 

int countStrDig(const char *str)
{
	int count = 0;
	while(*str)
	{
		if(isdigit(*str))
			count++;
		str++;
	}
	return count;
}

int mystrcmp(const char *str1, const char *str2)
{
	int count1, count2;
	count1 = countStrDig(str1);
	count2 = countStrDig(str2);
	if(count1 > count2)
		return 1;
	if(count1 < count2)
		return 2;
	return 0;
}




int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        return -1;
    }
    return mystrcmp(argv[1], argv[2]);
    
}
