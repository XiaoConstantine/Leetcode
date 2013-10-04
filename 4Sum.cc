/*
 * =====================================================================================
 *
 *       Filename:  4Sum.cc
 *
 *    Description:  LeetCode 4Sum
 *
 *        Version:  1.0
 *        Created:  04/10/13 19:18:56
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
 *         Name:  4Sum
 *  Description:  
 * =====================================================================================
 */
vector<vector<int> >
4Sum (vector<int> &num, int target)
{
	vector<vector<int> >result;
	if(num.size() < 4){
		return result;
	}else{
		sort(num.begin(), num.end());
		set<vector<int> > hset;
		for(int i = 0; i < num.size(); i++){
			for(int j = i+1; j< num.size(); j++){
				for(int k = j+1, l = num.size()-1; k < l;){
					int sum = num[i] + num[j] + num[k] + num[l];
					if(sum < target){
						k++;
					}else if(sum > target){
						l--;
					}else if(sum == target){
						vector<int> temp;
						temp.push_back(num[i]);
						temp.push_back(num[j]);
						temp.push_back(num[k]);
						temp.push_back(num[l]);
						if(hset.find(temp) == hset.end()){
							hset.insert(hset.begin(), temp);
							result.push_back(temp);
						}
						l--;
						k++;
					}
				}
			}
		}
		return result;
	}
}		/* -----  end of function 4Sum  ----- */
