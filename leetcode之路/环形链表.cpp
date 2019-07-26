c++,按照题解的双指针来的，不过原fast指针一次一个相对于慢指针太慢，运行超时，所以我把fast指针跳了两个指针。
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
从hash图中找到就说明有环
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,int> m;
        while(head!=NULL){
            if(++m[head]>1) return true;//每次把key填入表，key对应的value默认为值1；如果全部循环以后，如果出现值大于1的，即说明存在环
            head = head->next;
        }
        return false;
    }
};