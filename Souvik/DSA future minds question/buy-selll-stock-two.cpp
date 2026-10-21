#include<iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>&prices){
    int maxProfitValue = INT_MIN;
    int profit = 0;
    for(int i = 0; i<prices.size()-1; i++){
        if(prices[i+1]>prices[i]){
            profit+=prices[i+1]-prices[i];
        }

        maxProfitValue = max(maxProfitValue,profit);

    }

    return maxProfitValue;
    
}

int main(){
    vector<int>arr = {7,1,5,3,6,4};
    int result = maxProfit(arr);
    printf("%d\n",result);
    return 0;
}