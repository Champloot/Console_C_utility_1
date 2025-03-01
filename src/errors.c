#include <stdio.h>
#include <stdlib.h>

void redirect_errors(const char *path) {
	FILE *file = freopen(path, "w", stderr);
	if (file == NULL) {
		perror("freopen");
		exit(EXIT_FAILURE);
	}
}
