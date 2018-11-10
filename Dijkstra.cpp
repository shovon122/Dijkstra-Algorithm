#include<queue>
#include<iostream>
//#include<bits/stdc++.h>
using namespace std;

int vertex[100][100],parent[100],d[100],w[100][100],vertex_number;

void Dijkstra(int s)
{
    int u;
    priority_queue<int, vector<int>, greater<int> >Q;
    Q.push(d[s]);

    while(!Q.empty())
    {
        u=Q.top();
        for(int i=1;i<=vertex_number;i++){
           if(u==d[i]){
              s=i;
              break;
           }
        }
        Q.pop();
        for(int i=1; i<=vertex_number; i++)
        {
            if(vertex[s][i]==1&&d[i]>(d[s]+w[s][i]))
            {
                parent[i]=s;
                d[i]=d[s]+w[s][i];
                Q.push(d[i]);
            }
        }
    }

}

void FindPath(int s)
{
    if(parent[s]==-1){
        cout<<s<<"\t" ;
         return;
    }
   FindPath(parent[s]);
   cout<<s<<"\t" ;
}

int main()
{
    int edge_number,v1,v2;
    cout<<"Enter the number of vertex :"<<endl;
    cin>>vertex_number;

    for(int i=1;i<=vertex_number;i++){
         for(int j=1;j<vertex_number;j++){
                vertex[i][j] =0;
         }
    }

    edge_number=1;
    while(1){
       cout<<"Edge "<<edge_number<< ":"<<endl;
        cin>>v1>>v2;

        if((v1<=vertex_number && v1>=1) &&(v2<=vertex_number && v2>=1)){
           cout<<"Enter the weight :"<<endl;
           cin>>w[v1][v2];
           vertex[v1][v2]=1;
           edge_number++;
        }
        else if(v1==0 && v2==0){
              break;
        }
        else{
             cout<<"Invalid Input"<<endl;
        }
    }

        for(int i=1;i<=vertex_number;i++){
             for(int j=1;j<vertex_number;j++){
                   cout<<vertex[i][j]<<" ";
             }
            cout<<endl;
        }

        int source;
        cout<<"Enter the source :"<<endl;
        cin>>source;

        for(int i=1;i<=vertex_number;i++){
              d[i]=100000;
              parent[i]=-1;
        }
        d[source]=0;
        Dijkstra(source);

        for(int i=1;i<=vertex_number;i++){
             cout<<"vertex : "<<i<<"Distance : "<<d[i]<<endl;
        }

        cout<<"path from "<<source <<"to vertex :\t" ;
        int path;
        cin>>path;
        FindPath(path);
        return 0;
}

