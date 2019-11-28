//https://progcont.hu/progcont/100111/?pid=200734
#include <stdio.h>
#include <stdlib.h>


int foo(int *t, int n, int m){
	int i,j, azonos;
	for(i=0; i<m; i++){
		azonos = 1;
		for(j=1; j<n; j++)
			if( *((t+j*m)+i) != *((t+(j-1)*m)+i) )
				azonos = 0;
		if(azonos)
			return 1;
	}
	return 0;
}

/*int main()
{
    int m[3][4] = {{1, 99, 2, 30},
                   {2, 98, 2, 60},
                   {3, 97, 2, 90}};
    if (foo(&m[0][0], 3, 4))
        puts("YES");
    else
        puts("NO");
    return EXIT_SUCCESS;
}*/

