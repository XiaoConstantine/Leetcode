/*
 * =====================================================================================
 *
 *       Filename:  Anagram.cc
 *
 *    Description:  LeetCode Anagram
 *        Version:  1.0
 *        Created:  03/22/13 17:35:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
using namespace std;


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  anagrams
 *  Description:  Sort then compare
 * =====================================================================================
 */
vector<string>
anagrams (vector<string>& strs)
{
    vector<string> result;
	vector<string> temp(strs);
    map<string, vector<int> > hash;

	for(int i = 0; i< temp.size(); i++){
		sort(temp[i].begin(), temp[i].end());
	}

	for(int i = 0; i<temp.size(); i++){
		hash[temp[i]].push_back(i);
	}

	for(int i = 0; i< temp.size(); i++){
		if(hash[temp[i]].size() > 1){
			while(hash[temp[i]].size() > 0){
				result.push_back(strs[hash[temp[i]].back()]);
				hash[temp[i]].pop_back();
			}
		}
	}

	return result;
}		/* -----  end of function anagrams  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
