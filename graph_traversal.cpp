#include <iostream>
#include <stack>
#include <vector>
#include <list>


using namespace std;

void printgraph (int g[][6])
{
    int size=6;
    for (int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cout<<g[i][j]<<",";
        }
        cout<<endl;
    }

}

void dfs_util(int g[][6],int start, vector<int> & visited)
{
    int size=6;
    visited[start]=1;
    for(int i=0;i<size;i++)
    {
        if (g[start][i] ==1 && visited[i] !=1)
        {
            dfs_util(g,i,visited);
        }
    }
    cout<<start<<",";
    return ;

}

void printDFS_recur(int g[][6])
{
    int size=6;
    stack<int> s;
    vector<int> visited(size,0);
    dfs_util(g,3,visited);
    cout<<endl;
    cout<<endl;

}
void bfs_util(int g[][6],int start, vector<int> & visited)
{
    int size=6;
    list<int> l;

    if (!visited[start]) {
        cout<<start<<",";
        visited[start]=1;
    }
    else{
        return;
    }
    for(int i=0;i<size;i++)
    {
        if (g[start][i] ==1 && visited[i] !=1)
        {
        
            l.push_back(i);
        }
    }

    for (auto vec:l)
    {
            bfs_util(g,vec,visited);
    }
    return ;

}

void printBFS_recur(int g[][6])
{
    int size=6;
    list<int> l;
    vector<int> visited(size,0);
    bfs_util(g,0,visited);
}

void printDFS(int g[][6])
{
    int size=6;
    stack<int> s;
    vector<int> visited(size,0);

    s.push(3);
    while(! s.empty())
    {
        int curr=s.top();
        int next=-1;
        visited[curr]=1;
        for(int j=0;j<size;j++)
        {
            if(g[curr][j]==1 && visited[j] !=1)
            {
                next=j;
                s.push(j);
            }

        }
        if (next == -1)
        {
            s.pop();
            cout<<curr<<',';
        }
    }
    cout<<endl;

}


void printBFS(int g[][6])
{
    int size=6;
    list<int> l;
    vector<int> visited(size,0);

    l.push_back(0);

    while(!l.empty())
    {
        int curr=l.front();
        l.pop_front();
        if (visited[curr]) continue;
        visited[curr]=1;
        cout<<curr<<",";

        for(int j=0; j<size;j++)
        {
            if (g[curr][j] ==1 && visited[j] != 1)
            {
                l.push_back(j);
            }
        }
    }
    cout<<endl;



}

int main ()
{
    int g[6][6]={
        {0,1,0,1,0,0},      
        {0,0,0,1,0,1},      
        {1,0,0,0,0,0},      
        {0,0,1,0,0,0},      
        {0,0,0,0,0,0},      
        {0,0,0,0,1,0},      
        
    };
    printgraph(g);
    printDFS(g);
    printDFS_recur(g);

    printBFS(g);
    printBFS_recur(g);
    return 0;
}