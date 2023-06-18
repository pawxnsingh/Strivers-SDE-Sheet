Brute ---------------->>>

Time ----------> O(N^2)
Space ---------> O(1)
  
      #include <bits/stdc++.h> 
      int maximumProfit(vector<int> &prices){
          int size = prices.size();
          int profit = 0;

          for(int i = 0; i < size ;i++){
              int buy = prices[i];
              for(int j = i+1;j<size;j++){
                  int sell = prices[j] - buy ; 
                  // if(sell > profit){
                  //     profit = sell;
                  // }
                  profit = max(sell,profit);
              }
          }
          return profit;
      }


Better/Optimal ---------------->>>> 
Time -----------> O(N)
Space --------->>> O(1)
              
      #include <bits/stdc++.h> 
      int maximumProfit(vector<int> &prices){
          int size = prices.size();

          int bestBuy = prices[0];
          int max_Profit = 0;

          for(int i=1;i<size;i++){

              if(prices[i] < bestBuy){
                  bestBuy = prices[i];
              }

              else if(prices[i] - bestBuy > max_Profit){
                  max_Profit = prices[i] - bestBuy;
              }   
          }
          return max_Profit;   
      }
  
  
  
  
