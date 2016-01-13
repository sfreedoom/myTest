#ifndef __SUNDAYHH__
#define __SUNDAYHH__
#include <stdio.h>
#include <string.h>

int matchPos(const char theMatch, const char* thePattern)
{
	unsigned pattern_len = strlen(thePattern) - 1;

	while('\0' != *(thePattern + pattern_len) && pattern_len >= 0)
	{
		if(theMatch == *(thePattern + pattern_len))
		return (strlen(thePattern - pattern_len));

		--pattern_len;
	}

	return -1;
}

int sundaySearch(const char* theSource, const char* thePattern)
{
	unsigned source_len = strlen(theSource);	
	unsigned pattern_len = strlen(thePattern);	
	int i = 0, pos =0, j = 0;

	while(j < source_len)
	{
		i = 0;
		while(*(theSource + i + j) == *(thePattern + i))	
		{
			++i;	
			continue;
		}

		if('\0' == *(thePattern + i))
		{
			printf("matched!\n");	
		}
		else
		{
			printf("unmatched!\n");	
		}

		if(-1 != (pos = matchPos(*(theSource + pattern_len + j), thePattern)))
			j += pos;
		else
			j += (pattern_len + 1);
	}
}	
#endif //__SUNDYAHH__
