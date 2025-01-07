#include <cstdlib>
/**
 * 706. 设计哈希映射  不使用任何内建的哈希表库设计一个哈希映射（HashMap）。
 *
 * 实现 MyHashMap 类： 使用了拉链法解决hash冲突
 *
 * MyHashMap() 用空映射初始化对象
 * void put(int key, int value) 向 HashMap 插入一个键值对 (key, value) 。如果 key 已经存在于映射中，则更新其对应的值 value 。
 * int get(int key) 返回特定的 key 所映射的 value ；如果映射中不包含 key 的映射，返回 -1 。
 * void remove(key) 如果映射中存在 key 的映射，则移除 key 和它所对应的 value
 *
 * // todo 没有实现扩容
 */
#include <vector>
#include <iostream>
using namespace std;
class MyHashMap {
public:
    struct Node{
        int key;
        int value;
        Node *next;
        Node(int key,int value){
            this->key = key;
            this->value =value;
        }
    };

    vector<Node*> data;
    int capacity =16;

    MyHashMap() {
       data.reserve(16);
    }

    void put(int key, int value) {
        int hash = key%capacity;
        Node *firstNode = data[hash];
        if(firstNode==nullptr){
            data[hash] = new Node(key,value);
        }else{
            Node *cur = firstNode;
            while(cur!=nullptr){
                if( cur->key==key){
                    cur->value= value; // upate exist
                    break;
                }
                cur = cur->next;
            }
            if(cur==nullptr){
                Node *node = new Node(key,value);
                node->next = firstNode->next;
                firstNode->next = node;
            }
        }

    }

    int get(int key) {
        int hash = key%capacity;
        Node *firstNode = data[hash];
        if(firstNode==nullptr){
            return -1;
        }else{
            Node *cur = firstNode;
            while(cur!=nullptr){
                if( cur->key==key){
                    return cur->value; // find exist value
                }
                cur = cur->next;
            }
            return -1;
        }
    }

    void remove(int key) {
        int hash = key%capacity;
        Node *firstNode = data[hash];
        if(firstNode==nullptr){
            return ;
        }else if (firstNode->key==key){
            data[hash]= firstNode->next;
        }else{
            Node *pre = firstNode;
            Node *cur = pre->next;
            while(cur!=nullptr){
                if( cur->key==key){
                    pre->next = cur->next;
                    delete cur;
                    break;
                }
                pre =cur;
                cur = cur->next;
            }
        }
    }
};

int main() {
    auto map = new MyHashMap();
    map->put(1,2);
    map->put(2,2);
    std::cout<<map->get(1)<<std::endl;
    std::cout<<map->get(3)<<std::endl;
    std::cout<<map->get(2)<<std::endl;
    map->put(2,1);
    std::cout<<map->get(2)<<std::endl;

}