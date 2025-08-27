#include "cli.h"
#include <string.h>
#include <stdio.h>

#define MAX_COMMANDS 10
#define MAX_ARGS     8

static const cli_command_t *commands[MAX_COMMANDS];
static size_t command_count = 0;

void cli_init(void)
{
    command_count = 0;
}

void cli_register_command(const cli_command_t *cmd)
{
    if (command_count < MAX_COMMANDS) {
        commands[command_count++] = cmd;
    }
}

void cli_process_line(char *line)
{
    char *argv[MAX_ARGS];
    int argc = 0;

    // Tokenize the input line into arguments separated by whitespace
    char *token = strtok(line, " \t\n\r");
    while (token && argc < MAX_ARGS) {
        argv[argc++] = token;
        token = strtok(NULL, " \t\n\r");
    }
    if (argc == 0) {
        return;
    }

    // Search for the command name in the registered commands
    for (size_t i = 0; i < command_count; ++i) {
        if (strcmp(argv[0], commands[i]->name) == 0) {
            commands[i]->func(argc, argv);
            return;
        }
    }

    printf("Unknown command: %s\n", argv[0]);
}
