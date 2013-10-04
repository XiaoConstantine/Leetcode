/*
 * =====================================================================================
 *
 *       Filename:  Pow.cc
 *
 *    Description:  Implement Pow(x,n)  
 *        Version:  1.0
 *        Created:  03/19/13 16:35:16
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
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  pow
 *  Description:  Easy way just loop but if n is large may take too long so we take d&c
 *                x^n = x^n/2 * x^n/2 * x^n%2
 * =====================================================================================
 */
double
pow (double x, int n)
{
    if(n == 0) return 1;
    int m = abs(n);
	int remain = 0;
	int powindex = 1;
    double result = x;
	while(m/2){
	   	result = result*result;
		remain = remain + m%2*powindex;
		powindex *= 2;
		m /=2;
	}
	result = result * pow(x, remain);
	if(n > 0){
		return result;
	}else{
	    return 1.0/result;
	}
}
/* -----  end of function pow  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{   
	printf("%f\n", pow(2, 4));
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
