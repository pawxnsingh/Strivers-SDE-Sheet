#include<bits/stdc++.h>
using namespace std;

// Brute Force :- 
            // Firstly Generate all the Permutation in Sorted Order 
            // Do a linear Search To Find The Element And Search the Next Index of Current Element
            //  that How We can find the next permutation 
//Time Complexity = O(N! * N)


// Better Approach :- 
            // Only for c++ Programmer There is A 
            // Inbuilt Stl Function that we can use to Find the Next_permutation
   

        vector<int> nextPermutation(vector<int> &permutation){
            next_permutation(permutation.begin(),permutation.end());
            return permutation;
        }

        int main(){
            vector<int> input = {1,2,3};
            vector <int> output = nextPermutation(input);
            // run a for loop to print all the permutation 
        }


// Optimal Approach: -


    
  
  
