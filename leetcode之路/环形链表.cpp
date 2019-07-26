c++,��������˫ָ�����ģ�����ԭfastָ��һ��һ���������ָ��̫�������г�ʱ�������Ұ�fastָ����������ָ�롣
```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL) return false;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(slow!=fast){
            if(fast==NULL||fast->next==NULL) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
```
��hashͼ���ҵ���˵���л�
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,int> m;
        while(head!=NULL){
            if(++m[head]>1) return true;//ÿ�ΰ�key�����key��Ӧ��valueĬ��Ϊֵ1�����ȫ��ѭ���Ժ��������ֵ����1�ģ���˵�����ڻ�
            head = head->next;
        }
        return false;
    }
};