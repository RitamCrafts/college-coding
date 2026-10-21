#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool isValid(string s){
    if(s.empty()) return false;
    stack<char>st;

    for(char c:s){
        if(c == '(' || c == '{' || c == '['){
            st.push(c);
        }else if(c == ')' || c == ']' || c == '}'){
            if(st.empty()) return false;

            char top = st.top();
            if((top == '(' && c != ')') || (top == '{' && c != '}') || (top == '[' && c != ']')){
                return false;
            }

            st.pop();
        }
    }

    return st.empty();
}

int main(){
    string s = "[]";

    if(isValid(s) == true){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    return 0;
}