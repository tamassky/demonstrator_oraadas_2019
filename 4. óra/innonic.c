#include <stdio.h>

int no_duplicates(int t[], int n){
	int szerepel[100001];
	for(int i=0; i<=100000; i++) //calloc!
		szerepel[i] = 0;
	int db=0;
	for(int i=0; i<n; i++){
		if(!szerepel[t[i]]){
			t[db]=t[i];
			db++;
		}
		szerepel[t[i]] = 1;
	}
	return db;
}

int main(){
	int t[10] = {11,25,3,6,7,11,6,9,6,10};
	int db = no_duplicates(t,10);
	for(int i=0; i<db; i++)
		printf("%d ",t[i]);
	return 0;
}
