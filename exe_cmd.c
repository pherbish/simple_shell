#include "shell.h"
/**
 * exe_cmd -executes commands from the terminal
 * @cmd:pointer to the commands
 * Returns:executed command
 */
void exe_cmd(const char *cmd)
{
	pid_t chld = fork();

	if (chld == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (chld == 0)
	{
		execlp(cmd, cmd, (char *)NULL);
		perror("exclp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
