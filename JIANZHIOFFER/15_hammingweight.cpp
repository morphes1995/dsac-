/**
*191. 位1的个数
给定一个正整数 n，编写一个函数，获取一个正整数的二进制形式并返回其二进制表达式中
设置位的个数（也被称为汉明重量）。
 *
* 剑指 Offer 15. 二进制中1的个数
 * 编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为 汉明重量).）。
 */
public int hammingWeight(int n) {
    int count =0;
    while(n!=0){ // n的二进制表示中 所有bit位全为0 为终止条件
        n = (n-1)&n;  // 每次将n的二进制表示中的 最右侧的1置为0
        count++;
    }
    return count;

}

public int hammingWeight2(int n){
    int count =0;
    while(n!=0){
        if((n&1)!=0){
            count++;
        }

        n = n >>>1;  // 无符号右移，高位补0

    }
    return count;
}