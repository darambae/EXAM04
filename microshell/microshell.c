#include "unistd.h"
#include "sys/wait.h"
#include "stdlib.h"

int exec(char **argv, int i, char **envp)
{
    int fd[2];
    int pid;
    int has_pipe = argv[i] && !strcmp(argv[i], '|');

    if (!has_pipe && !strcmp(argv[i], "cd"))
        return cd(argv, i);
    if (has_pipe && pipe(fd) == -1)
}

int main(int argc, char **argv, char **envp)
{
    int i = 0;
    int status = 0;

    if (argc > 1)
    {
        while (argv[i] && argv[++i])
        {
            argv += i;
            i = 0;
            while (argv[i] && strcmp(argv[i], '|') && strcmp(argv[i], ';'))
                i++;
            if (i)
                status = exec(argv, i, envp);
        }
        
    }
}