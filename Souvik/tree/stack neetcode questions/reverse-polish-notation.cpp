#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

int evalRPN(vector<string>&tokens){
    if(tokens.size() == 0) return 0;

    stack<int>st;
    int result;
    for(string s:tokens){
        if(s != "+" && s != "-" && s != "*" && s != "/" ){
            st.push(stoi(s));
            continue;
        }

        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        if(s == "+"){
            st.push(a+b);
        }else if(s == "-"){
            st.push(b-a);
        }else if(s == "/"){
            st.push(b/a);
        }else if(s == "*"){
            st.push(a*b);
        }
    }

    result = st.top();
    return result;
}

int main(){
    vector<string>tokens = {"1","2","+","3","*","4","-"};
    int result = evalRPN(tokens);
    cout<<"Result: "<<result<<endl;
    return 0;
}