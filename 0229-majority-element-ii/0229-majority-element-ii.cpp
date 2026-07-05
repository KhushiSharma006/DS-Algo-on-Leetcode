class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        //  using Boyer-Moore Voting Algorithm for optimal solution
        // phase1: find potential candidate-  which is atmost the floor value of (n/3)
        int n =nums.size();
        int cnt1 =0, cnt2 =0;
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;

        for(int i =0; i<n; i++){
            if(cnt1 ==0 && ele2 != nums[i] ){
                ele1= nums[i];
                cnt1++;
            }else if(cnt2 ==0 && ele1 != nums[i]){
                ele2 =nums[i];
                cnt2++;
            }

            else if(ele1 == nums[i] ){
                cnt1++;
            }else if(ele2 == nums[i]){
                cnt2++;
            }
            else cnt1--, cnt2-- ;
        }


        // phase2: verification of potential candidates
        vector<int> ls;
        cnt1 =0, cnt2 =0;
      
        for(int i =0; i<n; i++){
            if(ele1 == nums[i]) cnt1++;
            if(ele2 == nums[i]) cnt2++;
        }
        
        int mini = int(n/3)+1;
        if(cnt1 >= mini){
            ls.push_back(ele1);
        }
        if(cnt2 >= mini){
            ls.push_back(ele2);
        }

        sort(ls.begin(), ls.end());
        return ls;
        
    }
};