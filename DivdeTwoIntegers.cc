/*
 * =====================================================================================
 *
 *       Filename:  DivdeTwoIntegers.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/15/13 14:26:29
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
 *         Name:  divide
 *  Description:  
 * =====================================================================================
 */
int
divide (int num_1, int num_2)
{
	long long a = ((double)num_1);
	long long b = ((double)num_2);

	long long ret = 0;
	while(a >= b){
		long long c = b;
		for(int i = 0; a >= c; i++; c<<=1){
			a -= c;
			ret += 1 << i;
		}
	}
	return ((num_1^num_2)>>31)?(-ret):ret;
}		/* -----  end of function divide  ----- */
