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
	void CreatList(int n);//����һ������Ϊn������
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
		cout << "��������" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n; i++) {
		newnode = new Node<T>;
		cout << "�������" << i + 1 << "��ֵ:";
		cin >> newnode->data;
		newnode->next = NULL;
		temp->next = newnode;
		temp = newnode;
	}
}

template<class T>
void List<T>::TravelList()
{
	if (head == NULL || head->next == NULL) cout << "����Ϊ�գ�" << endl;
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
	if (p->next == NULL) cout << "����Ϊ��" << endl;
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
	if (tmp->next == NULL) cout << "����Ϊ��";
	else {
		while (tmp->next) {
			pre = tmp;//pre�ڵ㱣�浱ǰ���
			tmp = tmp->next;//����������һ���ڵ�
		}
		delete tmp;//ɾ�����һ���ڵ�
		pre->next = NULL;//pre�ڵ��Ϊ���һ���ڵ�
	}
}

template<class T>
void List<T>::DeleteAll()
{
	Node<T> *p = head->next;
	Node<T> *ptemp = new Node<T>;
	while (p != NULL) {
		ptemp = p;//ptmp���浱ǰp��ֵ
		p = p->next;//pָ����һ���ڵ�
		head->next = p;//ͷָ��ָ��p
		ptemp->next = NULL;//��ptmp��ָ��ָ��NULL
		delete ptemp;//ɾ��ptmp��ֵ
	}
	head->next = NULL;//ͷ�ڵ�ָ��NULL
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

	if (p == NULL || p->next == NULL) cout << "������Ϊ��" << endl;
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
	cout << "1.����������   2.����������   3.��ȡ������ĳ���   4.�жϵ������Ƿ�Ϊ��   5.��ȡ�ڵ�\n";
	cout << "6.��β������ָ��Ԫ��   7.��ָ��λ�ò���ָ��Ԫ��   8.��ͷ������ָ��Ԫ��\n";
	cout << "9.��β��ɾ��Ԫ��   10.ɾ������Ԫ��   11.ɾ��ָ��Ԫ��   12.��ͷ��ɾ��Ԫ��   0.�˳�" << endl;
	do {
		cout << "������Ҫִ�еĲ���:" << endl;
		cin >> i;
		switch (i) {
		case 1:
			int n;
			l.Linklist();
			cout << "�����뵥����ĳ��ȣ�";
			cin >> n;
			l.CreatList(n);
			break;
		case 2:
			l.TravelList();
			break;
		case 3:
			cout << "�õ�����ĳ���" << l.GetLength() << endl;
			break;
		case 4:
			if (l.IsEmpty() == 1) cout << "�õ�����Ϊ��" << endl;
			else cout << "�õ������ǿձ�" << endl;
			break;
		case 5:
			int data;
			cout << "������Ҫ��ȡ�ڵ��ֵ��";
			cin >> data;
			cout << "�ýڵ��ֵΪ:" << l.Find(data)->data << endl;
			break;
		case 6:
			int endData;
			cout << "������Ҫ��β�������ֵ: ";
			cin >> endData;
			l.InsertAtEnd(endData);
			break;
		case 7:
			int pointData;
			int index;
			cout << "������Ҫ���������: ";
			cin >> pointData;
			cout << "������Ҫ�������ݵ�λ��: ";
			cin >> index;
			l.InsertAtIndex(pointData, index);
			break;
		case 8:
			int headData;
			cout << "������Ҫ��ͷ�������ֵ: ";
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
			cout << "������Ҫɾ��������: ";
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