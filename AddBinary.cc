/*
 * =====================================================================================
 *
 *       Filename:  AddBinary.cc
 *
 *    Description:  LeetCode Add Binary
 *
 *        Version:  1.0
 *        Created:  03/22/13 16:51:27
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
using namespace std;
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  addBinary
 *  Description:  
 * =====================================================================================
 */
string
addBinary (string a, string b )
{
    int carry = 0;
	int size_a = a.size();
	int size_b = b.size();

	string sum = size_a > size_b? a:b;
	for(int i = 0; i < sum.size(); i++){
		char ca = i < size_a? a[size_a-i-1]:'0';
		char cb = i < size_b? b[size_b-i-1]:'0';
		int bit = ca - '0' + cb - '0'+ carry;
		carry = bit /2;
		sum[sum.size() -  i - 1] = bit%2 + '0';
	}

	if(carry){
		sum = "1" + sum;  // the position of "1" and sum can not change
	}
	return sum;
}		
/* -----  end of function addBinary  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
