#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

int gpio_export(unsigned int qpio);
int gpio_unexport(unsigned int gpio);
int gpio_set_dir(unsigned int gpio, string dirStatus);
int gpio_set_value(unsigned int gpio, int value);

int LED_main(int choice, int LED, int state, int shining){
    if(choice == 1){
    if(state == 1){
        switch(LED){
        case '1':
            gpio_export(396);
            gpio_set_dir(396, "out");
            gpio_set_value(396,1);
            break;
        case '2':
            gpio_export(429);
            gpio_set_dir(429, "out");
            gpio_set_value(429,1);
            break;
        case '3':

            gpio_export(395);
            gpio_set_dir(395, "out");
            gpio_set_value(395,1);
            break;
        case '4':
            gpio_export(393);
            gpio_set_dir(393, "out");
            gpio_set_value(393,1);
            break;
    }}
    else{
        switch(LED){
        case '1':
            gpio_set_value(396, 0);
            gpio_unexport(396);
            break;
        case '2':
            gpio_set_value(429, 0);
            gpio_unexport(429);
            break;
        case '3':
            gpio_set_value(395, 0);
            gpio_unexport(395);
            break;
        case '4':
            gpio_set_value(393, 0);
            gpio_unexport(393);
            break;
}
    }}
    else{
    for (int i = 0; i < shining; i++){
        if(i % 2 == 0){
            gpio_export(396);
            gpio_set_dir(396, "out");
            gpio_set_value(396,1);
            gpio_export(429);
            gpio_set_dir(429, "out");
            gpio_set_value(429,1);

            gpio_set_value(395, 0);
            gpio_unexport(395);
            gpio_set_value(393, 0);
            gpio_unexport(393);
            sleep(1);
        }
        else{
            gpio_export(395);
            gpio_set_dir(395, "out");
            gpio_set_value(395,1);
            gpio_export(393);
            gpio_set_dir(393, "out");
            gpio_set_value(393,1);

            gpio_set_value(396, 0);
            gpio_unexport(396);
            gpio_set_value(429, 0);
            gpio_unexport(429);
            sleep(1);
}
}
gpio_set_value(395, 0);
            gpio_unexport(395);
            gpio_set_value(393, 0);
            gpio_unexport(393);
    gpio_set_value(396, 0);
            gpio_unexport(396);
            gpio_set_value(429, 0);
            gpio_unexport(429);
}

    return 0;
}


int gpio_set_value(unsigned int gpio, int value){
    int fd;
    char buf[64];

    snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%d/value", gpio);

    fd = open(buf, O_WRONLY);
    cout << fd << endl;
    if(fd < 0){
        perror("gpio/value");
        return fd;
}
    if(value == 0)
        write(fd, "0", 2);
    else
        write(fd, "1", 2);

    close(fd);
    return 0;
}

int gpio_set_dir(unsigned int gpio, string dirStatus){
    int fd;
    char buf[64];

    snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%d/direction", gpio);

    fd = open(buf, O_WRONLY);
    cout << fd << endl;
    if(fd < 0){
        perror("gpio/direction");
        return fd;
}
    if(dirStatus == "out")
        write(fd, "out", 4);
    else
        write(fd, "in", 3);

    close(fd);
    cout << "dir-ed!" << endl;
    return 0;
}

int gpio_unexport(unsigned int gpio){
    int fd, len;
    char buf[64];

    fd = open("/sys/class/gpio/unexport", O_WRONLY);
    if(fd <0){
        perror("gpio/export");
        return fd;
    }
    len = snprintf(buf, sizeof(buf), "%d", gpio);
    write(fd, buf, len);
    close(fd);
    return 0;
}

int gpio_export(unsigned int gpio){
    int fd, len;
    char buf[64];


    fd = open("/sys/class/gpio/export", O_WRONLY);
    cout << fd << endl;
    if(fd <0){
        perror("gpio/export");
        return fd;
    }
    len = snprintf(buf, sizeof(buf), "%d", gpio);
    write(fd, buf, len);
    close(fd);
    cout << "exported!" << endl;
    return 0;
}
