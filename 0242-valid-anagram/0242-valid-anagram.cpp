class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        int freq[26] = {0};

        /* +1 for every character in s
           -1 for every character in t

        If they're anagrams, every frequency ends at 0.

         Complexity
          Time: O(n)
         Space: O(1) → only 26 positions*/

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (int it : freq) {
            if (it != 0) {
                return false;
            }
        }

        return true;
    }
};