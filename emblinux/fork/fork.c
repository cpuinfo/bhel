#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t id;
    int fd[2];
    unsigned char buff[128];

    printf("Before fork\n");

    pipe(fd);

    id = fork();

    if (0 == id)
    {
        printf("Child PID: %d   :  PPID: %d\n", getpid(), getppid());
        read(fd[0], buff, 128);
        printf("Child: Buff: %s\n", buff);
    }
    else
    {
        printf("Parent PID: %d   : PPID: %d\n", getpid(), getppid());
        write(fd[1], "BHEL\n", 5);
    }

    return 0;
}
