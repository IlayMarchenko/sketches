//
// Created by Ilay Marchenko on 26.09.2020.
//
#include "header.h"

static int get_number_of_hours(int seconds) {
    int result;
    if (seconds < 3600)
        return 0;
    else
        result = seconds/60/60;
    return result;
}

static int get_number_of_minutes(int seconds) {
    float result;
    if (seconds < 60)
        return 0;
    else {
        result = (float)seconds / 60;
        while (result >= 60)
            result = result / 60;
    }
    return (int)result;
}

static int get_number_of_seconds(int seconds) {
    float result;
    if (seconds < 60)
        return seconds;
    else {
        result = (float)seconds / 60;
        while (result > 60)
            result = result / 60;
    }
    return (int)result;
}

void timer(int hours, int minutes, int seconds) {
    int total_seconds = seconds + (minutes * 60) + (hours * 60 * 60);
    int current_h;
    int current_m;
    int current_s;
    for (; total_seconds > 0; total_seconds--) {
        current_h = get_number_of_hours(total_seconds);
        current_m = get_number_of_minutes(total_seconds);
        current_s = get_number_of_seconds(total_seconds);
        if (current_h < 10)
            printf("0%d:", current_h);
        else
            printf("%d:", current_h);

        if (current_m < 10)
            printf("0%d:", current_m);
        else
            printf("%d:", current_m);

        if (current_s < 10)
            printf("0%d\n", current_s);
        else
            printf("%d\n", current_s);
        sleep(1);
    }

}

