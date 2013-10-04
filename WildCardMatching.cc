/*
 * =====================================================================================
 *
 *       Filename:  WildCardMatching.cc
 *
 *    Description:  LeetCode WildCard Matching
 *
 *        Version:  1.0
 *        Created:  05/28/13 15:56:32
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
 *  Description:  
 * =====================================================================================
 */
bool
isMatch (const char* s, const char* p)
{
	const char* start_p = NULL, *start_s = NULL;
	while(*s){
		if(*p == *s || *p == '?'){
			p++;
			s++;
		}else if(*p == '*'){
			while(*p == '*'){ // skip all continous '*'
				p++;
			}
			if(!*p) return true; // if end with '*' return true
			start_p = p; // store '*' pos for string and pattern (later char pos of '*')
			start_s = s;
		}else if((!*p || *s != *p)&&start_p){
			s = start_s++; // skip non-match char in string, regard it matched in '*'
			p = start_p; // pattern backtrace to later char of '*'
		}else{
			return false;
		}
	}
   // check later part if are all '*'
	while(*p == '*'){
		p++;
	}
	return *p == 0;
}		/* -----  end of function isMatch  ----- */
