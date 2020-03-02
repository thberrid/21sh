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
	int		fd[2];

	pipe(fd);
	pid_parent = fork();
	if (!pid_parent)
	{
		close(fd[0]);
		dup2(0, fd[0])
		printf("child\n");
		fd[0] = open("text.txt", O_CREAT);
		fd[1] = dup(1);
		execve("/bin/ls", av, env);
	}
	else
	{
		close(fd[1]);
		waitpid(pid_parent, &status, 0);
		printf("parent\n");
	}
	return (0);
}