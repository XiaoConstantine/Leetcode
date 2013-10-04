/*
 * =====================================================================================
 *
 *       Filename:  MergeTwoSortedArray.cc
 *
 *    Description:  Given two sorted arrays A and B, merge B into A as one sorted Array
 *                  Assume A has enough space to contain B
 *        Version:  1.0
 *        Created:  03/17/13 19:27:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include	<stdlib.h>
#include <stdio.h>
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  merge
 *  Description:  Compare begin from the end of two arrays put larger one in the end
 *              
 * =====================================================================================
 */
void
merge (int A[], int m, int B[], int n)
{ 
  int fullsize = m + n - 1;
  int index_b = n - 1;
  int index_a = m - 1;

  while(index_a >= 0 && index_b >= 0){
	  A[fullsize--] = A[index_a] > B[index_b]?A[index_a--]:B[index_b--];
      printf("index of b: %d ", index_b);
	  printf("\n");
	  printf("index of a: %d ", index_a);
  }
  while(index_b >= 0){
	  A[fullsize--] = B[index_b--];
  }
}		
/* -----  end of function merge  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{

	int a[] = {1, 3, 5, 7, 0, 0, 0,0};
	int b[] = {};
	merge(a, 4, b, 0);
	for(int i = 0; i < 8; i++){
		printf("%d ", a[i]);
	}
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

