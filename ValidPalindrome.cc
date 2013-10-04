/*
 * =====================================================================================
 *
 *       Filename:  ValidPalindrome.cc
 *
 *    Description:  LeetCode Valid Palindrome
 *        Version:  1.0
 *        Created:  04/19/13 17:01:14
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
 *         Name:  isAlpha
 *  Description:  
 * =====================================================================================
 */
bool
isAlpha (char c )
{
	if(c >= 'a' && c <= 'z') return true;
	if(c >= '0' && c <= '9') return true;
	return false;
}		
/* -----  end of function isAlpha  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  isPalindrome
 *  Description:  
 * =====================================================================================
 */
bool
isPalindrome (string s)
{
	int l = 0;
	int r = s.length() - 1;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	while(l < r){
		while( l < r && !isAlpha(s[l])) l++;
		while( l < r && !isAlpha(s[r])) r--;
		if(s[l] != s[r]){
			break;
		}
		l++;
		r--;
	}
	if(l >= r){
		return true;
	}else{
		return false;
	}
}		/* -----  end of function isPalindorme  ----- */

