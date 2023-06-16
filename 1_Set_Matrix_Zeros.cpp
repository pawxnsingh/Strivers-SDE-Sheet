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
//Time Complexity --- > O(N * M)
//Space Complexity ----> O(1)

void setZeros(vector<vector<int>> &matrix){
	int rSize = matrix.size();
	int cSize = matrix[0].size();
	
	//row -- > matrix [..][0]
	//col -- > matrix [0][..]
	int col0 = 1;
	// marking the inplace checker 
	for(int i=0;i<rSize;i++){
		for(int j=0;j<cSize;j++){
			if(matrix[i][j] == 0){
				matrix[i][0] = 0;
				if(j!=0){ // if j==0 you cant Mark it Here 
				// instead you mark in col0
					matrix[0][j] = 0;
				}
				else{
					col0 = 0;
				}
			}
		}
	}

	// marking Zero Inner Matrix 
	for(int i=1;i<rSize;i++){
		for(int j=1;j<cSize;j++){
			if(matrix[i][j] != 0){
				if(matrix[i][0] == 0 || matrix[0][j] == 0){
					matrix[i][j] = 0;
				}
			}
		}
	}
	
	// marking Checker equal To zero 

	if(matrix[0][0] == 0){
		for(int j=0;j<cSize;j++){
			matrix[0][j] = 0;
		}
	}

	if(col0 == 0){
		for(int i=0;i<rSize;i++){
			matrix[i][0] = 0 ;
		}
	}
}












