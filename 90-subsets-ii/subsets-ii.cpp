class Solution {
vector<vector<int>> result;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> current;
        sort(nums.begin(), nums.end());
        backtrack(0, current, nums);
        return result;
        
    }
    void backtrack(int start, vector<int>& current, vector<int>& nums){
        result.push_back(current);
        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i] == nums[i-1]) continue;
            current.push_back(nums[i]);
            backtrack(i+1, current, nums);
            current.pop_back();
        }
    }
};