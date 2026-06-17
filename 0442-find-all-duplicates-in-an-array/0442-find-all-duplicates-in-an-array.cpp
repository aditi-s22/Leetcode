class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;map<int, int> mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]==2) ans.push_back(nums[i]);
        }
        return ans;
        
    }
};