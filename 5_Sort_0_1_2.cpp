Brute Force Solution ---------------> 
  Tc ---------- >>>>>>> O(NlogN)
  Sc -------------->>> O(1)
  
	
	
	
		#include <bits/stdc++.h> 
		void sort012(int *arr, int n){
		   sort(arr,arr+n);
		}




Better Solution --------------- >> 
	TC --------------------->>>>>> O(2N)
	SC ---------------> O(1)

	
		#include <bits/stdc++.h> 
		void sort012(int *arr, int n){
		   int zero = 0 ; 
		   int one = 0 ;
		   int two = 0 ;
		   for(int i = 0 ; i < n ; i++){
			  if(arr[i] == 0){
				 zero++;
			  }
			  else if(arr[i] == 1){
				 one++;
			  }
			  else{
				 two++;
			  }
		   }


		   for(int i = 0 ; i < n ;i++){
			  arr[i] = 0; 
		   }

		   for(int i = zero ; i < n ; i++){
			  arr[i] = 1;
		   }

		   for(int i = zero + one ; i<n ;i++) {
			  arr[i] = 2;
		   }




Optimal Solution --------------->>>>>> 
	TC -------------->>>> O(N);
	SC --------------->>>> O(1);
	
	Dutch National Flag
		
	void sort012(int *arr, int n){
	   int start = 0 ;
	   int mid = 0;
	   int high = n-1;
	   for(int i = 0 ; i < n ;i++){
		  if(arr[mid] == 0){
			 swap(arr[start],arr[mid]);
			 start++;
			 mid++;
		  }
		  else if(arr[mid] == 1){
			 mid++;
		  }
		  else{
			 swap(arr[mid],arr[high]);
			 high--;
		  }
	   } 
	}


	
	
	
	
	
	
	
	
	
