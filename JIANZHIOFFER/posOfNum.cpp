#include <algorithm>
using namespace std;

/**
 *
* leetcode 50. Pow(x, n)
实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，xn ）

 * 剑指 Offer 16. 数值的整数次方
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。
 */

class Solution {
public:
    double myPow(double x, int n) {
        bool isNagitive = n>=0? false : true;
        double res = pow(x, abs((long)n)); // 转为long，防止越界
        if(isNagitive){
            res = 1.0/res;
        }
        return res;

    }
    // O(logn) 求 x的n次方
    // a^n  =  a ^ n/2 *  a ^ n/2  , n为偶数
    // a^n  =  a^(n-1)/2  *  a^(n-1）/2  * a , n为奇数  (n-1)/2  == n/2
    double pow(double x, long n){
        if(n==0){
            return 1;
        }
        if(n==1){
            return x;
        }

        double res = pow(x,n>>1);
        res *= res;
        if( (n & 1) ==1){
            res *= x; // n为奇数的情况
        }
        return res;
    }


};