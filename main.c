#include "shell.h"
/**
 *main-main function
 *Return:void on success
 */

int main(void) 
{
    char cmd[128];

    while (true)
    {
	    exe_cmd(cmd);
	    t_prmpt();
	    rd_cmd(cmd, sizeof(cmd));
    }
    return 0;
}
