/*
 * =====================================================================================
 *
 *       Filename:  RegularExpressionMatching.cc
 *
 *    Description:  LeetCode Regular Expression Matching
 *        Version:  1.0
 *        Created:  03/24/13 19:08:50
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
 *         Name:  isMatch
 *  Description:  Recursive 
 * =====================================================================================
 */
bool
isMatch (const char* s, const char* p)
{
	if(0 == *p) return 0 == *s;
	if(*(p+1) != '*'){
		if(*s == *p || *p == '.' && *s != 0){
			return isMatch(s+1, p+1);
		}
		return false;
	}else{
		while(*s == *p || *p == '.' && *s != 0){
			if(isMatch(s, p+2)){
				return true;
			}
			s++;
		}
		return isMatch(s, p+2);
	}
	
}		
/* -----  end of function isMatch  ----- */
