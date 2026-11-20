#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string encode(vector<string>&s){
    string encoded = "";
    for(string str:s){
        encoded+=to_string(str.length());
        encoded+="#";
        encoded+=str;
    }

    return encoded;
}

vector<string>decode(string s){}

int main(){
    vector<string>s={"Hello","World"};
    string encoded = encode(s);
    cout<<"Encoded String: "<<encoded<<endl;
    return 0;
}