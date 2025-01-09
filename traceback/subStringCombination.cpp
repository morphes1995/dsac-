
/**
 * 字符串的组合问题 (是否有重复字符的场景)
 * 思路： 从M个不同字符中任取[1-M]个字符的所有组合
 */
public String[] combination(String s){
    if(s==null || s.length()==0){
        return new String[0];
    }

    ArrayList<String> resTmp = new ArrayList<String>();
    //        HashSet<String> resTmp = new HashSet<String>(); // 如果输入字符串中有重复字符，可以考虑使用HashSet来去重
    char[] chars = s.toCharArray();

    for(int i=1;i<=s.length();i++){
        // 获取 i个字符构成的 字符串集合
        doCombination(chars,i,0,new StringBuffer(),resTmp);
    }


    String[] res = new String[resTmp.size()];
    for(int i=0;i<res.length;i++){
        res[i]=resTmp.get(i);
    }
    return res;
}

private void doCombination(char[] chars, int length, int startIdx,StringBuffer sb,ArrayList<String> resTmp) {

    if(length==0){
        resTmp.add(sb.toString());
        return;
    }

    if(startIdx>=chars.length){
        return;
    }

    // 1. 长度为length的一个组合中包含 char[startIdx]， 递归调用时length-1
    sb.append(chars[startIdx]);
    doCombination(chars,length-1,startIdx+1,sb,resTmp);
    sb.deleteCharAt(sb.length()-1);
    // 2. 长度为length的一个组合中不包含 char[startIdx]， 递归调用时length不变
    doCombination(chars,length,startIdx+1,sb,resTmp);
}


/**
 * 剑指 Offer 38. 字符串的排列
 * 输入一个字符串，打印出该字符串中字符的所有排列。 (注意考虑输入字符串是否包含重复字符,字符的范围 a-z ? A-Z ? 特殊字符？  )
 * 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
 */
public String[] permutation(String s) {
    if(s==null || s.length()==0){
        return new String[0];
    }

    ArrayList<String> resTmp = new ArrayList<String>();
    char[] chars = s.toCharArray();

    doPermutation(chars,0,resTmp);

    String[] res = new String[resTmp.size()];
    for(int i=0;i<res.length;i++){
        res[i]=resTmp.get(i);
    }
    return res;
}

private void doPermutation(char[] chars,int startIdx,ArrayList<String> resTmp){
    if(startIdx==chars.length){
        resTmp.add(new String(chars));
    }
    // 在chars[:startIdx-1] 确定的情况下，char[startIdx]不能出现重复的字符，
    // 如果char[startIdx]出现了2个重复字符， 则以chars[:startIdx]为前缀的字符排列均会出现两次
    boolean[] visited =new boolean[26];
    for(int i=startIdx;i<chars.length;i++){
        if(visited[chars[i]-'a']){
            continue;
        }
        visited[chars[i]-'a']=true;
        swap(chars,i,startIdx);
        doPermutation(chars,startIdx+1,resTmp);
        swap(chars,startIdx,i);
    }
}

private void swap(char[] chars,int x,int y){
    char tmp =chars[x];
    chars[x]=chars[y];
    chars[y]=tmp;
}

