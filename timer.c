#include "header.h"

static void print_current_time(int hours, int minutes, int seconds) {
    char *current_time = mx_strnew(10);
    char *temp = NULL;
    if (hours < 10) {
        temp = mx_itoa(hours);
        strcpy(current_time, "0");
        strcat(current_time, temp);
        mx_strdel(&temp);
    }
    else {
        temp = mx_itoa(hours);
        strcpy(current_time, temp);
        mx_strdel(&temp);
    }

    if (minutes < 10) {
        temp = mx_itoa(minutes);
        strcat(current_time, ":0");
        strcat(current_time, temp);
        mx_strdel(&temp);
    }
    else {
        temp = mx_itoa(minutes);
        strcat(current_time, ":");
        strcat(current_time, temp);
        mx_strdel(&temp);
    }

    if (seconds < 10) {
        temp = mx_itoa(seconds);
        strcat(current_time, ":0");
        strcat(current_time, temp);
        mx_strdel(&temp);
    }
    else {
        temp = mx_itoa(seconds);
        strcat(current_time, ":");
        strcat(current_time, temp);
        mx_strdel(&temp);
    }
    mx_printstr(current_time);
    mx_printchar('\n');
    mx_strdel(&current_time);
}

void timer(int hours, int minutes, int seconds) {
    printf("%d:%d:%d\n", hours, minutes, seconds);
    while (hours > 0) {
        if (minutes == 0) {
            hours--;
            minutes = 60;
        }
        while (minutes > 0) {
            if (seconds == 0) {
                minutes--;
                seconds = 60;
            }
            while (seconds > 0) {
                seconds--;
                print_current_time(hours, minutes, seconds);
                sleep(1);
            }
        }
    }
}
