/*
 * =====================================================================================
 *
 *       Filename:  Sqrt.cc
 *
 *    Description:  LeetCode Sqrt(x)  
 *        Version:  1.0
 *        Created:  03/22/13 16:14:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  sqrt(int x)
 *  Description:  Recursive using Newton's method'  
 * =====================================================================================
 */
int
sqrt(int x)
{
	double y = 1.0;
	while(fabs(1.0/2.0*(x/y + y) - y) >= 0.00001){
		y = 1.0/2.0*(x/y+y);
	}
	return int(y);
}		
/* -----  end of function sqrt  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{

	printf("%d\n", sqrt(2147395599));
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
