/*
 * =====================================================================================
 *
 *       Filename:  JumpGameII.cc
 *
 *    Description:  LeetCode Jump Game II
 *
 *        Version:  1.0
 *        Created:  04/08/13 00:58:38
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
 *         Name:  jump
 *  Description:  Greedy
 * =====================================================================================
 */
int
jump (int A[], int n)
{
	int min_v = 0;
	int end = 0;
	int start = 0;
	while(end < n){
		int max_v = 0;
		min_v++;
	    if(start > end) break;	
		for(int i = start; i <= end; i++){
			if(A[i] + i >= n - 1){
				return min_v;
			}
			if(A[i] + i > max_v){
				max_v = A[i] + i;
			}
		}
		
		start = end+1;
		end = max_v;
		cout << "Loop----" << endl;
	}
	return 0;
}		/* -----  end of function jump  ----- */

int main(){
	int A[] = {
		2,3,1,1,4
	};
	int n = sizeof(A)/sizeof(int);
	cout << jump(A, n) << endl;
	return 0;
}
