class Solution {
public:
    int majorityElement(vector<int>& v) {
         int n=v.size();
    if(n==0)return -1;
    if(n==1)return v[0];
    int element=0;int count=0;
    for (int i = 0; i < n; i++)
    {
        if(count==0){
            element=v[i];
            count=1;
        }
        else if(v[i]==element)count++;
        else count--;
    }
    int c=0;
    for (int i = 0; i <n; i++)    if(v[i]==element)c++;
    if(c>n/2)return element;
    else return -1;
    
    }
};