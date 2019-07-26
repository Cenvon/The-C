static const auto io_speed_up = []()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}();
/*
ios::sync_with_stdio(false)����⣺
cin������ԭ��ģ���ʵĬ�ϵ�ʱ��cin��stdin���Ǳ���ͬ���ģ�Ҳ����˵�����ַ������Ի��ã������ص����ļ�ָ����ң�
ͬʱcout��stdoutҲһ�������߻��ò������˳����ҡ�����Ϊ��������Ե����ԣ�����cin��������Ŀ�������ν������
�����أ�ֻ��һ�����std::ios::sync_with_stdio(false);�������Ϳ���ȡ��cin��stdin��ͬ���ˡ�


�ؼ��� auto ��auto����������������ʱ����ݱ�����ʼֵ�������Զ�Ϊ�˱���ѡ��ƥ�������
int a=0;
auto m=a;
��ô m �ͻ��Զ�ת��Ϊ int �ͱ�����
*/

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ans = new ListNode(0); ListNode* head = ans;
		int k = 0;
		while (l1 != NULL && l2 != NULL)
		{
			int c = l1->val + l2->val + k;
			ListNode* cur = new ListNode(c % 10);
			if (c >= 10)
				k = 1;
			else
				k = 0;
			ans->next = cur;
			ans = ans->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		ListNode* l3 = l1;
		if (l1 == NULL)
			l3 = l2;
		while (l3 != NULL)
		{
			int c = l3->val + k;
			ListNode* cur = new ListNode(c % 10);
			if (c >= 10)
				k = 1;
			else
				k = 0;
			ans->next = cur;
			ans = ans->next;
			l3 = l3->next;
		}
		if (k)
		{
			ListNode* cur = new ListNode(1);
			ans->next = cur;
		}
		return head->next;
	}
};