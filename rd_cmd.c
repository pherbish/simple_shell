#include "shell.h"
/**
 * rd_cmd-gets input from terminal
 * @cmd:pointer to commands
 * @size:size of cmd
 * Return:inputs
 */
void rd_cmd(char *cmd, size_t size)
{
	if (fgets(cmd , size , stdin) == NULL)
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
}
