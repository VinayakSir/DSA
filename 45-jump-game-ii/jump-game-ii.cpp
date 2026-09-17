class Solution {
public:
    int jump(vector<int>& nums) {
        
    int jumps = 0, currentEnd = 0, farthest = 0;

    for (int i = 0; i < nums.size() - 1; ++i)
    {
        farthest = max(farthest, i + nums[i]);
        if (i == currentEnd)
        {
            // We need to make a jump
            jumps++;

            // Move the current end to the farthest index we can reach
            currentEnd = farthest;
        }
    }

    // Return the total jumps needed
    return jumps;
    }
};