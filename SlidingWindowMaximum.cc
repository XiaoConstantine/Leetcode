/*
 * =====================================================================================
 *
 *       Filename:  SlidingWindowMaximum.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/22/13 13:47:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> Pair;
void maxSlid(int A[], int n, int w, int B[]){
	priority_queue<Pair> q;
	for(int i = 0; i < w; i++){
		q.push(Pair(A[i], i));
	}

	for(int i = w; i< n; i++){
		Pair p = q.top();
		B[i-w] = p.first;
		while(p.second <= i- w){
			q.pop();
			p = q.top();
		}
		q.push(Pair(A[i], i));
	}
	B[n-w] = q.top().first;
}

int main(){
	int A[] = {
		1,3,-1,-3,5,3,6,7
	};
	int n = sizeof(A)/sizeof(A[0]);
	int B[6];
	int w = 3;
	maxSlid(A, n, w, B);
	for(int i = 0; i < 6; i++){
		cout<< B[i] << " ";
	}
	return 0;
}

