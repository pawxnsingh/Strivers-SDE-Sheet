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
    Time -------------------------->>O(N)
    Space----------------------------->>> O(N)


    #include <bits/stdc++.h>
    vector<int> majorityElementII(vector<int> &arr){
        map<int,int>mpp;
        vector<int>ans;
        int size = arr.size();
        int minival = (size/3)+1;
        for(auto it:arr){
            mpp[it]++;
            if(mpp[it] == minival){
                ans.push_back(it);
            }
        }
        return ans;
    }
    

Optimal -------------------------->>>>>
    (Extended Version of Moores Voting Algorithm)
    in the previous algo of moore Voting algo
    there Was Onkly one element that occur More than n/2
    In this case there will be Two Element At max
    Time ------------------->>>> O(N)
    Space------------------>>>>> O(1)


    #include <bits/stdc++.h>
    vector<int> majorityElementII(vector<int> &arr){
        vector<int>ans;
        int size = arr.size();
        int cnt1 = 0;
        int cnt2 = 0;
        int ele1 , ele2;
        
        for(int i=0;i<size;i++){
            if(cnt1 == 0 && arr[i] != ele2){
                cnt1 = 1;
                ele1 = arr[i];
            }
            else if(cnt2 == 0 && arr[i] != ele1){
                cnt2 = 1;
                ele2 = arr[i];
            }
            else if(arr[i] == ele1){
                cnt1++;
            }
            else if(arr[i] == ele2) {
                cnt2++;
            }
            else {
                cnt1--;   
                cnt2--;
            }
        }
        // Verify if Element is Possible Answer Or Not
        int count1 = 0;
        int count2 = 0;
        for(int i=0;i<size;i++){
            if(arr[i] == ele1){
                count1++;
            }
            else if(arr[i] == ele2){
                count2++;
            }
        }
    
        if(count1 > size/3){
            ans.push_back(ele1);
        }
        if(count2 > size/3){
            ans.push_back(ele2);
        }
        return ans;
    }















    
    
    
    



