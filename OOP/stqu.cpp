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
	typedef struct* node stqu;

	int empty(stqu l) {
		if (l == NULL) return 1;
		return 0;
	}

	void push(stqu& l, int x) {
		node* q = new node;
		q->data = x;
		q->next = NULL;
		if (empty(l)) l = q;
		else {
			node* temp = l;
			temp->next = q;
		}
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
	void pop(stqu& l, int* x) {
		if (empty(l)) {
			cout << "Stack rong" << endl;
		}
		else {
			node* temp = l;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			*x = temp->data;
			temp = NULL;
		}
	}
};

class queue : public chuc_nang
{
public:
	void pop(stqu& l, int* x) {
		if (empty(l)) cout << "queue rong" << endl;
		else {
			node* temp = l;
			*x = temp->data;
			while (temp->next != NULL) {
				temp = temp->next;
			}
		}
	}
};

int main() {
	stack s;
	queue q;
	stqu* l, * k;
	int m
		if (s.empty(l)) cout << "kiem tra rong: stack rong" << endl;
	for (int i = 1; i < 5; i++) {
		s.push(l, i);
	}
	s.show(l);
	s.pop(l, &m);
	cout << m << endl;
	if (q.empty(k)) cout << "kiem tra rong: queue rong" << endl;
	for (int i = 1; i < 5; i++) {
		q.push(k, i);
	}
	q.show(k);
	q.pop(k, &m);
	cout << m << endl;
	return 0;
}
