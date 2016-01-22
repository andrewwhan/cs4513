// Andrew Han -- rm.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //String operations

int main(int argc, char* argv[]){
	if(argc < 2){
		printf("No file specified. \n");
		return 1;
	}
	//printf("Target: %s \n", argv[1]);
	const char* dumpsterLoc = getenv("DUMPSTER");
	if(dumpsterLoc == NULL){
		printf("DUMPSTER environment variable not specified. \n");
		return 1;
	}
	//TODO Malloc, smarter name change stuffs: tokenize by /,
	//check and see if there's already / on the end of dumpster
	char targetLoc[64];
	strcpy(targetLoc, dumpsterLoc);
	strcat(targetLoc, "/");
	strcat(targetLoc, argv[1]);
	//printf("TargetLoc: %s \n", targetLoc);
	if(rename(argv[1], targetLoc)){
		perror("Rename error");
		return 1;
	}
	printf("End! \n");
	return 0;
}