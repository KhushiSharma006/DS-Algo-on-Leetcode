class Solution {
public:
    const int MOD = 1e9 + 7;

    long long nCr[1001][1001];

    int solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return 1;

        vector<int> left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long ways = nCr[n - 1][left.size()];

        ways = ways * solve(left) % MOD;
        ways = ways * solve(right) % MOD;

        return ways;
    }

    int numOfWays(vector<int>& nums) {
        for (int i = 0; i <= 1000; i++) {
            nCr[i][0] = nCr[i][i] = 1;

            for (int j = 1; j < i; j++) {
                nCr[i][j] =
                    (nCr[i - 1][j - 1] + nCr[i - 1][j]) % MOD;
            }
        }

        return (solve(nums) - 1 + MOD) % MOD;
    }
};