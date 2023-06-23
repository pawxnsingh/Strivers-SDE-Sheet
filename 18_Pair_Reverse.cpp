BruteForce ----------------->>>>
  Time------------------------>>>>> O(N^2)
  Space ------------------->>>>>>>>> O(1)


    class Solution {
    public:
        int reversePairs(vector<int>& nums) {
            int n = nums.size();
            int pair=0;
    
            for(int i=0;i<=n-1;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(i<j && nums[i] > (2* 1LL* nums[j])){
                        pair++;
                    }
                }
            }
            return pair;
        }
    };



