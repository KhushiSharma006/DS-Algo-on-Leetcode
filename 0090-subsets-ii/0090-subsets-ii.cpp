class Solution {
public:
    void findSubsets(int index, vector<int>& nums, vector<vector<int>>& ans,vector<int>& ds) {

        ans.push_back(ds);
        for(int i =index; i<nums.size(); i++){
            if(i!=index && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            findSubsets(i+1, nums, ans, ds);
            ds.pop_back();

        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubsets(0, nums, ans, ds);
        return ans;
    }
};