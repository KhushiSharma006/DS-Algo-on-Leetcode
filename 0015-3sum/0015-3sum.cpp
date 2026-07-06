class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       
        /*
        Optimal: using 2 pointer approach, 
        Time Complexity: O(NlogN)+O(N2)
        Space Complexity: O(no. of quadruplets), This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1)
        */


        vector<vector<int>>ans;
        int n = nums.size();

        // sort the array to avoid duplicates
        sort( nums.begin(), nums.end());
        
        for(int i =0; i<n; i++){
            // skip duplicates for first element
            if( i > 0 && nums[i] == nums[i-1]) continue;

            // initialize 2 pointers
            int j =i+1;
            int k =n-1;
            
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum < 0) j++;

                else if(sum > 0) k--;

                // if sum=0
                else{
                    ans.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    // Skip duplicates for left "j"
                    while(j<k && nums[j] == nums[j-1]) j++;
                    // Skip duplicates for right "k"
                    while(j<k && nums[k] == nums[k+1]) k--;

                }
            }
        }

         return ans;
        
    }
};