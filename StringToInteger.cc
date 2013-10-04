/*
 * =====================================================================================
 *
 *       Filename:  StringToInteger.cc
 *
 *    Description:  LeetCode String To Integer  
 *        Version:  1.0
 *        Created:  05/02/13 17:03:45
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
 *         Name:  atoi
 *  Description:  
 * =====================================================================================
 */
int
atoi (const char* str)
{
	if(str == NULL) return 0;
	int i = 0;
	bool neg = false;

	while(str[i] == ' '){
		i++;
	}

	if(str[i] == '-'){
		neg = true;
		i++;
	}else if(str[i] == '+'){
		i++;
	}

	double result = 0;
	while(str[i] != '\0'&& str[i] >= '0' && str[i] <= '9'){
		int n = str[i] - '0';
		result = result*10 + n;
	}
	int output;
	if(neg){
		output = result > INT_MAX?INT_MIN:(~(unsigned int)result + 1);
	}else{
		output = result >= INT_MAX?INT_MAX: (int)result;
	}

	return output;
}		/* -----  end of function atoi  ----- */
