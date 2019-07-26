/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//����Ļ�������
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode * p = head;
        
        while(p->next)//���p��һ���ڵ㲻Ϊ�վͼ���
            if(p->val == p->next->val)//�ҵ�ֵ��ȵĽڵ�
                p->next = p->next->next;
                else p=p->next;
        return head;
    }
};