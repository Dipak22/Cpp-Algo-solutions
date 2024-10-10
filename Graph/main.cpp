#include<iostream>
#include "Graph.h"
#include<vector>
#include<stack>
#include<queue>

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
    visited[source] = true;
    list<int>::iterator i;
    for(i = this->adjacencyList[source].begin(); i!=this->adjacencyList[source].end();i++){
        if(visited[*i])
            continue;
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

Graph Graph::getTranspose(){
    Graph g(this->vertices);
    for(int v=0;v<this->vertices;v++){
        list<int>::iterator i;
        for(i= this->adjacencyList[v].begin(); i!=this->adjacencyList[v].end();i++){
            g.adjacencyList[*i].push_back(v);
        }
    }
    return g;
}

void Graph::utilityFunction(int source, int destination, vector <bool>& visited, vector<int>& path, int & pathIndex){
    visited[source] = true;
    path[pathIndex] = source;
    if(source ==destination){
        for(int i =0;i<=pathIndex;i++)
            cout<<path[i]<<" ";
        cout<<endl;
    }
    else{
        for(list<int>::iterator i = this->adjacencyList[source].begin(); i!=this->adjacencyList[source].end();i++){
            if(visited[*i])
                continue;
            utilityFunction(*i,destination,visited,path,++pathIndex);
        }
    }
    visited[source] = false;
    pathIndex--;
}


void Graph::printAllPaths(int source,int destination){
    vector<bool> visited(this->vertices,false);
    vector<int> path(this->vertices);
    int pathIndex =0;
    utilityFunction(source,destination,visited,path,pathIndex);
}
/*int main() {
  Graph g(9);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(1, 5);
  g.addEdge(2, 3);
  g.addEdge(2, 4);
  g.addEdge(5, 3);
  g.addEdge(5, 6);
  g.addEdge(3, 6);
  g.addEdge(6, 7);
  g.addEdge(6, 8);
  g.addEdge(6, 4);
  g.addEdge(7, 8);

  int source = 0, destination = 6;
  cout << "Paths from " << source << " to " << destination << endl;
  g.printAllPaths(source, destination);

  return 0;
}*/
void Graph::scUtility(int source, vector<bool>& visited){
    visited[source] = true;
    for(list<int>::iterator i = this->adjacencyList[source].begin(); i !=this->adjacencyList[source].end();i++){
        if(visited[*i])
            continue;
        scUtility(*i,visited);
    }
}
bool Graph::isStronglyConnected(){
    vector<bool> visited(this->vertices,false);
    scUtility(0,visited);
    for(int i =0;i<this->vertices;i++){
        if(!visited[i])
            return false;
        
    }
    Graph g = this->getTranspose();
    for(int i =0;i<g.vertices;i++)
        visited[i] = false;
    g.scUtility(0,visited);
    for(int i =0;i<g.vertices;i++){
        if(!visited[i])
            return false;
    }
    return true;

}
/*int main() {
  Graph g1(5);
  g1.addEdge(0, 1);
  g1.addEdge(1, 2);
  g1.addEdge(2, 3);
  g1.addEdge(3, 0);
  g1.addEdge(2, 4);
  g1.addEdge(4, 2);
  
  if(g1.isStronglyConnected())
    cout << "Yes Graph1 is strongly connected\n"; 
  else
    cout << "No Graph1 is not strongly connected\n";

  Graph g2(4);
  g2.addEdge(0, 1);
  g2.addEdge(1, 2);
  g2.addEdge(2, 3);
  
  if(g2.isStronglyConnected())
    cout << "Yes Graph2 is strongly connected\n"; 
  else
    cout << "No Graph2 is not strongly connected\n";

  return 0;
} */
void Graph::printConnectedComponents(){
    bool* visited = new bool[this->vertices];
    fill(visited,visited+this->vertices,false);
    for(int i =0;i<this->vertices;i++){
        if(!visited[i]){
            dfsUtility(i,visited);
            cout<<endl;
        }
    }
}
/*int main() {
  Graph g(7);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(3, 4);
  g.addEdge(5, 3);
  g.addEdge(5, 6);
  g.addEdge(3, 6);

  cout << "The connected components are:" << endl;
  g.printConnectedComponents();

  return 0;
}*/

bool Graph::willCauseSeparateComponents(int u,int v){
    this->adjacencyList[u].remove(v);
    this->adjacencyList[v].remove(u);
    vector<bool> visited(this->vertices,false);
    scUtility(0,visited);
    for(int i=1;i<this->vertices;i++){
        if(!visited[i])
            return !false;
    }
    return !true;

}

/* int main() {
  Graph g(5);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 4);
  g.addEdge(0, 4);
  
  // remove edge 3 -> 4
  if(g.willCauseSeparateComponents(3, 4))
    cout << "Yes, separate components created due to deletion of edge 3 -> 4" << endl;
  else
    cout << "No, separate components not created due to deletion of edge 3 -> 4"<< endl;
  
  // remove edge 1 -> 2
  if(g.willCauseSeparateComponents(1, 2))
    cout << "Yes, separate components created due to deletion of edge 1 -> 2"<< endl;
  else
    cout << "No, separate components not created due to deletion of edge 1 -> 2"<< endl;

  return 0;
} */
bool Graph::utilityFunction(int v, vector<bool>& visited, vector<bool>& color){
    visited[v] = true;
    for(list<int>::iterator i = this->adjacencyList[v].begin(); i!=this->adjacencyList[v].end(); i++){
        if(visited[*i]){
            if(color[*i] == color[v])
                return false;
        }else{
            color[*i] = !color[v];
            if(!utilityFunction(*i,visited,color))
                return false;
        }
    }
    return true;
}

bool Graph::isBipartite(int source){
    vector<bool> visited(this->vertices,false);
    vector<bool> color(this->vertices,false);
    return utilityFunction(source,visited,color);

}
/* int main() { 
	int V = 6; 
  Graph g(V);

	g.addEdge(0, 1); 
	g.addEdge(1, 2); 
	g.addEdge(2, 3); 
	g.addEdge(3, 4); 
	g.addEdge(4, 5); 
	g.addEdge(5, 0); 
  
  //Example 1
  int source = 0;
  if (g.isBipartite(source)){
    cout << " Graph1 is bipartite" << endl;
  }
  else
    cout << " Graph1 is not bipartite" << endl;
  cout << endl;
  
  
  V = 5; 
  Graph g1(V);

	g1.addEdge(0, 1); 
	g1.addEdge(0, 2); 
	g1.addEdge(0, 3); 
	g1.addEdge(0, 4); 
	g1.addEdge(1, 2); 
  
  //Example 2
  if (g1.isBipartite(source)){
    cout << " Graph2 is bipartite" << endl;
  }
  else
    cout << " Graph2 is not bipartite" << endl;
  cout << endl;
} */

void Graph::topologicalSort(){
    vector<int> inDegree(this->vertices,0);
    queue<int> myQueue;
    vector<int> topologicalOrd;
    for(int i=0;i<this->vertices;i++){
        list<int>::iterator it;
        for(it = this->adjacencyList[i].begin(); it != this->adjacencyList[i].end(); it++){
            inDegree[*it] +=1;
        }
    }
    for(int i =0;i<this->vertices;i++){
        if(inDegree[i]==0)
            myQueue.push(i);
    }
    while(!myQueue.empty()){
        int v = myQueue.front();
        topologicalOrd.push_back(v);
        myQueue.pop();
        list<int>::iterator it;
        for(it = this->adjacencyList[v].begin(); it != this->adjacencyList[v].end(); it++){
            inDegree[*it] -=1;
            if(inDegree[*it]==0)
                myQueue.push(*it);
        }
    }
    for(int i=0;i<topologicalOrd.size();i++)
        cout<<topologicalOrd[i]<<" ";
    cout<<endl;
}

int main() {
  Graph g(6); 
	g.addEdge(5, 0); 
	g.addEdge(5, 2); 
	g.addEdge(4, 2); 
	g.addEdge(4, 1); 
	g.addEdge(2, 3); 
	g.addEdge(3, 1); 

	cout << "Graph1 Topological Sort: ";  
	g.topologicalSort();
  
  cout << endl << endl;
  
  Graph g1(5);
  g1.addEdge(0 ,1);
  g1.addEdge(1 ,2);
  g1.addEdge(2 ,3);
  g1.addEdge(2 ,4);
  g1.addEdge(3, 4);
  g1.addEdge(0, 3);
  
  cout << "Graph2 Topological Sort: "; 
	g1.topologicalSort(); 

  return 0;
}
