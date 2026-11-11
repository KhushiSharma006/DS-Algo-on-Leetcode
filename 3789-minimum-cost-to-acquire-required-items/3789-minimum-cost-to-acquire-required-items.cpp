
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        // Option 1: Buy individual items
        long long a = 1LL * need1 * cost1 + 1LL * need2 * cost2;

        // Option 2: Buy common items for overlapping requirements
        int common = min(need1, need2);

        long long b = 1LL * common * costBoth
                    + 1LL * (need1 - common) * cost1
                    + 1LL * (need2 - common) * cost2;

        // Option 3: Buy only type 3 items
        long long c = 1LL * max(need1, need2) * costBoth;

        return min({a, b, c});
    }
};
