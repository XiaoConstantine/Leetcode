/*
 * =====================================================================================
 *
 *       Filename:  RotateImage.cc
 *
 *    Description:  LeetCode Rotate Image
 *
 *        Version:  1.0
 *        Created:  04/07/13 23:58:57
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
 *         Name:  naive
 *  Description:  O(n^2) space  
 * =====================================================================================
 */
	void
naive (vector<vector<int> >&matrix)
{
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<int> > temp(m, vector<int>(n, 0));

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			temp[j][m-i-1] = matrix[i][j];
		}
	}

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			matrix[i][j] = temp[i][j];
		}
	}
}		/* -----  end of function naive  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  rotateImage
 *  Description:  1. follow reverse diangol -line reverse element
 *				  2. follow x-line reverse element
 *				  e.g. 1 2    4 2   3 1
 *					   3 4 -> 3 1-> 4 2
 * =====================================================================================
 */
void
rotateImage (vector<vector<int> >&matrix )
{
	int n = matrix.size();
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n-i; j++){
			swap(matrix[i][j], matrix[n-1-j][n-1-i]);
		}
	}

	for(int i = 0; i < n/2; i++){
		for(int j = 0; j < n; j++){
			swap(matrix[i][j], matrix[n-1-i][j]);
		}
	}
}		/* -----  end of function rotateImage  ----- */

