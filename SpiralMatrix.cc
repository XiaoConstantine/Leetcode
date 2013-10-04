/*
 * =====================================================================================
 *
 *       Filename:  SpiralMatrix.cc
 *
 *    Description:  LeetCode Spiral Matrix
 *        Version:  1.0
 *        Created:  04/06/13 20:19:00
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
 *         Name:  spiralOrder
 *  Description:  
 * =====================================================================================
 */
vector<int>
spiralOrder (vector<vector<int>  >&matrix)
{
	vector<int> result;
	if(matrix.empty()) return result;
	int m = matrix.size();
	int n = matrix[0].size();

	int min_v = min(m, n);
	int layer = min_v/2;
	for(int i = 0; i < layer; i++){
		int j;
		for(j = i; j < n-1-i; j++){
			result.push_back(matrix[i][j]);
		}
		for(j = i; j < m-1-i; j++){
			result.push_back(matrix[j][n-1-i]);
		}
		for(j = n-1-i; j>i; j--){
			result.push_back(matrix[m-1-i][j]);
		}
		for(j = m-1-i; j>i; j--){
			result.push_back(matrix[j][i]);
		}
	}

	if(min_v % 2 == 1){
		if(m > n){
			for(int i = layer; i<= m-1-layer; i++){
				result.push_back(matrix[i][n/2]);
			}
		}else{
			for(int i = layer; i<=n-1-layer; i++){
				result.push_back(matrix[m/2][i]);
			}
		}
	}
	return result;
}		/* -----  end of function spiralOrder  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  spiral
 *  Description:  
 * =====================================================================================
 */
vector<int>
spiral (vector<vector<int> > &matrix)
{
	vector<int> result;
	if(matrix.empty()) return result;
	int m = matrix.size();
	int n = matrix[0].size();
	vector<int> result;

	int k = 0, l = 0;
	/* k start row index
	 * m end row index
	 * l start col index
	 * n end col index
	 * */

	while(k < m && l < n){
		/* print first row from remain rows*/
		for(int i = l; i < n; i++){
			result.push_back(matrix[k][i]);		
		}
		k++;

		/* print first col from remain cols*/
		for(int i = k; k < m; i++){
			result.push_back(matrix[k][n-1]);
		}
		n--;

		/* print last row from remain rows*/
		if(k < m){
			for(int i = n-1; i >= l; i--){
				result.push_back(matrix[m-1][i]);
			}
			m--;
		}

		/* print the first col from remain cols */
		if(l < n){
			for(int i = m-1; i>=k; i--){
				result.push_back(matrix[i][l]);
			}
			l++;
		}
	}
	return result;
}		/* -----  end of function spiral  ----- */
