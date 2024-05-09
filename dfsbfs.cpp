#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void dfs(int adjMat[10][10], int v, int start)
{
    int visited[v] = {0};
    stack<int> s;
    s.push(start);
    visited[start]=1;
    cout << "DFS traversal: ";
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        cout << temp << " ";
        
        for (int i = v-1; i >= 0; i--)                   //(i=n-1;i>=0;i--) only for dfs
        {
            if (adjMat[temp][i] && visited[i] == 0)
            {
                s.push(i);
                visited[i]=1;
            }
        }
    }
    cout << endl;
}

void bfs(int adjMat[10][10], int v, int start)
{
    int visited[v] = {0};
    queue<int> visit;
    visit.push(start);
    visited[start] = 1;
    
    cout<<"BFS traversal: ";
    while (!visit.empty())
    {
        int temp = visit.front();
        visit.pop();
        cout << temp << " ";

        for (int i = 0; i < v; i++)
        {
            if (adjMat[temp][i] && visited[i] == 0)
            {
                visit.push(i);
                visited[i] = 1;
            }
        }
    }
    cout << endl;
}

int main() {

	int n;
	int adj_mat[10][10] = {0};
	cout<<"Enter the total number of nodes in the graph --> ";
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			cout<<"Do you want to add the Edge between "<<i<<" and "<<j<<"?. (Y or N) ";
			char s;	
            cin>>s;
			if(s=='y' || s=='Y'){
				adj_mat[i][j] = adj_mat[j][i] = 1;
			}
		}
	}

	int ch;
	do{

		cout<<"\n\n";
		cout<<"1. DFS"<<endl;
		cout<<"2. BFS"<<endl;
		cout<<"0. Exit"<<endl;
		cout<<"Enter Choice:- ";
		cin>>ch;
		switch(ch){
			case 1:				
				dfs(adj_mat,n,0);
				break;
			case 2:				
				bfs(adj_mat,n,0);
				break;
			case 0:
				break;
			default:
				cout<<"Invalid Choice \n\n";
			break;
		}
	}while(ch!=0);
	cout<<"Program Finished ";
	return 0;
}