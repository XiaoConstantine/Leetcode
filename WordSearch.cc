/*
 * =====================================================================================
 *
 *       Filename:  WordSearch.cc
 *
 *    Description:  LeetCode word search
 *        Version:  1.0
 *        Created:  03/21/13 16:32:54
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
#include <string>
using namespace std;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DFS
 *  Description:  
 * =====================================================================================
 */
bool
DFS (vector<vector<char> > &board, string &word,int* visited, int op, int maxLen, int i , int j)
{ 
    if(maxLen == word.size()){
		return true;
	}
	int row = board.size();
	int col = board[0].size();

	if(i+1 < row && op!=0){
	   if(visited[(i+1)*col + j] == 0 && board[i+1][j] == word[maxLen]){
		 visited[(i+1)*col + j] = 1;
		 if(DFS(board, word, visited, 1, maxLen+1, i+1, j))
			 return true;
		 visited[(i+1)*col + j] = 0;
	   }
	}
	if(i-1>=0 && op!=1){
		if(visited[(i-1)*col + j] == 0 && board[i-1][j] == word[maxLen]){
			visited[(i-1)*col + j] =1;
			if(DFS(board, word, visited, 0, maxLen+1, i-1, j))
				return true;
			visited[(i-1)*col + j] = 0;
		}
	}

	if(j+1 < col && op!=2){
		if(visited[i*col + j+1] == 0 && board[i][j+1] == word[maxLen]){
			visited[i*col + j + 1] = 1;
			if(DFS(board, word, visited, 3, maxLen+1, i, j+1))
				return true;
			visited[i*col + j + 1] = 0;
		}
	}

	if(j-1 >= 0 && op!=3){
		if(visited[i*col + j - 1] == 0 && board[i][j-1] == word[maxLen]){
			visited[i*col + j -1 ] = 1;
			if(DFS(board, word, visited, 2, maxLen+1, i, j-1))
				return true;
			visited[i*col + j-1] = 0;
		}
	}

	return false;
}		
/* -----  end of function DFS  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  exist
 *  Description:  
 * =====================================================================================
 */
bool
exist (vector<vector<char> >&board, string word)
{
	if(word.size() == 0)
		return false;
	if(board.size() == 0 || board[0].size() == 0)
		return false;
	
    int row = board.size();
	int col = board[0].size();

	int *visited = new int[row*col];
	memset(visited, 0, row*col*sizeof(int));

	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if(board[i][j] == word[0]){
				visited[i*col + j] = 1;
				if(DFS(board, word, visited, -1,1,i,j))
					return true;
				visited[i*col+j] = 0;
			}
		}
	}
	delete visited;
	return false;
}		

/* -----  end of function exist  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	vector<vector<char> > board;
	vector<char > temp;
	temp.push_back('a');
	temp.push_back('b');
	board.push_back(temp);

	printf("%d\n", exist(board, "ab"));
	
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
