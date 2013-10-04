/*
 * =====================================================================================
 *
 *       Filename:  SpiralMatrixII.cc
 *
 *    Description:	LeetCode Spiral Matrix
 *        Version:  1.0
 *        Created:  04/06/13 18:15:45
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
 *         Name:  generateMatrix
 *  Description:  
 * =====================================================================================
 */
vector<vector<int> >
generateMatrix (int n)
{
	vector<vector<int> > result(n, vector<int>(n));
	if(n == 0) return result;

	int num = 0;
	int layer = n/2;
	for(int i = 0; i < layer; i++){
		int j;
		for(j = i; j < n-1-i; j++){
			result[i][j] = ++num;
		}
		for(j = i; j < n-1-i; j++){
			result[j][n-1-i] = ++num;
		}
		for(j = n -1-i; j > i; j--){
			result[n-1-i][j] = ++num;
		}
		for(j = n-1-i; j>i; i--){
			result[j][i] = ++num;
		}
	}

	if(n%2 == 1){
		result[n/2][n/2] =++num;
	}
	return result;
}		/* -----  end of function generateMatrix  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  generateMatrixII
 *  Description:  
 * =====================================================================================
 */
vector<vector<int> >
generateMatrixII (int n)
{
	vector<vector<int> > result(n, vector<int>(n));
	if(n == 0) return result;
	int num = 1;
	int start = 0, end = n-1;
	while(start < end){
		for(int j = start; j < end; j++){
			result[start][j] = num++;
		}
		for(int i = start; i < end; i++){
			result[i][end] = num++;
		}
		for(int j = end; j > start; j--){
			result[end][j] = num++;
		}
		for(int i = end; i > start; i--){
			result[i][start] = num++;
		}
		start++;
		end--;
	}
	if(start == end){
		result[start][start] = num;
	}

	return result;
}		/* -----  end of function generateMatrixII  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  generateM
 *  Description: O(m*n)  
 * =====================================================================================
 */
vector<vector<int> >
generateM (int n)
{
	vector<vector<int> > result(n, vector<int>(n,0));
	int k = 0, l = 0;
	int i = 1;
	int row = n;
	int col = n;

	while(k < row && l < n){
		for(int j = l; j < col; j++){
			result[k][j] = i;
			i++;
		}
		k++;

		for(int j = k; j < row; j++){
			result[j][col-1] = i;
			i++;
		}
		col--;

		if(k < row){
			for(int j = col-1; j>= l; j--){
				result[row-1][j] = i;
				i++;
			}
			row--;
		}

		if(l < col){
			for(int j = row-1; j >= k; j--){
				result[j][l] = i;
				i++;
			}
			l++;
		}
	}
	return result;
}		/* -----  end of function generateM  ----- */
