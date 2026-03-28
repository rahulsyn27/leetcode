// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         unordered_map<int, int> mp;
//         int left = 0, right = 0, maxFruits = 0;
//         while (right < fruits.size()){
//             if(mp.count(fruits[right]) || mp.size() < 2){
//                 mp[fruits[right++]]++;
//             }
//             else{
//                 mp[fruits[left]]--;
//                 if(mp[fruits[left]] == 0) mp.erase(fruits[left]);
//                 left++;
//             }
//             maxFruits = max(maxFruits, right-left);
//         }
//         return maxFruits;
//     }
// };

class Solution{
public:
    int totalFruit(vector<int>& fruits){
        int left = 0, right = 0;
        unordered_map<int, int> count;
        for(right = 0; right < fruits.size(); right++){
            count[fruits[right]]++;
            if(count.size() > 2){
                if(--count[fruits[left]] == 0) count.erase(fruits[left]);
                left++;
                
            }
        }
        return right-left;
    }
};
/* * Approach: Non-Shrinking Sliding Window
 * * 1. Use 'right' to expand the window and a hash map to track fruit frequencies.
 * 2. If the number of unique fruits exceeds 2, we don't fully shrink the window.
 * Instead, we shift 'left' forward by one position to maintain the current 
 * maximum window size.
 * 3. The window only grows when the unique fruit count is <= 2.
 * 4. Final result is 'right - left', representing the maximum width achieved.
 * * Time Complexity: O(n) - Each element is visited at most twice.
 * Space Complexity: O(1) - The map stores at most 3 distinct keys.
 */