/*
 * =====================================================================================
 *
 *       Filename:  PlusOne.cc
 *
 *    Description:  LeetCode Plus One
 *        Version:  1.0
 *        Created:  04/06/13 17:27:26
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
 *         Name:  plusOne
 *  Description:  
 * =====================================================================================
 */
vector<int>
plusOne (vector<int>& digits)
{
	int carry = 1, sum = 0;
	vector<int> result(digits.size(), 0);
	for(int i = digits.size() - 1; i>=0; i--){
		sum = carry + digits[i];
		carry = sum /10;
		result[i] = sum%10;
	}

	if(carry > 0){
		result.insert(result.begin(), carry);
	}
	return result;
}		/* -----  end of function plusOne  ----- */
