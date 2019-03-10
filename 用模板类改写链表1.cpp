#include "pch.h"
#include "iostream"

using namespace std;
template<class T>
class Node {
public:
	T data;
	Node *next;
};

template<class T>
class List {
public:
	int Linklist();
	int DestroyLinkList();
	void CreatList(int n);//创建一个长度为n的链表
	void TravelList();
	int GetLength();
	bool IsEmpty();
	Node<T> *Find(int n);
	void InsertAtEnd(T data);
	void InsertAtHead(T data);
	void InsertAtIndex(T data, int n);
	void DeleteAtEnd();
	void DeleteAll();
	void DeleteAtPoint(T data);
	void DeleteAtHead();
private:
	Node<T> *head;
};

template<class T>
int List<T>::Linklist()
{
	head = new Node<T>;
	head->data = 0;
	head->next = NULL;
	return 1;
}

template<class T>
int List<T>::DestroyLinkList()
{
	delete head;
	return 0;
}

template<class T>
void List<T>::CreatList(int n)
{
	Node<T> *newnode, *temp;
	temp = head;
	if (n < 0) {
		cout << "输入有误" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n; i++) {
		newnode = new Node<T>;
		cout << "请输入第" << i + 1 << "个值:";
		cin >> newnode->data;
		newnode->next = NULL;
		temp->next = newnode;
		temp = newnode;
	}
}

template<class T>
void List<T>::TravelList()
{
	if (head == NULL || head->next == NULL) cout << "链表为空！" << endl;
	Node<T> *p = head;
	while (p->next != NULL) {
		p = p->next;
		cout << p->data << " ";
	}
}

template<class T>
int List<T>::GetLength()
{
	int count = 0;
	Node<T> *p = head;
	while (p->next != NULL) {
		count++;
		p = p->next;
	}
	return count;
}

template<class T>
bool List<T>::IsEmpty()
{
	if (head->next == NULL)
		return true;
	else
		return false;
}

template<class T>
Node<T> * List<T>::Find(int n)
{
	Node<T> *p = head;
	if (p->next == NULL) cout << "链表为空" << endl;
	int i = 0;
	while (n > i) {
		p = p->next;
		i++;
	}
	return p;
}

template<class T>
void List<T>::InsertAtEnd(T data)
{
	Node<T> *newnode = new Node<T>;
	newnode->next = NULL;
	newnode->data = data;
	Node<T> *p = head;
	if (head == NULL) head = newnode;
	else {
		while (p->next) p = p->next;
		p->next = newnode;
	}
}

template<class T>
void List<T>::InsertAtHead(T data)
{
	Node<T> *newnode = new Node<T>;
	newnode->data = data;
	Node<T> *p = head;
	if (head == NULL) head = newnode;
	newnode->next = p->next;
	p->next = newnode;
}

template<class T>
void List<T>::InsertAtIndex(T data, int n)
{
	Node<T> *newnode = new Node<T>;
	newnode->data = data;
	Node<T> *p = head;
	if (p->next == NULL) head = newnode;
	int i = 1;
	while (n > i) {
		p = p->next;
		i++;
	}
	newnode->next = p->next;
	p->next = newnode;
}

template<class T>
void List<T>::DeleteAtEnd()
{
	Node<T> *tmp = head, *pre = NULL;
	if (tmp->next == NULL) cout << "链表为空";
	else {
		while (tmp->next) {
			pre = tmp;//pre节点保存当前结点
			tmp = tmp->next;//继续遍历下一个节点
		}
		delete tmp;//删除最后一个节点
		pre->next = NULL;//pre节点成为最后一个节点
	}
}

template<class T>
void List<T>::DeleteAll()
{
	Node<T> *p = head->next;
	Node<T> *ptemp = new Node<T>;
	while (p != NULL) {
		ptemp = p;//ptmp保存当前p的值
		p = p->next;//p指向下一个节点
		head->next = p;//头指针指向p
		ptemp->next = NULL;//把ptmp的指针指向NULL
		delete ptemp;//删除ptmp的值
	}
	head->next = NULL;//头节点指向NULL
}

template<class T>
void List<T>::DeleteAtPoint(T data)
{

	Node<T> *p = head, *ptmp = Find(data);
	if (ptmp == head->next) DeleteAtHead();
	else {
		while (p->next != ptmp) p = p->next;
		p->next = ptmp->next;
		delete ptmp;
		ptmp = NULL;
	}
}

template<class T>
void List<T>::DeleteAtHead()
{
	Node<T> *p = head;

	if (p == NULL || p->next == NULL) cout << "该链表为空" << endl;
	else {
		Node<T> *tmp = NULL;
		p = p->next;
		tmp = p->next;
		delete p;
		p = NULL;
		head->next = tmp;
	}
}


int main() {
	List<int> l;
	int i;
	cout << "1.创建单链表   2.遍历单链表   3.获取单链表的长度   4.判断单链表是否为空   5.获取节点\n";
	cout << "6.在尾部插入指定元素   7.在指定位置插入指定元素   8.在头部插入指定元素\n";
	cout << "9.在尾部删除元素   10.删除所有元素   11.删除指定元素   12.在头部删除元素   0.退出" << endl;
	do {
		cout << "请输入要执行的操作:" << endl;
		cin >> i;
		switch (i) {
		case 1:
			int n;
			l.Linklist();
			cout << "请输入单链表的长度：";
			cin >> n;
			l.CreatList(n);
			break;
		case 2:
			l.TravelList();
			break;
		case 3:
			cout << "该单链表的长度" << l.GetLength() << endl;
			break;
		case 4:
			if (l.IsEmpty() == 1) cout << "该单链表为空" << endl;
			else cout << "该单链表不是空表" << endl;
			break;
		case 5:
			int data;
			cout << "请输入要获取节点的值：";
			cin >> data;
			cout << "该节点的值为:" << l.Find(data)->data << endl;
			break;
		case 6:
			int endData;
			cout << "请输入要在尾部插入的值: ";
			cin >> endData;
			l.InsertAtEnd(endData);
			break;
		case 7:
			int pointData;
			int index;
			cout << "请输入要插入的数据: ";
			cin >> pointData;
			cout << "请输入要插入数据的位置: ";
			cin >> index;
			l.InsertAtIndex(pointData, index);
			break;
		case 8:
			int headData;
			cout << "请输入要在头部插入的值: ";
			cin >> headData;
			l.InsertAtHead(headData);
			break;
		case 9:
			l.DeleteAtEnd();
			break;
		case 10:
			l.DeleteAll();
			break;
		case 11:
			int pointDeleteData;
			cout << "请输入要删除的数据: ";
			cin >> pointDeleteData;
			l.DeleteAtPoint(pointDeleteData);
			break;
		case 12:
			l.DeleteAtHead();
			break;
		default:
			break;
		}
	} while (i != 0);
	system("pause");

	return 0;

}