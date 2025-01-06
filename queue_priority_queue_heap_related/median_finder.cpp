#include <queue>
using namespace std;

/**
* 295. 数据流的中位数
* 中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。
例如 arr = [2,3,4] 的中位数是 3 。
例如 arr = [2,3] 的中位数是 (2 + 3) / 2 = 2.5 。
实现 MedianFinder 类:
MedianFinder() 初始化 MedianFinder 对象。
void addNum(int num) 将数据流中的整数 num 添加到数据结构中。
double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10-5 以内的答案将被接受。
 */
class MedianFinder {
public:
    priority_queue<int,vector<int>, less<int>> biggerHeap ; // small part
    priority_queue<int,vector<int>, greater<int>> smallHeap ; // bigger part
    MedianFinder() {
    }
    void addNum(int num) {
        if(biggerHeap.empty()){
            biggerHeap.push(num);
        }else{
            if (num > biggerHeap.top()){
                smallHeap.push(num);
            }else{
                biggerHeap.push(num);
            }
        }


        int size1 = smallHeap.size();
        int size2 = biggerHeap.size();

        if(size1-size2>1){
            biggerHeap.push(smallHeap.top());
            smallHeap.pop();
        }

        if(size2-size1>1){
            smallHeap.push(biggerHeap.top());
            biggerHeap.pop();
        }
    }

    double findMedian() {
        int size1 = smallHeap.size();
        int size2 = biggerHeap.size();

        if(size1-size2==1){
            return smallHeap.top();
        }

        if(size2-size1==1){
            return biggerHeap.top();
        }

        return (smallHeap.top()+biggerHeap.top())/2.0;
    }
};