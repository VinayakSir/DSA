
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();

        // Sort the array to make it easier to skip duplicates and use two pointers
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicate elements for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i]; // We want nums[j] + nums[k] == -nums[i]
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for the second number
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    // Skip duplicates for the third number
                    while (left < right && nums[right] == nums[right - 1]) --right;

                    ++left;
                    --right;
                } 
                else if (sum < target) {
                    ++left;
                } 
                else {
                    --right;
                }
            }
        }

        return result;
    }
};