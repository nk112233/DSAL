#include <iostream>
#include "stack.h"
#include <cmath>
#include <algorithm>
#include<string>
using namespace std;
class Tree{
	private: struct Root {
    char elem;
    Root *lc;
    Root *rc;
	};

	private: int isp(Stack<char> s){
	char x = s.peep();
	if(x == '^'){
		return 3;
	}
	else if(x == '*' || x == '/'){
		return 2;

	}
	else if(x == '+' || x == '-'){
		return 1;
	
	}
	else if(x == '('){
		return 0;
	}
	else{
		return -1;
	}

}

private: int icp(char a){
	if(a == '('){
		return 4;
	
	}
	if(a == '^'){
		return 3;
	}
	else if(a == '*' || a == '/'){
		return 2;

	}
	else if(a == '+' || a == '-'){
		return 1;
	
	}
	else{
		return 0;
	}

}


public: string  infxtpstfx(string infx,int n){
	string postfix;
	Stack<char> s;
	for(int i = 0;i<n;i++){
		char ch = infx[i];
		//cout <<"infx[i] = "<<infx[i]<<endl;
		if(!isalpha(ch)){			
			if(ch ==')'){
				while(s.peep() != '('){
					postfix += s.pop();
					//cout << "tos = "<<s.peep()<<endl;
				
				}
				s.pop();

			}
			else if(icp(ch)<=isp(s)){
				while(icp(ch)<isp(s)){
					if(!s.IsEmpty())
						postfix += s.pop();
					else{
						break;
					}
			}
				s.push(ch);
			}
			else if(icp(ch)>isp(s))
				s.push(ch);
			
		}
		else{
				postfix += ch;
			}
	
	}
	while(!s.IsEmpty())
		postfix += s.pop();
	return postfix;
}
public: Root* exptree(string infix){
	int n = infix.length();
	string postfix = infxtpstfx( infix, n);
	int i = 0;
	Stack<Root*> s;
	while(postfix[i] !='\0'){
		char ch = postfix[i];
		if(isalpha(ch)){
			Root* ele = new Root();
			ele->elem = ch;
			s.push(ele);
		}
		else{
			Root* ele = new Root();
			ele->elem = ch;
			if(!s.IsEmpty()){
			Root* op1 = s.pop();
			Root* op2 = s.pop();
			ele->rc = op1;
			ele->lc = op2;
			s.push(ele);
			}
		}
		i++;
	
	}
	return s.peep();



}
public: void Inorderdisp(Root* P){
	if(P!=NULL){
		Inorderdisp(P->lc);
		cout << P->elem;
		Inorderdisp(P->rc);
}
}
public: void Preorder(Root* P){
	if(P!=NULL){
		cout << P->elem;
		Preorder(P->lc);
		Preorder(P->rc);
}
}
public: void Postorder(Root* P){
	if(P!=NULL){
		Postorder(P->lc);
		Postorder(P->rc);
		cout << P->elem;
}
}
public: void iterativeInorder(Root* P){ 
	string inorder;
	Stack<Root*> s;
	do
	{
	while (P!= NULL){ 
		s.push(P);
		P = P->lc;
		}
	if(!s.IsEmpty()){
		P = s.pop();
		inorder += P->elem;
		P = P->rc;	
	}
	}while(P!= NULL || !s.IsEmpty());
	cout << inorder;
	}
public: levelorder(root) { 
if(T=NULL ) 
then write(‘Tree is Empty) 
return 
else 
{ 
q = empty queue 
enqueue(T) 

while(!(isempty(q)) 
{ node = dequeue(q) 
else { write /visit (node) 
if (node->left != NULL ) 	

enqueue(node->left) 
if (node->right != NULL) 
	enqueue(node->right)
};


int main(){
	string infix;
	int n;
	Tree t;
	cout << "Enter Infix Expression : "<<endl;
	cin >> infix;
	n = infix.length();
	string postfix = t.infxtpstfx( infix, n);
	cout <<"PostFix Expression : "<<postfix<<endl;
	cout <<"Expresion tree of "<<infix<<" is :" <<endl; 
	cout <<"Inorder : "<<endl;
	t.Inorderdisp(t.exptree(infix));
	cout<<endl;
	cout <<"Postorder : "<<endl;
	t.Postorder(t.exptree(infix));
	cout<<endl;
	cout <<"Preorder : "<<endl;
	t.Preorder(t.exptree(infix));
	cout<<endl;
	cout <<"Iterative Inorder : "<<endl;
	t.iterativeInorder(t.exptree(infix));
	cout<<endl;






















return 0;
}
