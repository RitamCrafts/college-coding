#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<climits>
using namespace std;

vector<int>topKFrequentElements(vector<int>&nums,int k){
    if(nums.size() == 0) return {};
    vector<pair<int,int>>result;
    vector<int>finalResult;
    unordered_map<int,int>freq;
    for(int i:nums){
        freq[i++];
    }

    for(auto it:freq){
        result.push_back({it.first,it.second});
    }

    sort(result.begin(),result.end(),[](auto a, auto b){
        return a.second>b.second;
    });
    for(int i = 0; i<k; i++){
        finalResult.push_back(result[i].first);
    }

    return finalResult;
}

int main(){
    int n;
    cout<<"Enter Size of Array: "<<endl;
    cin>>n;
    vector<int>nums;
    for(int i = 0; i<n; i++){
        int num;
        cout<<"Enter Number "<<i+1<<": ";
        cin>>num;
        nums.push_back(num);
    }

    int k;
    cout<<"Enter k: ";
    cin>>k;
    vector<int>result = topKFrequentElements(nums,k);
    for(int i:result){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}