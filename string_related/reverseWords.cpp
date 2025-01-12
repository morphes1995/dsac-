/**
 *151. 反转字符串中的单词
* 剑指 Offer 58 - I. 翻转单词顺序
 * 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。
 * 例如输入字符串"I am a student. "，则输出"student. a am I"。
 * 输入字符串可以在前面或者后面包含多个多余的空格，但是反转后的字符不能包括； 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个
 */
public String reverseWords(String s) {
    if(s==null) {
        return null;
    }
    s = s.trim();
    if(s.length()==0){
        return s;
    }

    char[] chars = s.toCharArray();

    // 1. 除去多余的空格
    StringBuffer sb = new StringBuffer();
    boolean prevSpace = true;
    for(int i=0;i<chars.length;i++){
        if ((chars[i]==' ' &&  !prevSpace)  ||chars[i]!=' '){
            sb.append(chars[i]);
        }
        prevSpace = chars[i]==' '? true:false;
    }

    // 2. 整个字符串反转
    chars = sb.toString().toCharArray();
    reverse(chars,0,chars.length-1);

    // 3. 每个单词反转 （滑动窗口）
    int left=0;
    int right=0;
    while (right <= chars.length) {
        // reverse last word
        if (right == chars.length) {
            reverse(chars, left, right - 1);
            break;
        }

        if (chars[right] != ' ') {
            right++;
        } else if (chars[right] == ' ') {
            reverse(chars, left, right - 1);
            right = right + 1;
            left = right;
        }
    }

    return new String(chars);
}

private void reverse(char[] chars ,int left,int right){
    while(left<right){
        char tmp= chars[left];
        chars[left] = chars[right];
        chars[right] =tmp;

        left++;
        right--;
    }

}