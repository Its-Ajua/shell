#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	char *command = NULL;
	size_t len = 0;
	char *stkn;
	pid_t fa_pid;
	int status;

	while (1)
	{
		printf("$ ");
		getline(&command, &len, stdin);

		stkn = strtok(command, " \n");
		printf("%s/n", stkn);

		char **arr = malloc(sizeof(char *) * 32);

		arr[0] = stkn;

		if (strcmp(arr[0], "exit") == 0)
			exit(0);

		int j = 1;

		while (stkn != NULL)
		{
			stkn = strtok(NULL, "  \n");
			arr[j] = stkn;
			j++;
		}

		fa_pid = fork();
		if (fa_pid == -1)
		{
			perror("Error");
			return (1);
		}
		else if (fa_pid == 0)
		{
			execve(arr[0], arr, NULL);
		}
		else
		{
			wait(&status);
		}
	}
	free(command);
	return (0);
}
