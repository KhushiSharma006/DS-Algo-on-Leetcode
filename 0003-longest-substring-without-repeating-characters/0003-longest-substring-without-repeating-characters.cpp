class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastSeen[256];
        fill(lastSeen, lastSeen + 256, -1);


        int n = s.size();
        int l =0, r =0;
        int maxLen =0;

        while(r<n){
            if(lastSeen[s[r]] != -1){
                if(lastSeen[s[r]] >= l){
                    l = lastSeen[s[r]]+1;
                }
            }
            int len = r-l+1;
            maxLen = max(len, maxLen);
            lastSeen[s[r]] = r;
            r++;
        }
        return maxLen;
        
    }
};