/**
* 剑指 Offer 46. 把数字翻译成字符串
 * 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
 * 一个数字可能有多个翻译
 * 思路：f(i) 表示[i~n]个字符有多少种翻译方法，则 f(i) = f(i+1) + f(i+2)* g(i,i+1) ,其中g(i,i+1)表示 第i,与第i+1个字符表示的数字是否 >=10 && <=25
 *      由于f(i) 依赖 f(i+1) ，因此需要从右到左遍历，利用dp保存子集问题的中间结果避免重复计算
 *
 * 相似题目： 青蛙跳台阶问题
 *
* LCR 165. 解密数字
* 现有一串神秘的密文 ciphertext，经调查，密文的特点和规则如下：
密文由非负整数组成
数字 0-25 分别对应字母 a-z
请根据上述规则将密文 ciphertext 解密为字母，并返回共有多少种解密结果
 */
public int translateNum(int num) {
    if(num<0){
        return 0;
    }
    char[] chars = String.valueOf(num).toCharArray();

    int[] dp = new int[chars.length+1];
    dp[chars.length]=1; // dummy end， 对倒数第二个字符的count计算过程进行统一处理
    for(int i=chars.length-1;i>=0;i--){

        if(i==chars.length-1){
            dp[i]=1;
            continue;
        }

        int curNum = chars[i]-'0';
        int nextNum = chars[i+1]-'0';
        if (curNum*10 + nextNum>=10 && curNum*10 + nextNum <=25){
            dp[i]= dp[i+1]+dp[i+2];
        }else{
            dp[i]=dp[i+1];
        }
    }
    return dp[0];
}