class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};

        if (nums.empty())
            return ans;

        int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (first == nums.size() || nums[first] != target)
            return ans;

        int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

        ans[0] = first;
        ans[1] = last;

        return ans;
    }
};