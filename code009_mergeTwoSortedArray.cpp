WITH USING EXTRA SPACE ------------------->
  TIME --------------->>> O(N+M)
  SPACE --------------->>>> O(N+M)

        vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
          vector<int>ans;
          int i = 0 ;
          int j = 0 ;

          while(i < m && j < n){
            if(arr1[i] <= arr2[j]){
              ans.push_back(arr1[i]);
              i++;
            }
            else if(arr1[i] > arr2[j]){
              ans.push_back(arr2[j]);
              j++;
            }
          }

          while(i < m){
            ans.push_back(arr1[i]);
            i++;
          }

          while(j < n){
            ans.push_back(arr2[j]);
            j++;
          }

          return ans;
        }




WIHTOUT USING EXTRA SPACE-------------------------------->>>>>>
  TIME ------------------------->>> O(MIN(M+N)) + O(NLOGN) + O(MLOGM)
  SPACE --------------------->>>>>>> O(1)
	

		void merge(long long arr1[], long long arr2[], int n, int m){
		int i = n-1 ; 
		int j = 0;

		while(i >= 0  && j < m){
			if(arr1[i] >= arr2[j]){
				swap(arr1[i],arr2[j]);
				i--;
				j++;
			}

			else{
				break;
			}
		}

		sort(arr1,arr1+n);

		sort(arr2,arr2+m);

	} 


Another Optimal Solution -------------->
	Time ------------------->>> O(nLogn)
	Space ----------------->>>>> O(1)
			
        void swapIfGreater(long long arr1[], long long arr2[],int ind1 , int ind2){
            if(arr1[ind1]>arr2[ind2]){
                swap(arr1[ind1],arr2[ind2]);
            }
        }

		void merge(long long arr1[], long long arr2[], int n, int m) { 
		int len = (n+m);
		int gap = (len/2) + (len%2);
		while(gap > 0){
			int left = 0;
			int right = left + gap;
			while(right < len){
				if(left < n && right >= n ){
					swapIfGreater(arr1,arr2,left,right-n);
				}
				else if(left >= n){
					swapIfGreater(arr2,arr2,left-n,right-n);
				}
				else{
					swapIfGreater(arr1,arr1,left,right);
				}
				left++;
				right++;
			}
			if(gap == 1) break;
			gap = (gap/2) + (gap%2);
		}
	} 

	
  
  
  
  
  
  
  








