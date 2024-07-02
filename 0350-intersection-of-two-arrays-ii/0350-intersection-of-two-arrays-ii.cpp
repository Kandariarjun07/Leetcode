class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> freq;
        for(auto ele : nums1){
            freq[ele]++;
        }
        for(auto it : nums2){
            if(freq[it] > 0){
                ans.push_back(it);
                freq[it]--;
            }
        }
        return ans;
    }
};