

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        
        set<int> available;
        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> busy;

        vector<int> count(k, 0);

        // Initially, all servers are available
        for(int i = 0; i < k; i++) {
            available.insert(i);
        }

        for(int i = 0; i < arrival.size(); i++) {

            // Release servers whose requests are completed
            while(!busy.empty() && busy.top().first <= arrival[i]) {
                int server = busy.top().second;
                busy.pop();
                available.insert(server);
            }

            if(available.empty()) {
                continue;
            }

            // Preferred server
            int target = i % k;

            // Find next available server
            auto it = available.lower_bound(target);

            // Wrap around if necessary
            if(it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // Assign request
            available.erase(it);
            count[server]++;

            // Store finishing time
            busy.push({arrival[i] + load[i], server});
        }

        // Find maximum number of requests handled
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            if(count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
