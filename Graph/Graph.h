#ifndef graph
#include<list>
#include<vector>
#include<iostream>
using namespace std;
class Graph{
    int vertices;
    list<int> *adjacencyList;
    public:
    Graph();
    Graph(int v);
    void addEdge(int u,int v);
    void BFS(int source);
    void BFSRecurse(int source);
    void bfsUtility(list<int> &queue, bool *visited);
    void DFS(int source);
    void DFSRecurse();
    void dfsUtility(int source,bool* visited);
    int numberOfNodesInGivenLevel(int level);
    void modifiedDFS(vector<bool>& visited, int source, int& currentLevel, int level, int& numberOfNodes);
    Graph getTranspose();
    void printGraph();
    void printAllPaths(int source,int destination);
    void utilityFunction(int source, int destination, vector <bool>& visited, vector<int>& path, int & pathIndex);
    bool isStronglyConnected();
    void scUtility(int source,vector<bool>& visited);
    void printConnectedComponents();
    bool willCauseSeparateComponents(int u,int v);
    bool isBipartite(int source);
    bool utilityFunction(int v, vector<bool>& visited, vector<bool>& color);
    void topologicalSort();
};

#endif