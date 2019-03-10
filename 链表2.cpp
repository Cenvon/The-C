#include "pch.h"
#include "iostream"

using namespace std;
template<class T> class List;

template<class T>
class Node {
friend class List<T>;//��Ԫ�࣬����������˽��Ԫ��
private:
	T data;
	Node *next;
	Node(T element);//��ʼ��
};

template<class T>
class List {
public:
	List() { head = 0; };
	void Insert(T k);//ǰ�����
	void Delete(T data);//ɾ��ĳ�ڵ�ֵ
	void Invert();//��ת
	void Concatenate(List<T> b);//������������
	void Show();//��ӡ����
private:
	Node<T> *head;
};

template<class T>
void List<T>::Insert(T k)
{//�������Ǵ�ͷ�ڵ�head������
	Node<T> *newnode = new Node<T>(k);//����һ�����������k
	newnode->next = head;//���½ڵ��ָ�뱣��ͷ�ڵ�ָ��Ľڵ�
	head = newnode;//�޸�ͷ�ڵ��ָ��
}

template<class T>
void List<T>::Delete(T k)
{
	Node<T> *pre = 0;
	Node<T> *cur;
	for (cur = head; cur&&cur->data != k; pre = cur, cur = cur->next);//Ѱ�ҵ�k�Ľڵ�
	if (pre) pre->next = cur->next;//��ǰ��һ���ڵ��ָ��ȡ����ǰ�ڵ��ָ��
	else head = head->next;
	delete cur;//ɾ����ǰ�ڵ�
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
{//��ʼ������
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
