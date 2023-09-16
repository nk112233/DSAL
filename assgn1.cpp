// WAP to accept student database and perform different searching operations : Linear , Binary and sorting algorithms : Bubble, Insertion , Quick

#include <iostream>

using namespace std;
struct Student {
	int rno;
	string name;
	double sgpa;
	};

class SE11{
	private: struct Student S[25];
	private: int n;
	public: SE11(){
		S[0] = {1,"a",4.6};
		S[1] = {2,"b",6.7};
		S[2] = {5,"z",5.4};
		S[3] = {24,"d",9.6};
		S[4] = {38,"e",9.23};
		S[5] = {16,"m",7.38};
		S[6] = {56,"r",2.4};
		S[7] = {72,"h",8.82};
		S[8] = {45,"i",9.71};
		S[9] = {13,"j",9.06};
		S[10] = {12,"k",8.52};
		S[11] = {52,"y",6.2};
		S[12] = {50,"t",2.23};
		S[13] = {48,"q",7.9};
		S[14] = {32,"o",3.4};
		n = 15;


	}
	public: 
		
	 	void accept();
		int getsize();
	 	void display();
	 	void linear_sgpa();
	 	void disp_one(int index);
	 	void menu();
		void swap(int i,int j);
	 	void bubl_rno();
	 	void bnrys_rno();
	 	void name_sort();
		void qcksrt_sgpa(int l,int h);
		int b_arr(int l,int h);
		void sgpa_sort();
		void name_search();
		void disp10();
		
	};
int SE11 :: getsize(){
	return n;


}
void SE11 :: accept(){
	cout << "Enter How many student's databse to add : "<<endl;
	cin >>n;
	for(int i= 0;i<n;i++){
		
		cout << "Enter Roll No. of Student : "<<endl;
		cin >> S[i].rno;
		cout << "Enter Name of Student : "<<endl;
		cin >> S[i].name;
		cout << "Enter SGPA of Student : "<<endl;
		cin >> S[i].sgpa;
	
	}

}
    void SE11 :: menu(){
    	cout<<endl;
        cout<<"Enter the operation: "<<endl;
        cout<<"1. Display all student records "<<endl;
        cout<<"2. Display student record "<<endl;                 // menu
        cout<<"3. Sort by roll numbers" <<endl;
        cout<<"4. Sort by Names"<<endl;
        cout<<"5. Search by Names"<<endl;
        cout<<"6. Sort by SGPA"<<endl;
        cout<<"7. Search SGPA"<<endl;
        cout<<"8. Display 10 Toppers"<<endl;
        cout<<endl;


    }
