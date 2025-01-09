/**
* 剑指 Offer 59 - II. 队列的最大值
 * 请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
 * 若队列为空，pop_front 和 max_value 需要返回 -1
 *
 * 思路：与 带有getMin函数的栈问题类似，  使用一个辅助队列来存放最大值， 在push_bak, pop_front时同时更新该辅助队列
 */
class MaxQueue {
    LinkedList<Integer>  dataQ;
    LinkedList<Integer>  maxQ;
    public MaxQueue() {
        dataQ = new LinkedList<Integer>();
        maxQ  =  new  LinkedList<Integer>();
    }

    public int max_value() {
        if (maxQ.isEmpty()){
            return -1;
        }
        return maxQ.getLast();
    }

    public void push_back(int value) {
        dataQ.addFirst(value);

        while(!maxQ.isEmpty() && value > maxQ.getFirst()){
            maxQ.removeLast();

        }
        maxQ.addFirst(value);
    }

    public int pop_front() {
        if (dataQ.isEmpty()){
            return -1;
        }

        int num = dataQ.removeLast();

        if(num== maxQ.getLast()){
            maxQ.removeLast();
        }

        return num;
    }
}