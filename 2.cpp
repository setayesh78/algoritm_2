#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	string input[n];
	int time[n];
	
	for(int i = 0; i < n; i++){
		cin >> input[i];
		time[i] = 0;
	}
	
	for(int i = 0; i < n; i++){
		stack <char> a;
		for(unsigned j = 0; j < input[i].length(); j++){
			if((!a.empty()) && input[i].at(j) == a.top()){
				a.pop();
				time[i] += 1;
			}else{
	    		if(input[i].at(j) == 'N')
	    			a.push('S');
	    		if(input[i].at(j) == 'S')
	    			a.push('N');
	    		if(input[i].at(j) == 'W')
	    			a.push('E');
	    		if(input[i].at(j) == 'E')
	    			a.push('W');
	    		time[i] += 5;
				}
  		}
	}
	
	for(int i = 0; i < n; i++)
		cout << time[i] << "\n";
	
	return 0;
}

import java.util.HashMap;
import java.util.Objects;
import java.util.Scanner;
public class Barf {
    static int row;
    static char[][] matrix;
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        row = scanner.nextInt();
        matrix = new char[row][4000];
        for(int i = 0; i < row; i++)
            matrix[i] = scanner.next().toCharArray();
        scanner.nextLine();
        int x=0,y=0;
        int time=0;
        HashMap<Interval,Integer> hashMap ;
        for(int i=0;i<row;i++){
            time=0;
            x=0;
            y=0;
            hashMap=new HashMap<>();
            for (int j=0;j<matrix[i].length;j++){
                x=(matrix[i][j]=='E')? x+1:(matrix[i][j] == 'W'?x-1:x);
                y=(matrix[i][j]=='N')? y+1:(matrix[i][j] == 'S'?y-1:y);
                Interval interval = new Interval((matrix[i][j] == 'W'?x+1:x),(matrix[i][j] == 'S'?y+1:y),(matrix[i][j]=='E' || matrix[i][j]=='W')?false:true);
                if(hashMap.size()==0 || !hashMap.containsKey(interval)){
                    time+=5;
                    hashMap.put(interval,0);
                }
                else {
                    time+=1;
                }
            }
            System.out.println(time);
        }
    }
}

