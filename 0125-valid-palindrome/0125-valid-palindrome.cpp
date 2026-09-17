class Solution {
public:
    bool isPalindrome(string s) {
        int left =0;
        int right = s.size();

        while(left<right){
            //Keep moving left until we find a valid letter/number
            while(left < right && !isalnum(s[left])) left++;

            //Keep moving right until we find a valid letter/number
            while(left< right && !isalnum(s[right]))right--;

            if(tolower(s[left]) != tolower(s[right])) return false;

            left++;
            right--;

        }
        return true;
        
    }
};