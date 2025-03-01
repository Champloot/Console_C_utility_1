#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "users.h"
#include "processes.h"
#include "help.h"

int main(int argc, char *argv[]) {
    int opt;
    const char *log_path = NULL;
    const char *errors_path = NULL;
    int users_flag = 0;
    int processes_flag = 0;

    // Обработка аргументов командной строки
    while ((opt = getopt(argc, argv, "uphl:e:")) != -1) {
        switch (opt) {
            case 'u':
                users_flag = 1; // Устанавливаем флаг для вывода пользователей
                break;
            case 'p':
                processes_flag = 1; // Устанавливаем флаг для вывода процессов
                break;
            case 'h':
                print_help(); // Вывод справки
                return 0;
            case 'l':
                log_path = optarg; // Сохраняем путь для логов
                break;
            case 'e':
                errors_path = optarg; // Сохраняем путь для ошибок
                break;
            default:
                fprintf(stderr, "Unknown option: %c\n", opt);
                print_help();
                return EXIT_FAILURE;
        }
    }

    // Перенаправляем stdout в файл, если указан флаг -l
    if (log_path) {
        if (freopen(log_path, "w", stdout) == NULL) {
            perror("freopen");
            return EXIT_FAILURE;
        }
    }

    // Перенаправляем stderr в файл, если указан флаг -e
    if (errors_path) {
        if (freopen(errors_path, "w", stderr) == NULL) {
            perror("freopen");
            return EXIT_FAILURE;
        }
    }

    // Выполняем команды в зависимости от флагов
    if (users_flag) {
        print_users(); // Вывод списка пользователей
    }
    if (processes_flag) {
        print_processes(); // Вывод списка процессов
    }

    // Если не было указано ни одной команды, выводим справку
    if (optind == 1 && !users_flag && !processes_flag) {
        print_help();
    }

    return 0;
}
