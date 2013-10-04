/*
 * =====================================================================================
 *
 *       Filename:  ReverseInteger.cc
 *
 *    Description:  LeetCode Reverse Integer
 *        Version:  1.0
 *        Created:  03/24/13 22:44:54
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
 *         Name:  reverse
 *  Description: Recursive  
 * =====================================================================================
 */
int
reverse (int x)
{
	int result = 0;
	int lastDigit = 0;
	while(x!=0){
		lastDigit = x%10;
		result = result*10 + lastDigit;
		x = x/10;
	}
	return result;
}		/* -----  end of function reverse  ----- */
