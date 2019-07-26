static const auto io_speed_up = []()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}();
/*
ios::sync_with_stdio(false)的理解：
cin慢是有原因的，其实默认的时候，cin与stdin总是保持同步的，也就是说这两种方法可以混用，而不必担心文件指针混乱，
同时cout和stdout也一样，两者混用不会输出顺序错乱。正因为这个兼容性的特性，导致cin有许多额外的开销，如何禁用这个
特性呢？只需一个语句std::ios::sync_with_stdio(false);，这样就可以取消cin于stdin的同步了。


关键字 auto ：auto可以在声明变量的时候根据变量初始值的类型自动为此变量选择匹配的类型
int a=0;
auto m=a;
那么 m 就会自动转变为 int 型变量。
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