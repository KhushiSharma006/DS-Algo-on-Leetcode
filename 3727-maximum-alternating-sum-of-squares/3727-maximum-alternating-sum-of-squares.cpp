class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        /*
        Key idea: Sort the squared values in ascending order, subtract the
        smallest half, and add the largest half. Use long long to avoid
        overflow. T.C. = O(nlog n) , S.C. = O(n)
        */

        int n = nums.size();
        vector<long long> sqr;
        long long ans = 0;

        for (int x : nums) {
            sqr.push_back(1LL * x * x);
        }

        sort(sqr.begin(), sqr.end());

        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                ans = ans - sqr[i];
            } else {
                ans = ans + sqr[i];
            }
        }

        return ans;
    }
};