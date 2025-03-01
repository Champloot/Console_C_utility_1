#include <stdio.h>

void print_help() {
	printf("Usage: program [option]\n");
	printf("Options:\n");
	printf("	-u, --users	Print list of users and their home directories\n");
	printf("	-p, --processes	Print list of running processes\n");
	printf("	-h, --help	Print this help message\n");
	printf("	-l PATH, --log PATH	Redirect output to the specified file\n");
	printf("	-e PATH, --errors PATH	Redirect errors to the specified file\n");
}
