#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int row,col;
	cin >> row;
	cin >> col;
	
	char input_array[600][600];
	int output_array[600][600];
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> input_array[i][j];
		}
	}
	 
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout << "(" << i << ", " << j << ")\n";
			if(input_array[i][j] == 'X')
				output_array[i][j] = -1;
		    else if(input_array[i][j] == 'M')
		    	output_array[i][j] = 0;
			else{
				int a_up = i,a_down = i, b_up = j, b_down = j;
				while(a_down > 0 && a_up < (row-1) && b_left > 0 && b_right < (col-1)){
					while(1){
						count++;
						if(input_array[++a_up][j] == 'M' || input_array[--a_down][j] == 'M' || input_array[i][++b_right] == 'M' || input_array[i][--b_left] == 'M'){
							break;
						}
						count++;
						if(input_array[a_up][++b_right] == 'M' || input_array[a_up][--b_left] == 'M'){
							break;
						}		
					}	
				}
				
				if(i > 0 && i < (row-1) && j > 0 && j < (col-1)){
					int count = 0;
					int a_up = i,a_down = i, b_right = j, b_left = j;
					while(1){
						count++;
						if(input_array[++a_down][j] == 'M' || input_array[--a_up][j] == 'M' || input_array[i][++b_right] == 'M' || input_array[i][--b_left] == 'M'){
							break;
						}		
					}
					cout << "****" << count << "****\n";	
				}else{
					if(i == 0 && j == 0){
						cout << "i = 0 , j = 0\n";
						int count = 0;
						int a_up = i,a_down = i, b_up = j, b_down = j;
						while(1){
							count++;
							if(input_array[++a_up][j] == 'M' || input_array[i][++b_up] == 'M'){
								break;
							}		
						}
						cout << count << "\n";
					}
					if(i == 0 && j == (col-1)){
						cout << "i = 0 , j = col\n";
						int count = 0;
						int a_up = i,a_down = i, b_up = j, b_down = j;
						while(1){
							count++;
							if(input_array[++a_up][j] == 'M' || input_array[i][--b_down] == 'M'){
								break;
							}		
						}
						cout << count << "\n";
					}
					
					if(i == 0 && j > 0 && j < (col-1)){
						cout << "i = 0\n";
						int count = 0;
						int a_up = i,a_down = i, b_up = j, b_down = j;
						while(1){
							count++;
							if(input_array[++a_up][j] == 'M' || input_array[i][++b_up] == 'M' || input_array[i][--b_down] == 'M'){
								break;
							}		
						}
						cout << count << "\n";
					}
					if(i == (row-1) && j > 0 && j < (col-1)){
						cout << "i = row\n";
						int count = 0;
						int a_up = i,a_down = i, b_up = j, b_down = j;
						while(1){
							count++;
							if(input_array[--a_down][j] == 'M' || input_array[i][++b_up] == 'M' || input_array[i][--b_down] == 'M'){
								break;
							}		
						}
						cout << count << "\n";
					}
					if(j == 0 && i == (row-1)){
						cout << "i = row, j = 0 \n";
						int count = 0;
						int a_up = i,a_down = i, b_up = j, b_down = j;
						while(1){
							count++;
							if(input_array[--a_down][j] == 'M' || input_array[i][++b_up] == 'M'){
								break;
							}		
						}
						cout << count << "\n";
					}
					if(j == 0 && i > 0 && i < (row-1)){
						cout << "j = 0\n";
						int count = 0;
						int a_up = i,a_down = i, b_up = j, b_down = j;
						while(a_up > -1 && a_down < row && b_up > -1 ){
							count++;
							if(input_array[++a_up][j] == 'M' || input_array[--a_down][j] == 'M' || input_array[i][++b_up] == 'M'){
								i_up = a_up;
								if(input_array[i_up][++b_up] == 'M'){
									
								}
								break;
							}		
						}
						cout << count << "\n";
					}
					if(j == (col-1) && i > 0 && i < (row-1)){
						cout << "j = col\n";
						int count = 0;
						int a_up = i,a_down = i, b_up = j, b_down = j;
						while(1){
							count++;
							if(input_array[++a_up][j] == 'M' || input_array[--a_down][j] == 'M' || input_array[i][--b_down] == 'M'){
								break;
							}		
						}
						cout << count << "\n";
					}
					if(j == (col-1) && i == (row-1)){
						cout << "i = row, j = col\n";
						int count = 0;
						int a_up = i,a_down = i, b_up = j, b_down = j;
						while(1){
							count++;
							if(input_array[--a_down][j] == 'M' || input_array[i][--b_down] == 'M'){
								break;
							}		
						}
						cout << count << "\n";
					}	
				}
				
			}
		}
	}	
	
//	cout << "\n";
//	for(int i = 0; i < row; i++){
//		for(int j = 0; j < col; j++){
//			cout << output_array[i][j];
//		}
//		cout << "\n";
//	}
	
	return 0;
}
