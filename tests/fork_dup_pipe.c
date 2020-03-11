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

//	pipe(fd);
	pid_parent = fork();
	if (!pid_parent)
	{
	//	close(fd[0]);
		printf("child\n");
		open_fd = open("text.txt", O_CREAT | O_RDWR | O_APPEND, 755);
		dup2(open_fd, 1);
	//	dup2(1, fd[1]);
		execve("/bin/ls", av, env);
		close(open_fd);
	}
	else
	{
	//	close(fd[1]);
		waitpid(pid_parent, &status, 0);
	//	write(fd[0], );
		printf("parent\n");
	}
	return (0);
}