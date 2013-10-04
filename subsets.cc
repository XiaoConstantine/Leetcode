#include <vector>
#include <iostream>
using namespace std;

/*given distinct array [1,2,3]
 * return all subsets
 *suppose u have all subsets([1,2])
 then what u have to do is just to add the last element into all the subsets([1,2])
 * */

vector<vector<int> > subsets(vector<int> input){
	vector<vector<int> >results;
	
	if(input.size() == 0){
		return results;
	}else{
		int temp = *input.begin();
        input.erase(input.begin());
		vector<vector<int> > subs = subsets(input);
		vector<int> t;
		results.push_back(t);  /*empty subset*/
		t.push_back(temp);
		results.push_back(t); /*subset with the element*/

		for(vector<vector<int> >::iterator it = subs.begin(); it!=subs.end(); it++){
			if(!it->empty()){
				vector<int> s(*it);
			    s.push_back(temp);
			//	s.emplace_back(temp);
				results.push_back(*it);
				results.push_back(s);
			}
		}
	}

	return results;
}


/*subsets II problem
 *if the input is [1,2,2]
 *remove the dup subsets
 * */
vector<vector<int> > subsets2(vector<int> input){
	vector<vector<int> >results;
	if(input.size() == 0){
		return results;
	}else{
		int temp = *input.begin();
        input.erase(input.begin());
		vector<vector<int> > subs = subsets(input);
		vector<int> t;
		results.push_back(t);  /*empty subset*/
		t.push_back(temp);
		results.push_back(t); /*subset with the element*/
		
		for(vector<vector<int> >::iterator it = subs.begin(); it!=subs.end(); it++){
			if(!it->empty()){
			vector<int> s(*it);
			s.push_back(temp);
			//	s.emplace_back(temp);
			results.push_back(*it);
			//	if(find(results.begin(), results.end(),s) == results.end()){
			results.push_back(s);
			}
		}
	}

    vector<vector<int> > ans;
	for(vector<vector<int> >::iterator it = results.begin(); it!=results.end(); it++){
		if(find(ans.begin(), ans.end(), *it) == ans.end()){
			ans.push_back(*it);
		}
	}

	return ans;
}

int main(){
	vector<int> input;
/*	for(int i = 1; i<=3; i++){
		input.push_back(i);
	}*/
	input.push_back(2);
	input.push_back(2);
    input.push_back(1);
	
	
	vector<vector<int> > result = subsets2(input);
	for(vector<vector<int> >::iterator it = result.begin(); it!=result.end(); it++){
		for(vector<int>::iterator itr = it->begin(); itr!=it->end(); itr++){
			cout<<*itr<<' ';
		}
		cout<<endl;
	}
	return 0;
}

