#include <iostream>
#include <climits>

using namespace std;

class MyGraph
{
private:
    int arr[20][20];
    int n, m;

    bool visit[20];
    int distance[20];
    int parent[20];

public:
    void addGraph(int arr1[]);
    void dijsktras(int arr1[], int s);
    void printShortestPath(int arr1[], int s);
};

void Graph::dijsktras(int arr1[], int s)
{
    for (int i = 0; i < n; i++)
    {
        parent[arr1[i]] = -1;

        if (arr[s][i] != 0)
        {
            distance[i] = arr[s][i];
        }
        else
        {
            distance[i] = INT_MAX;
        }
    }

    distance[s] = 0;

    for (int i = 0; i < n; i++)
    {
        int minDist = INT_MAX;
        int curr = -1;

        for (int j = 0; j < n; j++)
        {
            if (!visit[arr1[j]] && distance[arr1[j]] < minDist)
            {
                minDist = distance[arr1[j]];
                curr = arr1[j];
            }
        }

        if (curr == -1)
        {
            break; 
        }

        visit[curr] = true;

        for (int j = 0; j < n; j++)
        {
            if (!visit[arr1[j]] && arr[curr][arr1[j]] != 0)
            {
                int newDistance = distance[curr] + arr[curr][arr1[j]];
                if (newDistance < distance[arr1[j]])
                {
                    distance[arr1[j]] = newDistance;
                    parent[arr1[j]] = curr;
                }
            }
        }
    }
}

void Graph::shrtpath(int arr1[], int s)
{
    cout << "Shortest paths from source " << s << " to other vertex:" << endl;

    for (int i = 0; i < n; i++)
    {
        if (arr1[i] != s)
        {
            cout << "Vertex " << arr1[i] << ": Distance = " << distance[arr1[i]] << ", Path = ";
            int currentVertex = arr1[i];
            while (currentVertex != -1)
            {
                cout << currentVertex << " to ";
                currentVertex = parent[currentVertex];
            }
            cout << s;
            cout << endl;
        }
    }
}

void Graph::addGraph(int arr1[])
{
    for (int i = 0; i < 20; i++)
    {
        visit[i] = false;
        parent[i] = -1;
        distance[i] = INT_MAX;
        for (int j = 0; j < 20; j++)
        {
            arr[i][j] = 0;
        }
    }

    cout << "Enter the number of vertices" << endl;
    cin >> n;
    cout << "Enter the number of edges" << endl;
    cin >> m;
    cout << "Enter the vertices of graph" << endl;
    for (int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    int u, v, w;

    for (int i = 0; i < m; i++)
    {
        cout << "Enter the first vertex and last vertex" << endl;
        cin >> u >> v;
        cout << "Enter the weight of edge" << endl;
        cin >> w;

        arr[u][v] = w;
        arr[v][u] = w; 
    }
}

int main(){
    MyGraph graph;
    int vertices[20];

    graph.addGraph(vertices);

    int srcv;
    cout << "Enter the source vertex: ";
    cin >> srcv;

    graph.dijsktras(vertices, sourceVertex);
    graph.shrtpath(vertices, sourceVertex);

    return 0;
}
