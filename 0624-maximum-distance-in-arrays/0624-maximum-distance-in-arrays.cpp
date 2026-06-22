class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {

        int ans = 0;

        int mini = arrays[0][0];
        int maxi = arrays[0].back();

        for(int i = 1; i < arrays.size(); i++) {

            int first = arrays[i][0];
            int last = arrays[i].back();

            ans = max(ans, abs(last - mini));
            ans = max(ans, abs(maxi - first));

            mini = min(mini, first);
            maxi = max(maxi, last);
        }

        return ans;
    }
};