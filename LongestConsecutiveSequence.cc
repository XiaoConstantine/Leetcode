/*
 * =====================================================================================
 *
 *       Filename:  LongestConsecutiveSequence.cc
 *
 *    Description:  LeetCode Longest Consecutive Sequence
 *        Version:  1.0
 *        Created:  03/30/13 15:56:01
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
 *         Name:  longestConsecutive
 *  Description:  Asked time complexity O(n) and input is unordered array. Can use hashmap
 *				  searh with i-1 i+1 two direction
 * =====================================================================================
 */
int
longestConsecutive (vector<int>& num)
{
	unordered_map<int, int> hashmap;
	for(int i = 0; i < num.size(); i++){
		hashmap[num[i]] = i;
	}
    vector<int> visited(num.size(), 0);
	int min = 0;
	for(int i = 0; i < num.size(); i++){
		if(visited[i] == 1)continue;
		visited[i] = 1;
		int len = 1;
		int index = num[i] - 1;
		while(hashmap.find(index) != hashmap.end()){
			visited[hashmap[index]] = 1;
			len++;
			index--;
		}
		index = num[i] + 1;
		while(hashmap.find(index) != hashmap.end()){
			visited[hashmap[index]] = 1;
			len++;
			index++;
		}
		if(len > min){
			min = len;
		}
	}
	return min;
}		/* -----  end of function longestConsecutive  ----- */
