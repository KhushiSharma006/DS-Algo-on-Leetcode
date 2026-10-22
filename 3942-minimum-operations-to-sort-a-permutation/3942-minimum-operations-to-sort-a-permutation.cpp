class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int k = nums[0];

        bool increasing = true, decreasing = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (k + i) % n)
                increasing = false;

            if (nums[i] != (k - i + n) % n)
                decreasing = false;
        }

        if (!increasing && !decreasing)
            return -1;

        if (increasing && k == 0)
            return 0;

        return min(n - k, k + 2);
    }
};