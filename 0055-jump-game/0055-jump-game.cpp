class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx =0;

        // if the array have no zero, you will definitely go to end 
        //TC = O(n), SC = O(1)

        for(int i =0; i<nums.size(); i++){
            if(i>maxIdx) return false;

            maxIdx = max( maxIdx, i+nums[i]);
        }
        return true;
        
    }
};