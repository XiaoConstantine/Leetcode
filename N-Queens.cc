/*
 * =====================================================================================
 *
 *       Filename:  N-Queens.cc
 *
 *    Description:  LeetCode N-Queens
 *        Version:  1.0
 *        Created:  03/25/13 14:20:51
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
 *         Name:  check
 *  Description:  Check if the place can place queen  
 * =====================================================================================
 */
bool
check (int dep, int*place )
{
	for(int i = 0; i< dep; i++){
		int diff = abs(place[dep] - place[i]);
		if(diff == 0 || diff == dep - i){
			return false;
		}
	}
	return true;
}		
/* -----  end of function check  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DFS
 *  Description:  
 * =====================================================================================
 */
	void
DFS (vector<vector<string> >&result, int dep, int n)
{
	if(dep == n){
		vector<string> temp;
		for(int i = 0; i < dep; i++){
			string str(n, '.');
			str[place[i]] = 'Q';
			temp.push_back(str);
		}
		result.push_back(temp);
		return;

	}

	for(int i = 0; i < n; i++){
		place[dep] = i;
		if(check(dep, place)){
			DFS(result dep+1, n);
		}
	}
}		
/* -----  end of function DFS  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  solveNQueens
 *  Description:  
 * =====================================================================================
 */
vector<vector<string> >
solveNQueens (int n)
{
	vector<vector<string> >result;
	int *place = new int[n];
	DFS(result, n, 0);
	return <+return_value+>;
}		/* -----  end of function solveNQueens  ----- */

