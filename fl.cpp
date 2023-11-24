#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
struct Student{
	int roll_no;
	char name[15];
	char div[2];
};
class Mystdb{
	public: void add_db(){
		int n;
		ofstream file;
		cout <<"How many Students to add to database : "<<endl;
		cin >> n;
		file.open("std.txt",ios::app);
		for(int i = 0 ; i < n ; i++){
		Student stdrc;
		cout <<"Enter Roll Number of Student : "<<endl;
		cin >> stdrc.roll_no;
		cout << "Enter Name : "<<endl;
		cin >> stdrc.name;
		cout << "Enter Division"<<endl;
		cin >> stdrc.div;
		file.write((char*) &stdrc, sizeof(stdrc));
	}
	file.close();
	}
	public: void add_rc(){
		ofstream file;
		file.open("std.txt",ios::app);
		Student stdrc;
		cout <<"Enter Roll Number of Student : "<<endl;
		cin >> stdrc.roll_no;
		cout << "Enter Name : "<<endl;
		cin >> stdrc.name;
		cout << "Enter Division"<<endl;
		cin >> stdrc.div;
		file.write((char*) &stdrc, sizeof(stdrc));
	}
	public: void display_all(){
		ifstream file;
		Student stdrc;
		file.open("std.txt",ios::binary);
		while(file.read((char*) &stdrc, sizeof(stdrc))){
			cout <<"Student Name : "<<stdrc.name<<endl;
		}
		file.close();

	}
	public: void search(int rn){
		ifstream file;
		Student stdrc;
		file.open("std.txt",ios::binary);
		while(file.read((char*) &stdrc, sizeof(stdrc))){
			if(stdrc.roll_no == rn){
				cout << "Found "<< rn <<endl;
				file.close();
				return;
			}
		}
		cout << "Not Found "<<endl;
		file.close();

	}
	public: void del_rc(int key){
		ifstream file;
		file.open("std.txt",ios::binary);
		Student stdrc;
		ofstream temp;
		bool found = 0;
		temp.open("temp.txt",ios::binary);
		while(file.read((char*) &stdrc, sizeof(stdrc))){
			if(stdrc.roll_no != key){
				temp.write((char*) &stdrc, sizeof(stdrc));
			}
			else{
				found = 1;
			}
		}
		file.close();
		temp.close();
		remove("std.txt");
		rename("temp.txt","std.txt");
		if(found){
			cout << "Deleted : "<< key<<endl;
		}
		else{
			cout << "Element Not Found to Delete"<<endl;
		}
		
	}
	public: void modify_rc(int key){
		ifstream file;
		file.open("std.txt",ios::binary);
		Student stdrc;
		ofstream temp;
		bool found = 0;
		temp.open("temp.txt",ios::binary);
		while(file.read((char*) &stdrc, sizeof(stdrc))){
			if(stdrc.roll_no == key){
				cout << "Enter data to Modify "<<endl;
				cout <<"Enter Roll Number of Student : "<<endl;
				cin >> stdrc.roll_no;
				cout << "Enter Name : "<<endl;
				cin >> stdrc.name;
				cout << "Enter Division"<<endl;
				cin >> stdrc.div;
				found = 1;
			}
			temp.write((char*) &stdrc, sizeof(stdrc));
			}
		file.close();
		temp.close();
		remove("std.txt");
		rename("temp.txt","std.txt");
		if(found){
			cout << "Modified : "<< key<<endl;
		}
		else{
			cout << "Element Not Found to Modify"<<endl;
		}
	}
	public: void clear_db(){
		ofstream file;
		file.open("std.txt",ios::trunc);
		file.close();
	}





};
int main(){
	Mystdb s;
	s.add_db();
	s.display_all();
	s.search(16);
	s.del_rc(16);
	s.modify_rc(12);
	s.display_all();
	s.clear_db();
	s.add_rc();
	s.display_all();
}
