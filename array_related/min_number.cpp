#include <string>
#include <vector>
using namespace  std;

/**
* 剑指 Offer 45. 把数组排成最小的数
 * 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个
 *
 */
class Solution {
public:
    static bool cmp(string &a, string &b){
        return a+b<b+a;
    }
    string crackPassword(vector<int>& password) {
        vector<string> strs;
        for(int val :password){
            strs.push_back(to_string(val));
        }
        sort(strs.begin(),strs.end(), cmp);
        // sort(strs.begin(), strs.end(), [](string& x, string& y){ return x + y < y + x; });

        string res;
        for(string str:strs){
            res+=str;
        }

        return res;
    }
};