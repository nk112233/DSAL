#include <iostream>
using namespace std;

template <class T>
class Queue{
    private: struct Node {
    T elem;
    Node *next;
};
    private : Node* f;
    private : Node* r;
    public: Queue(){
    	f = NULL;
    	r = NULL;
    }
public:
    bool Eque(T elem){
        Node *temp = new Node;
       	if(r == NULL || f == NULL){
       	 	f = temp;
        	r = temp; 
        	temp->elem = elem;
        	temp->next = NULL;
        	return 1;
        }
        else{ 
        	temp->elem = elem;
        	r->next = temp;
        	temp->next = NULL;
        	r = temp;
            return 1;
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
        if(r == NULL || f == NULL){
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
        	cout << temp->elem<<endl;
            temp = temp->next;
        }
    }



};
/*int main(){
	Stack s;
	cout << s.peep()<<endl;











return 0;
}
*/
