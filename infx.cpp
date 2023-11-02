#include <iostream>
#include "stack.h"
#include <cmath>
#include <string.h>
using namespace std;
class MyPostfix{
public: int isp(Stack<char> s){
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

 public:  int icp(char a){
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
		if(!isalpha(ch)){			
			if(ch ==')'){
				while(s.peep() != '('){
					postfix += s.pop();
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


public: int calculate(int op1 , char oprt,int op2){
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


public: int evaluate(string postfix){
	Stack<int> s;
	int i = 0;
	while(postfix[i]!='\0'){
		if(isalpha(postfix[i])){
			int push;
			
			cout <<"Enter the value of "<<postfix[i]<<" : "<<endl;
			cin >>push; 
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
};
int main(){
	string infix;
	int n;
	cout << "Enter Infix Expression : "<<endl;
	cin >> infix;
	n = infix.length();
	MyPostfix pst;
	cout <<"Postfix Expression is : "<< pst.infxtpstfx(infix,n) <<endl;
	int ans = pst.evaluate(pst.infxtpstfx(infix,n));
	cout <<"Evaluation of "<<infix<<" is : "<<ans<<endl;

return 0;
}
