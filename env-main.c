#include "main.h"
/**
 * main - Entry Point
 * @ac: int ac
 * @av: char av
 * @env: char env
 *
 * Return: Always
 */
int main(int ac, char **av, char **env)
{
	unsigned int i;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
