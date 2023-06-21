BruteForce ------------>>>
  Time ---------------->> O(N^2)
  Space ---------------->>> O(1)


      #include <bits/stdc++.h>
      int findDuplicate(vector<int> &arr, int n){
      	int dup = -1;
      	for(int i=0;i<n;i++){
      		for(int j=i+1;j<n;j++){
      			if(arr[i] == arr[j]){
      				dup = arr[i];
      			}
      		}
      	}
      	return dup;
      }


Better -------------->>>
	Time --------->>>>>>O(Nlogn) + O(N)
	Space -------------->>>> O(1)



	int findDuplicate(vector<int> &arr, int n){
	int dupElement = 0;
	//Sort The Entire Array
		sort(arr.begin(),arr.end());
		for(int i=0;i<n;i++){
			if(arr[i] == arr[i+1]){
				dupElement = arr[i];
			}
		}
		return dupElement;
	}


More Better------------------>>>
	Time ------------->>
	Space------------->>

	int findDuplicate(vector<int> &arr, int n){
		unordered_map<int,int>temp;
		int dupEle=0;
		for(int i=0;i<n;i++){
			temp[arr[i]]++;
		}
		for(auto it:temp){
			if(it.second >= 2){
				dupEle = it.first;		
			}
		}
		return dupEle;
	}




