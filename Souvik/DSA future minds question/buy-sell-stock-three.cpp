#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int maxProfit(vector<int>&prices){
    if(prices.size() == 1){
        return 0;
    }
    int maxProfitValue = INT_MIN;
    int totalProfit = 0;
    vector<int>profits;
    for(int i = 0; i<prices.size()-1; i++){
        int profit;
        if(prices[i+1]>prices[i]){
            profit = prices[i+1]-prices[i];
            profits.push_back(profit);
        }

        sort(profits.begin(),profits.end());
        totalProfit+=profits[profits.size()-1]+profits[profits.size()-2];

        maxProfitValue = max(totalProfit,maxProfitValue);
    }

    return maxProfitValue;
}

int main(){
    vector<int>prices = {3,3,5,0,0,3,1,4};
    int maxProfitValue = maxProfit(prices);
    printf("%d \n",maxProfitValue);
    return 0;
}