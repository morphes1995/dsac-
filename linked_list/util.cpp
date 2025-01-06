#include "list_node.h"
#include "iostream"

void printList(ListNode *head) {
    while (head!=nullptr) {
        std::cout<< head->val<<std::endl;
        head = head->next;
    }
}