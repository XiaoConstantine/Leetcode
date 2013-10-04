/*
 * =====================================================================================
 *
 *       Filename:  ValidParentheses.cc
 *
 *    Description:  Given a string containing just the charac '('')' '{'' }''['']'
 *					determine if the input string is valid. The brackets must close in
 *					the correct order, "()" and "([]){} are valid but "(]" and "([)]"
 *					are not
 *        Version:  1.0
 *        Created:  03/19/13 18:13:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <stdlib.h>
#include <string>
#include <stack>
using namespace std;
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  isValid
 *  Description:  Using one stack as assitant, if met a left kuohao, push into stack
 *                when met a right kuohao compare with stack's top'
 * =====================================================================================
 */
bool
isValid (string s)
{
	stack<char> assist;
    if(s.size() == 0){
		return false;
	}

	for(int i = 0; i< s.size(); i++){
		if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
			assist.push(s[i]);
		}
		if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
			char c = assist.top();
			if(s[i] == ')'){
				if(c != '(')
					return false;
			}else if(s[i] == ']'){
				if(c != '['){
					return false;
				}
			}else{
				if(c != '{'){
					return false;
				}
			}

			assist.pop();
		}
	}
	return assist.size()==0;
}		
/* -----  end of function isValid  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	string s = "([)]";
	string s1 = "()[]";
	printf("%d\n", isValid(s));
	printf("%d\n", isValid(s1));
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
