#include <stdio.h>
#include <stdlib.h>

void redirect_output(const char *path) {
	FILE *file = freopen(path, "w", stdout);
	if (file == NULL) {
		perror("freopen");
		exit(EXIT_FAILURE);
	}
}
