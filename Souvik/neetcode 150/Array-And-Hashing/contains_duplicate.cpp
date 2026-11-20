#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool hasDuplicate(vector<int>&arr){
    map<int,int>freq;
    for(int i:arr){
        freq[i]++;
    }

    for(auto it:freq){
        if(it.second>1){
            return true;
        }
    }

    return false;
}

int main(){
    vector<int>nums = {1,2,3,3};
    if(hasDuplicate(nums) == true){
        cout<<"Contains Duplicate."<<endl;
    }else{
        cout<<"All Unique."<<endl;
    }
    return 0;
}