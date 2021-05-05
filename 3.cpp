#include<bits/stdc++.h>  

using namespace std; 

int R,C;

// visited[i][j] Stores length of longest consecutive path 
int visited[500][500]; 
char mat[500][500];

int x[8] = {0, 1, 1, -1, 1, 0, -1, -1}; 
int y[8] = {1, 0, 1, 1, -1, -1, 0, -1}; 

int I,J;

int dfs(char mat[500][500], int i, int j, char prev){ 

	if (i < 0 || j < 0 || i >= R || j >= C || !((mat[i][j] - prev) == 1)) //check if the next char in matrix is the correct next letter
		return 0; 

	if (visited[i][j] != -1) 
		return visited[i][j]; 

	int ans = 0;
	for (int k=0; k<8; k++) 
		ans = max(ans, 1 + dfs(mat, i + x[k], j + y[k], mat[i][j])); 

	return visited[i][j] = ans; 
} 

int getLen(char mat[500][500], char s){ 
	int ans = 0; 
	int temp;
	for (int i=0; i<R; i++) { 
		for (int j=0; j<C; j++) { 
			if (mat[i][j] == s) { 
				for (int k=0; k<8; k++) {
					temp = ans;
					ans = max(ans, 1 + dfs(mat, i + x[k], j + y[k], s)); 
					if(ans > temp){
						I = i;
						J = j;
					}	
				}
			} 
		} 
	} 
	return ans; 
} 


int main() { 

	cin >> R;
	cin >> C;
	
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cin >> mat[i][j];
			visited[i][j] = -1;
		}
	} 
	
	char s;
	cin >> s;
	
	int ans = getLen(mat, s);
	
	cout << ans << "\n" << I << " " << J;  
 
	return 0; 
} 

