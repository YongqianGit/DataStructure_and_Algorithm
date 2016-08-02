double calc_pow(double x, int n) {
        if (n == 0) return 1;
        
        double res = calc_pow(x, n / 2);
        res *= res;
        if (n % 2 != 0) {
            res *= x;
        }
        return res;
    }

double myPow(double x, int n) {
        return n > 0? calc_pow(x, n): 1 / calc_pow(x, n);
    }
