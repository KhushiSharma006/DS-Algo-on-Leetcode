class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // Brute Force: compute k 
        // T.C. = O(n^2)
/*
        int n = nums.size();
        int maxLen =0;

        for(int i =0; i<n; i++){
            int zero =0;
            for(int j =i; j<n; j++){
                if( nums[j] == 0){
                    zero++;
                }
                if(zero <= k){
                    int len = j-i+1;
                    maxLen = max(len, maxLen);
                }
                else{
                    break;
                }
            }
        }  
        return maxLen;   
*/

    //Better: Sliding window
    // T.C. = O(2n)
    int maxLen =0;
    int l =0, r = 0;
    int zeros =0;

    
    while(r < nums.size()){
        if(nums[r] == 0) {
            zeros++;
        }
        while(zeros > k ){
            if(nums[l] == 0) zeros--;
            l++;
        }
        if(zeros <= k){
            int len = r-l+1;
            maxLen = max(maxLen, len);
        }
        r++;
    }
    return maxLen;






    }
};