Extreme Brute------------->>
    Time ------->>>  O(N^3)   
    Space -------->>> O(N) 
  
        vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
        	set<vector<int>>st;
        	for(int i=0;i<= n-3;i++)
        	{
        		for(int j=i+1;j<= n-2;j++)
        		{
        			for(int k=j+1;k<= n-1;k++)
        			{
        				int sum = arr[i] + arr[j] + arr[k];
        				if(sum == K)
        				{
        					vector<int>v = {arr[i],arr[j],arr[k]};
        					sort(v.begin(),v.end());
        					st.insert(v);
        				}
        			}
        
        		}
        	}
        	vector<vector<int>>ans(st.begin(),st.end());
        	return ans;
        }





better ---------------->>>>
    Time ----------->>> O(N^2)
    Space ----------->>> O(N)

        vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
        	set<vector<int>>st;
        	for(int i=0;i<n;i++)
        	{
        		set<int>s;
        		for(int j=i+1;j<n;j++)
        		{
        			int value = K - arr[i] - arr[j];
        			if(s.find(value) != s.end())
        			{
        				vector<int>temp = {arr[i],arr[j],value};
        				sort(temp.begin(),temp.end());
        				st.insert(temp);
        			}
        			s.insert(arr[j]);
        		}
        	}
        	vector<vector<int>>ans(st.begin(),st.end());
        	return ans;
        }



Optimal --------------->>>
    Time ----------->>> O(Nlogn) + O(N*N)
    Space ----------->>>> O(3k)
    
        vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
        	sort(arr.begin(),arr.end());
        	vector<vector<int>>ans;
        	for(int i=0;i<n;i++)
        	{
        		if(i>0 && arr[i] == arr[i-1]) continue;	
        		int j=i+1;
        		int k=n-1;
        		while(j<k)
        		{
        			long long sum = arr[i];
        			sum += arr[j];
        			sum += arr[k];
        			if(sum < K)
        			{
        				j++;
        			}
        			else if(sum > K)
        			{
        				k--;
        			}
        			else
        			{
        				vector<int>v1 = {arr[i],arr[j],arr[k]};
        				ans.push_back(v1);
        				j++;
        				k--;
        				while(j<k && arr[j] == arr[j-1]) j++;
        				while(j<k && arr[k] == arr[k+1]) k--;
        			}
        		}
        	}
        	return ans;
        }
