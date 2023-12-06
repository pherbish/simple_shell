#include "shell.h"
/**
 * n_print-function of printf
 * @msg:holder of the char to be printed
 * Return:message to std output
 */
void n_print(const char *msg)
{
	write(STDOUT_FILENO, msg ,strlen(msg));
}
