class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> hash;
        for(char c : text){
            hash[c]++;
        }
        return(min(hash['b'], min(hash['a'], min(hash['l']/2, min(hash['o']/2, hash['n'])))));
    }
};