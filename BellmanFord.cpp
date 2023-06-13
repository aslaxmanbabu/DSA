#include <iostream>
using namespace std;

class Edge {
    public:
    int src, dest, weight;    
};

class Graph {
    public:
        int V, E;
        Edge *edge = new Edge();
        Graph *createGraph(int , int );
        void printArr(int[] , int );
        void BellmanFord(Graph *, int );    
};

Graph * Graph :: createGraph(int V, int E) {
    Graph *graph = new Graph();
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void Graph :: printArr(int dist[], int n) {
    cout<<"Vertex\tDistance from Source"<<endl;
    for(int i=0; i<n; i++) {
        cout<<i<<"\t"<<dist[i]<<endl;
    }
}

void Graph :: BellmanFord(Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    
    for(int i=0; i<V; i++) {
        dist[i] = 999;
    }
    dist[src] = 0;
    for(int i=1; i<=V-1; i++) {
        for(int j=0; j<E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            
            if(dist[u] != 999 and dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    printArr(dist, V);
}

int main()
{
    int V, E, i, T;
    cout<<"Enter number of vertices: ";
    cin>>V;
    cout<<"Enter number of egdes: ";
    cin>>E;
    Graph * graph = graph->createGraph(V, E);
    
    for(int i=0; i<E; i++) {
        cout<<"Enter source "<<i<<": ";
        cin>>graph->edge[i].src;
        cout<<"Enter destination "<<i<<": ";
        cin>>graph->edge[i].dest;
        cout<<"Enter Weight "<<i<<": ";
        cin>>graph->edge[i].weight;
    }
    
    cout<<"Enter the source node for traversal: ";
    cin>>T;
    
    graph->BellmanFord(graph, T);
    
    return 0;
}
