#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    int fd;
    fd = open("bhel.txt", O_RDWR);
    write(fd, "BHEL", 4);
    close(fd);
    return 0;
}
