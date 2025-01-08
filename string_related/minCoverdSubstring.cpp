#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
/**
* leetcode 76. 最小覆盖子串
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
 * 如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须 `不少于`  t中该字符数量
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案
 *
 * 思路： 使用滑动窗口 + 2个hashMap
 */
string minWindow(string s, string t) {

    std::unordered_map<char, int>tMap;// 统计字符串t中每个字符出现的频率
    for(int i=0;i<t.size();i++){
        tMap[t[i]]++;
    }
    // 当前发现的最小覆盖子串 的索引范围
    int minLeft=0;
    int minRight =s.size()-1;
    bool found = false;

    std::unordered_map<char, int>sMap;; // 统计当前 滑动窗口s[left,right]中每个字符出现的频率
    int left =0;
    int count=0; // 统计当前滑动窗口中的字符，匹配字符串t中的字符个数
    for(int right=0;right<s.size();right++){
        sMap[s[right]]++; // 更新 右边界字符 在sMap中的频率

        if(sMap[s[right]]<=tMap[s[right]]) count++; // 右边界字符 包含在 t中

        // 如果 左边界字符是 不需要的，窗口的左边界右移
        while(left<=right && sMap[s[left]] > tMap[s[left]]){
            sMap[s[left]]--;
            left ++;
        }

        if(count == t.length()){ // 当前滑动窗口包含了t中的所有字符
            found =true;
            if(right-left<minRight-minLeft){ // 如果当前滑动窗口表示的字符串更短，则更新 当前发现的最小覆盖子串
                minRight = right;
                minLeft = left;
            }
        }
    }
    if(!found) return "";
    // substr(pos,n)与java的substring不一样
    return s.substr(minLeft,minRight-minLeft+1);
}

int main() {
    // cout<<minWindow("abc","b");
    // cout<<minWindow("a","a");
    for (int i=0;i<10;i++) {
        cout<<((double)rand() / (RAND_MAX))<<endl;
    }

}
