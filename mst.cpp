#include <iostream>
using namespace std;
struct Edge{
	int v1;
	int v2;
	int w;
};
class MyGraph{
	private: 
		int v,ec;
		int Am[10][10];
		Edge E[10];
		public: void AcceptG(){
				int cont;
				int c = 0;
				cout <<"Enter Number of Vertices in Graph : "<<endl;
				cin >> v;
				for(int i = 0 ; i < v ; i++){
					for(int j = 0 ; j<v ; j++){
						Am[i][j] = 0;
					}
				}
				do{
					int v1,v2,w;
					cout << "Enter the First Vertex : "<<endl;
					cin >> v1;
					cout << "Enter the Second Vertex : "<<endl;
					cin >> v2;
					cout << "Enter The Weight of the edge connecting the edges"<<endl;
					cin >> w;
					Am[v1][v2] = w;
					Am[v2][v1] = w;
					E[c].v1 = v1;
					E[c].v2 = v2;
					E[c].w = w;
					c++;
					ec = c;
					cout <<"Do you want to continue?(Press 1 or 0)"<<endl;
					cin >> cont;
				}while(cont);
			
			}
		public: void display(){
			cout << "Adjacency Matrix"<<endl;
			for(int i = 0 ; i < v ; i++){
				for(int j = 0 ; j<v ; j++){
					cout << Am[i][j]<<" ";
		
				}
				cout <<endl;
			}
			cout <<"Adjacency List"<<endl;
			for(int i = 0 ; i <ec ; i++){
				cout <<" V1 = "<< E[i].v1 <<" "<<" V2 = "<< E[i].v2 << " " << " "<< " w = "<< E[i].w <<endl;
			}
			}


































};
int main(){
	MyGraph graph;
	graph.AcceptG();
	graph.display();
	
	
	
	
	
	
	
	
	
	



return 0;
}
