#include <iostream>
#include "stack.h"
#include <cctype>
#include <typeinfo>
#include <cmath>
#include <string.h>
#include <map>
using namespace std;

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
bool check_key(map<char, int> m, char key)
{
    // Key is not present
    if (m.find(key) == m.end())
        return 0;
 
    return 1;
}
 

int calculate(int op1 , char oprt,int op2){
	int result;
	
	if(oprt == '+'){
		result = op2+op1;
	}
	else if(oprt == '-'){
		result = op2-op1;
	}
	else if(oprt == '*'){
		result = op2*op1;
	}
	else if(oprt == '/'){
		result = op2/op1;
	}
	else if(oprt == '^'){
		result = pow(op2,op1);
	
	}
	return result;


}


int evaluate(string postfix){
	Stack<int> s;
	int i = 0;
	while(postfix[i]!='\0'){
		if(isalpha(postfix[i])){
			int push;
			map<char, int> opinfo;
			if(check_key(opinfo,postfix(i)){
				
			
			}
			cout <<"Enter the value of "<<postfix[i]<<" : "<<endl;
			cin >>push;
			opinfo[postfix[i]] = push; 
			s.push(push);
		}
		else{
			if(!s.IsEmpty()){
				int op1 = s.pop();
				int op2 = s.pop();
				char oprt = postfix[i];
				if(postfix[i+1] == '^' && oprt == '^'){
					oprt = '*';
				}
				s.push(calculate(op1,oprt,op2));
				}
		}
		i++;
	}
	
	return s.peep(); 
}

int main(){
	string infix;
	int n;
	cout << "Enter Infix Expression : "<<endl;
	cin >> infix;
	n = infix.length();
	cout <<"Postfix Expression is : "<< infxtpstfx(infix,n) <<endl;
	int ans = evaluate(infxtpstfx(infix,n));
	cout <<"Evaluation of "<<infix<<" is : "<<ans<<endl;

return 0;
}
