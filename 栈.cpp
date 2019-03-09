#include "pch.h"
#include "iostream"

using namespace std;

template<class T>
class ArrayStack {
public:
	ArrayStack();
	~ArrayStack();
	void push(T t);
	T peek();
	T pop();
	int size();
	int isEmpty();
private:
	T *arr;
	int count;
};

template<class T>
ArrayStack<T>::ArrayStack()
{
	arr = new T[12];
	if (!arr)
		cout << "array malloc error" << endl;
}

template<class T>
ArrayStack<T>::~ArrayStack()
{
	if (arr) {
		delete[]arr;
		arr = NULL;
	}
}

template<class T>
void ArrayStack<T>::push(T t)
{
	arr[count++] = t;
}

template<class T>
T ArrayStack<T>::peek()
{
	return arr[count - 1];
}

template<class T>
T ArrayStack<T>::pop()
{
	int ret = arr[count - 1];
	count--;
	return ret;
}

template<class T>
int ArrayStack<T>::size()
{
	return count;
}

template<class T>
int ArrayStack<T>::isEmpty()
{
	return size() == 0;
}

int main() {

	int tmp = 0;
	ArrayStack<int> *stack = new ArrayStack<int>();
	cout << "main" << endl;
	stack->push(10);
	stack->push(20);
	stack->push(30);

	tmp = stack->pop();
	cout << "tmp=" << tmp << endl;
	tmp = stack->peek();
	stack->push(40);
	while (!stack->isEmpty()) {
		tmp = stack->pop();
		cout << tmp << endl;
	}
	system("pause");
	return 0;
}