void SE11 :: display(){

	for(int i = 0 ; i < n ; i++){
			disp_one(i);
		
	}



}
void SE11 :: name_search() {                                 //Binary search for names
        int l=0;
        int h=n-1;
        char elem[50];

        cout<<"Enter the name to be searched: "<<endl;
        cin>>elem;

        while(h>=l){
            int mid=(l + h)/2;

           

            if (S[mid].name==elem){
                cout<<"Name found at location: "<<mid+1<<endl;
				disp_one(mid);
                return;
            }
            else if(S[mid].name<elem){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        cout<<"Name not found in the array."<<endl;
    }

void SE11 :: linear_sgpa(){
	double tsgpa;
	cout <<"Enter the Sgpa for which you have to display data : "<<endl;
	cin >> tsgpa;										//linearsearch for sgpa
	for(int i = 0 ; i<n;i++){
		cout <<"Searching on index "<<i<<endl;
		if( tsgpa == S[i].sgpa){
			disp_one(i);
		}
	
	}
}

void SE11 :: qcksrt_sgpa(int l , int h){
	int index;											//quicksort for sgpa
	if(l<h){
		index = b_arr(l,h);
		qcksrt_sgpa(l,index-1);
		qcksrt_sgpa(index+1,h);
}

}
void SE11 :: swap(int i,int j){
		struct Student t;
		t = S[i];									//swap
		S[i] = S[j];
		S[j] = t;
	
	
}	
int SE11 :: b_arr(int l,int h){
	 int i,j;
	float pivot = S[l].sgpa;
	cout <<"pivot = "<<pivot<<"\t";					//partition for quicksort
	
	i = l;
	cout <<"i = "<<	i<<"\t";
	
	j = h;
	cout <<"j = "<<	j<<"\t";
	cout<<endl;
	
	while(i<j){
		while(pivot>=S[i].sgpa && i<=h){	
			
				i++;
			

		
		}
	
		while(S[j].sgpa>pivot && j>l){
			
				 j--;
			

		
		}
		cout <<"swi = "<< i <<"\t";
		cout <<"swj = "<< j <<endl;
		cout<<"before swap element: "<<"\t";
		 for(int p = 0; p<=h;p++){
	  	cout << S[p].sgpa<<" , ";
	 }
	 	cout<<endl;
		if(i<j){
			swap(i,j);
		}
		cout<<"after swap element: "<<"\t";
		 for(int p = 0; p<=h;p++){
	  	cout << S[p].sgpa<<" , ";
	 }
	 	cout<<endl;
	}
		 
			swap(j,l);
			
		cout<<"after swap pivot: "<<"\t";
		 for(int p = 0; p<=h;p++){
	  	cout << S[p].sgpa<<" , ";
	 }
	 cout<<endl;
		return j;
	
	 for(int p = 0; p<=h;p++){
	  	cout << S[p].sgpa<<" , ";
	 }
	
	
	 }
	
void SE11 :: sgpa_sort(){
    	qcksrt_sgpa(0,n-1);
    }
    
    
void SE11 :: name_sort(){                           //insertion sort for names
    
        for(int i=1;i<n;i++){
            Student key=S[i];
            int j=i-1;
            while(j>=0 && S[j].name>key.name)
            {
                S[j+1]=S[j];
                j--;
				
            }
			cout <<i<<" iteration"<<endl;
			cout <<"key = "<<key.name<<"\t";
			for(int p = 0; p<n;p++){
	  			cout << S[p].name<<" , ";
	 }
	 cout <<endl;
             S[j+1]=key;
        }
	
    }	
	






void SE11 :: disp_one(int index){
	cout <<"******************************************************"<<endl;
	cout << "Name : "<< S[index].name << endl;
	cout << "Roll_No : "<< S[index].rno << endl; 
	cout << "SGPA : "<< S[index].sgpa << endl;
	cout <<"******************************************************"<<endl;





}

void SE11 :: bubl_rno(){

	for(int j = 1;j<n-1;j++){
		int counter = 0;
		for(int i = 0 ; i<n-j;i++){
			if(S[i].rno > S[i+1].rno){
				int j = i+1;
				swap(i,j);
				counter++;										//bubble sort
			
			
			}
		
		}
		cout <<j<<" iteration"<<endl;
		for(int p = 0; p<n;p++){
	  		cout << S[p].rno<<" , ";
	 }
	 cout <<endl;
		if (counter == 0){
			break;
		
		
		}
	
	
	
	}






}
void SE11 :: bnrys_rno(){
	int m,l,u,rn;
	l = 0;
	u  = n-1;
	
	cout << "Enter the rollno. to display info of : "<<endl;
	cin >> rn;
	
	while(l < u){												//binary search
		m = (l+u)/2;
		cout << "l = "<<l<<"\t";
		cout << "u = "<<u<<"\n";
		if(rn == S[l].rno){
			disp_one(l);
			break;
			
			
		
		
		
		}
		else if(rn == S[u].rno){
			disp_one(u);
			break;
			
		
		
		
		
		}
		else if(rn  == S[m].rno){
			disp_one(m);
			break;
			
			
			
		
		
		
		}
		else if(rn > S[m].rno){
			l = m+1;
			
			
			}
		else if(rn < S[m].rno){
			u = m-1;
		
		
		}
		else {
			cout << "Roll No. not found!"<<endl;
		
		
		}
		
		
		
		}
	



}
void  SE11 :: disp10(){
	for(int i = n-1;i>n-1-10;i--){
		disp_one(i);
	}



}


int main() {
    SE11 SD1;
    // SD1.accept();
    int n,choice;

    do {
       SD1.menu();
    	cout <<"Enter choice : "<<endl;
    	cin >> choice;
		


        switch (choice) {
           
            case 1:
               // Display all students
                SD1.display();
                break;
               
            case 2:
            	int index;
            	cout <<"Enter index: "<<endl;
            	cin >>index;
            	SD1.disp_one(index);
				break;
               
            case 3:
            	SD1.bubl_rno();
          		SD1.bnrys_rno();
          	break;
            case 4:
            	SD1.name_sort();
            	cout<<"Sorted names"<<endl;
            	break;

            case 5:
            	SD1.name_search();
            	break;

            case 6:
            	SD1.sgpa_sort();
            	cout << "Sorted by SGPA." << endl;
            	break;

            case 7:
            	SD1.linear_sgpa();
            	break;

			case 8:
				SD1.disp10();
				break;

            case 9:
            	exit(0);
                
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}












