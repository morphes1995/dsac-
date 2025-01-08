/**
* leetcode 83. 删除 排序链表 中的重复元素
* 给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素 `只出现一次` 。返回 已排序的链表 。
*/
public ListNode deleteDuplicates(ListNode head) {

   ListNode dummyNode = new ListNode();
   dummyNode.next= head;

   ListNode pre = dummyNode;
   ListNode cur = pre.next;
   while(cur!=null){
       ListNode next = cur.next;
       if(next!=null && next.val==cur.val){
           pre.next = next;// 删除cur节点
       }else{
           pre =cur;
       }

       cur=next;
   }

   return dummyNode.next;
}

/**
 * leetcode 82. 删除排序链表中的重复元素 II
 * 给定一个已排序的链表的头 head ， 删除原始链表中 `所有重复数字的节点`，`只留下不同的数字` 。返回 已排序的链表 。
 * @param head
 * @return
 */
public ListNode deleteDuplicates2(ListNode head) {

    ListNode dummyNode = new ListNode();
    dummyNode.next= head;

    ListNode pre = dummyNode;
    ListNode cur = pre.next;
    while(cur!=null){
        ListNode next = cur.next;

        if(next!=null && cur.val==next.val){
            // 如果cur和cur.next的value一致，此时有节点要删除
            while(next!=null && cur.val==next.val){ // 定位next指针，使其指向重复节点的后一个节点
                cur = next;
                next =next.next;
            }
            pre.next= next; // 删除所有重复节点
            // 此时不移动 pre指针
        }else{
            // 如果cur和cur.next的value不一致，则cur不需要删除，将pre,cur指针后移
            pre = cur;
        }
        cur =next;
    }
    return dummyNode.next;
}

