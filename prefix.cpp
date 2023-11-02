#include <iostream>
#include "stack.h"
#include <cmath>
#include <algorithm>
#include<string>
using namespace std;
class MyPrefix{
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
	else if(x == ')'){
		return 0;
	}
	else{
		return -1;
	}

}
public: int icp(char a){
	if(a == ')'){
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
public: string  infxtprfx(string infx,int n){
	string prefix;
	Stack<char> s;
	
	for(int i = n;i>=0;i--){
		 char ch  = infx[i];
		if(!isalpha(ch)){			
			if(ch =='('){
				while(s.peep() != ')'){
					prefix += s.pop();
				}
				s.pop();

			}
			else if(icp(ch)<=isp(s)){
				while(icp(ch)<=isp(s)){
					if(!s.IsEmpty())
						prefix += s.pop();
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
				prefix += ch;
			}
	
	
	}
	while(!s.IsEmpty())
		prefix += s.pop();
	reverse(prefix.begin(), prefix.end());
	
	return prefix;


}
public: int calculate(int op1 , char oprt,int op2){
	int result;
	if(oprt == '+'){
		result = op1+op2;
	}
	else if(oprt == '-'){
		result = op1-op2;
	}
	else if(oprt == '*'){
		result = op1*op2;
	}
	else if(oprt == '/'){
		result = op1/op2;
	}
	else if(oprt == '^'){
		result = pow(op1,op2);
	
	}
	return result;


}
public: int evaluate(string prefix,int n){
	Stack<int> oprnd;
	for(int i = n-1 ; i>0 ;i--){
		if(isalpha(prefix[i])){
			int op;
			cout << "Enter the value of "<<prefix[i]<<" :"<<endl;
			cin >> op;
			oprnd.push(op);

		}
		else{
			if(!oprnd.IsEmpty()){
			int op1 = oprnd.pop();
			int op2 = oprnd.pop();
			char opr = prefix[i];
			oprnd.push(calculate(op1,opr,op2));

		}
		}
	}

	return oprnd.peep();

}
};
int main(){
	string infix;
	int n;
	cout << "Enter Infix Expression : "<<endl;
	cin >> infix;
	n = infix.length();
	MyPrefix prf;
	string prefix = prf.infxtprfx(infix,n);
	int n1 = prefix.length();
	cout <<"Prefix Expression is : "<< prf.infxtprfx(infix,n)  <<endl;
	int ans = prf.evaluate(prf.infxtprfx(infix,n),n1);
	cout <<"Evaluation of "<<infix<<" is : "<<ans<<endl;

return 0;
}







