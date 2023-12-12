#include "shell.h"
/**
 * rd_cmd-gets input from terminal
 * @cmd:pointer to commands
 * @size:size of cmd
 * Return:inputs
 */
void rd_cmd(char **cmd)
{
	
	size_t size = 0;
	ssize_t brt;

	brt = getline(cmd , &size , stdin);
	if (brt == -1)
	{
		if (feof(stdin))
		{
			n_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			n_print("Error input\n");
			exit(EXIT_FAILURE);
		}
	}
	(*cmd)[strcspn(*cmd, "\n")] = '\0';

}
