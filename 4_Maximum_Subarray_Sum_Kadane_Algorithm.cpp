// Subarray ---------->>>>> Contigious Part of SubArray 



// Brute - ---------- > 
	
	
	#include <bits/stdc++.h> 
	long long maxSubarraySum(int arr[], int n){
		int maxi = 0;
		for(int i = 0 ; i < n ; i++){
			for(int j = i ; j < n ; j++){
				int sum = 0;				
				for(int k = i ; k <= j ; k++){
					sum = sum + arr[k];
					maxi = max(sum,maxi);
				}	
			}
		}
		return maxi;
	}
	
	
	
	
// Better  -----------> 
	
	#include <bits/stdc++.h> 
	long long maxSubarraySum(int arr[], int n){
		/*
			Don't write main().
			Don't read input, it is passed as function argument.    
			No need to print anything.
			Taking input and printing output is handled automatically.
		*/

		int maxi = 0;
		for(int i = 0 ; i < n ; i++){
			int sum = 0;
			for(int j = i ; j < n ; j++){
				sum += arr[j];
				maxi = max(sum,maxi);
			}
		}
		return maxi;
	}
	
// Optimal ------------ > Kadane Algorithm 

Time ----------> O(N)
Space --------->>>>>>> O(1)	

	#include <bits/stdc++.h> 
	long long maxSubarraySum(int arr[], int n){

	    long long maxi = LONG_MIN;
	    long long sum = 0;
	    int start = -1;
	    int startInd = -1;
	    int endInd = -1;
	    for(int i = 0 ; i < n ; i++){

		if(sum == 0 ) {
		    start = i;
		}

		sum = sum + arr[i];

		if(sum > maxi){
		    maxi = sum;
		    startInd = start;
		    endInd = i;
		}

		if(sum < 0){
		    sum = 0;

		}





	
