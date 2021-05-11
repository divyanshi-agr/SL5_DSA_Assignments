#include<bits/stdc++.h>
using namespace std;

#define MAX 10

typedef struct Edge {
    int src;
    int dest;
    int weight;
} edge;

void bellmanFord(int nv,edge e[],int src,int ne) {
    int x, y, wt;
    int distance[MAX];

    //initialize distance array with distance 999 denoting infinity
    for (int i = 0 ; i < nv ; i++)
        distance[i] = 999;

    //distance of src vertex from source is 0    
    distance[src] = 0;

   for(int i = 1 ; i <= nv - 1 ; i++)
   {
        for(int j = 0 ; j < ne ; j++)
        {
            x = e[j].src;
            y = e[j].dest;
            wt = e[j].weight;
            
            if(distance[x] != 999 && distance[x] + wt < distance[y])
            {
                distance[y] = distance[x] + wt;
            }  
        }
    
   }

    //for negative cycle
    for (int i = 0 ; i < ne ; i++) {
        x = e[i].src;
        y = e[i].dest;
        wt = e[i].weight;
        if (distance[x] != 999 && distance[x] + wt < distance[y]) {
            cout << "Negative Cycle Present!";
            return; 
        }
    }

    //output
    cout<<"\nVertex"<<"  Distance from source";
    for(int i = 1 ; i <= nv ; i++)
    {
        cout<<"\n"<<i<<"\t"<<distance[i];
    }
    cout<<endl;
}

int main() {
    int nv = 0, ne = 0, src;
    edge e[MAX];
    cout << "No. of Vertices: ";
    cin >> nv;
    cout << "No. of Edges: ";
    cin >> ne;
    cout<<"Enter the source vertex of graph: ";
    cin>>src;

    for(int i=0;i<ne;i++)
    {
        cout<<"\nFor edge "<<i+1<<"=>";
        cout<<"\nSource vertex: ";
        cin>>e[i].src;
        cout<<"Destination vertex: ";
        cin>>e[i].dest;
        cout<<"Weight: ";
        cin>>e[i].weight;  
    }

    bellmanFord(nv,e,src,ne);
    return 0;
}