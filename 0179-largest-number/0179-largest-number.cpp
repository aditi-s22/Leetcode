class Solution {
    static bool cmp(string a, string b) { return a + b > b + a; }

public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        string ans = "";
        for (int x : nums) {
            s.push_back(to_string(x));
        }
        sort(s.begin(), s.end(), cmp);
        for (string st : s) {
            ans=ans + st;
        }
        if(ans[0] == '0') return "0";
        return ans;
    }
};