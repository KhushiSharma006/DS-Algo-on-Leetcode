class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // take a hash and initialize with -1
        int lastSeen[256];
        fill(lastSeen, lastSeen + 256, -1);


        int n = s.size();
        int l =0, r =0;
        int maxLen =0;

        while(r<n){
            // If char was seen inside current window
            if(lastSeen[s[r]] != -1){ 
                if(lastSeen[s[r]] >= l){ 
                    // Move left pointer
                    l = lastSeen[s[r]]+1;
                }
            }

            int len = r-l+1;//current window length
            maxLen = max(len, maxLen);

            // Update last seen index
            lastSeen[s[r]] = r;
            r++;
        }
        return maxLen;
        
    }
};