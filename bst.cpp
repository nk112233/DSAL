#include<iostream>
#include<math.h>
#include"queue.h"
using namespace std;
struct Root{
	int data;
	Root* lc;
	Root* rc;
};
class MyBST{
	private: Root* root = new Root;
	private: Root* parent[20];
	private: int i = 0;
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
	public: Root* Insert(int x){
		// int x;
		Root* P = root;
		Root* Q = root;
		// cin >> x;
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
	public: int del(int key){
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
		// cout << "delele"<<delele->data<<endl;
		if(delele->lc == NULL && delele->rc == NULL){
			if(p->lc == delele){
				p->lc = NULL;
			}
			else if(p->rc == delele){
				p->rc = NULL;
			}
			return delele->data;
		}
		else if(delele->lc != NULL && delele->rc != NULL){
			cout <<"both child"<<endl;
			Root* Q = new Root;
			Root* P = new Root;
			Q = delele;
			P = delele;
			// cout <<"P = "<<P->data<<endl;
			// cout <<"Q = "<<Q->data<<endl;
			Q = Q->rc;
			while(Q->lc != NULL && Q->rc !=NULL){
				    cout <<"working"<<endl;
					P = Q;
					Q = Q->lc;
				}
			// cout <<"P = "<<P->data<<endl;
			// cout <<"Q = "<<Q->data<<endl;
			int elem  = delele->data;
			delele->data = Q->data;
			if(P->lc == Q){
				P->lc = NULL;
			}
			else if(P->rc == Q){	
				P->rc = NULL;
			}
			return elem;
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
			return delele->data;
		}
	}
public : int height(Root *root){
	 	if (root == NULL)
			return -1;
		else {
			return 1 + max(height(root->lc),height(root->rc));
		}
	}
	public: void mirrortree(Root * root){
			Root * temp = new Root;
			if(root  != NULL)
			{
				temp =root->rc;
				root->rc= root->lc;
				root->lc=temp;
				mirrortree(root->lc);
				mirrortree(root->rc);
			}
			else {
				return;
			}
	}

	public: void copy_tree( Root * tree2, Root *tree1){
		tree2 = new Root;
		if(tree1 == NULL){
			tree2 = NULL;
		}
		else{
			tree2->data = tree1->data;
			copy_tree(tree2->lc,tree1->lc);
			copy_tree(tree2->rc , tree1->rc);
		}
	}
	public : void parentarr(Root * root){
		if(root == NULL){
			return;
		}
		if(!(root->lc == NULL && root->rc == NULL)){
			cout <<"Parent :"<< root->data<<endl;
			if(root->lc == NULL){
				cout <<"Left Child : NULL"<<endl;
			}
			else{
				cout <<"Left Child :"<<root->lc->data<<endl;
			}
			
			if(root->rc == NULL){
				cout <<"Right Child : NULL"<<endl;
			}
			else{
				cout <<"Right Child :"<<root->rc->data<<endl;
			}
			
		}
		else{
			return;
		}
		parentarr(root->lc);
		parentarr(root->rc);
	}
	public: void displf(Root* root){
		if(root == NULL){
			return;
		}
		if((root->lc == NULL && root->rc == NULL)){
			cout <<"Leaf Node : "<<root->data<<endl;
		}
		displf(root->lc);
		displf(root->rc);
	}
	public: void level_order(Root* root){
		if(root == NULL){
			return;
		}
		else{
			Queue<Root *> q;
			q.Eque(root);
			Root* node = new Root;
			while(!q.IsEmpty()){
				node = q.Deque();
				cout << node->data<<endl;

				if(node->lc != NULL){
					q.Eque(node->lc);
				}

				if(node->rc != NULL){
					q.Eque(node->rc);
				}
				
			}
			
		}
	}
	









};
int main(){
	int n,ch;
	//cout <<"Enter n:"<<endl;
	//cin>>n;
	MyBST tree;
	int inp[] = {50,34,89,56,26,78,37,11,13,10};
	for(int i = 0 ; i<10;i++){
		tree.Insert(inp[i]);
	}
	tree.Inorderdisp(tree.getroot());
	cout <<"1.Search\n2.Delete\n3.Display\n4.Height\n5.Mirror Tree\n6.Copy Tree\n7.Display Parent and Child Nodes\n8.Display all leaf nodes\n9.Level-wise Traversal"<<endl;
	 cin>>ch;
	 Root* tree2 = new Root;
	 switch(ch){
	 	case 1:
	 		int sh;
	 		cout<<"Enter element to be searched :"<<endl;
	 		cin >>sh;
	 		cout<<"Found"<<tree.search(sh)->data<<endl;
	 	case 2:
	 		
	 		cout<<"Enter element to be deleted :"<<endl;
	 		cin >>sh;
	 		cout <<"Deleted : "<<tree.del(sh)<<endl;
	 	case 3:
	 		tree.Inorderdisp(tree.getroot());
		case 4:
			tree.height(tree.getroot());
		case 5:
			tree.mirrortree(tree.getroot());
			tree.Inorderdisp(tree.getroot());
		
		case 6:
			tree.copy_tree(tree2,tree.getroot());
	 		tree.Inorderdisp(tree2);
	 	case 7:
			tree.parentarr(tree.getroot());
		case 8:
			tree.displf(tree.getroot());
		case 9:
			tree.level_order(tree.getroot());
	 
	 }
return 0;
}
