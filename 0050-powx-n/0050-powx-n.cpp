class Solution {
public:
    double myPow(double x, int n) {

        double ans = 1.0;
        long long num = n;
        if(num<0) num = -1*num;
        while(num){
            // if power if even
            if(num%2){
                ans = ans*x;
                num = num-1;
            }
            else{
                x=x*x;
                num = num/2;
            }
        }
        if(n<0) ans = (double)(1.0) / (double)(ans);
        return ans;


       /* if (n == 0) return 1.0;

        // Handle negative power
        if (n < 0) {
            return 1.0 / myPow(x, -(long long)n); // avoid overflow
        }
        // (2^10 = (2*2)^5)
        if (n % 2 == 0) {
            return myPow(x * x, n / 2);
        }

        return x * myPow(x, n - 1);*/
    }
};