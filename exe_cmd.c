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
		char *args[128];
		int arg_count = 0;
		char *token = strtok((char *)cmd, " ");
		
		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;
		if (strcmp(args[0], "exit") == 0)
                {
                        exit(EXIT_SUCCESS);
                }
		dup2(STDOUT_FILENO, STDERR_FILENO);

		/*close(STDOUT_FILENO);*/

		execvp(args[0], args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
	int prcs;
        pid_t pid = waitpid(chld, &prcs, WUNTRACED);

        if (pid == -1) 
	{
            perror("waitpid");
            exit(EXIT_FAILURE);
        }
	}

        
        /*if (WIFEXITED(prcs)) {
            printf("Child process %d exited with status %d\n", pid, WEXITSTATUS(prcs));
        } else if (WIFSIGNALED(prcs)) {
            printf("Child process %d terminated by signal %d\n", pid, WTERMSIG(prcs));
        }*/
}
