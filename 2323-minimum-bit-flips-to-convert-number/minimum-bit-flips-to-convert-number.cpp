class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp = start ^ goal, count = 0;
        while(temp >= 2){
            if(temp % 2 == 1) count++;
            temp /= 2;
        }
        if (temp == 1) count++;
        return count;
        
    }
};