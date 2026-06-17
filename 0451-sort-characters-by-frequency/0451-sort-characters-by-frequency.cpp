class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> freq;

        for(char ch : s){
            freq[ch]++;
        }

        vector<pair<char,int>> v(freq.begin(), freq.end());

        sort(v.begin(), v.end(),
            [](auto &a, auto &b){
                return a.second > b.second;
            });

        string ans = "";

        for(auto &p : v){

            char ch = p.first;
            int count = p.second;

            ans.append(count, ch);
        }

        return ans;
    }
};