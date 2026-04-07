class Solution {
public:
    int countPrimes(int n) {
        if(n < 2) return 0;
        vector<bool> isPrime(n, true);
        int x, count = 0;
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i < n; i++){
            if(isPrime[i] == true) {
                count++;
                x = 2;
                while(i*x < n){
                    isPrime[i*x++] = false;
                }
            }
        }
        return count;
        
    }
};