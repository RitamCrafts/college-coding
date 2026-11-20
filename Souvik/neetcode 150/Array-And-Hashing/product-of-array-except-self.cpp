#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

vector<int>prefProduct(vector<int>&arr){
    int product = 1;
    vector<int>result;
    result.push_back(1);
    for(int i = 1; i<arr.size(); i++){
        product*=arr[i-1];
        result.push_back(product);
    }

    return result;
}

vector<int>suffProduct(vector<int>&arr){
    int product = 1;
    vector<int>result;
    for(int i = arr.size(); i>1; i--){
        product*=arr[i-1];
        result.push_back(product);
    }

    
    reverse(result.begin(),result.end());
    result.push_back(1);

    return result;
}

vector<int> productExceptSelf(vector<int>& nums){
    vector<int>prefProductResult = prefProduct(nums);
    vector<int>suffProductResult = suffProduct(nums);

    vector<int>result;
    
    for(int i = 0; i<nums.size(); i++){
        result.push_back(prefProductResult[i]*suffProductResult[i]);
    }

    return result;
}


int main(){
    vector<int>nums = {1,2,3,4};
    vector<int>result = productExceptSelf(nums);
    for(int i:result){
        cout<<i<<" ";
    }

    cout<<endl;
    return 0;
}