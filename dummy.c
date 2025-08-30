#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int bf_size = 5;
    char buffer[bf_size+1];
    int fd = open(argv[1], O_RDONLY, 0644);
    int bytes_read;
    while((bytes_read = read(fd, buffer, bf_size)) > 0)
    {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }
    return 0;
}