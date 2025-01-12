/**
 *LCR 182. 动态口令
* 剑指 Offer 58 - II. 左旋转字符串
 * 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
 * 比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"
 *
 * 思路：基于字符串反转的思想，将字符串的前面部分和后面部分分别反转
 */
public String reverseLeftWords(String s, int n) {

    if(s==null || n<0 || s.length()<n){
        throw new RuntimeException("invalid params");
    }

    char[] chars = s.toCharArray();

    // 先分别反转前后两部分，再反转整个字符串
    reverse(chars,0,n-1);
    reverse(chars,n,s.length()-1);
    reverse(chars,0,s.length()-1);


    // 先反转整个字符串，再分别反转前后两部分
    // reverse(chars,0,s.length()-1);
    // reverse(chars,0,s.length()-1-n);
    // reverse(chars,s.length()-n,s.length()-1);


    return new String(chars);
}