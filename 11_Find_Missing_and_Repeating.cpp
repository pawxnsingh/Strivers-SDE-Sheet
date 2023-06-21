Brute --------------------->>>
  Time ------------->>> O(N^2)
  Space ----------->>>>> O(1)
  
    pair<int,int> missingAndRepeating(vector<int> &arr, int n){
        int mis = -1;
        int rep = -1;
        for(int i=1;i<=n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(arr[j] == i){
                    count++;
                }
            }
            if(count==0) mis = i;
            else if(count==2) rep = i;
        }
        pair<int,int>ans(mis,rep);
        return ans;	
    }




Another Brute---------->>>> 
    Time-------------->>> 
    Space------------>>>
    
    
        #include <bits/stdc++.h>
        int repeating(vector<int> arr, int n){
            unordered_map<int,int>temp;
            int Rep=0;
            for(int i=0;i<n;i++){
                temp[arr[i]]++;
            }
            for(auto it:temp){
                if(it.second >= 2){
                    Rep = it.first;		
                }
            }
            return Rep;
        }

        int missing(vector<int> arr, int n){
            unordered_set<int>st;
            for(auto it:arr){
                st.insert(it);
            }
            int total = n*(n+1)/2;
            int setSum = 0;
            for(auto it:st){
                setSum+=it;
            }
            
            int miss = total - setSum;
            return miss;
        }

        pair<int,int> missingAndRepeating(vector<int> &arr, int n){
            int rep = repeating(arr,n);
            int mis = missing(arr,n);
            pair<int,int>ans(mis,rep);
            return ans ;
        }


Better ---------------------->>>
    Time ----------->>>> O(N);
    Space ------------>>> O(N)
        
        #include <bits/stdc++.h>
        pair<int,int> missingAndRepeating(vector<int> &arr, int n){
            // hashing 

            int rep = -1;
            int mis = -1;

            int hash[n+1] = {0};
            for(int i=0;i<n;i++){
                hash[arr[i]] +=1;
            }

            for(int i=1;i<=n;i++){
                if(hash[i] == 0){
                    mis = i;		
                }
                else if(hash[i] == 2){
                    rep = i;
                }
            }
            pair<int,int>ans(mis,rep);
            return ans;
        }


Optimal--------------------->>>>>>
    Time -------------->>> O(N)
    Space ------------->>>> O(1)
    
    #include <bits/stdc++.h>

    pair<int,int> missingAndRepeating(vector<int> &arr, int n){

        long long sum = 0;
        long long SumNatural = (n*(n+1))/2;

        long long squareSum = 0;
        long long squareSumNatural  = (n*(n+1)*(2*n+1))/6;

        for(int i=0;i<n;i++){
            sum += arr[i];
            squareSum += (long long)arr[i] * (long long)arr[i];
        }

        long long val1 = sum - SumNatural;
        long long val2 = squareSum - squareSumNatural ;
        val2 = val2/val1;

        long long x = (val1 + val2)/2;
        long long y = x - val1;
    
        return {(int)y,(int)x};
    }








