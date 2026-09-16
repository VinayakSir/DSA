class Solution {
public:
    int maxSubArray(vector<int>& v) {
          int sum = 0;
    int maxsum = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        if (sum > maxsum)   maxsum = sum;
        if (sum < 0)         sum = 0;
    }
    return maxsum;
    }
};