#include "shell.h"
/**
 * find_command-searches for commands passed in the terminal.
 * @cmd:string passed
 * Return:void
 */
char *find_command(const char *cmd)
{
	char *path_env = getenv("PATH");
	
	if (path_env != NULL)
	{
		char *path_copy = strdup(path_env);
		char *dir = strtok(path_copy, ":");
		
		while (dir != NULL)
		{
			char *full_path = (char *)malloc(strlen(dir) + strlen(cmd) + 2);
			if (full_path == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			/* Construct the full path to the command*/
			strcpy(full_path, dir);
			strcat(full_path, "/");
			strcat(full_path, cmd);
			/* Check if the command exists at the full path*/
			if (access(full_path, X_OK) == 0)
			{
				free(path_copy);
				return full_path;
			}
			free(full_path);
			dir = strtok(NULL, ":");
		}
		free(path_copy);
	}
	return NULL;
}
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
		/* If the command is an absolute path or starts with './' or '../', execute it directly*/
		if (strchr(args[0], '/') != NULL || strncmp(args[0], "./", 2) == 0 || strncmp(args[0], "../", 3) == 0) 
		{
			execve(args[0], args, NULL);
		}
		else
		{
			/*Search for the command in the directories listed in PATH*/
			char *full_path = find_command(args[0]);
			if (full_path != NULL)
			{
				execve(full_path, args, NULL);
				perror("execve");
				free(full_path);
			}
			else
			{
				/*If the command is not found, print an error message*/
				perror("command not found");
				exit(EXIT_FAILURE);
			}
		}

		/*if (strchr(args[0], '/') != NULL)
		{
			execvp(args[0], args);
		}
		else
		{
			prt();
		}
		dup2(STDOUT_FILENO, STDERR_FILENO);

		close(STDOUT_FILENO);
		execvp(args[0], args);
		perror("execvp");
		exit(EXIT_FAILURE);*/
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
