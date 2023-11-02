#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ofstream myfile ("expl.txt");
	if(myfile.is_open()){
		myfile << "This is a line.\n";
    	myfile << "This is another line.\n";
	}
	myfile.close();
	string line;
  	ifstream mfile ("expl.txt");
  	if (mfile.is_open()){	
    	while ( getline(mfile,line) ){
      		cout << line << '\n';
    	}
 	}
  	myfile.close();
return 0;
}
