class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
      
       vector<int>st;

        for(int i =0; i<n; i++){
            if(asteroids[i] > 0){
                st.push_back(asteroids[i]);
            }

            else{
                /* Until the right moving asteroids are 
                smaller in size, keep on destroying them */ 
                while(!st.empty() && st.back() > 0 && st.back()< abs(asteroids[i])){
                    st.pop_back();
                }

                if(!st.empty() && st.back() == abs(asteroids[i])){
                     // Destroy both the asteroids
                    st.pop_back();
                }
                 
                  /* Otherwise, if there is no left
                moving asteroid, the right moving 
                asteroid will not be destroyed */
                else if(st.empty() || st.back() < 0){
                    // Storing the array in final state
                    st.push_back(asteroids[i]);
                }

            }
        }

        return st;
        
    }
};