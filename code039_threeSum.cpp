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
