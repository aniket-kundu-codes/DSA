#include<bits/stdc++.h>
using namespace std;

//Finding strongly connected components from a given directed graph
void strongly_connected(long long n,vector<long long> *AdjList)
{
   //Kosaraju's algorithm

   stack<long long> st; // more top -> more finishing time
   bool visited[n];
   memset(visited,false,sizeof(visited));
   

   function<void(long long)> DFS=[&](long long node)
   {
     visited[node]=true;
     for(long long child_id=0;child_id<AdjList[node].size();child_id++)
        if(!visited[AdjList[node][child_id]])
         DFS(AdjList[node][child_id]);

     st.push(node);
   };
   for(long long i=0;i<n;i++)
    if(!visited[i])
     DFS(i);

    //reverse the graph
    vector<long long> rev_adj[n];
    for(long long parent=0;parent<n;parent++)
     for(auto&child:AdjList[parent])
      rev_adj[child].push_back(parent);

    // Run DFS in-order from the stack, and gets Strongly Connected (SCC)
    memset(visited,false,sizeof(visited));

   function<void(long long)> DFS2=[&](long long node)
   {
     cout<<node<<" ";
     visited[node]=true;
     for(long long child_id=0;child_id<rev_adj[node].size();child_id++)
      if(!visited[rev_adj[node][child_id]])
       DFS2(rev_adj[node][child_id]);
   };    
    while(!st.empty())
    {
        long long node=st.top();
        st.pop();
        if(!visited[node])
         {
            cout<<"SCC : ";
            DFS2(node);
            cout<<endl;
         }
    }
}
int  main()
{
    long long n,m;
    cin>>n>>m;
    vector<long long> adj[n];
    for(long long i=0;i<m;i++)
    {
        // x-->y
        long long x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    strongly_connected(n,adj);
    return 0;
}