/**
* leetcode 415. 字符串相加 (leetcode 2.两个链表表示的数相加)
     * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
     */
    public String addStrings(String num1, String num2) {

        char[] chars1 = num1.toCharArray();
        char[] chars2 = num2.toCharArray();

        StringBuilder sb = new StringBuilder();
        int carry =0;// 进位
        int tail1= chars1.length-1;
        int tail2 =chars2.length-1;
        while(tail1>=0 && tail2>=0){
            int n1 = chars1[tail1--]-'0';
            int n2 = chars2[tail2--]-'0';
            sb.append((n1+n2+carry)%10);
            carry = (n1+n2+carry)/10;
        }

        while(tail1>=0){
            int n1 = chars1[tail1--]-'0';
            sb.append((n1+carry)%10);
            carry = (n1+carry)/10;
        }
        while(tail2>=0){
            int n2 = chars2[tail2--]-'0';
            sb.append((n2+carry)%10);
            carry = (n2+carry)/10;
        }

        if(carry>0){
            sb.append(carry);
        }

        return sb.reverse().toString();
    }