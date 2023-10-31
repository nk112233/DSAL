#include<iostream>
using namespace std;
struct Root{
	int data;
	Root* lc;
	Root* rc;
};
class MyBST{
	private: Root* root = new Root;
	public:MyBST(){
		root = NULL;
	}

	public: void Inorderdisp(Root* P){
	if(P!=NULL){
		Inorderdisp(P->lc);
		cout << P->data;
		Inorderdisp(P->rc);
}
}
	public: Root* getroot(){
		return root;
	
	}
	private: Root* makenode(int x){
		Root* p = new Root;
		p-> lc = NULL;
		p-> rc = NULL;
		p->data = x;
		return p;
	}
	public: Root* Insert(){
		int x;
		Root* P = root;
		Root* Q = root;
		cin >> x;
		if(root == NULL){
			root = makenode(x);
			return root;

		}
		else{
		while(Q!=NULL){
			P = Q;

			if(P->data<x){
				Q = P->lc;
			}
			else if(P->data>x){
				Q = P->rc;
			}
			else{
				cout<<"Duplicates not allowed"<<endl;
				return P;
			}
		}
		if (x < P->data){
			P->lc= makenode(x);
			} 
		else{
			P->rc= makenode(x);
			}
		}


	}











};
int main(){
	int n;
	cout <<"Enter n:"<<endl;
	cin>>n;
	MyBST tree; 
	for(int i = 0 ; i<n;i++){
		cout<<"1"<<endl;
		tree.Insert();
	}
	tree.Inorderdisp(tree.getroot());










return 0;
}
