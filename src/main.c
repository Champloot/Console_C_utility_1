#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "users.h"
#include "processes.h"
#include "log.h"
#include "errors.h"
#include "help.h"

int main(int argc, char *argv[]) {
    int opt;
    const char *log_path = NULL;
    const char *errors_path = NULL;

    while ((opt = getopt(argc, argv, "uphl:e:")) != -1) {
        switch (opt) {
            case 'u':
                print_users();
                break;
            case 'p':
                print_processes();
                break;
            case 'h':
                print_help();
                return 0;
            case 'l':
                log_path = optarg;
                redirect_output(log_path);
                break;
            case 'e':
                errors_path = optarg;
                redirect_errors(errors_path);
                break;
            default:
                fprintf(stderr, "Unknown option: %c\n", opt);
                print_help();
                return 1;
        }
    }

    return 0;
}
