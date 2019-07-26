/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//链表的基本操作
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode * p = head;
        
        while(p->next)//如果p下一个节点不为空就继续
            if(p->val == p->next->val)//找到值相等的节点
                p->next = p->next->next;
                else p=p->next;
        return head;
    }
};