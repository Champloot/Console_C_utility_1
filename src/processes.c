#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void print_processes() {
	DIR *dir;
	struct dirent *entry;

	dir = opendir("/proc");
	if (dir == NULL) {
		perror("opendir");
		return;
	}

	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_type == DT_DIR) {
			printf("Process ID: %s\n", entry->d_name);
		}
	}
	closedir(dir);
}
