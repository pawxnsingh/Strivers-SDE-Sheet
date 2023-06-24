BruteForce ----------------->>>>
  Time------------------------>>>>> O(N^2)
  Space ------------------->>>>>>>>> O(1)



Test case : [6,13,21,25] --- [1,2,3,5]


    

    class Solution {
    public:
        int reversePairs(vector<int>& nums) {
            int n = nums.size();
            int pair=0;
    
            for(int i=0;i<=n-1;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(i<j && nums[i] > (2* 1LL* nums[j])){
                        pair++;
                    }
                }
            }
            return pair;
        }
    };




Better ----------------------->>>> 
  Time --------------------->>> O(Logn) * (N+ N) = O(2NlogN)
  Space ------------------->>>> O(N)



    #include <bits/stdc++.h> 
    void Merge(vector<int> &arr,int low,int mid,int high){
    	int left = low;
    	int right = mid+1;
    	vector<int>ans;
    	while(left <= mid && right <= high){		
    		if(arr[left] <= arr[right]){
    			ans.push_back(arr[left]);
    			left++;
    		}	
    		else{
    			ans.push_back(arr[right]);
    			right++;
    		}
    	}
    	while(left <= mid){
    		ans.push_back(arr[left]);
    		left++;
    	}
    	while(right <= high){
    		ans.push_back(arr[right]);
    		right++;		
    	}
    	for(int i=low;i<=high;i++){
    		arr[i] = ans[i-low];
    	}
    }
    
    int countPairs(vector<int> &arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > 2 * arr[right]){
    			right++;
    		} 
            cnt += (ight - (mid + 1));
        }
        return cnt;
    }
    
    int MergeSort(vector<int> &arr,int low,int high){
    	//Base Case
    	int pair = 0;
    	if(low>=high) return pair;
    	int mid = (low+high)/2;
    	pair += MergeSort(arr,low,mid);
    	pair +=MergeSort(arr,mid+1,high);
    	pair += countPairs(arr, low, mid, high); //Modification
    	Merge(arr,low,mid,high);
    	return pair;	
    }
    int reversePairs(vector<int> &arr, int n){
    	return MergeSort(arr,0,n-1);
    }

