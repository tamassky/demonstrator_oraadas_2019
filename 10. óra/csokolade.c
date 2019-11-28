//https://progcont.hu/progcont/100154?pid=200889
#include <stdio.h>

int main(int argc, char* argv[]){
	FILE* f = fopen(argv[1],"r");
	int n, m, i, j;
	char matrix[45][45], spam;
	while(fscanf(f, "%d %d\n", &n, &m) != EOF){ //!!!
		for(i=0;i<n;i++){
			for(j=0;j<m;j++)
				fscanf(f, "%c", &matrix[i][j]);
			fscanf(f, "%c", &spam); //!!!
		}
		int db = 0;
		for(i=0;i<n-1;i++)
			for(j=0;j<m-1;j++)
				if(matrix[i][j]== 'X' && matrix[i+1][j]== 'X' && matrix[i+1][j+1]== 'X' && matrix[i][j+1]== 'X'){
					db++;
					matrix[i][j]='0';
					matrix[i+1][j]='0';
					matrix[i][j+1]='0';
					matrix[i+1][j+1]='0';
				}
		printf("%d\n", db);
	}
	fclose(f);
	return 0;
}
