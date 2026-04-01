// class Solution {
// public:
//     int minBitFlips(int start, int goal) {
//         int temp = start ^ goal, count = 0;
//         while(temp >= 2){
//             if(temp % 2 == 1) count++;
//             temp /= 2;
//         }
//         if (temp == 1) count++;
//         return count;
        
//     }
// };

//method 2
// class Solution {
// public:
//     int minBitFlips(int start, int goal) {
//         // __builtin_popcount is the GCC/Clang equivalent if not on C++20
//         return __builtin_popcount(start ^ goal);
//     }
// };

//method 3 The Classical "Brian Kernighan’s Algorithm"
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp = start ^ goal, count = 0;
        while(temp > 0){ //this loop only runs as many times as there are set bits.
            temp &= (temp-1);
            count++;
        }
        return count;
    }
};
