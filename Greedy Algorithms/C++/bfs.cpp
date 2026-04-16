#include<bits/stdc++.h>
using namespace std;
void bfs(int st,vector<vector<int>>&graph,int n){
    vector<bool>vis(n,false);
    queue<int>q;
    q.push(st);
    vis[st]=true;
    while (q.size()>0)
    {
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(int it:graph[node]){
            if(!vis[it]){
                q.push(it);
                vis[it]=true;
            }
        }

    }
    
}
int main(){
    cout<<"enter the number of nodes and edges"<<endl;
    int nodes,edges;
    cin>>nodes>>edges;
    vector<vector<int>>graph(nodes);
    for(int i=0;i<edges;i++){
        cout<<"enter the edges"<<endl;
        int src,dst;
        cin>>src>>dst;
        graph[src].push_back(dst);
        graph[dst].push_back(src);
    }
    cout<<"\n BFS traversal"<<endl;
    bfs(0,graph,nodes);
}