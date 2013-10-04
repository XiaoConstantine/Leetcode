/*
 * =====================================================================================
 *
 *       Filename:  SurroundedRegion.cc
 *
 *    Description:  LeetCode Surrounded Region
 *        Version:  1.0
 *        Created:  03/30/13 15:06:56
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
 *         Name:  dfs
 *  Description: run dfs on all four side(the first out layer of the matrix) mark +;
 *				 scan whole matrix , if see O mark X else if see + mark O
 * =====================================================================================
 */
void
dfs (vector<vector<char> >&board, int x, int y)
{
	board[x][y] = '+';
	if(x-1 >= 0 && board[x-1][y] == 'O'){
		dfs(board, x-1, y);
	}
	if(y-1 >= 0 && board[x][y-1] == 'O'){
		dfs(board, x, y-1);
	}
	if(x+1 < board.size() && board[x+1][y] == 'O'){
		dfs(board, x+1, y);
	}
	if(y+1 < board[0].size() && board[x][y+1] == 'O'){
		dfs(board, x, y+1);
	}
}	
/* -----  end of function dfs  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  solve
 *  Description:  
 * =====================================================================================
 */
void
solve (vector<vector<char> >&board)
{
	if(board.size() == 0){
		return;
	}
    for(int i = 0; i < board.size(); i++){
		if(board[i][0] == 'O'){
			dfs(board, i, 0);
		}
		if(board[i][board[0].size() - 1] == 'O'){
			dfs(board, i, board[0].size() - 1);
		}
	}

	for(int i = 1; i < board[0].size() - 1; i++){
		if(board[0][i] == 'O'){
			dfs(board, 0, i);
		}
		if(board[board.size()-1][i] == 'O'){
			dfs(board, board.size()- 1, i);
		}
	}

	for(int i = 0; i < board.size(); i++){
		for(int j = 0; j < board[0].size(); j++){
			if(board[i][j] == 'O'){
				board[i][j] = 'X';
			}else if(board[i][j] == '+'){
				board[i][j] = 'O';
			}
		}
	}


	return <+return_value+>;
}		/* -----  end of function solve  ----- */
