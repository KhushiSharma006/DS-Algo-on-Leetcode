class Solution {
public:
    bool isValid(string s) {

        stack<char>st;
        unordered_map<char, char>pair{{')','('},{'}','{'},{']','['}};

        for(char c: s){
            if(c == '(' || c == '{' || c == '[') st.push(c);
            else{
                if(st.empty() || st.top() != pair[c]){
                    return false;
                }
                st.pop();
            }
         
          
        }
         return st.empty();
        





        /* stack<char>st;
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
        return st.empty();*/
        
    }
};