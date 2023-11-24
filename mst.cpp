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
		int parent[100];
		int Am[10][10] = {{0,4,0,4},{4,0,3,2},{0,3,0,5},{4,2,5,0}};
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
			v = 4;
			cout << "Adjacency Matrix"<<endl;
			for(int i = 0 ; i < v ; i++){
				for(int j = 0 ; j<v ; j++){
					cout << Am[i][j]<<" ";
		
				}
				cout <<endl;
			}
			// cout <<"Adjacency List"<<endl;
			// for(int i = 0 ; i <ec ; i++){
			// 	cout <<" V1 = "<< E[i].v1 <<" "<<" V2 = "<< E[i].v2 << " " << " "<< " w = "<< E[i].w <<endl;
			// }
			 }
		public: int prims() {
			v = 4;
			int Visited[v], P[v], D[v];
			for (int i = 0; i < v; i++) {
				Visited[i] = 0;
				P[i] = 0;
				D[i] = 32767;
			}
			int current = 0;
			int totalvisited = 1;
			int mincost = 32767;
			Visited[current] = 1;
			D[current] = 0;
			while (totalvisited != v) {
				for (int i = 0; i < v; i++) {
					if (Am[current][i] != 0 && Visited[i] == 0) {
						D[i] = min(D[i], Am[current][i]);
						P[i] = current;
					}
				}

				// Update this part within the loop
				mincost = 32767;
				for (int i = 0; i < v; i++) {
					if (Visited[i] == 0 && D[i] < mincost) {
						mincost = D[i];
						current = i;
					}
				}
				Visited[current] = 1;
				totalvisited += 1;
			}

			// Calculate the total minimum cost
			mincost = 0;
			for (int i = 0; i < v; i++) {
				mincost += D[i];
				cout << "i = " << i << " Parent: " << P[i] << endl;
			}
			return mincost;
		}
		int find(int i){
			while (parent[i] != i){
			i = parent[i];
			return i;
			}
		}
		void union1(int i, int j){
			int a = find(i);
			int b = find(j);
			parent[a] = b;
			}
			int kruskal(){
			int mincost = 0; // Cost of min MST.
			for (int i = 0; i < v; i++)
				parent[i] = i;
			// Include minimum weight edges one by one
			int edge_count = 0;
			while (edge_count < v - 1) {
				int min = 32767;
				int  a = -1;
				int b = -1;
				for (int i = 0; i < v; i++) {
					for (int j = 0; j < v; j++) {
						if (find(i) != find(j) && Am[i][j] < min){
							min = Am[i][j];
							a = i;
							b = j;
						}
					}
				}
				union1(a, b);
				mincost += min;
			}
			return mincost;
			}






};
int main(){
	MyGraph graph;
	// graph.AcceptG();
	graph.display();
	int min = graph.prims();
	int minkr = graph.kruskal();
	cout <<"Minimum Cost : "<<min<<endl;
	cout <<"Minimum Cost : "<<minkr<<endl;
	
	
	
	
	
	
	
	
	



return 0;
}
