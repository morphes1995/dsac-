#include <stack>
using namespace std;

/**
* 155. 最小栈
* 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
 */
class MinStack {
public:
    stack<int> s ;
    stack<int>  minStack;
    MinStack() {
    }
    void push(int val) {
        s.push(val);
        if(minStack.empty()|| val < minStack.top()){
            minStack.push(val);
        }else{
            minStack.push(minStack.top());
        }
    }

    void pop() {
        if(!s.empty()){
            s.pop();
            minStack.pop();
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minStack.top();

    }
};