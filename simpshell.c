#include "holberton.h"

/**
 * main - entry point of the shell, checks program
 * @argc: arg num
 * @argv: array of argus
 *
 * Return: 0 on success or other integer
 */

int main(int argc, char *argv[])
{
	size_t bufsize = 0;
	char *line = NULL;
	int i, num_tokens = 0, cmdcount = 1, shell_interaction;

	signal(SIGINT, SIG_IGN); /* Check programs */
	shell_interaction = isatty(STDIN_FILENO);
	if (shell_interaction == 0 && argc == 1) /* if non-program */
	{
		while (getline(&line, &bufsize, stdin) > 0) /* collect input */
		{
			num_tokens = numcount(line); /* nums the # of tokens */
			parse(line, num_tokens, argv, cmdcount);
			line = NULL;
			/* sends line and num token to parser */
		}
		free(line);
		return (0);
	}
	while (shell_interaction)/* if intera */
	{
		/* Shell commaned */
		write(1, "($) ", 4);
		num_tokens = 0; /* restart token count to 0 */
		i = getline(&line, &bufsize, stdin); /* grabs input */
		if (i < 0)
		{
			free(line);
			write(1, "\n", 1);
			/* frees, skip line, and repeats for failed input or CTRL - D */
			break;
		}
		num_tokens = numcount(line); /* counts tokens */
		parse(line, num_tokens, argv, cmdcount);
		cmdcount++;
		/* sends line and numtoken to parser - tracks fails*/
		line = NULL; /* resets line to null */}
	return (0);
}
