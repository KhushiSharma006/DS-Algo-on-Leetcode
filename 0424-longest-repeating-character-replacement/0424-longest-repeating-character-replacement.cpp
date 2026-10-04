class Solution {
public:
    int characterReplacement(string s, int k) {
        
        //Brute Force: T.C. = O(n^2), S.C. = O(26)

        /*
        int maxLen=0;
        int n = s.size();

        for(int i =0; i<n; i++){
            int hash[26] = {0};
            int maxFreq =0;

            for(int j = i; j<n; j++){
                hash[s[j] - 'A']++;

                maxFreq = max(maxFreq, hash[s[j] - 'A']);

                int changes = (j-i+1) - maxFreq;

                if(changes <= k){
                    maxLen = max(maxLen, j-i+1);
                }
                else{
                    break;
                }
            }
        }
       return maxLen; 
       */

        //Optimal: Sliding Window + 2-pointer
        // T.C. = O((n+n)*26), S.C. = O(26)

      /*
        int l =0, r =0;
        int maxLen =0, maxFreq = 0;
        int hash[26] = {0};

        while(r < s.size()){
            hash[s[r] - 'A']++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);

            while((r-l+1) - maxFreq > k){
                hash[s[l] - 'A']--;
                maxFreq = 0;

                for(int i = 0; i<25 ;i++){
                    maxFreq = max(maxFreq, hash[i]);
                    l = l+1;
                }
            }
            if((r-l+1) -maxFreq <= k){
                maxLen = max(maxLen, r-l+1);
            }
            r++;
        }
        return maxLen;
        */

        //suppose current maxLen is 5, then we try to find larger subarrays like 6,7,8...... ,so there is no point of checking for smaller arrays, so we can use simple 'if' in place of 'while'.
        // T.C = O(n)

         int l =0, r =0;
        int maxLen =0, maxFreq = 0;
        int hash[26] = {0};

        while(r < s.size()){
            hash[s[r] - 'A']++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);

            //remove only 1 element    
            if((r-l+1) - maxFreq  > k){
                hash[s[l] - 'A']--;
                maxFreq = 0;

                l = l+1;
                
            }
            if((r-l+1) -maxFreq <= k){
                maxLen = max(maxLen, r-l+1);
            }
            r++;
        }
        return maxLen;



        
    }
};