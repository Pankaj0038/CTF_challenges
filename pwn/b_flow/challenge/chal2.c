#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define ANSI_COLOR_YELLOW     "\033[1;33m"
#define ANSI_COLOR_GREEN   "\033[1;32m"
#define ANSI_COLOR_RED   "\033[1;31m"
#define ANSI_COLOR_WHITE   "\033[1;37m"


void ret2win(){
	int key = 0;
	char buffer[32];
	printf(ANSI_COLOR_GREEN"  _____   _                 _     _ "		 "\n");
	printf(ANSI_COLOR_GREEN" / ____| | |         /\\    | |   | |"	 "\n");
	printf(ANSI_COLOR_GREEN"| (___   | |        /  \\    \\ \\_/ / "	 "\n");
	printf(ANSI_COLOR_GREEN" \\___ \\  | |       / __ \\    \\   / "	 "\n");
	printf(ANSI_COLOR_GREEN" ____) | | |____  / ____ \\    | |  "		 "\n");
	printf(ANSI_COLOR_GREEN"|_____/  |______|/_/    \\_\\   |_|  "	 "\n");
	printf(ANSI_COLOR_YELLOW"You need to overflow me to get the flag "	 "\n");
	printf(ANSI_COLOR_RED"root" ANSI_COLOR_GREEN "@gengar:/" ANSI_COLOR_WHITE ">");
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
