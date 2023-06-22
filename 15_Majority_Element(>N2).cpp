Brute -------------------->>>> 
    Time ----------->>> O(N^2)
    Space ---------->>> O(1)
    
    int findMajorityElement(int arr[], int n) {
        int majority = -1;
        for(int i=0;i<=n-1;i++){
            int count=0;
            for(int j=i+1;j<n;j++){
                if(arr[i] == arr[j]){
                    count++;
                }
            }
            if(count >= n/2){
                majority = arr[i];
            }
        }
        return majority;
    }

Better --------------->>>>>>>>>>>>
    Time ------------->> O(N)
    Space ----------->> O(N)
    
    int findMajorityElement(int arr[], int n) {
        int majority = -1;
        map<int,int>mpp;

        for(int it=0;it<n;it++){
            mpp[arr[it]]++;
        }

        for(auto it: mpp){
            if(it.second > n/2){
                majority = it.first;
            }
        }
        return majority;
    }


Optimal ---------------------->>>>> (Moores Voting Algorithm)
    Time ------------------------->>>>  O(N)
    Space------------------------>>>>> O(1)
   
    
    Majority == Miniority
    
    
    1. Apply Moore Voting Algorithm
    2. Verify The Element is in majority or not
    
    
    
    
    int findMajorityElement(int arr[], int n){
        int element;
        int vote = 0;

        for(int i=0;i<n;i++){
            if(vote == 0){
                vote = 1;
                element = arr[i];
            }
            else if(arr[i] == element){
                vote++;
            }
            else{
                vote--;
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(arr[i] == element){
                count++;
            }
        }
        if(count > n/2){
            return element;
        }
        return -1;



    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
