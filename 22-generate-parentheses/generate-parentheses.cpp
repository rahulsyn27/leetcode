class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve(n, 0, 0, "", result);
        return result;
    }
    void solve(int n, int open, int close, string current, vector<string> &result){
        if(current.length() == 2*n){
            result.push_back(current);
            return;
        }
        if(open < n){
            solve(n, open+1, close, current + '(', result);
        }
        if(close < open){
            solve(n, open, close+1, current + ')', result);
        }
    }
};

// 1. **Uninitialized Pointer:** When you write `vector<string> *result;`, you are declaring a *pointer* named `result`, but it doesn't point to any valid `vector<string>` object yet. It's an uninitialized pointer, and trying to use it (like `result->push_back(current);` in `solve`) will lead to undefined behavior (likely a crash).
// You need to make sure the pointer points to a valid `vector<string>` object.
// vector<string> &result: it modifies the original vector created in generateParenthesis without making a copy.