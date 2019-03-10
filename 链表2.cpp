#include "pch.h"
#include "iostream"

using namespace std;
template<class T> class List;

template<class T>
class Node {
friend class List<T>;//友元类，允许该类操作私有元素
private:
	T data;
	Node *next;
	Node(T element);//初始化
};

template<class T>
class List {
public:
	List() { head = 0; };
	void Insert(T k);//前面插入
	void Delete(T data);//删除某节点值
	void Invert();//反转
	void Concatenate(List<T> b);//两个链表链接
	void Show();//打印链表
private:
	Node<T> *head;
};

template<class T>
void List<T>::Insert(T k)
{//该链表是从头节点head处插入
	Node<T> *newnode = new Node<T>(k);//声明一个变量来存放k
	newnode->next = head;//让新节点的指针保存头节点指向的节点
	head = newnode;//修改头节点的指针
}

template<class T>
void List<T>::Delete(T k)
{
	Node<T> *pre = 0;
	Node<T> *cur;
	for (cur = head; cur&&cur->data != k; pre = cur, cur = cur->next);//寻找到k的节点
	if (pre) pre->next = cur->next;//用前面一个节点的指针取代当前节点的指针
	else head = head->next;
	delete cur;//删除当前节点
}

template<class T>
void List<T>::Invert()
{
	Node<T> *p = head, *q = 0;
	while (p) {
		Node<T> *r = q; q = p;
		p = p->next;
		q->next = r;
	}
	head = q;
}

template<class T>
void List<T>::Concatenate(List<T> b)
{
	if (!head) { head = b.head; return; }
	if (b.head) {
		Node<T> *p;
		for (p = head; p->next; p->next);
		p->next = b.head;
	}
}

template<class T>
void List<T>::Show()
{
	for (Node<T> *current = head; current; current = current->next) {
		cout << current->data;
		if (current->next) cout << "->";
	}
	cout << endl;
}

template<class T>
Node<T>::Node(T element)
{//初始化操作
	data = element;
	next = 0;
}

int main() {
	List<int> intList;
	intList.Insert(5);
	intList.Insert(15);
	intList.Insert(35);
	cout << "hello world!" << endl;
	intList.Show();
	intList.Delete(5);
	intList.Show();
	intList.Invert();
	intList.Show();
}
