/**
* O(1)时间内删除链表中的一个节点 (给定的节点 node 可能是链表中的最后一个节点)
 */
public class Question18 {

    public ListNode deleteNode(ListNode head, ListNode node){
        if(head==null){
            return null;
        }

        if(node.next!=null){
            // O（1）
            node.val =node.next.val;
            node.next = node.next.next;
            return head;
        }else{
            // O(N)
            ListNode dummy = new ListNode();
            dummy.next =head;
            ListNode cur =dummy;

            while(cur!=null){
                if(cur.next==node){
                    cur.next=cur.next.next;
                    break;
                }
                cur=cur.next;
            }
            return dummy.next;// 如果要删除的node == head的话， 链表的head会发生变化
        }
    }

    /**
     * 82. 删除排序链表中的重复元素 II
     * 在排序链表中删除有重复数据的节点
     */

    public ListNode deleteDuplicatedNode(ListNode head){
        if(head==null){
            return null;
        }

        ListNode dummy = new ListNode();
        dummy.next =head;

        ListNode pre =dummy;
        ListNode cur =head;
        while(cur!=null){
            boolean needDelete =false;
            if(cur.next!=null &&cur.val == cur.next.val){
                needDelete =true;
            }

            if(!needDelete){
                // 如果cur和cur.next的value不一致，则cur不需要删除，将pre,cur指针后移
                pre=cur;
                cur=cur.next;
            }else{
                // cur和cur.next的value不致，cur需要删除，此时循环遍历与cur值一样的后序节点，直到遇到与cur值不一样的节点（或空节点），
                // 并删除所有与cur值一样的节点
                int val =cur.val;
                while(cur!=null && cur.val==val){
                    cur=cur.next;
                }
                pre.next=cur; // 删除所有与cur值一样的节点
                // 此时，pre节点不会向后移动，
                // 因为cur此时的值与val不一样了，但是 cur后面的节点的值可能又与cur的值一致，因此还无法判断cur的值在后序是否存在重复
            }
        }

        return dummy.next;
    }