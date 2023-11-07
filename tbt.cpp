#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* lc , rc;
	bool lth , rth;
}
class MyTBT{
	private : Node* head = new Node;
	
	public: TBT(){
		head->data = '$';
		head->lth = 1;
		head->rth = 1;
		head->lc = head;
		head->rc = head;
	}
	Node* makeNode(int key){
		Node* P = new Node;
		P->data = key;
		P->lth = 1;
		P->rth = 1;
		P->lc = P;
		P->rc = P;
	}
	void Insert(int key){
		
	
	
	
	}






};
int main(){
	
























return 0;
}
