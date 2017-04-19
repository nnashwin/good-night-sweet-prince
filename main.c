#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAX_LEN 128

int check_if_root();
void print_image(FILE *fptr);

int main( int argc, char ** argv ) {
	char *filename = "prince-ascii.txt";
	FILE *prince_ascii;

	if((prince_ascii = fopen(filename,"r")) == NULL)
	{
		fprintf(stderr,"error opening %s\n",filename);
		return 1;
	}

	print_image(prince_ascii);

	fclose(prince_ascii);

	if (check_if_root() == 1) {
		printf("Good Night Sweet Prince!");
		return system("shutdown -P now");
	} else {
		return 0;
	}
}

void print_image(FILE *fptr)
{
	char read_string[MAX_LEN];

	while(fgets(read_string, sizeof(read_string), fptr) != NULL)
	{
		printf("%s", read_string);
	}
}

int check_if_root() {
	if (geteuid() != 0) 
	{
		printf("Change to root-user and try again");
		return 0;
	}
	return 1;
}
