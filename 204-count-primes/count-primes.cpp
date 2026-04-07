// class Solution {
// public:
//     int countPrimes(int n) {
//         if (n < 2)
//             return 0;
//         vector<bool> isPrime(n, true);
//         int x, count = 0;
//         isPrime[0] = isPrime[1] = false;
//         for (int i = 2; i < n; i++) {
//             if (isPrime[i] == true) {
//                 count++;
//                 x = 2;
//                 while (i * x < n) {
//                     isPrime[i * x++] = false;
//                 }
//             }
//         }
//         return count;
//     }
// };

// more efficient method is to check only till p*p
class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;

        vector<bool> prime(n,true);
        prime[0] = prime[1] = false;

        // Apply Sieve of Eratosthenes
        for (int p = 2; p * p <= n; p++) {
            if (prime[p]) {

                // Mark all multiples of p as not prime
                for (int i = p * p; i < n; i += p) {
                    prime[i] = false;
                }
            }
        }

        int count = 0;
        for (int p = 2; p < n; p++) {
            if (prime[p]) {
                count++;
            }
        }

        return count;
    }
};