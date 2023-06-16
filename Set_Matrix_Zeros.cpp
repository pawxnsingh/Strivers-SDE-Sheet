#include <bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>> &matrix){
	int row = matrix.size();
	int col = matrix[0].size();

	vector<int>rTemp(row,1); // 3 
	vector<int>cTemp(col,1); // 3

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(matrix[i][j] == 0){
				rTemp[i] = 0;
				cTemp[j] = 0;
			}
		}
	}


	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(rTemp[i] == 0 || cTemp[j] == 0){
				matrix[i][j] = 0;
			}
		}
	}

	//return matrix;
}
