/*
 * =====================================================================================
 *
 *       Filename:  PalindromeNumber.cc
 *
 *    Description:  LeetCode Palindrome Number
 *        Version:  1.0
 *        Created:  04/13/13 23:54:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  isPalindrome
 *  Description:  Recursive first compare first digit and last digit, then second and last second
 *				  one
 * =====================================================================================
 */
bool
isPalindrome (int x)
{
	if(x < 0) return false;
	int div = 1;
	while(x / div >= 10){
		div *= 10;
	}

	while(x > 0){
		int l = x/div;
		int r = x%10;
		if(l != r) return false;
		x = x%div/10;
		cout << x << endl;
		div /= 100;
	}
	return true;
}		/* -----  end of function isPalindrome  ----- */

int main(){
	int x = 1111;
	isPalindrome(x);
	return 0;
}
