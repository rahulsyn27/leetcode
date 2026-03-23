class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix;
        int result = 0, current = 0;
        prefix[0] = 1;
        for (int i = 0; i < nums.size(); i++){
            current += nums[i];
            if (prefix.find(current - k) != prefix.end()) result += prefix[current - k];
            prefix[current]++;
            
        }
        return result;
    }
};