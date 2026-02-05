class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> initial; //so that i can pass a null vector
        power(initial, 0, nums, nums.size());
        return result;
    }
    void power(vector<int> &current, int i, vector<int> nums, int n){
        if(i == n){
            result.push_back(current);
            return;
        }
        
        power(current, i+1, nums, n);
        current.push_back(nums[i]);
        power(current, i+1, nums, n);
        current.pop_back();
    }
};

