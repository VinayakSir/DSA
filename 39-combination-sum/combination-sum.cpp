class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int idx, int target, vector<int>& candidates, vector<int>& curr) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        if (target < 0 || idx == candidates.size()) return;
        
        // pick current element
        curr.push_back(candidates[idx]);
        solve(idx, target - candidates[idx], candidates, curr);
        curr.pop_back();
        
        // skip current element
        solve(idx + 1, target, candidates, curr);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        solve(0, target, candidates, curr);
        return ans;
    }
};