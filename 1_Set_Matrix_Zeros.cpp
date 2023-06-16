#include <bits/stdc++.h>
using namespace std;

// Brute Solution- 
//Time -> O(N*M) * (N+M) + (N+M) ~= O(N^3)
//Space -> O(1)
 

#include <bits/stdc++.h>

void markrow(vector<vector<int>> &matrix,int csize,int i){
	for(int j=0;j<csize;j++){
		if(matrix[i][j] != 0){
			matrix[i][j] = -1;
		}
	}
}

void markcol(vector<vector<int>> &matrix,int rsize,int j){
	for(int i=0;i<rsize;i++){
		if(matrix[i][j] != 0){
			matrix[i][j] = -1;
		}
	}
}

void setZeros(vector<vector<int>> &matrix){
	int rsize = matrix.size();
	int csize = matrix[0].size();
	
	for(int i=0;i<rsize;i++){
		for(int j=0;j<csize;j++){
			if(matrix[i][j] == 0){
				markrow(matrix,csize,i); //TC - N 
				markcol(matrix,rsize,j); //TC - M 
			}
		}
	}
	
	for(int i=0;i<rsize;i++){
		for(int j=0;j<csize;j++){
			if(matrix[i][j] == -1){
				matrix[i][j] = 0;
			}
		}
	}
	
}



// Better Solution
// Time - O(2 * N * M)
// Space - O(N) + O(M)
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
}



//Optimal Solution - 













