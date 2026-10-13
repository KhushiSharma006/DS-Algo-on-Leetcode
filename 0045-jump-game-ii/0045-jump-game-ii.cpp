class Solution {
public:
    int jump(vector<int>& nums) {
        //Track the farthest position reachable within the current jump range. When you reach the end of that range, take another jump and extend the range to farthest.
       
        int n = nums.size();
        int jumps = 0;
        int farthest = 0;
        int end = 0;

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            if (i == end) {
                jumps++;
                end = farthest;
            }
        }

        return jumps;
        
    }
};