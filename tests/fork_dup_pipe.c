#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>

/*
http://www.cs.loyola.edu/~jglenn/702/S2005/Examples/dup2.html
*/

int		redirection(char **av, char **env)
{
	pid_t	pid_forked;
	int		status;
	int		open_fd;

	pid_forked = fork();
	if (!pid_forked)
	{
		printf("child\n");
		open_fd = open("text.txt", O_CREAT | O_RDWR | O_APPEND, 755);
		dup2(open_fd, 1);
		execve("/bin/ls", av, env);
		close(open_fd);
	}
	else
	{
		waitpid(pid_forked, &status, 0);
		printf("parent\n");
	}
	return (0);
}

int		pipe(char **av, char **env)
{
	pid_t	pid_forked;
	int		piped_fd[2];

	pipe(piped_fd);
	pid_forked = fork();
	if (!pid_forked)
	{
		printf("child\n");
	}
	else
	{
		printf("parent\n");
	}
	return (0);
}

int		main(int ac, char **av, char **env)
{
//	redirection(av, env);
	pipe(av, env);
	return (0);
}