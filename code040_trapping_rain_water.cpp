Brute------------->>>>> 
    Time ----------->>> O(N^2)
    Space ---------->>> O(1)

        find the leftmax and rightmax in each n every ith position

        long long getTrappedWater(long long* arr, int n) {    
            long long waterTrapped = 0;
            for(int i=0;i<n;i++)
            {
                int j = i;
                long long maxLeft = 0;
                long long maxRight = 0;
                while(j>=0)
                {
                    maxLeft = max(maxLeft,arr[j]);
                    j--;    
                }
        
                j = i;
                while(j<n)
                {
                    maxRight = max(maxRight,arr[j]);
                    j++;
                }
                waterTrapped += min(maxRight,maxLeft) - arr[i];           
            }
            return waterTrapped;
        }


Better ----------->>>> 
    Time ----------->>> O(3N)
    Space --------->>> O(N) + O(N)


        long long getTrappedWater(long long* arr, int n) {
        //left max preprocessing
            long long left[n] = {0};
            left[0] = arr[0];
            for(int i=1;i<n;i++)
            {
                left[i] = max(left[i-1],arr[i]);
            }
        //right max preprocessing
            long long right[n] = {0};
            right[n-1] = arr[n-1];
            for(int i=n-2;i>=0;i--)
            {
                right[i] = max(arr[i],right[i+1]);
            }
        //now counting
            long long count = 0;
            for(int i=0;i<n;i++)
            {
                count += min(left[i],right[i]) - arr[i];
            }
            return count;
        }




optimal ------------->>>
    Time ------------->>>> O(N)
    Space----------------->>> O(1)

        long long getTrappedWater(long long* arr, int n) {
            long long  left = 0, right = n - 1;
            long long res = 0;
            long long maxLeft = 0, maxRight = 0;
            while(left <= right){
                if(arr[left] <= arr[right]){
                    if (arr[left] >= maxLeft){
                        maxLeft = arr[left];
                    } 
                    else {
                        res += maxLeft - arr[left];
                    }
                    left++;
                }
                else{
                    if(arr[right] >= maxRight){
                        maxRight = arr[right];
                    } 
                    else{
                        res += maxRight - arr[right];
                    }
                    right--;
                }
            }
            return res;
        }
