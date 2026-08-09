class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto it:s){
            if(it == '(' || it == '{' || it == '['){
                st.push(it);
            }
            else{
                if(st.empty()) return false;

                char ele = st.top();
                st.pop();
                if((it == ')' &&  ele =='(') ||
                        (it == '}' &&  ele =='{')||
                        (it == ']' &&  ele =='['))
                       continue;
                else return false;       
            }
        }
        return st.empty();
        
    }
};