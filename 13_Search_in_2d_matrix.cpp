Linear Search ---------->>
  Time ----------->>> O(N^2)
  Space ----------->>>> O(1)
  

      bool searchMatrix(vector<vector<int>>& mat, int target) {
        int rSize = mat.size();
        int cSize = mat[0].size();
        for(int i=0;i<rSize;i++){
            for(int j=0;j<cSize;j++){
                if(mat[i][j] == target){
                    return true;
                }
            }
        }
        return false;
      }


Binary Search ------------------->>>>
    Time --------------->>> O(LogN)
    Space ----------->>>>> O(1)
    
    
    bool searchMatrix(vector<vector<int>>& mat, int target) {
    int rsize = mat.size();
    int cSize = mat[0].size();
    
    int low = 0;
    int high = rsize*cSize-1;
    

    while(low <= high){
        
        int mid = (low+high)/2;

        int val = mat[mid / cSize][mid % cSize];

        if(val > target){
            high = mid-1;
        }
        else if(val == target){
            return true;
        }
        else{
            low = mid+1;
        }
                
    }
    return false;
    
}
