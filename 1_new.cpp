#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

int row,col;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
char input_array[600][600];
int visited[600][600];
int m_arr_i[360000];
int m_arr_j[360000];
int output_array[600][600];
int m_count = 0;
bool flag;

void check(int x, int y,int id){
	visited[x][y] = id;
	for(int it = 0; it < 4; it++){
		int nx = x + dx[it];
		int ny = y + dy[it];
		if(nx >= 0 && ny >= 0 && nx < row && ny < col && input_array[nx][ny] != 'X' && visited[nx][ny] == -1)
			flag = true;
	}
}


int main(){

	cin >> row;
	cin >> col;
	
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> input_array[i][j];
			visited[i][j] = -1;
		}
	}
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if(input_array[i][j] == 'M'){
			   	m_arr_i[m_count] = i;
		    	m_arr_j[m_count] = j;
		    	m_count++;
		    }
		}
	}
	if(m_count == 0){
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				output_array[i][j] = -1;
			}	
		}
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				cout << output_array[i][j] << " ";
			}
			cout << "\n";
		}
		return 0;
	}
	
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if(input_array[i][j] == 'X'){
				output_array[i][j] = -1;
			}
			
		    else if(input_array[i][j] == 'M'){
		    	output_array[i][j] = 0;
			}
			
			else if(input_array[i][j] == 'O'){
				
				for(int I = 0; I < row; I++){
					for(int J = 0; J < col; J++){
						visited[I][J] = -1;
					}
				}
				
				flag = false;
				int id = 0;
				check(i,j,id);
				id++;
				if(flag == false){
					output_array[i][j] = -1;
				}else{
				int min_path = row*col;
				int k = m_count - 1;
				while(k > -1){
					int temp_i = abs(i-m_arr_i[k]);
					int temp_j = abs(j-m_arr_j[k]);
					k--;
					int a = i-m_arr_i[k];
					int b = j-m_arr_j[k];
					
					if(min_path > temp_i + temp_j)
						min_path = temp_i + temp_j;
				}
				output_array[i][j] = min_path;
			}
			
			
			}
		}
	}

	cout << "\n";
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout << output_array[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
	
	
	
	
	
	
	
	
	
