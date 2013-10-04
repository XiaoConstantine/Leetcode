/*
 * =====================================================================================
 *
 *       Filename:  SearchForRange.cc
 *
 *    Description:  LeetCode Search For Range
 *
 *        Version:  1.0
 *        Created:  03/25/13 13:03:55
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
 *         Name:  binarySearch
 *  Description:  
 * =====================================================================================
 */
int
binarySearch (int A[], int n, int target)
{
	int l = 0;
	int r = n - 1;
	while(l <= r){
		int mid = l+r/2;
		if(A[mid] == target){
			return mid;
		}else if(A[mid] > target){
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	return -1;
}		

/* -----  end of function binarySearch  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  searchRange
 *  Description:  Binary Search  
 * =====================================================================================
 */
vector<int>
searchRange (int A[], int n, int target)
{
	vector<int> result;
	if(bs(A, n, target) == -1){
		result.push_back(-1);
		result.push_back(-1);
		return result;
	}else{
		int start = bs(A, n, target);
		int end;

		for(int i = start + 1; i<n; i++){
			if(A[i] == A[start]){
				end = i;
			}
		}

		if(end == 0 && start != 0){
			end = start;
		}

		if(start - 1 >= 0){
			for(int i = start-1; i>=0; i--){
				if(A[i] == A[start]){
					start = i;
				}
			}
		}
		result.push_back(start);
		result.push_back(end);
		return result;
	}
}		/* -----  end of function searchRange  ----- */
