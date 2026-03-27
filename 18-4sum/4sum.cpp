class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        int left, right, n = nums.size();
        long long remaining;
        for (int i = 0; i < n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n; j++){
                if(j>i+1 && nums[j] == nums[j-1]) continue;

                remaining = (long long)target - nums[i] - nums[j];
                left = j+1; right = n-1;
                while(left < right){
                    if(nums[left] + nums[right] == remaining){
                        results.push_back({nums[i], nums[j],nums[left], nums[right]});
                        left++; right--;
                    
                    
                    while(left < right && nums[left] == nums[left-1]){
                        left++;
                    } 
                    while(left < right && nums[right] == nums[right+1]) {
                        right--;
                    }
                    }
                    else if(nums[left] + nums[right] < remaining) left++;
                    else if(nums[left] + nums[right] > remaining) right--;

                    
                }
            }
        }
        return results;
        
    }
};