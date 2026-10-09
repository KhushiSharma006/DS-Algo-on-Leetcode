class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        //T.C. = O(NlogN + MlogM + m), S.C.= O(1)
        
        int n = g.size();
        int m = s.size();
        int l =0, r = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while(l<m && r<n){
            if(g[r] <= s[l]){
                r++;
            }
            l++;
        }

        return r;
    }
};