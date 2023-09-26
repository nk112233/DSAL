#include <iostream>
using namespace std;

template <class T>
class Stack{
    private: struct Node {
    T elem;
    Node *next;
    
    
};
    private : Node *tos;
    public: Stack(){
    	tos = NULL;
    }
public:
    bool push(T elem){
       
        Node *temp = new Node;
        if(temp == NULL)
            return 0;
        temp->elem = elem;
        temp->next = tos;
        tos = temp;
        return 1;

    }
public:
    T pop(){
        Node *temp = new Node;
        temp = tos;
        tos = temp->next;
        return temp->elem;



    }
public:
    bool IsEmpty(){
        if(tos == NULL){
            return 1;

        }
        else{
        	return 0;
        }


    }
public:
    T peep(){
        if(tos != NULL){
            return tos->elem;
        }
            
        else{
            return 0;
        }


    }



};
/*int main(){
	Stack s;
	cout << s.peep()<<endl;











return 0;
}
*/
