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
		cout << P->data<<endl;
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

			if(P->data>x){
				Q = P->lc;
			}
			else if(P->data<x){
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
		return P;


	}
	public: Root* search(int key){
		if(root == NULL){
			cout<<"Empty Tree!"<<endl;
		}
		Root *temp = new Root;
		temp = root;
		while(temp!=NULL){
			if(temp->data == key){
				return temp;
			}
			else if(temp->data > key){
				temp = temp->lc;
			}
			else if(temp->data < key){
				temp = temp->rc;
			}
		return NULL;
		}
		}
	public: Root* del(int key){
		if(root == NULL){
			cout<<"Empty Tree!"<<endl;
		}
		Root* delele = new Root;
		Root* p = new Root;
		delele = root;
		p = root;
		while(delele!=NULL && delele->data != key){
			p = delele;
			if(delele->data > key){
				delele = p->lc;
			}
			else if(delele->data < key){
				delele = p->rc;
			}
		}
		if(delele->lc == NULL && delele->rc == NULL){
			if(p->lc == delele){
				p->lc = NULL;
			}
			else if(p->rc == delele){
				p->rc = NULL;
			}
			return delele;
		}
		else if(delele->lc != NULL && delele->rc != NULL){
			Root* Q = new Root;
			Root* P = new Root;
			Q = delele;
			while(Q->lc != NULL && Q->rc !=NULL){
				P = Q;
				Q = Q->lc;
			}
			delele->data = Q->data;
			if(P->lc == Q){
				P->lc = NULL;
			}
			else if(p->rc == Q){
				P->rc = NULL;
			}
			return delele;
		}
		else{
			Root* temp = new Root;
			if(delele->lc != NULL){
				temp = delele->lc;
				if(p->data<temp->data){
					p->rc = temp;
				}	
				else if(p->data>temp->data){
					p->lc = temp;
			}	
			
			}
			else{
				temp = delele->rc;
				if(p->data<temp->data){
					p->rc = temp;
				}	
				else if(p->data>temp->data){
					p->lc = temp;
				}
			}
			return delele;
		}

}









};
int main(){
	int n,ch;
	cout <<"Enter n:"<<endl;
	cin>>n;
	MyBST tree;
	for(int i = 0 ; i<n;i++){
		tree.Insert();
	}
	tree.Inorderdisp(tree.getroot());
	cout <<"1.Search\n2.Delete\n3.Display"<<endl;
	 cin>>ch;
	 switch(ch){
	 	case 1:
	 		int sh;
	 		cout<<"Enter element to be searched :"<<endl;
	 		cin >>sh;
	 		cout<<"Found"<<tree.search(sh)->data<<endl;
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 }











return 0;
}
