#include<stdio.h>
#include<string.h>

int main(){
	char buffer[20];
	int val = 0;
	printf("Spells won't allow you to go further !!");
	gets(buffer);
	printf("%d\n",val);
	char *flag = "redacted";
	if(val!=0){
		printf(flag);
	}
	else{
		printf("\nMay be broken bariers can help you to get in!");
	}
	return 0;
	
}
