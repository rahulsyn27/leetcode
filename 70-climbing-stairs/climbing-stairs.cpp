class Solution {
public:
    int memo[46] = {0, 1, 2};
    
    int climbStairs(int n) {
        if(memo[n] != 0) return memo[n];
        memo[n] = climbStairs(n-1) + climbStairs(n-2);
        return memo[n];
    }
};