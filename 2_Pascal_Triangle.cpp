#include<bits/stdc++.h>
using namespace std;
/*
    In the Pascal Triangle There Are Usually Three Type of Problem that is Generally Asked
    1. Print the Element by Giving Row and Column 
    2. Print Nth Row of The Pascal Triangle
    3. Print The Entire Pascal Triangle by just The Number of Row As Input
*/

//1. Print the Element by Giving Row and Column 

// Run Loop For r Time 
// This Approach is Better than find factorial first then calculating
O(R)

int nCr(int n, int r)
{
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int main()
{
    int n = 6;
    int r = 3;
    // ouput must be 10;

    int ans = nCr(n - 1, r - 1);
    cout << "The Answer Will Be : " << ans << endl;
}








//    2. Print Nth Row of The Pascal Triangle

o(N)
    
void rownCr(int n)
{
    int answer = 1;
    cout << answer << " ";
    for (int i = 1; i < n; i++)
    {
        answer = answer * (n - i);
        answer = answer / (i);

        cout << answer << " ";
    }
}




int main()
{
    int n = 6;
    int r = 3;

    cout <<"Required Row Will Be: " ;
    rownCr(n);
    cout << endl;


    cout << "The Pascal Triangle will Be: " << endl;
    for(int i = 1 ; i<=n ;i++){
        rownCr(i);
        cout << endl;
    }

}




//    3. Print The Entire Pascal Triangle by just The Number of Row As Input

TC - O(N^2)

#include <bits/stdc++.h>
vector<long long int>generateRow(int n){
    long long int answer = 1 ;
    vector<long long int>ans ;
    ans.push_back(answer);

    for(int i = 1 ; i<n ;i++){
        answer = answer * (n-i);
        answer = answer / (i);
        ans.push_back(answer);
    }
    return ans;
}


vector<vector<long long int>> printPascal(int n){
    vector<vector<long long int>>ans;

    for(int i = 1 ; i<=n ;i++){
        vector<long long int> temp = generateRow(i);
        ans.push_back(temp);    
    }
    return ans;

  
}











































