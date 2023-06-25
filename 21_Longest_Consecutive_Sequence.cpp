BruteForce ------------------->>>>
    Time ----------->>>> O(N^2)
    Space----------->>>>> O(1)


    #include <bits/stdc++.h>
    bool ls(vector<int> &arr,int x){
        for(int i=0;i<arr.size();i++){
            if(arr[i] == x)
            {
                return true;
            }
        }
        return false;
    }
    
    
    int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
        int longcount = 1;
        for(int i=0;i<n;i++)
        {
            int count=1;
            int x = arr[i];
            while(ls(arr,x+1) == true)
            {
                count++;
                x++;
            }
            longcount = max(longcount,count);
        }
        return longcount;
    }



Better ------------------------->>>>
    Time --------------->>>> O(Nlogn)
    Space -------------->>>> O(1)

    #include <bits/stdc++.h>

    int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
        sort(arr.begin(),arr.end());
        int prevSmall = INT_MIN;
        int currcnt = 0;
        int longcnt = 1;
        for(int i=0;i<n;i++){
            if((arr[i])-1 == prevSmall){
                currcnt++;
                prevSmall = arr[i];
            }
            else if(arr[i] != prevSmall){
                prevSmall = arr[i];
                currcnt = 1;
                
            }
            longcnt = max(longcnt,currcnt);
        }
        return longcnt;
    }

Optimal -------------------->>>
    Time ----------------->>> O(3N)
    Space ---------------->>> O(N)

    #include <bits/stdc++.h>

    int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n){
        unordered_set<int>st;
        for(int it:arr){
            st.insert(it);
        }
    
        int cnt=0 , longCnt=1;
        
        for(auto it:st){
            if(st.find(it-1) == st.end()) // First Element
            {
                cnt=1;
                int x = it;
                while(st.find(x+1) != st.end())
                {
                    x++;
                    cnt++;
                }                 
            }
            longCnt = max(cnt,longCnt);
        }
        return longCnt;
    }






    
    
    
































    
