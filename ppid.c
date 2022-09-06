#include "main.h"
/**
 * main - Entry Point
 *
 * Return: Always
 */
int main(void)
{
	pid_t my_pid;

	my_pid = getppid();
	printf("%u\n", my_pid);
	return (0);
}
