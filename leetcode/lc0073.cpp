//
// Created by aleafall on 16-10-26.
//

/*
 * 使用第一行、第一列来暂存各行各列的信息
 * */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
	    if (matrix.empty() || matrix[0].empty()) {
		    return;
	    }
        bool is0FirstRow = 0, is0FirstCol = 0;
	    for (int i = 0; i < matrix.size(); ++i) {
		    if (matrix[i][0] == 0) {
			    is0FirstCol = 1;
			    break;
		    }
	    }
	    for (int i = 0; i < matrix[0].size(); ++i) {
		    if (matrix[0][i] == 0) {
			    is0FirstRow = 1;
			    break;
		    }
	    }
	    for (int i = 1; i < matrix.size(); ++i) {
		    for (int j = 1; j < matrix[0].size(); ++j) {
			    if (matrix[i][j] == 0) {
				    matrix[i][0] = 0;
				    matrix[0][j] = 0;
			    }
		    }
	    }
	    for (int i = 1; i < matrix.size(); ++i) {
		    if (matrix[i][0] == 0) {
			    for (int j = 1; j < matrix[0].size(); ++j) {
				    matrix[i][j] = 0;
			    }
		    }
	    }
	    for (int i = 1; i < matrix[0].size(); ++i) {
		    if (matrix[0][i] == 0) {
			    for (int j = 1; j < matrix.size(); ++j) {
				    matrix[j][i] = 0;
			    }
		    }
	    }
	    if (is0FirstCol) {
		    for (int i = 0; i < matrix.size(); ++i) {
			    matrix[i][0] = 0;
		    }
	    }
	    if (is0FirstRow) {
		    for (int i = 0; i < matrix[0].size(); ++i) {
			    matrix[0][i] = 0;
		    }
	    }
    }
};
