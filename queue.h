#include <iostream>
using namespace std;

template <class T>
class Queue{
    private: struct Node {
    T elem;
    Node *next;
    
    
};
    private : Node* f,r;
    public: Stack(){
    	f = NULL;
    	r = NULL;
    }
public:
    bool Eque(T elem){
       	if(r == NULL){
        	Node *temp = new Node;
        	if(temp == NULL)
            	return 0;
       	 	f = temp;
        	r = temp; 
        	temp->elem = elem;
        	temp->next = NULL;
        	return 1;
        }
        else{
        	r = temp; 
        	temp->elem = elem;
        	r->next = temp;
        	temp->next = NULL;
        	r = temp;
        }

    }
public:
    T Deque(){
        Node *temp = new Node;
        temp = f;
        f = temp->next;
        return temp->elem;



    }
public:
    bool IsEmpty(){
        if(r == NULL){
            return 1;

        }
        else{
        	return 0;
        }


    }
public:
    void display(){
        Node *temp = new Node;
        temp = f;
        while(temp != NULL){
        	cout << temp->elem;
        }
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
