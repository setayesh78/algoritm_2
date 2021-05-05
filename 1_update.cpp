#include <bits/stdc++.h> 

using namespace std; 


int output[600][600];
int visited[600][600]; 
char grid[600][600];

class QItem { 
public: 
	int row; 
	int col; 
	int dist; 
	QItem(int x, int y, int w) 
		: row(x), col(y), dist(w) 
	{ 
	} 
}; 

int minDistance(char grid[600][600],int i,int j,int N, int M){ 
	QItem source(i, j, 0); 
	int temp_visited[N][M]; 

    for (int i = 0; i < N; i++){ 
        for (int j = 0; j < M; j++){ 
            if (grid[i][j] == 'X') 
                temp_visited[i][j] = 1; 
            else
                temp_visited[i][j] = 0; 
        } 
    }

	queue<QItem> q; 
	q.push(source); 
	temp_visited[source.row][source.col] = 1; 
	while (!q.empty()) { 
		QItem p = q.front(); 
		q.pop(); 

		if (grid[p.row][p.col] == 'M') {
			return p.dist; 
		}

		if (p.row - 1 >= 0 && temp_visited[p.row - 1][p.col] == 0) { 
			q.push(QItem(p.row - 1, p.col, p.dist + 1)); 
			temp_visited[p.row - 1][p.col] = 1; 
		} 
 
		if (p.row + 1 < N && temp_visited[p.row + 1][p.col] == 0) { 
			q.push(QItem(p.row + 1, p.col, p.dist + 1)); 
			temp_visited[p.row + 1][p.col] = 1; 
		} 

		if (p.col - 1 >= 0 && temp_visited[p.row][p.col - 1] == 0) { 
			q.push(QItem(p.row, p.col - 1, p.dist + 1)); 
			temp_visited[p.row][p.col - 1] = 1; 
		} 

		if (p.col + 1 < M && temp_visited[p.row][p.col + 1] == 0) { 
			q.push(QItem(p.row, p.col + 1, p.dist + 1)); 
			temp_visited[p.row][p.col + 1] = 1; 
		} 
	} 
	return -1; 
} 

int main(){
	int M,N;
	cin >> N;
	cin >> M;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> grid[i][j];
		}
	}						
						
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if (grid[i][j] == 'X'){
				visited[i][j] = 1; 
				output[i][j] = -1;
			}
			else
				visited[i][j] = 0;
				 
			if (grid[i][j] == 'O') { 
				output[i][j] = minDistance(grid,i,j,N,M); 
			}
		}
	} 
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << output[i][j] << " ";
		}
		cout << "\n";
	}
	return 0; 
} 

