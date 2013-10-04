/*
 * =====================================================================================
 *
 *       Filename:  3Sum.cc
 *
 *    Description:  Given a array S of n integers, are there elements a, b,c, in S such
 *                  that a + b + c = 0? find all unique triplets in the array which gives
 *                  the sum of 0
 *
 *        Version:  1.0
 *        Created:  03/20/13 19:23:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  threeSum
 *  Description:  First sort the array, then use two pointer method in 2Sum 
 * =====================================================================================
 */
vector<vector<int> > 
threeSum (vector<int> &num)
{
   vector<vector<int> > result;
   if(num.size() < 3){
	   return result;
   }else{
	  sort(num.begin(), num.end());
	  for(int i = 0; i < num.size() - 2; i++){
		  if(i = 0 || num[i] > num[i - 1]){
			  int j = i + 1, k = num.size() - 1;
			  while(j < k){
				  if(num[i] + num[j] + num[k] == 0){
					  vector<int> temp;
					  temp.push_back(num[i]);
					  temp.push_back(num[j]);
					  temp.push_back(num[k]);
					  result.push_back(temp);
					  k--;
					  j++;
				      while(k > j && num[k] == num[k + 1]){
					  k--;
				      }
				      while(j < k && num[j] == num[j - 1]){
					  j++;
				      }
				  }else if(num[i] + num[j] + num[k] > 0){
					  k--;
				  }else{
					  j++;
				  }
			  }
		  }
	  }
	  return result;
   }
}		
/* -----  end of function threeSum  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	vector<int> num;
	num.push_back(3);
	num.push_back(0);
	num.push_back(-2);
	num.push_back(-1);
	num.push_back(1);
	num.push_back(2);

	vector<vector<int> > result = threeSum(num);
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; i < result[i].size(); j++){
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
