#include <iostream>
using namespace std;
struct Node {
    char elem;
    Node *next;
    
    
};
class Stack{
    private : Node *tos = NULL;
public:
    bool push(char elem){
       
        Node *temp = new Node;
        if(temp == NULL)
            return 0;
        temp->elem = elem;
        temp->next = tos;
        tos = temp;
        return 1;

    }
public:
    char pop(){
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


    }
public:
    char peep(){
        if(tos != NULL){
            return tos->elem;
        }
            
        else{
            return '/';
        }


    }



};
int main(){












return 0;
}