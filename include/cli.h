#ifndef CLI_H
#define CLI_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * Function pointer type for CLI command handlers.
 * @param argc Number of arguments (including the command name).
 * @param argv Array of argument strings.
 */
typedef void (*cli_command_func)(int argc, char **argv);

/**
 * Structure defining a CLI command entry.
 */
typedef struct {
    const char *name;             /**< Command name (string). */
    cli_command_func func;        /**< Function to call when command is executed. */
    const char *help;             /**< Help string describing the command. */
} cli_command_t;

/**
 * Initialise the CLI system. Must be called before using other CLI functions.
 */
void cli_init(void);

/**
 * Register a command with the CLI.
 * @param cmd Pointer to a static cli_command_t describing the command.
 */
void cli_register_command(const cli_command_t *cmd);

/**
 * Process a line of input and execute the corresponding command if found.
 * @param line A mutable buffer containing the input line. The buffer will be modified.
 */
void cli_process_line(char *line);

#ifdef __cplusplus
}
#endif

#endif /* CLI_H */
