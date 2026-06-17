class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string curr = "";
        vector<string> words;
        for (char c : s) {
            if (c != ' ')
                curr += c;
            else if (!curr.empty()) {
                words.push_back(curr);
                curr = "";
            }
        }
        if (!curr.empty())
            words.push_back(curr);
        reverse(words.begin(), words.end());
        string ans = "";
        for (int i = 0; i < words.size(); i++) {
            if (i > 0)
                ans += " ";
            ans += words[i];
        }
        return ans;
    }
};