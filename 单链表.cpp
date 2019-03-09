
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
	LinkList();//����һ��������
	~LinkList();//����һ��������
	void CreatList(int n);//����һ��������
	void TravelList();//����������
	int GetLength();//��ȡ���Ա���
	bool IsEmpty();//�ж������Ƿ�Ϊ��
	ElemType * Find(DataType data);//���ҽ��
	void InsertAtEnd(DataType data);//β������
	void InsertAtHead(DataType data);//�ײ�����
	void InsertAtIndex(DataType data,int n);//ָ��λ�ò���
	void DeleteAtEnd();//��β��ɾ��Ԫ��
	void DeleteAll();//ɾ��ȫ��Ԫ��
	void DeleteAtPoint(DataType data);//ɾ��ָ��������
	void DeleteAtHead();//��ͷ��ɾ���ڵ�
private:
	ElemType *head;//ͷ�ڵ�
};


LinkList::LinkList() {
	head = new ElemType;
	head->data = 0;//��ͷ�ڵ����������Ϊ0
	head -> next = NULL;//��ͷ�ڵ����һ������ΪNULL
}

LinkList::~LinkList(){
	delete head;//ɾ��ͷ�ڵ�
}

//����һ��������
void LinkList::CreatList(int n)
{
	ElemType *pnew, *ptemp;
	ptemp = head;
	if (n < 0) {//�����ֵ����ʱ�������쳣
		cout << "�����ֵ����" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n; i++) {//��ֵһ��һ�����뵽��������
		pnew = new ElemType;
		cout << "�������" << i + 1 << "��ֵ";
		cin >> pnew->data;
		pnew->next = NULL;//�½ڵ����һ����ַΪNULL
		ptemp -> next = pnew;//��ǰ�ڵ����һ����ַ��Ϊ�½ڵ�
		ptemp = pnew;//����ǰ�����Ϊ�½ڵ�
	}
}

void LinkList::TravelList()
{
	if (head == NULL || head->next == NULL) cout << "����Ϊ�գ�" << endl;
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
		cout << "������Ϊ������" << endl;
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
		cout << "�����ֵ����" << endl;
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
	if (p->next == NULL) cout << "����Ϊ��" << endl;
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
	if (p == NULL || p->next == NULL) cout << "������Ϊ��" << endl;
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
	cout << "1.����������   2.����������   3.��ȡ������ĳ���   4.�жϵ������Ƿ�Ϊ��   5.��ȡ�ڵ�\n";
	cout << "6.��β������ָ��Ԫ��   7.��ָ��λ�ò���ָ��Ԫ��   8.��ͷ������ָ��Ԫ��\n";
	cout << "9.��β��ɾ��Ԫ��   10.ɾ������Ԫ��   11.ɾ��ָ��Ԫ��   12.��ͷ��ɾ��Ԫ��   0.�˳�" << endl;
	do{
		cout << "������Ҫִ�еĲ���:" << endl;
		cin >> i;
		switch (i) {
			case 1:
				int n;
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
				DataType data;
				cout << "������Ҫ��ȡ�ڵ��ֵ��";
				cin >> data;
				cout << "�ýڵ��ֵΪ:" << l.Find(data)->data << endl;
				break;
			case 6:
				DataType endData;
				cout << "������Ҫ��β�������ֵ: ";
				cin >> endData;
				l.InsertAtEnd(endData);
				break;
			case 7:
				DataType pointData;
				int index;
				cout << "������Ҫ���������: ";
				cin >> pointData;
				cout << "������Ҫ�������ݵ�λ��: ";
				cin >> index;
				l.InsertAtIndex(pointData, index);
				break;
			case 8:
				DataType headData;
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
				DataType pointDeleteData;
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