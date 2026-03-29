// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int left = 0, right = 0, start = INT_MAX, changeCount = 0, maxlen = 0;
//         char current = s[0];
//         while (right < s.size()){
//             if(s[right] == current){
//                 right++;
//             }
//             else if(changeCount < k){
//                 start = min(start, right);
//                 right++;
//                 changeCount++;
//             }
//             else{
//                 start = min(start, right);
//                 left = start;
//                 right = start;
//                 changeCount = 0;
//                 current = s[left];
//                 start = INT_MAX;
//             }
//             maxlen = max(maxlen, right - left);
//         }
//         return maxlen;
//     }
// }; not gonna work for "ABBB"

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0, maxCount = 0, maxlen = 0;
        
        for (int right = 0; right < s.size(); right++) {
            // Update frequency of the current character
            maxCount = max(maxCount, ++count[s[right] - 'A']);
            
            // If the window is invalid, shrink it from the left
            while ((right - left + 1) - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }
            
            // Update the global maximum length
            maxlen = max(maxlen, right - left + 1);
        }
        
        return maxlen;
    }
};