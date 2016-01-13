#include <stdio.h>
#include <string.h>

int matchPos(const unsigned char word, const char* pattern)
{
	int i = strlen(pattern) - 1;

	while( '\0' != (*(pattern + i) ) && i >= 0)
	{
		if(word == *(pattern + i))	
			return (strlen(pattern) - i);
		--i;
	}
	return -1;
}

int sundayMatch(const char* str, const char* pattern)
{
	int str_len = strlen(str);
	int pattern_len = strlen(pattern);

	int i = 0, j = 0, pos = 0;
	int k = 0;

	while(j < str_len)
	{
		i = 0;
		while( *(str + i + j) == *(pattern + i) && i < pattern_len )
		{
			++i;
			continue;
		}

		if( *(pattern + i) == '\0' )
		{
			printf("matched! \n");
			++k;
		}
		else
		{
			printf("unmatched! \n");
		}

		if( -1 != (pos = matchPos(*(str + pattern_len + j), pattern)) )
			j += pos;
		else
			j += (pattern_len + 1);
	}
	return k;
}

int main()
{
	const char* str = "fagrgaahh/ga 4 *@ra";
	const char* des = "/ga 4 *@";

	//const char* str = "abc";
	//const char* des = "abc";

	//const char* str = "hfeiafifabcabcabcdsafabcdafabcjfsafkhfabc";
	//const char* des = "abc";

	printf("SundayMatch counters:%d\n", sundayMatch(str, des));
	return 0;
};
