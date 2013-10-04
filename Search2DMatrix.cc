/*
 * =====================================================================================
 *
 *       Filename:  Search2DMatrix.cc
 *
 *    Description:  LeetCode Search 2D Matrix
 *        Version:  1.0
 *        Created:  03/25/13 19:41:26
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
 *         Name:  searchMatrix
 *  Description:  use twice binary search
 * =====================================================================================
 */
bool
searchMatrix (vector<vector<int> >&matrix, int target)
{
	int m = matrix.size();
	int n = matrix[0].size();
	if(m == 0) return false;
	if(n == 0) return false;
	if(target < matrix[0][0]) return false;
	if(target > matrix[m-1][n-1]) return false;

	int start = 0;
	int end = m - 1;
	while(start <= end){
		int mid = (start + end)/2;
		if(matrix[mid][0] == target){
			return true;
		}else if(matrix[mid][0] > target){
			end = mid - 1;
		}else{
			start = mid + 1;
		}
	}
    int targetRow = end;
	start = 0;
	end = n - 1;
	while(start <= end){
		int mid = (start + end)/2;
		if(matrix[targetRow][mid] == target){
			return true;
		}else if(matrix[targetRow][mid] > target){
			end = mid - 1;
		}else{
			start = mid + 1;
		}
	}

	return false;
}		/* -----  end of function searchMatrix  ----- */


bool searchMatrix(vector<vector<int> >&matrix, int target){
	int r = 0, c = matrix[0].size();
	while(r < matrix.size() && c >=0){
		if(matrix[r][c] == target){
			return true;
		}else if(matrix[r][c] < target){
			r++;
		}else{
			c--;
		}
	}
	return false;
}
