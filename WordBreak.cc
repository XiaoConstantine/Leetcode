/*
 * =====================================================================================
 *
 *       Filename:  WordBreak.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/07/13 18:57:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <string>
#include <unordered_set>

bool wordBreak(string s, unordered_set<string> &dict){
	int size = s.length();
	bool dp[size+1];
	dp[size] = true;

	for(int i = size - 1; i >= 0; i--){
		int j;
		for(j = i; j < size; j++){
			string sub = s.substr(i, j-i+1);
			if(dict.find(sub) != dict.end()){
				dp[i] = true;
				break;
			}
		}
		if(j == size) dp[i] = false;
	}
	return dp[0];
}

void helper(string s, int dep, string tmp, unordered_set<string> &dict, bool dp[], vector<string> &ret){
	if(dep == s.size()){
		tmp.erase(tmp.end()-1); // remove last " "
		ret.push_back(tmp);
		return;
	}

	for(int i = start; i < s.size(); i++){
		if(dp[i+1] == false) continue; // prune
		string sub = s.substr(start, i-start+1);
		if(dict.find(sub) != dict.end()){
			helper(s, i+1, tmp+sub+" ", dict, dp, ret);
		}
	}
}

bool wordBreak_ii(string s, unordered_set<string> &dict){
	int size = s.length();
	
	vector<string> ret;
	bool dp[size+1];
	dp[size] = true;

	for(int i = size - 1; i >= 0; i--){
		int j;
		for(j = i; j < size; j++){
			string sub = s.substr(i, j-i+1);
			if(dict.find(sub) != dict.end()){
				dp[i] = true;
				break;
			}
		}
		if(j == size) dp[i] = false;
	}
	string tmp;
	helper(s, 0, tmp, dict, dp, ret);
	return ret;
}


