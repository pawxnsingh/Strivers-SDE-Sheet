Naive ---------------->>> 
  Time ----------------------->>>O(N^4)
  Space -------------------->>>> O(1)


        #include <bits/stdc++.h>
        string fourSum(vector<int> arr, int target, int n) {
            string ans = "No";
            for(int i=0;i<=n-4;i++){
                for(int j=i+1;j<=n-3;j++){
                    for(int k=j+1;k<=n-2;k++){
                        for(int l=k+1;l<=n-1;l++){
                            if(arr[i]+arr[j]+arr[k]+arr[l] == target){
                                ans = "Yes";
                            }
                        }
                    }
                }
            }
            return ans;
        }


Better ------------------------>>>>
    Time---------------->>> O(N^3 Logn)
    Space ------------------>>> O(N)


    #include <bits/stdc++.h>
    string fourSum(vector<int> arr, int target, int n) {
        string ans = "No";
    
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                set<int>st;  //this may store all the element in the vector
                for(int k=j+1;k<n;k++)
                {
                    int check = target-(arr[i]+arr[j]+arr[k]);
                    if(st.empty() || !st.count(check)){
                        st.insert(arr[k]);
                    }
                    else{
                        ans = "Yes";   
                    }
                }
            }
        }
        return ans;
    }


Optimal ------------------>>>>
    Time -------------------->>>> O()
    Space---------------------->>>


    #include <bits/stdc++.h>
    string fourSum(vector<int> arr, int target, int n) {
        string ans = "No";
        int k,l;
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++){
            if(i>0 && arr[i] == arr[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j != i+1 && arr[j] == arr[j-1]) continue;
               
                k=j+1 , l = n-1;
                while(k<l){
                    int sum = arr[i]+arr[j]+arr[k]+arr[l];
                    if(sum == target){
                        ans = "Yes";
                        k++;
                        l--;
                        while(k<l && arr[k] == arr[k-1]) k++;
                        while(k<l && arr[l] == arr[l+1]) l--;
                    }
                    else if(sum > target){
                        l--;
                    }
                    else{
                        k++;
                    }
                }
            }
        }
        return ans;
    }




