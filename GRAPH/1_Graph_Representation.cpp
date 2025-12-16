#include<bits/stdc++.h>
using namespace std;

int main(){

    int v,e;
    cout<<"Enter the number of vertices and edges -"<<endl;
    cin>>v>>e;

    //Adjacency Matrix
    vector<vector<int>> adjMatrix(v, vector<int>(v,0));

    //Adjacency List
    vector<vector<int>> adjList(v);

    cout<<"enter edges (u v): "<<endl;

    for(int i=0;i<e;i++){
        int U,V;
        cin>>U>>V;

        adjMatrix[U][V]=1;
        adjMatrix[V][U]=1;

        adjList[U].push_back(V);
        adjList[V].push_back(U);

    }
    cout<<"Adjacency Matrix is - "<<endl;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;

    }

    cout<<"Adacency List is - "<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<" -> ";
        for(int neighbour : adjList[i]){
            cout<<neighbour<<" ";
        }
        cout<<endl;
    }
    return  0;
}