
#include "pch.h"


#include "iostream"

using namespace std;
typedef int DataType;
#define Node ElemType
#define ERROR NULL

class Node {

public:
	int data;
	Node *next;
};

class LinkList {
public:
	LinkList();//构建一个单链表
	~LinkList();//销毁一个单链表
	void CreatList(int n);//创建一个单链表
	void TravelList();//便利单链表
	int GetLength();//获取线性表长度
	bool IsEmpty();//判断链表是否为空
	ElemType * Find(DataType data);//查找结点
	void InsertAtEnd(DataType data);//尾部插入
	void InsertAtHead(DataType data);//首部插入
	void InsertAtIndex(DataType data,int n);//指定位置插入
	void DeleteAtEnd();//在尾部删除元素
	void DeleteAll();//删除全部元素
	void DeleteAtPoint(DataType data);//删除指定的数据
	void DeleteAtHead();//在头部删除节点
private:
	ElemType *head;//头节点
};


LinkList::LinkList() {
	head = new ElemType;
	head->data = 0;//将头节点的数据域定义为0
	head -> next = NULL;//将头节点的下一个定义为NULL
}

LinkList::~LinkList(){
	delete head;//删除头节点
}

//创建一个单链表
void LinkList::CreatList(int n)
{
	ElemType *pnew, *ptemp;
	ptemp = head;
	if (n < 0) {//输入的值有误时，处理异常
		cout << "输入的值有误" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n; i++) {//将值一个一个插入到单链表中
		pnew = new ElemType;
		cout << "请输入第" << i + 1 << "个值";
		cin >> pnew->data;
		pnew->next = NULL;//新节点的下一个地址为NULL
		ptemp -> next = pnew;//当前节点的下一个地址设为新节点
		ptemp = pnew;//将当前结点设为新节点
	}
}

void LinkList::TravelList()
{
	if (head == NULL || head->next == NULL) cout << "链表为空！" << endl;
	ElemType *p = head;
	while (p->next != NULL) {
		p = p->next;
		cout << p->data << " ";
	}
}

int LinkList::GetLength()
{
	int count = 0;
	ElemType *p = head->next;
	while (p != NULL) {
		count++;
		p = p->next;
	}
	return count;
}

bool LinkList::IsEmpty()
{
	if (head->next == NULL)
		return true;
	return false;
}

ElemType * LinkList::Find(DataType data)
{
	ElemType *p = head;
	if (p == NULL) {
		cout << "此链表为空链表" << endl;
		return ERROR;
	}
	else {
		while (p->next != NULL) {
			if (p->data == data) return p;
			p = p->next;
		}
	}
	return NULL;
}

void LinkList::InsertAtEnd(DataType data)
{
	ElemType *newNode = new ElemType;
	newNode->next = NULL;
	newNode->data = data;
	ElemType *p = head;
	if (head == NULL) head = newNode;
	else {
		while (p->next != NULL) p = p->next;
		p->next = newNode;
	}
}

void LinkList::InsertAtHead(DataType data)
{
	ElemType *newNode = new ElemType;
	newNode->data = data;
	ElemType *p = head;
	if (head == NULL) head = newNode;
	newNode->next = p->next;
	p->next = newNode;
}

void LinkList::InsertAtIndex(DataType data,int n)
{
	if (n<1 || n>GetLength())
		cout << "输入的值有误" << endl;
	else {
		ElemType *ptemp = new ElemType;
		ptemp->data = data;
		ElemType *p = head;
		int i = 1;
		while (n > 1) {
			p = p->next;
			i++;
		}
		ptemp->next = p->next;
		p->next = ptemp;
	}
}

void LinkList::DeleteAtEnd()
{
	ElemType *p = head;
	ElemType *ptemp = NULL;
	if (p->next == NULL) cout << "单链为空" << endl;
	else {
		while (p->next != NULL) {
			ptemp = p;
			p = p->next;
		}
		delete p;
		p = NULL;
		ptemp->next = NULL;
	}
}

void LinkList::DeleteAll()
{
	ElemType *p = head->next;
	ElemType *ptemp = new ElemType;
	while (p != NULL) {
		ptemp = p;
		p = p->next;
		head->next = p;
		ptemp->next = NULL;
		delete ptemp;
	}
	head->next = NULL;
}

void LinkList::DeleteAtPoint(DataType data)
{
	ElemType *ptemp = Find(data);
	if (ptemp == head->next) DeleteAtHead();
	else{
		ElemType *p = head;
		while (p->next != ptemp) p = p->next;
		p->next = ptemp->next;
		delete ptemp;
		ptemp = NULL;
	
	}
}

void LinkList::DeleteAtHead()
{
	ElemType *p = head;
	if (p == NULL || p->next == NULL) cout << "该链表为空" << endl;
	else {
		ElemType *ptemp = NULL;
		p = p->next;
		ptemp = p->next;
		delete p;
		p = NULL;
		head->next = ptemp;

	}
}

int main() {
	LinkList l;
	int i;
	cout << "1.创建单链表   2.遍历单链表   3.获取单链表的长度   4.判断单链表是否为空   5.获取节点\n";
	cout << "6.在尾部插入指定元素   7.在指定位置插入指定元素   8.在头部插入指定元素\n";
	cout << "9.在尾部删除元素   10.删除所有元素   11.删除指定元素   12.在头部删除元素   0.退出" << endl;
	do{
		cout << "请输入要执行的操作:" << endl;
		cin >> i;
		switch (i) {
			case 1:
				int n;
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
				DataType data;
				cout << "请输入要获取节点的值：";
				cin >> data;
				cout << "该节点的值为:" << l.Find(data)->data << endl;
				break;
			case 6:
				DataType endData;
				cout << "请输入要在尾部插入的值: ";
				cin >> endData;
				l.InsertAtEnd(endData);
				break;
			case 7:
				DataType pointData;
				int index;
				cout << "请输入要插入的数据: ";
				cin >> pointData;
				cout << "请输入要插入数据的位置: ";
				cin >> index;
				l.InsertAtIndex(pointData, index);
				break;
			case 8:
				DataType headData;
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
				DataType pointDeleteData;
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
