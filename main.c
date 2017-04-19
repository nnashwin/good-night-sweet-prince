#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int check_if_root() {
	if (geteuid() != 0) 
	{
		printf("Change to root-user and try again");
		return 0;
	}
	return 1;
}

int main() {
	if (check_if_root() == 1) {
		printf("Good Night Sweet Prince!");
		return system("shutdown -P now");
	} else {
		return 0;
	}
}
