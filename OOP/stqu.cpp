#include <iostream>
#include <stdlib.h>

using namespace std;

class chuc_nang
{
public:
	struct node {
		int data;
		node* next;
	};
	typedef struct node* stqu;

	int empty(stqu l) {
		return (l == NULL);
	}

	void show(stqu l) {
		if (empty(l)) cout << "list rong" << endl;
		else {
			while (l != NULL) {
				cout << l->data << " ";
				l = l->next;
			}
			cout << endl;
		}
	}
};

class stack : public chuc_nang
{
public:
	void push(stqu& l, int x) {
		node* q = new node;
		q->data = x;
		q->next = l;
		l = q;
	}

	void pop(stqu& l, int& x) {
		if (empty(l)) {
			cout << "Stack rong" << endl;
			return;
		}
		else {
			node* temp = l;
			x = l->data;
			l = l->next;
			delete temp;
		}
	}
};

class queue : public chuc_nang
{
public:
	void push(stqu& l, int x) {
		node* q = new node;
		q->data = x;
		q->next = NULL;
		if (empty(l)) l = q;
		else {
			node* temp = l;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = q;
		}
	}

	void pop(stqu& l, int& x) {
		if (empty(l)) cout << "queue rong" << endl;
		else {
			node* temp = l;
			x = l->data;
			l = l->next;
			delete temp;
		}
	}
};

int main() {
	stack s;
	queue q;
	chuc_nang::stqu l = NULL, k = NULL;
	int m;
	if (s.empty(l)) cout << "kiem tra rong: stack rong" << endl;
	for (int i = 1; i <= 5; i++) {
		s.push(l, i);
	}
	s.show(l);
	s.pop(l, m);
	cout << m << endl;
	s.show(l);
	if (q.empty(k)) cout << "kiem tra rong: queue rong" << endl;
	for (int i = 1; i <= 5; i++) {
		q.push(k, i);
	}
	q.show(k);
	q.pop(k, m);
	cout << m << endl;
	q.show(k);
	return 0;
}
