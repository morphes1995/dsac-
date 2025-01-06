#include <iostream>
#include <unordered_map>
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
*146. LRU 缓存
* 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
* 实现 LRUCache 类：
* LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
* int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
* void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
* 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
*/

class LRUCache {
public:
    struct Node{
        Node *prev;
        Node *next;
        int key;
        int val;
        Node():prev(nullptr),next(nullptr){
            // 指针显示赋值nullptr 解决leetcode
            // runtime error: member access within misaligned address 0xbebebebebebebebe for type 'struct ListNode',
            // which requires 8 byte alignment [ListNode.c] 0xbebebebebebebebe
        }
        Node(int k, int v):key(k),val(v),prev(nullptr),next(nullptr){}
    };

    std::unordered_map<int, Node*> data;
    Node *head;
    Node *tail;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new Node();
        this->tail = new Node();
        head->next = tail;
        tail->prev = head;

    }
    ~LRUCache() {
        delete head;
        delete tail;
    }

    void remove(Node *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
        data.erase(node->key);
    }

    void addToTail(Node *node){
        node->prev = tail->prev;
        tail->prev->next = node;

        node->next = tail;
        tail->prev = node;
        data.emplace(node->key, node);
    }

    int get(int key) {
        if(data.contains(key)){
            Node *node = data[key];
            remove(node);
            addToTail(node);
            return node->val;
        }

        return -1;
    }

    void removeFirst(){
        if (head->next==tail){
            return;
        }
        remove(head->next);
    }

    void put(int key, int value) {
        if(data.contains(key)){
            Node *node = data[key];
            node->val = value;
            remove(node);
            addToTail(node);
            return;
        }

        if(data.size()>=capacity){
            removeFirst();
        }

        Node *node = new Node(key, value);
        data.emplace(key, node);
        addToTail(node);
    }
};


// int main() {
//     LRUCache *c = new LRUCache(2);
//
//     std::cout<<c->get(2)<<std::endl;
//     c->put(2,6);
//     std::cout<<c->get(1)<<std::endl;
//     c->put(1,5);
//     c->put(1,2);
//     std::cout<<c->get(1)<<std::endl;
//     std::cout<<c->get(2)<<std::endl;
// }