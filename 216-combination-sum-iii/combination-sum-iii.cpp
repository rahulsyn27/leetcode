class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> current;
        vector<vector<int>> result;
        backtrack(k, n, current, result, 0, 1, 0);
        return result;
        
    }
    void backtrack(int k, int n,vector<int> &current, vector<vector<int>> &result, int count, int itre, int sum){
        if(count > k) return;
        if(sum == n && count == k){
            result.push_back(current);
            return;
        }
        for(int i = itre; i < 10; i++){
            if(sum + i > n) return;
            current.push_back(i);
            backtrack(k, n, current, result, count+1, i+1, sum+i);
            current.pop_back();
        }

        
    }
};