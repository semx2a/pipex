typedef struct s_info
{
    int        pipefd[2];
    int        fd_f1;
    int        fd_f2;
    pid_t    pid;
    pid_t    pid2;
    char    cmd1;
    char    cmd2;

}                t_info;

void    ft_outfile(t_info info, char *cmd, char env)
{
    info.pid2 = fork();
    if (info.pid2 == -1)
        ft_errors(" Process cannot be created\n");
    if (info.pid == 0)
    {
        info.cmd2 = ft_split(cmd, ' ');
        dup2(info.fd_f2, 1);
        dup2(info.pipefd[0], 0);
        close(info.fd_f2);
        close(info.pipefd[0]);
        close(info.pipefd[1]);
        ft_exec(info.cmd2, env, 0, -1);
        ft_free_tab(info.cmd2);
    }
}

void    ft_infile(t_info info, char *cmd, char env)
{
    info.pid = fork();
    if (info.pid == -1)
        ft_errors(" Process cannot be created\n");
    if (info.pid == 0)
    {
        info.cmd1 = ft_split(cmd, ' ');
        dup2(info.fd_f1, 0);
        dup2(info.pipefd[1], 1);
        close(info.fd_f1);
        close(info.pipefd[0]);
        close(info.pipefd[1]);
        ft_exec(info.cmd1, env, 0, -1);
        ft_free_tab(info.cmd1);
    }
}

void    ft_pipex(t_info info, char av, char env)
{
    pipe(info.pipefd);
    ft_infile(info, av[2], env);
    ft_outfile(info, av[3], env);
    waitpid(info.pid, NULL, 0);
    waitpid(info.pid2, NULL, 0);
    close(info.fd_f1);
    close(info.fd_f2);
    close(info.pipefd[0]);
    close(info.pipefd[1]);
}