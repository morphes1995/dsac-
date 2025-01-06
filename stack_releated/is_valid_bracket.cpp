#include <vector>
#include <stack>
#include <string>
using namespace std;

/**
* 20. 有效的括号
* 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (int i=0;i<s.size();i++) {
            char c = s[i];
            if(c=='('|| c=='{' || c=='['){
                stack.push(c);
            }else{
                if(stack.empty()|| !isPair(stack.top(),c)){
                    return false;
                }
                stack.pop();
            }
        }

        if(stack.empty()){
            return true;
        }
        return false;
    }

    bool isPair(char a,char b){
        if ((a=='(' && b==')')|| (a=='{' && b=='}') || (a=='[' && b==']')){
            return true;
        }
        return false;
    }
};