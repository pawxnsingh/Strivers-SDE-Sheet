Bruteforce-------->>
    Time ------->>> O(Nlogn)
    Space ------->>> O(N)

        int removeDuplicates(vector<int> &arr, int n) {
        	//Defining set data stucture in order to store the unique value
        	set<int>st;
        	int sizeunique = 0;
        	for(int i=0;i<n;i++)
        	{
        		st.insert(arr[i]);
        	}
        	sizeunique = st.size();
        	int j = 0;
        	for(auto it:st)
        	{
        		arr[j] = it;
        		j++;
        	}
        	return sizeunique;	
        }


Optimal ------------>>>
    Time ----------------->>>>> O(N)
    Space ----------------->>>>> O(1)

        int removeDuplicates(vector<int> &arr, int n) {
        	int i=0;
        	int j = i+1;
        	while(j<n)
        	{
        		if(arr[i] != arr[j])
        		{
        			arr[i+1] = arr[j];		
        			i++;		
        		}
        		j++;
            }
        	return i+1;
        }
        



    
