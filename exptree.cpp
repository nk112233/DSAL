#include <iostream>
#include "stack.h"
#include <cmath>
#include <algorithm>
#include<string>
using namespace std;
struct Root {
    char elem;
    Root *lc;
    Root *rc;
    
    
};

	int isp(Stack<char> s){
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

int icp(char a){
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


string  infxtpstfx(string infx,int n){
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
Root* exptree(string infix){
	int n = infix.length();
	string postfix = infxtpstfx( infix, n);
	cout <<"PostFix Expression : "<<postfix<<endl;
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
void Inorderdisp(Root* P){
	if(P!=NULL){
		Inorderdisp(P->lc);
		cout << P->elem;
		Inorderdisp(P->rc);
}
}
void Preorder(Root* P){
	if(P!=NULL){
		cout << P->elem;
		Inorderdisp(P->lc);
		Inorderdisp(P->rc);
}
}
void Postorder(Root* P){
	if(P!=NULL){
		Inorderdisp(P->lc);
		Inorderdisp(P->rc);
		cout << P->elem;
}
}


int main(){
	string infix;
	int n;
	cout << "Enter Infix Expression : "<<endl;
	cin >> infix;
	n = infix.length();
	cout <<"Expresion tree of "<<infix<<" is :" <<endl; 
	cout <<"Inorder : "<<endl;
	Inorderdisp(exptree(infix));
	cout <<"Postorder : "<<endl;
	Postorder(exptree(infix));
	cout <<"Preorder : "<<endl;
	Preorder(exptree(infix));
	
	cout<<endl;






















return 0;
}
