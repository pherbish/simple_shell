#include "shell.h"
/**
 *main-main function
 *Return:void on success
 */

int main(void) 
{
    char *cmd = NULL;
    char *envrn[128];

    while (true)
    {
	    exe_cmd(cmd,envrn);
	    t_prmpt();
	    rd_cmd(&cmd);
    }
    free(cmd);
    return 0;
}
