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

                        
//                Time Complexity ---  >  O(N) + O(N) + O(N) 
//                                        O(3N)
               
//                Space Complexity  ---- > if Interviewer Allow Us to Modify The array O(1)
//                                                or we Can Take O(N)
                                        











            #include <bits/stdc++.h> 
            void rev(vector<int> &permutation , int index , int n){
                int i = index;
                int j = n;
                while(i<j){
                    swap(permutation[i],permutation[j]);
                    i++;
                    j--;
                } 
            }

            vector<int> nextPermutation(vector<int> &permutation, int n){
                //Find The Break Point That has Been found
                int index = -1;
                for(int i = n-2 ;i > 0 ;i--){
                    if(permutation[i] < permutation[i+1]){
                        index = i ;
                        break;
                    }
                }

                if(index == -1 ){
                    reverse(permutation.begin(),permutation.end());
                    return permutation;
                }

                // find small but greater than index == i

                int smallmaxindex = -1;
                for(int i = n-1 ; i>index ; i--){
                    if(permutation[i] > permutation[index]){
                        swap(permutation[i],permutation[index]);
                        break;
                    }
                }


                // now Reverse the index+1 to get the next permutation which is just greater
                // than the given vector

                rev(permutation,index,n);
                        
                reverse(permutation.begin() + index + 1 , )
                        
                return permutation;




    
}

    
  
  
