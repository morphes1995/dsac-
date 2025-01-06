//
// Created by aaab on 2025/1/2.
//

#ifndef LIST_NODE_H
#define LIST_NODE_H
struct ListNode {
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode *next):val(x),next(next){}
};

extern void printList(ListNode *head);

#endif //LIST_NODE_H
