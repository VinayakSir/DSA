#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int start,int end){
        return ((start=='[' && end ==']')||(start=='(' && end ==')')||(start=='{' && end =='}'));
    }
    bool isValid(string s) {
        int n=s.length();
        if(n==0)return true;
        stack<char>st;
        for (int i = 0; i < n; i++)
        {
            char current=s[i];
            if(current=='{'||current=='['|| current=='(')st.push(current);
            else{
            if(st.empty())return false;
            else if(!check(st.top(),current))return false;
            else st.pop();
            }
        }
       return st.empty();
    }
};