#include <iostream>

using namespace std;

class linklist{
	protected:
	struct Node {
        int data;
        Node* next;
    };
    Node* first;
    Node* last;
    
	public:
		linklist() {
        first = last = NULL;
    	}	
		
		bool empty(){
			return (last == NULL && first == NULL);
		}
		
		void push(int x){
			Node *p = new Node;
			p->data = x;
			p->next = NULL;
			if(empty()){
				last = first = p;
			}
			else{
				last->next = p;
				last =p;
			}
		}
		
		void show(){
			if(empty()){
				cout << "danh sach rong" << endl;
				return;
			}
			else{
				Node *temp = first;
				while(temp!=NULL){
					cout << temp->data << " ";
					temp = temp->next;
				}
				cout << endl;
			}
		}
};

class stack : public linklist{
	public:	
		void pop(int &x){
			if(empty()){
				cout << "stack rong" << endl;
				return;
			}
			else if (first == last){
				x= last->data;
				delete last;
				last=first= NULL;
				return;
			}
			else{
			Node* temp = first;
            while (temp->next != last) {
            	temp = temp->next;
            }
            x = last->data;
            delete last;
            last = temp;
            last->next = NULL;
			}
		}
};

class queue : public linklist{
	public:
		void pop(int &x){
			Node* temp=first;
			if(empty()){
				cout << "queue rong" << endl;
				return;
			}
			else if (last == first){
				x= last->data;
				delete last;
				last=first= NULL;
				return;
			}
			else{
				x = first->data;
				first = first->next;
				delete temp;
			}
		}
};

int main(){
	stack s; queue q;
	linklist l;
	int x;
	for(int i=1;i<=10;i++){
		s.push(i);
		q.push(i);
	}
	cout << "stack" << endl;
	s.show();
	s.pop(x);
	s.show();
	cout << "queue" << endl;
	q.show();
	q.pop(x);
	q.show();
	return 0;
}