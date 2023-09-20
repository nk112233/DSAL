#include <iostream>
using namespace std;
struct Employ{
    string emplname;
    string emplid;
    long emplsalary;

};
class MyQue{

    struct Employ e[10];
    private : 
        int f,r,size;
    public:MyQue(){
        f = -1;
        r = -1;
        size = 10; 
    }
    public:MyQue(int finp , int rinp ){
        f = finp;
        r = rinp; 
        size = 10;
    }
    public :
        bool Isempty();
        bool Isfull();
        void Equeue();
        void Dqueue();
        void display();
        void disprec(int index);
        int getsize();
};
int MyQue :: getsize(){
	return size;
}
bool MyQue :: Isempty(){
    if(r == -1){
        // cout <<"Empty"<<endl;
        return 1;
    }
    else {
        return 0;
    }
}
bool MyQue :: Isfull(){
    if(  ((r == size-1 && f == 0) || (r == f-1))){
        // cout <<"Full"<<endl;
        return 1;
    }
    else {
        return 0;
    }
}
void MyQue :: Equeue(){
    if(!Isfull()){
         if (r == size - 1 && f != 0){
            r = -1;
            r = (r+1)%size;
            cout <<"Enter Employee Name : "<<endl;
            cin>>e[r].emplname;
            cout <<"Enter Employee ID : "<<endl;
            cin>>e[r].emplid;
            cout <<"Enter Employee Salary : "<<endl;
            cin>>e[r].emplsalary;
            }
        else{
            r = (r+1)%size;
            cout <<"Enter Employee Name : "<<endl;
            cin>>e[r].emplname;
            cout <<"Enter Employee ID : "<<endl;
            cin>>e[r].emplid;
            cout <<"Enter Employee Salary : "<<endl;
            cin>>e[r].emplsalary;
        if(f==-1){
            f++;
        
    }
     cout <<"r = "<<r;
     cout <<"f = "<< f<<endl;
    }
    }
    else{
        cout <<"Queue is full"<<endl;
    }
}
void MyQue :: Dqueue(){
    if(!Isempty()){
    cout <<"Deleteting "<<(f%size)<<" element "<<endl;
    f = (f+1)%size;
    cout <<"f = "<< f<<endl;
    cout <<"r = "<< r<<endl;
    }
    else{
    	if(f==r){
    		cout <<"Deleteting "<<(f%size)<<" element "<<endl;
    		cout <<"f = "<< f<<endl;
    		cout <<"r = "<< r<<endl;
    		f =-1;
        	r = -1;
    	
    	}
    	else{
        cout <<"Queue is empty"<<endl;
        f =-1;
        r = -1;
        }
    }

}
void MyQue :: disprec(int index){
    cout <<"Employee name : "<<"\t"<<"Employee ID : "<<"\t"<<"Employee Salary : "<<"\t"<<endl;
    cout <<e[index].emplname<<"\t\t\t\t"<<e[index].emplid<<"\t\t\t"<<e[index].emplsalary<<"\t";
    cout <<"\n";
}
void MyQue :: display(){
    cout <<"Working "<<endl;
if (r >= f && r>=0) {
    for (int i = f; i <= r; i++) {
        disprec(i);
    }
} 
else if(r<f && r>0) {
    for (int i = f; i < size; i++) {
        disprec(i);
    }
    for (int i = 0; i <= r; i++) {
        disprec(i);
    }
}
else{
	cout <<"Enter data to display ! "<<endl;
}
}
int main(){
    MyQue Q;
    int ne,nd;
    char ch;
    int choice;
    int counter = 0;
    do{
        cout <<"1.Add data\n2.Delete Data\n3.Display Data"<<endl;
        cin >> choice;
        switch (choice)
    {
    case 1:
    	
        cout <<"Enter no. of employees to add in the database: "<<endl;
        cin >>ne;
        if((Q.getsize()-counter)>=ne){
        	for(int i = 0 ; i<ne;i++){
            	Q.Equeue();
            	counter++;
            	}
            	}
        else{
        	cout <<"Enter valid input according to the size !"<<endl;
        }
        break;
    case 2:
        cout <<"Enter no. of employees to delete in the database: "<<endl;
        cin >>nd;
        if(counter>=nd){
        for(int i = 0 ; i<nd;i++){
            Q.Dqueue();
            counter--;
            }
            }
         else{
        	cout <<"Enter valid input according to the size !"<<endl;
        }
        break;
    case 3:
        Q.display();
        break;
    default:
        cout<<"You have enetered wrong choice !"<<endl;
        break;
    }
    cout <<"Do you want to continue(y or n) ? "<<endl;
    cin>>ch;
    }while (ch == 'y' || ch == 'Y');
  
return 0;
}
