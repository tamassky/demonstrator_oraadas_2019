//https://progcont.hu/progcont/100109?pid=200717
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
	int i;
	for(i=1;i<argc;i++)
		if(strcmp(argv[i], "kakukktojas")==0)
			printf("%d\n",i);
	return 0;
}
