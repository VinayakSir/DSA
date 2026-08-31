class Solution {
public:
    int search(vector<int>& v, int target) {
         int low = 0, high = v.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (v[mid] == target) return mid;
        
        if (v[low] <= v[mid]) { // Left half sorted
            if (v[low] <= target && target < v[mid]) high = mid - 1;
            else low = mid + 1;
        }
        else { // Right half sorted
            if (v[mid] < target && target <= v[high]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return -1;
    }
};