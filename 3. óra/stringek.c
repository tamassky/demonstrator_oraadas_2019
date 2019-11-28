#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char s[20] = "debreceni egyetem";
	printf("%d\n", strlen(s));
	printf("%s\n", s);

	char t[20];
	scanf("%s", t);
	printf("%s\n", strcat(s,t));
	
	/*gets(s);
	puts(s);*/
	
	printf("%s\n", strchr(s,'e'));
	if(strcmp(s,t)==0)
		puts("Egyforma");
	
	char r[20];
	strcpy(r,s);
	puts(r);

	char s1[10], s2[10];
	scanf("%s %s",s1,s2);
	printf("%s",strstr(s1,s2));

	strcpy(s,"1337");
	int a;
	a = atoi(s);
	printf("%d", a);
	
	return 0;
}
