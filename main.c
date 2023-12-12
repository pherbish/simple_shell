#include "shell.h"
/**
 *main-main function
 *Return:void on success
 */

int main(void) 
{
    char *cmd = NULL;

    while (true)
    {
	    exe_cmd(cmd);
	    t_prmpt();
	    rd_cmd(&cmd);
    }
    free(cmd);
    return 0;
}
