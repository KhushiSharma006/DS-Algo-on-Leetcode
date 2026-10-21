class Solution {
public:
    int minOperations(string s) {
        string t = s;
        sort(t.begin(), t.end());

        if (s == t) return 0;

        int n = s.size();

        if (n == 2) return -1;

        char mn = t[0];
        char mx = t[n - 1];

        if (s[0] == mn || s[n - 1] == mx)
            return 1;

        if (s[0] == mx && s[n - 1] == mn) {
            int minCount = count(s.begin(), s.end(), mn);
            int maxCount = count(s.begin(), s.end(), mx);

            if (minCount == 1 && maxCount == 1)
                return 3;
        }

        return 2;
    }
};