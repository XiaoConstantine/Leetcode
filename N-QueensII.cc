/*
 * =====================================================================================
 *
 *       Filename:  N-QueensII.cc
 *
 *    Description:  LeetCode N-Queens II  
 *
 *        Version:  1.0
 *        Created:  03/25/13 15:06:58
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
DFS (vector<vector<string> >&result, int dep, int n, int& count)
{
	if(dep == n){
		vector<string> temp;
		count++;
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
 *         Name:  totalNQueens
 *  Description:  
 * =====================================================================================
 */
int
totalNQueens (int n)
{
	vector<vector<string> > result;
	int* place = new int[n];
	int count = 0;
	DFS(place, n, 0, result, count);
	return count;
}		/* -----  end of function totalNQueens  ----- */
