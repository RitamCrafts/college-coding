#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int>result;
    int forwardProduct = 1;
    int backWardProduct = 1;
    for(int i = 0; i<nums.size(); i++){
        result.push_back(forwardProduct);
        forwardProduct*=nums[i];
    }

    for(int i = nums.size()-1; i>=0; i--){
        result[i]*=backWardProduct;
        backWardProduct*=nums[i];
    }

    return result;
}



int main(){
    vector<int>nums = {1,2,3,4};
    vector<int>result = productExceptSelf(nums);
    for(int i = 0; i<result.size(); i++){
        cout<<result[i]<<" ";
    };
    return 0;
}