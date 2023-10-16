#include <iostream>
#include "stack.h"
#include <cctype>
#include <typeinfo>
#include <cmath>
#include <bits/stdc++.h>
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
	else if(x == ')'){
		return 0;
	}
	else{
		return -1;
	}

}
int icp(char a){
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
string  infxtprfx(string infx,int n){
	string prefix;
	Stack<char> s;
	
	for(int i = n;i>=0;i--){
		 char ch  = infx[i];
		if(!isalpha(ch)){			
			if(ch =='('){
				while(s.peep() != ')'){
					prefix += s.pop();
					//cout << "tos = "<<s.peep()<<endl;
				
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
 
int evaluate(string prefix){
	Stack<char> opr;
	Stack<int> oprnd;
	for(char i : prefix){
		if(!isalpha(i)){
			opr.push(i);


		}
		else{
			oprnd.push(i);

		}
	

	}







}
int main(){
	string infix;
	int n;
	//cout << "Enter the length of the expression : "<<endl;
	//cin >> n;
	cout << "Enter Infix Expression : "<<endl;
	cin >> infix;
	n = infix.length();
	cout <<"Prefix Expression is : "<< infxtprfx(infix,n) <<endl;
	//int ans = evaluate(infxtpstfx(infix,n));
	//cout <<"Evaluation of "<<infix<<" is : "<<ans<<endl;

return 0;
}







