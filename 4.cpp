#include <bits/stdc++.h>

using namespace std;

int visited[100];
int arr[100];
int output[100];
int I = 0;

void dfs(int arr[100],int i,int n){
	for(int j = 2; j <= n; j++){
		if(i == n){
			output[I] = n;
			I++;
			return;
		}
		if(arr[j] == i && visited[j] == -1){
			visited[j] = 0;
			output[I] = i;
			I++;
			dfs(arr,j,n);
		}
	}
}

int main(){
	int n;
	cin >> n;

	output[0] = 1;
	
	for(int i = 2; i <= n; i++){
		cin >> arr[i];
	}
	
	for(int i = 2; i <= n; i++){
		visited[i] = -1;
	}

	
	for(int i = 1; i < n; i++){
		dfs(arr,i,n);
	}
	
	int a[100];
	a[0] = 1;
	int A = 0;
	for(int i = 1; i < n; i++){
		if(output[i] == n){
			a[i] = n;
			A = i+1;
			break;	
		}else{
				a[i] = output[i];
		}
	}


//*****************delete the repeated element of array************************************//	
int i, j;

/* new length of modified array */
int NewLength = 1;

for(i=1; i< A; i++){

   for(j=0; j< NewLength ; j++)
   {

      if(a[i] == a[j])
      break;
   }

   /* if none of the values in index[0..j] of array is not same as array[i],
      then copy the current value to corresponding new position in array */

  if (j==NewLength )
      a[NewLength++] = a[i];
}	

//**************************************************************************************//	


	for(int i = 0; i < NewLength; i++){
		cout << a[i] << " ";
	}
	return 0;
}

