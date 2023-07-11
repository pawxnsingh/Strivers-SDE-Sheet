//you are-given-n-number-of-intervals-where-each-interval-contains-two-integers-
//denoting-the-start-time-and-the-end-time-for-the-interval"
//You are given N number of intervals, 
//where each interval contains two integers denoting the start time and the end time for the interval

#include <bits/stdc++.h> 
using namespace std;
    //intervals[i][0] = start point of i'th interval
    //intervals[i][1] = finish point of i'th interval


/*
    Time Complexity :- nLogn(sorting) + o(n^2)(Not Actually Taking N2 
    Space Complexity :- O(N);
*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){
    int size = intervals.size();
    sort(intervals.begin(),intervals.end());
    vector<vector<int>>ans;

    for(int i = 0 ;i < size;i++){
        int start = intervals[i][0];
        int end = intervals[i][1];
        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }

        for(int j = i+1 ;j<size;j++){
            int sstart = intervals[j][0];
            if(sstart <= end){
                end = max(end,intervals[j][1]);
            }
            else{
                break;
            }
        }   
        ans.push_back({start,end});
    }
    return ans;
}


// Time Complexity :- O(NlogN) + O(N)
// Space Complexity :- O(N) 


vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){
    int size = intervals.size();
    sort(intervals.begin(),intervals.end());
    vector<vector<int>>ans;
    for(int i=0;i<size;i++){
        if(ans.empty() || intervals[i][0] > ans.back()[1] ){
            //we have to make new instance when ans is empty ans
            // and it has next interval is not in prev one
            ans.push_back({intervals[i][0],intervals[i][1]});
        }
        else{
            ans.back()[1] = max(ans.back()[1],intervals[i][1]);
        }
    }
    return ans;
}







