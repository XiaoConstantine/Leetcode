/*
 * =====================================================================================
 *
 *       Filename:  RestoreIP.cc
 *
 *    Description:  LeetCode Restore IP address
 *        Version:  1.0
 *        Created:  03/27/13 16:01:33
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
 *         Name:  DFS
 *  Description:  
 * =====================================================================================
 */
void
DFS (string s, vector<string>& result, string temp, int dep, int partNum)
{
	if(s.size() - dep > (4-partNum)*3) return; // 3bit a split
	if(s.size() - dep < (4-partNum)) return;  // 1bit a split

	if(dep == s.size() && partNum == 4){
		temp.resize(temp.size() - 1);
		result.push_back(temp);
		return;
	}
	int num = 0;
	for(int i = dep; i<dep+3; i++){
        num = num*10 + s[i] - '0';
		if(num <= 255){
			temp += s[i];
			DFS(s, result, temp+'.', i+1, partNum+1);
		}
		if(num == 0){
			break;
		}
	}
}		
/* -----  end of function DFS  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  restoreIP
 *  Description:  
 * =====================================================================================
 */
vector<string>
restoreIP (string s)
{
	vector<string> result;
	string temp;
	DFS(s, result, temp, 0, 0);
	return result;
}		/* -----  end of function restoreIP  ----- */
