class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Sliding Window: max lenght subarray with atmost 2 (number of buckets) types of element

        int l =0, r = 0;
        int maxLen =0;
        unordered_map<int, int> mpp;

        while(r < fruits.size()){
            mpp[fruits[r]]++;

            if(mpp.size() > 2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
                l++;
            }

            if(mpp.size() <= 2){
                maxLen = max(maxLen, r-l+1);

            }
            r++;

        }

        return maxLen;
        
    }
};