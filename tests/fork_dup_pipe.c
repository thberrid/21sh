#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>

int		main(int ac, char **av, char **env)
{
	pid_t	pid_parent;
	int		status;
	int		dup_fd;
	int		open_fd;

	pid_parent = fork();
	if (!pid_parent)
	{
		printf("child\n");
		open_fd = open("text.txt", O_CREAT);
		dup_fd = dup2(1, open_fd);
		execve("/bin/ls", av, env);
		close(open_fd);
	}
	else
	{
		waitpid(pid_parent, &status, 0);
		printf("parent\n");
	}
	return (0);
}