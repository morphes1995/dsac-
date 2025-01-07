/**
*LCR 165. 解密数字
已解答
中等
相关标签
相关企业
现有一串神秘的密文 ciphertext，经调查，密文的特点和规则如下：

密文由非负整数组成
数字 0-25 分别对应字母 a-z
请根据上述规则将密文 ciphertext 解密为字母，并返回共有多少种解密结果。
*/

class Solution {
    public int translateNum(int num) {
        char[] chars =String.valueOf(num).toCharArray();
        return translate(chars,0);
    }
    // 从左到右递归尝试
    private int translate(char[] chars,int idx){
        if(idx>=chars.length){
            return 1;
        }
        int res=0;
        if(chars[idx]=='1'){
            //  翻译为b,
            res += translate(chars,idx+1);
            if (idx+1<chars.length){
                // chars[idx],chars[idx+1] 一块进行翻译
                res += translate(chars,idx+2); // chars[idx,idx+1] = [10, 19]
            }
        }else if (chars[idx]=='2'){
            // 将 chars[idx] 翻译为c,
            res += translate(chars,idx+1);
            if (idx+1<chars.length && chars[idx+1]<='5'){ //chars[idx,idx+1]= [20,25]
                // chars[idx],chars[idx+1] 一块进行翻译
                res += translate(chars,idx+2);
            }
        }else{
            // chars[idx] 为 '0' ， '3' ~'9' 的情况 ，只能将 将 chars[idx] 进行单独翻译
            res += translate(chars,idx+1);
        }
        return res;
    }

}