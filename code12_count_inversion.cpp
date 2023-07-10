Brute------------->>>
    Time------->> O(N^2)
    Space --------->> O(1)


    #include <bits/stdc++.h> 
    long long getInversions(long long *arr, int n){
        long long count = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j] && i < j ){
                    count++;
                }
            }
        }
        return count;
    }



Optimal ---------------->>>>>
    Time---------->> O(Nlogn)
    Space--------->> O(N)
    
    long long Merge(long long *arr,int low,int mid,int high){
        int left = low;
        int right = mid+1;
        long long cntInv = 0;

        long long temp[high-low+1];

        int ind = 0;
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp[ind] = arr[left];
                left++;
                ind++;
            }
            else{
                temp[ind] = arr[right];
                cntInv += (mid-left+1);
                right++;
                ind++;
            }
        }
        while(left <= mid){
            temp[ind] = arr[left];
            ind++;
            left++;
        }

        while(right <= high){
            temp[ind] = arr[right];
            ind++;
            right++;
        }

        for(int i=low,k=0;i<=high;i++,k++){
            arr[i] = temp[k];
        }
        return cntInv;
    }

    long long MergeSort(long long *arr,int low,int high){
        long long cntInv = 0;

        if(low>=high) return cntInv;
        int mid = (low+high)/2;
        cntInv += MergeSort(arr,low,mid);
        cntInv += MergeSort(arr,mid+1,high);
        cntInv += Merge(arr,low,mid,high);

        return cntInv;

    }

    long long getInversions(long long *arr, int n){    
        return MergeSort(arr,0,n-1);
    }
    

