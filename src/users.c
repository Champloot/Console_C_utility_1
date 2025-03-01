#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>

void print_users(){
	struct passwd *pw;
	while ((pw = getpwent()) != NULL){
	printf("Users: %s, Home: %s\n", pw->pw_name, pw->pw_dir);
	}
	endpwent();
}
