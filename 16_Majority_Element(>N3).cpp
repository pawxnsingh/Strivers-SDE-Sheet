Brute---------------->>>
    Time ------------------>>> O(N^2)
    Space  --------------->>> O(1) We are Using Extra Space only to Store  Two Element which is as good as Constant

Question :- How Many Integer At Max be Their in Answer??
    Ans :- for let take an example of size N = 8;
            if we divide >N/3 = 2
                at minimum the integer has to appear 3 Time
                if 3 + 3 + 3 = 9 integer
                where n is just 8 integer 
            So There Will be at Max 2 Integer as answer That will be 
            More Than N/3


    #include <bits/stdc++.h>
    
    vector<int> majorityElementII(vector<int> &arr){
        vector<int>ans;
        int size = arr.size();
    
        for(int i=0;i<size;i++){
            if(ans.empty() || ans.back() != arr[i]){
                int count = 0;
                for(int j=0;j<size;j++){
                    if(arr[j] == arr[i]){
                        count++;
                    }
                }
                if(count > size/3){
                    ans.push_back(arr[i]);
                    if(ans.size() == 2){
                        break;
                    }
                }
            }
        }
        return ans;
    }


Better--------------------->>>
    Time -------------------------->>O()
    Space----------------------------->>> O()








