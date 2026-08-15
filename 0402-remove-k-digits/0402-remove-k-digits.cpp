class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(int i =0; i<num.size(); i++){
            char digit = num[i];

            while(!st.empty()  && st.top() > digit && k>0){
                st.pop();
                k--;
            }

            st.push(digit);
        }

         // If more digits can be removed
         while( !st.empty() && k > 0){
            st.pop();
            k--;
         }
        
        // edge case
        if(st.empty()) return "0";

        string ans = "";
        
        // adding digit from stack to ans
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        // trimming the zeroes at the back
        while(!ans.empty() && ans.back() == '0' && ans.size()>0){
            ans.pop_back();
        }

        // reverse the ans to get thr real number
        reverse(ans.begin(), ans.end());

        // edge case
        if(ans.empty()) return "0";

        return ans;
  
    }
};