// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         int n = nums.size();
//         for(int i = 0; i < n; i++){
//             if(mp.count(nums[i])){
//                 mp.erase(nums[i]);
//             }
//             else{
//                 mp[nums[i]] = 1;
//             }
//         }
//         auto it = mp.begin();
//         return it->first;
//     }
// };

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            res ^= num; // duplicates cancel out
        }
        return res;
    }
};
//0 ^ 4 ^ 1 ^ 2 ^ 1 ^ 2 = 4.