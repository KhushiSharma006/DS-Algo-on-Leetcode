class Solution {
public:
    int numberOfSubstrings(string s) {

        // with every character,  there is a substring that ends
        int lastSeen[3] = {-1, -1, -1};
        int count = 0;

        for (int i = 0; i < s.size(); i++) {

            lastSeen[s[i] - 'a'] = i;

            // All three characters are present
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {

                count += 1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
            }
        }

        return count;
    }
};