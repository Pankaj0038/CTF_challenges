#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void ret2win(){
	int key = 0;
	char buffer[32];
	printf("  _____   _                 _     _ \n");
	printf(" / ____| | |         /\\    | |   | |\n");
	printf("| (___   | |        /  \\    \\ \\_/ / \n");
	printf(" \\___ \\  | |       / __ \\    \\   / \n");
	printf(" ____) | | |____  / ____ \\    | |  \n");
	printf("|_____/  |______|/_/    \\_\\   |_|  \n");
	printf("You need to bypass me to get the flag: \n");
	printf(">");
	fflush(stdout);
	gets(buffer);
	if(key==0xf007ba11){
		printf("Redacted\n");
		printf("%04x\n",key);
		fflush(stdout);
	}
	else{
		printf("F4k3_k3y\n");
		printf("%04x\n",key);
		fflush(stdout);
	}
}

int main(int argc , char* argv[]){
	ret2win();
	return 0;
}