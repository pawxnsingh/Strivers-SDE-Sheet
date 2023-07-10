Brute--------------->>>
    Time ----------->>> O(N)
    Space -------------->> O(1)


Iterative Method ------------->> 
    Time ----------->>>> O(LogN)
    Space ------------>>> O(1)
   
    int modularExponentiation(int x, int n, int m) {  
        int ans = 1;
        while (n){
            if (n&1){
                // This will check if last bit is set or not
                ans = (ans * 1LL *  x) % m;
            }
            x = (x * 1LL *x) % m;
            n >>= 1;
        }
        return ans;
    }


