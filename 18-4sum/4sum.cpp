class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }

private:
    vector<vector<int>> kSum(vector<int>& nums, long long target, int start, int k) {
        vector<vector<int>> res;
        int n = nums.size();

        if (k == 2) { // 2Sum using two pointers
            int l = start, r = n - 1;
            while (l < r) {
                long long sum = nums[l] + nums[r];
                if (sum == target) {
                    res.push_back({nums[l], nums[r]});
                    l++; r--;
                    while (l < r && nums[l] == nums[l-1]) l++;
                    while (l < r && nums[r] == nums[r+1]) r--;
                }
                else if (sum < target) l++;
                else r--;
            }
            return res;
        }

        for (int i = start; i < n - k + 1; i++) {
            if (i > start && nums[i] == nums[i-1]) continue; // avoid duplicate
            // early termination checks
            if ((long long)nums[i] + (long long)nums[n-1]*(k-1) < target) continue;
            if ((long long)nums[i] * k > target) break;

            auto sub = kSum(nums, target - nums[i], i + 1, k - 1);
            for (auto &v : sub) {
                v.insert(v.begin(), nums[i]);
                res.push_back(v);
            }
        }
        return res;
    }
};