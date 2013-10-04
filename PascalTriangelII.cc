/*
 * =====================================================================================
 *
 *       Filename:  PascalTriangelII.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/02/13 22:44:55
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
 *         Name:  getRows
 *  Description:  
 * =====================================================================================
 */
vector<int>
getRows (int rowIndex)
{
	vector<int> result;
	if(rowIndex < 0) return result;
	result.push_back(1);
	if(rowIndex == 0) return result;
	result.push_back(1);
	if(rowindex == 1) return result;
	int t1 = 0, t2 = 0;
	for(int i = 2; i <= rowIndex; i++){
		t2 = 1;
		for(int j = 1; j < i; j++){
			t1 = t2;
			t2 = result[j];
			result[j] = t1 + t2;
		}
		result.push_back(1);
	}
	return result;
}		/* -----  end of function getRows  ----- */

