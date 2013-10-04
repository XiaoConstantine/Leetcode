/*
 * =====================================================================================
 *
 *       Filename:  SetMatrixZeros.cc
 *
 *    Description:  Given m*n matrix, if an element is 0, set its row and column to 0
 *                  Do it in place
 *        Version:  1.0
 *        Created:  03/17/13 22:56:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  setZeros
 *  Description:  Symbol version of dp, set all values based on first row and col
 *                then set first row and col
 *                1. Check if 1st row and 1st col need to clear to zero
 *                2. process residual, if met a 0 make correspond row and col position set 0
 *                3. process residual, assign 0 based on 1st row and 1st col
 *                4. process 1st row and 1st col based on 1.
 * =====================================================================================
 */
void
setZeros(vector<vector<int> >&matrix)
{
	bool first_row_zero = false;
	bool first_col_zero = false;

	for(int i = 0; i < matrix.size(); i++){
        if(matrix[i][0] == 0){
			first_col_zero = true;
		    break;
		}
	}

	for(int i = 0; i < matrix[0].size(); i++){
        if(matrix[0][i] == 0){
			first_row_zero = true;
		    break;
		}
	}

	for(int i = 1; i < matrix.size(); i++){
		for(int j = 1; j < matrix[i].size(); j++){
			if(matrix[i][j] == 0){
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for(int i = 1; i < matrix.size(); i++){
		for(int j = 1; j < matrix[i].size(); j++){
			if(matrix[0][j] == 0 || matrix[i][0] == 0){
				matrix[i][j] = 0;
			}
		}
	}

	if(first_row_zero){
		for(int i = 0; i < matrix[0].size(); i++){
			matrix[0][i] = 0;
		}
	}

	if(first_col_zero){
		for(int i = 0; i < matrix.size(); i++){
			matrix[i][0] = 0;
		}
	}
}		

/* -----  end of function setZeros  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int
main ( int argc, char *argv[] )
{
	vector<int> s1;
	vector<vector<int> >matrix;
	s1.push_back(0);
	s1.push_back(0);
	s1.push_back(0);
    s1.push_back(5);
    matrix.push_back(s1);
	s1.clear();
	s1.push_back(4);
    s1.push_back(3);
	s1.push_back(1);
	s1.push_back(4);
	matrix.push_back(s1);
	s1.clear();
	s1.push_back(0);
	s1.push_back(1);
	s1.push_back(1);
	s1.push_back(4);
	matrix.push_back(s1);
	s1.clear();
	s1.push_back(1);
	s1.push_back(2);
	s1.push_back(1);
	s1.push_back(3);
	matrix.push_back(s1);

	setZeros(matrix);
    for(int i = 0; i < matrix.size(); i++){
		for(int j = 0; j < matrix[i].size(); j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
