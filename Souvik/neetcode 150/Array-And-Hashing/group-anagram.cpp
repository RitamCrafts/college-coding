#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string>&strs){
    if(strs.size() == 0){
        return {};
    }

    vector<vector<string>>result;
    unordered_map<string,vector<string>>myMap;

    for(string s:strs){
        string str = s;
        sort(str.begin(),str.end());

        myMap[str].push_back(s);
    }
    
    for(auto it:myMap){
        result.push_back(it.second);
    }
    return result;
}

int main(){
    vector<string>strs = {"act","pots","tops","cat","stop","hat"};
    vector<vector<string>>result = groupAnagrams(strs);
    for(int i = 0; i<result.size(); i++){
        for(string j:result[i]){
            cout<<j<<" ";
        }
    }

    cout<<endl;
    return 0;
}