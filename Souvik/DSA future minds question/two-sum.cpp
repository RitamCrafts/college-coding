#include<iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int>map;
    vector<int>result;
    for(int i = 0; i<nums.size(); i++){
        int complement = target-nums[i];
        if(map.find(complement) != map.end()){
            result.push_back(map[complement]);
            result.push_back(i);
            return result;
        }
        else{
            map[nums[i]] = i;
        }
    }

    return {};
}

int main(){
    vector<int>arr = {2,7,11,15};
    int target = 9;
    vector<int>result = twoSum(arr,target);
    for(int i = 0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    
    return 0;
}