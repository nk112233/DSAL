#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *lc;
	Node *rc;
	bool lth, rth;
};
 class MyTBT
{
private:
	Node *head = new Node;

public:
	MyTBT(){
		head->data = -1;
		head->lth = 1;
		head->rth = 1;
		head->lc = head;
		head->rc = head;
	}
	Node * gethead(){
		return head;
	}
	Node *makeNode(int key){
		Node *P = new Node;
		P->data = key;
		P->lth = 1;
		P->rth = 1;
		P->lc = P;
		P->rc = P;
		return P;
	}
	public: bool Insert(int key){
		Node* P;
		int ch;
		bool insert = 0;
		P = head->lc;
		cout << "Inserting : "<<key<<endl;
		do{	
			cout << "Root : "<< P->data << " 1.Left 2.Right" << endl;
			cin >> ch;
			if (ch == 1){
				if(P->lth == 1){
					Node *Q = makeNode(key);
					Q->lc = P->lc;
					Q->rc = P;
					P->lc = Q;
					P->lth = 0;
					insert = 1;
				}
			
				else{
				P = P->lc;
				}
				}
			if (ch == 2){
				if(P->rth == 1){
					Node *Q = makeNode(key);
					Q->rc = P->rc;
					Q->lc = P;
					P->rc = Q;
					P->rth = 0;
					insert = 1;
				}
			
				else{
					P = P->rc;
				}
			}
		}while(!insert);
		return insert;
	}

	public: void preorder_trav(Node* head){
		Node * current = head->lc;
		if(current->lc == head){
			cout << "Tree is Empty!"<<endl;
			return;
		}
		else{
			cout <<"Preorder Traversal : "<<endl;
			while(current != NULL){
				cout<<current->data<<" ";
				if(current->lth == 0){
					current = current->lc;
				}
				else{
					while(current->rth == 1 && current != head){
						current = current->rc;
					}
					current = current->rc;
				}
			}
		}
		cout<<endl;	

	}
	public: void inorder_trav(Node* head){
		Node * current = head->lc;
		if(current->lc == head){
			cout << "Tree is Empty!"<<endl;
			return;
		}
		else{	
			cout <<"Inorder Traversal : "<<endl;
			while(current->lth == 0){
				current = current->lc;
			}
			while(current != head){
				cout << current->data<<" ";
				if(current->rth == 1){
					current = current->rc;
				}
				else{
					current = current->rc;
					while(current->lth == 0){
						current = current->lc;
					}
				}
			}
		}
		cout<<endl;	
	}
};
int main(){	
	MyTBT thtree;
	thtree.Insert(12);
	thtree.Insert(8);
	thtree.Insert(18);
	thtree.Insert(17);
	thtree.Insert(5);
	thtree.Insert(11);
	thtree.Insert(4);
	thtree.Insert(2);
	thtree.Insert(7);
	thtree.inorder_trav(thtree.gethead());
	thtree.preorder_trav(thtree.gethead());
	



	return 0;
}
