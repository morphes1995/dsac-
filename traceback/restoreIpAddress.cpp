#include <vector>
#include <list>
#include <string>
using namespace std;

/**
*93. 复原 IP 地址
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，
但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，
这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
 */
class Solution {
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        list<string> curIP;
        dfs(res,s,0,curIP);
        return res;
    }

    void dfs(vector<string> &res,string s,int startIdx,list<string>  &curIp){

        if(startIdx==s.length()){
            if(curIp.size()==4){
                string ip;

                for (string part: curIp) {
                    ip.append(part);
                    ip.push_back('.');
                }
                res.push_back(ip.substr(0,ip.size()-1));
            }

            return;
        }

        if(s[startIdx]=='0'){
            curIp.push_back("0");
            dfs(res,s,startIdx+1,curIp);
            curIp.pop_back();
            return;
        }

        int sub =0;
        for(int i= startIdx,count=1;i<s.length();i++,count++){

            char c = s[i];
            sub = sub*10 + (c-'0');
            if (sub>255){
                break;
            }

            curIp.push_back((to_string(sub)));
            dfs(res,s,startIdx+count,curIp);
            curIp.pop_back();
        }

    }
};