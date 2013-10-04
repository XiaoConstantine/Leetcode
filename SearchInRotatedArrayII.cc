/*
 * =====================================================================================
 *
 *       Filename:  SearchInRotatedArrayII.cc
 *
 *    Description:  LeetCode Search In Rotated Array
 *        Version:  1.0
 *        Created:  03/25/13 22:43:24
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
 *         Name:  search
 *  Description:  if array has duplicates, then we can not make sure that if A[mid] >= A[l]
 *				  then A[L....M] is nondescending  therefore we split it into two condition
 * =====================================================================================
 */
bool

search (int A[], int n, int target)
{
	int l = 0;
	int r = n - 1;
	while(l <= r){
		int mid = (l+r)/2;
		if(A[mid] == target){
			return true;
		}
		if(A[mid] > A[l]){
			if(A[l] <= target && target < A[mid]){
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}else if(A[l] > A[mid]){
			if(A[l] <=  target || target <= A[mid]){
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}else{
			l++;
		}
	}
	return false;
}		/* -----  end of function search  ----- */
