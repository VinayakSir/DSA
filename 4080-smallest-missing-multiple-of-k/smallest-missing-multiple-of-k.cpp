class Solution {
public:
  int missingMultiple(vector<int>& v, int k) {  
   int n=v.size();
    set<int>st;
    for (int i = 0; i < n; i++)    st.insert(v[i]);
    int j=1;
    for(auto &ele:st){
        if(st.find(j*k)!=st.end())j++;
        else return j*k;
    }
    int r=st.size();
    return r*k +k;
}
};