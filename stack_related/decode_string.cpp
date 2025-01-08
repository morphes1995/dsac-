#include <string>
#include <stack>
#include <iostream>

using namespace std;

/**
leetcode 394. 字符串解码
* 394. 字符串解码
    给定一个经过编码的字符串，返回它解码后的字符串。
    编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
    你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
    此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
 */
class Solution {
public:
    string decodeString(string s) {
        string res;
        stack<char> stack_data;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if((c>='0' && c<='9') || c=='[' || (c>='a' && c<='z')){
                stack_data.push(c);
            }else if(c==']'){
                string str;
                while(stack_data.top()>='a' && stack_data.top()<='z'){
                    str.push_back(stack_data.top());
                    stack_data.pop();
                }

                if(stack_data.top()=='['){
                    stack_data.pop();
                }

                string countStr;
                while(!stack_data.empty()&&stack_data.top()>='0' && stack_data.top()<='9'){
                    countStr.push_back(stack_data.top());
                    stack_data.pop();
                }
                reverse(countStr.begin(), countStr.end());
                int count = stoi(countStr);

                string strRepeated;
                for(int j=0;j<count;j++){
                    strRepeated.append(str);
                }

                reverse(strRepeated.begin(), strRepeated.end());

                for(int j=0;j<strRepeated.size();j++){
                    stack_data.push(strRepeated[j]);
                }
            }

        }


        while(!stack_data.empty()){
            res.push_back(stack_data.top());
            stack_data.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    string a= "3[a]2[bc]";
    Solution *s = new Solution();
    std::cout<<s->decodeString(a);

}