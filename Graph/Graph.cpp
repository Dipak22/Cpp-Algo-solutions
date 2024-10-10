#include"Graph.h"
Graph::Graph(){
    vertices = 0;
}

Graph::Graph(int v){
    vertices = v;
    adjacencyList = new list<int>[v];
}

void Graph::addEdge(int u,int v){
    if(v<vertices && u<vertices){
        adjacencyList[u].push_back(v);
    }
}

void Graph::printGraph(){
    for(int v=0;v<vertices;v++){
        cout<<v<<" -> ";
        for(list<int>::iterator i = adjacencyList[v].begin(); i!=adjacencyList[v].end();i++ ){
            cout<<" "<<*i;
        }
        cout<<endl;
    }

}

