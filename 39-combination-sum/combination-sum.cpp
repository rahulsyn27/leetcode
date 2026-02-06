class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        combination(candidates, target, 0, current, result, 0);
        return result;
        
    }
    void combination(vector<int>& candidates, int target, int sum, vector<int> &current, vector<vector<int>> &result, int start){
        
        if(sum == target){
            result.push_back(current);
            return; 
        }
        for(int i = start; i < candidates.size(); i++){
            if(sum+candidates[i] > target){
            continue;
            }
            current.push_back(candidates[i]);
            combination(candidates, target, sum + candidates[i], current, result, i);
            current.pop_back();


        }
    }
};