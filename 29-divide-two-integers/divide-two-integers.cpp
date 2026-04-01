class Solution {
public:
    int divide(int dividend, int divisor) {
        // if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        // bool sign = false;
        // long long dividend_long;
        // if(dividend == INT_MIN){
        //     dividend_long = (long long)(INT_MAX) + 1;
        //     sign = ~sign;
        // }
        // else if(dividend < 0) {
        //     sign = ~sign;
        //     dividend_long = abs(dividend);
        // }
        // if(divisor < 0){
        //     sign = ~sign;
        //     divisor = abs(divisor);
        // }

        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dividend_long = llabs((long long)dividend);
        long long divisor_long = llabs((long long)divisor);
        long long r = dividend_long, Q = 0, temp_divisor, count;

        if (dividend_long == divisor_long) {
            Q = (sign == 1) ? 1 : -1;
            return Q;
        }

        while (r >= divisor_long) {
            count = 1;
            temp_divisor = divisor_long;
            while (r >= (temp_divisor << 1)) {
                temp_divisor <<= 1;
                count <<= 1;
            }
            r -= temp_divisor;
            Q += count;
        }
        Q = (sign == 1) ? Q : -Q;
        return Q;
    }
};