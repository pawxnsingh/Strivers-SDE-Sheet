Brute --------------------->>>> 
    Time --------------->>> O(N^2)
    Space -------------->>> O(1)


    #include <bits/stdc++.h>
    int subarraysXor(vector<int> &arr, int x)
    {
        int count = 0 ;
        for(int i=0;i<arr.size();i++)
        {
            int xorSum = 0;
            for(int j=i;j<arr.size();j++)
            {
                xorSum = xorSum ^ arr[j];
                if(xorSum == x){
                    count++;
                }
            }
        }
        return count;
    }

Optimal ---------------------->>> 
    Time ---------------->>>> O(N) 
    Space --------------->>>> O(N)


    #include <bits/stdc++.h>
    int subarraysXor(vector<int> &arr, int k)
    {
        map<int,int>xorSum;
        
        xorSum[0] = 1;
        int maxCnt = 0;
        
        int xr = 0;
        
        for(int i=0;i<arr.size();i++){
            xr = xr ^ arr[i];
            int x = xr ^ k;
    
            maxCnt += xorSum[x];
            xorSum[xr]++;
               
        }
        return maxCnt;    
    }


    
