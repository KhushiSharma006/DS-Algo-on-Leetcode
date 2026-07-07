class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m;
      
        for(int j=0; j<n; j++){
            swap(nums1[i], nums2[j]);
            i++;
        }
        sort(nums1.begin(), nums1.end());


        
       //optimal soln 1: works if the 0s are considered T.C.=O(2(nlogn)+ n)
       /*
        int left = m - 1;
        int right = 0;
        while(left>=0 && right<n){
            if(nums1[left] > nums2[right]){
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            }
            else {
                break;
            }
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        */
        
    }
};