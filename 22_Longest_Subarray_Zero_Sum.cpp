Brute -------------->>>> O(N^3)
  Time ------------------->>>> O(N^3)
  Space ------------------>>>> O(1)

    #include <bits/stdc++.h>
    int LongestSubsetWithZeroSum(vector<int>arr){
        int size = arr.size();
        int largeCount = 0;
        for(int i=0;i<size;i++)
        {
            for(int j=i;j<size;j++)
            {
                int sum = 0;
                for(int k=i;k<=j;k++)
                {
                    sum+=arr[k];
                    if(sum == 0)
                    {
                        largeCount = max(largeCount,j-i+1);
                    }
                }
            }
        }
        return largeCount;
    }


Better ----------------------->>>
    Time ------------------------------>>> O(N^2)
    Space ----------------------------->>> O(1)


    #include <bits/stdc++.h>
    int LongestSubsetWithZeroSum(vector<int>arr){
        int size = arr.size();
        int largeCount = 0;
        for(int i=0;i<size;i++)
        {
            int sum = 0;
            for(int j=i;j<size;j++)
            {
                sum+=arr[j];
                if(sum == 0){
                    largeCount = max(largeCount,j-i+1);
                }
            }
        }
        return largeCount;
    }


Optimal --------------------------->>>
    Time -------------->>> O(N)
    Space--------------->>> O(N)

    #include <bits/stdc++.h>
    //Hashing Approach O(N) and O(N)
    int LongestSubsetWithZeroSum(vector<int>arr)
    {
        unordered_map<int,int>mpp;
        
        int maxSum = 0;
        int sum = 0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(sum == 0){
                maxSum = i + 1;
            }
            else{
                if(mpp.find(sum) != mpp.end())
                {
                    maxSum = max(maxSum,i - mpp[sum]);
                }
                else
                {
                    mpp[sum] = i;
    
                }
            }
        }
        return maxSum;   
    }
    

