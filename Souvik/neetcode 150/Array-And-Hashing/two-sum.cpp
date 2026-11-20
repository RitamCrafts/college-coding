#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int>twoSum(vector<int>&nums,int target){
    unordered_map<int,int>myMap;
    vector<int>result;
    for(int i = 0; i < nums.size(); i++){
        int complement = target-nums[i];
        auto it = myMap.find(complement);
        if(it != myMap.end()){
            result.push_back(myMap[complement]);
            result.push_back(i);
        }else{
            myMap[nums[i]] = i;
        }
    }

    return result;
}

int main(){
    vector<int>nums = {3,4,5,6};
    int target = 7;
    vector<int>result = twoSum(nums,target);

    for(int i:result){
        cout<<i<<" ";
    }

    cout<<endl;
}