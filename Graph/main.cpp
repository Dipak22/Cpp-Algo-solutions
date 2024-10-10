#include<iostream>
#include "Graph.h"
#include<vector>
#include<stack>

void Graph::BFS(int source){
    list<int> queue;
    vector<bool> visited(this->vertices,false);
    queue.push_back(source);
    visited[source] = true;
    while(!queue.empty()){
        int node = queue.front();
        queue.pop_front();
        cout<<node<<" -> ";
        list<int> neig = this->adjacencyList[node];
        list<int>::iterator i;
        for(i = neig.begin() ; i!=neig.end();i++){
            if(visited[*i])
                continue;
            queue.push_back(*i);
            visited[*i] = true;
        }
    }
    cout<<"end";
}

void Graph::bfsUtility(list<int>& queue, bool* visited){
    if(queue.empty())
        return;
    int node = queue.front();
    cout<<node<<" ";
    queue.pop_front();
    list<int>:: iterator i;
    for(i = this->adjacencyList[node].begin() ; i != this->adjacencyList[node].end();i++){
        if(visited[*i])
            continue;
        queue.push_back(*i);
        visited[*i] = true;
    }
    bfsUtility(queue,visited);
}

void Graph::BFSRecurse(int source){
    list<int> queue;
    bool* visited = new bool[this->vertices];
    fill(visited,visited+this->vertices,false);
    queue.push_back(source);
    visited[source] = true;
    bfsUtility(queue,visited);
}

void Graph::DFS(int source){
    vector<bool> visited(this->vertices,false);
    stack<int> stk;
    stk.push(source);
    visited[source] = true;
    while(!stk.empty()){
        int node = stk.top();
        stk.pop();
        cout<<node<<" ";
        list<int>::iterator i;
        for(i = this->adjacencyList[node].begin(); i!= this->adjacencyList[node].end();i++){
            if(visited[*i])
                continue;
            stk.push(*i);
            visited[*i] = true;
        }
    }
}

void Graph::dfsUtility(int source,bool* visited){
    cout<<source<<" ";
    list<int>::iterator i;
    for(i = this->adjacencyList[source].begin(); i!=this->adjacencyList[source].end();i++){
        if(visited[*i])
            continue;
        visited[*i] = true;
        dfsUtility(*i,visited);
    }
}
void Graph::DFSRecurse(){
    bool* visited = new bool[this->vertices];
    fill(visited,visited+this->vertices,false);
    for(int i =0;i<this->vertices;i++){
        if(visited[i]==false){
            visited[i] = true;
            dfsUtility(i,visited);
        }
    }

}
/*int main() {
  Graph g(6);
  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(1,3);
  g.addEdge(2,4); 
  g.addEdge(3,4); 
  g.addEdge(3,5);
  g.BFS(0);
  cout<<endl;
  g.BFSRecurse(0);
  cout<<endl;
  g.DFS(0);
  cout<<endl;
  g.DFSRecurse();

  return 0;
} */

void Graph::modifiedDFS(vector<bool>& visited,int source, int& currentLevel, int level, int& numberOfNodes){
    visited[source] = true;
    if(currentLevel>level)
        return;
    else if(currentLevel == level)
        numberOfNodes++;
    else{
        list<int>::iterator i;
        for(i = this->adjacencyList[source].begin(); i!= this->adjacencyList[source].end();i++){
            if(visited[*i])
                continue;
            currentLevel++;
            modifiedDFS(visited,*i,currentLevel,level,numberOfNodes);
        }
    }
    currentLevel--;
}
int Graph::numberOfNodesInGivenLevel(int level){
   /* vector<int> visited(this->vertices,0);
    visited[0] =1;
    list<int> queue;
    queue.push_back(0);
    while(!queue.empty()){
        int node = queue.front();
        queue.pop_front();
        list<int>::iterator i;
        for(i = this->adjacencyList[node].begin(); i!=this->adjacencyList[node].end();i++){
            if(visited[*i] ==0){
                visited[*i] = visited[node] +1;
                queue.push_back(*i);
            }
        }
    }
    int count = 0;
    for(int i =0;i<visited.size();i++){
        if(visited[i] == level)
            count++;
    }
    return count; */

    vector<bool> visited(this->vertices,false);
    int numNodes = 0;
    int currLevel = 1;
    int source = 0;
    modifiedDFS(visited,source,currLevel,level,numNodes);
    return numNodes;
}
/*int main() { 
	Graph g(6);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 3);
  g.addEdge(2, 4);
  g.addEdge(3, 5); 

	int level = 1;
	cout << "The number of nodes at level " << level << " are: " << g.numberOfNodesInGivenLevel(level) << endl; 

	level = 2;
	cout << "The number of nodes at level " << level << " are: " << g.numberOfNodesInGivenLevel(level) << endl; 

	level = 3;
	cout << "The number of nodes at level " << level << " are: " << g.numberOfNodesInGivenLevel(level) << endl; 
	return 0; 
}  */

void Graph::getTranspose(){
    Graph g(this->vertices);
    for(int v=0;v<this->vertices;v++){
        list<int>::iterator i;
        for(i= this->adjacencyList[v].begin(); i!=this->adjacencyList[v].end();i++){
            g.adjacencyList[*i].push_back(v);
        }
    }
    g.printGraph();
}

int main() {
  Graph g1(5);
  g1.addEdge(0, 1);
  g1.addEdge(1, 2);
  g1.addEdge(2, 3);
  g1.addEdge(3, 0);
  g1.addEdge(2, 4);
  g1.addEdge(4, 2);
  cout << "Transpose of given Graph: " << endl;
  g1.getTranspose();
  cout << endl << endl;

  return 0;
}
