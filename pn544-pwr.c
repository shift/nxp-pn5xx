#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include "pn5xx_i2c.h"

int main(int argc, char **argv) {
    unsigned int mode = (argc > 1) ? (unsigned int)atoi(argv[1]) : PWR_ON;
    int fd = open("/dev/pn544", O_RDWR | O_NONBLOCK);
    if (fd < 0) {
        perror("open /dev/pn544");
        return 1;
    }
    if (ioctl(fd, PN544_SET_PWR, mode) < 0) {
        perror("ioctl PN544_SET_PWR");
        close(fd);
        return 2;
    }
    printf("PN544_SET_PWR(%u) OK\n", mode);
    close(fd);
    return 0;
}
