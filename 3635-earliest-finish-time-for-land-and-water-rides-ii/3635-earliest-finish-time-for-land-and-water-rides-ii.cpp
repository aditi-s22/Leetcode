class Solution {
public:
    int solve(vector <int> &start1, vector<int> &dur1, vector<int> &start2, vector <int> &dur2){
        int m = start2.size();
        vector <pair<int, int>> rides;
        for(int i=0; i<m; i++){
        rides.push_back({start2[i], dur2[i]});
        }
        sort(rides.begin(), rides.end());
        vector <int> prefixMin(m);  // min duration 
        prefixMin[0]=rides[0].second;
        for(int i=1; i<m; i++){
            prefixMin[i]=min(prefixMin[i-1], rides[i].second);
        }

        vector<int> suffixMin(m);
        suffixMin[m - 1] = rides[m - 1].first + rides[m - 1].second;

        for(int i = m - 2; i >= 0; i--) {

            suffixMin[i] = min(suffixMin[i + 1], rides[i].first + rides[i].second);
        }
        int ans = INT_MAX;
        for(int i=0; i<start1.size(); i++){
            int finish1=start1[i]+dur1[i];
            int low=0, high=m-1;
            int idx=m;

            while(low<=high){
                int mid = (low+high)/2;
                if(rides[mid].first > finish1) {

                    idx = mid;
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }

            // Case 1:
            // rides with start <= finish1
            if(idx > 0) {

                ans = min(ans,
                          finish1 + prefixMin[idx - 1]);
            }

            // Case 2:
            // rides with start > finish1
            if(idx < m) {

                ans = min(ans,
                          suffixMin[idx]);
            }
        }

        return ans;
            }
        
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int ans1 =
            solve(landStartTime,
                  landDuration,
                  waterStartTime,
                  waterDuration);

        int ans2 =
            solve(waterStartTime,
                  waterDuration,
                  landStartTime,
                  landDuration);

        return min(ans1, ans2);
    
    }
};