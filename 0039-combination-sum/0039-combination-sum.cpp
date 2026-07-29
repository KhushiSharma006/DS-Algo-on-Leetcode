class Solution {
public:
    vector<vector<int >>ans;
    vector<int>temp;
    
    void solve(vector<int>&candidates, int target, int index){
        //base case:
        if(target ==0 ){
            ans.push_back(temp);
            return;
        }

        if(index ==candidates.size() || target<0){
            return;
        }

        //pick up the current element
        temp.push_back(candidates[index]);
        solve(candidates, target-candidates[index], index);
        // dont pick the currect element
        temp.pop_back();
        solve(candidates, target, index+1);
        

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, target, 0);
        return ans;
        
    }
};