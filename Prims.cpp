#include<iostream>
using namespace std;
int main()
{
    int n,i,j,k,row,col,mincost=0,min;
    char op;
    //accepting the number of vertices of the graph
    cout<<"Enter the no. of vertices: ";
    cin>>n;

    //creating a 2d array to represent the graph(default =-1) 
    int cost[n][n];
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cost[i][j]=-1;
        }
    }
    //an array of size n to store the visited vertices(default=0)
    int visit[n];
    for(i=0; i<n; i++){
        visit[i]=0;
    }
    //Create the graph and add values
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            //use i and j if vertices start from 0
            cout<<"Do you want an edge between "<<i+1<<" and "<<j+1<<" (y/n): ";
            cin>>op;
            if (op=='y'||op=='Y')
            {
                cout<<"Enter Weight: ";
                cin>>cost[i][j];
                cost[j][i] = cost[i][j];
            }
        }
    }
    visit[0]=1;
    //iterate through all the path
    for(k=0;k<n-1;k++){
        min=999;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(visit[i]==1 && visit[j]==0){
                    if(cost[i][j]!=-1 && min>cost[i][j])
                    {
                        min=cost[i][j];
                        row=i;
                        col=j;
                    }
                }
            }
        }
        mincost+=min;
        visit[col]=1;
        cost[row][col]=cost[col][row]=-1;
        cout<<row+1<<"->"<<col+1<<endl;
    }
    cout<<"Minimum cost: "<<mincost<<endl;
    return 0;
}
