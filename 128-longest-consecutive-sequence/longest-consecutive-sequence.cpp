// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int count = 1, res = 0;
//         unordered_set<int> s;
//         for (int n : nums){
//             s.insert(n);
//         }
//         for(auto it = s.begin(); it != s.end(); it++){
//             int temp = *it;
//             if(!s.count(temp-1)){
//                 while(s.count(++temp)){
//                     count++;
//                 }
//                 res = max(res, count);
//                 count = 1;
//             }
//         }
//         return res;
//     }
// };

// Clean version 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; // Explicitly handle empty case for clarity
        
        unordered_set<int> s(nums.begin(), nums.end()); // Initialize set directly
        
        int longest = 0;

        for (int num : s) {
            // Check if this is the start of a sequence
            if (!s.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                // Count upwards
                while (s.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longest = max(longest, currentStreak);
            }
        }
        return longest;
    }
};