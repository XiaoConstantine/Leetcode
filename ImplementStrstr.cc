/*
 * =====================================================================================
 *
 *       Filename:  ImplementStrstr.cc
 *
 *    Description:  LeetCode Implement Strstr
 *        Version:  1.0
 *        Created:  04/08/13 17:40:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  prefix
 *  Description:  Check how many characters in pre and post are equal for example:
 *				  str = cacca
 *				  p[0] = -1   str = c  
 *				  p[1] = -1   str = ca cause c and a are not equal
 *				  p[2] = 0    str = cac since c and c are equal this means 1 charac in prefix and post are equal
 *				  p[3] = 0    str = cacc
 *				  p[4] = 1    str = cacca
 *				  for a new charac like cac + c we just check a and c if they are equal a and c are not equal then
 *				  we check back
 *				  if situation is cac + a  and a equal we just P[3] + 1
 * =====================================================================================
 */
void
prefix (char* str, int len, int* pattern)
{
	pattern[0] = -1;
	int k = -1;
	for(int j = 1; j < len; j++){
		while(k > -1 && str[k+1] != str[j]){
			k = pattern[k];
		}
		if(str[k+1] == str[j]){
			k++;
		}
		pattern[i] = k;
	}
}		
/* -----  end of function prefix  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  kmp_match
 *  Description:  
 * =====================================================================================
 */
char*
kmp_match (char* haystack, char* needle, int* pattern)
{
	int hlen = strlen(haystack);
	int nlen = strlen(needle);
	int k = -1;

	for(int i = 0; i < hlen; i++, haystack++){
		while(k > - 1 && needle[k+1] != *haystack){
			k = pattern[k];
		}
		if(needle[k+1] == *haystack){
			k++;
		}
		if(k == nlen - 1){
			return haystack - k;
		}
	}
	return NULL;
}		/* -----  end of function kmp_match  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  strStr
 *  Description:  
 * =====================================================================================
 */
char*
strStr (char* haystack, char* needle)
{
	if(haystack == NULL || needle == NULL) return NULL;

	int hlen = strlen(haystack);
	int nlen = strlen(needle);

	if(nlen == 0) return haystack;
	if(hlen == 0) return NULL;

	int *pattern = new int[nlen];
	prefix(needle, nlen, pattern);
	return kmp_match(haystack, needle, pattern);
}		
/* -----  end of function strStr  ----- */
