#ifndef SKETCHES_HEADER_H
#define SKETCHES_HEADER_H

#include "libmx.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>


typedef struct s_lattrib {
    int *id;
    int *bl;
    char ftype;
    char *rights;
    int *lins;
    char *user;
    int *group;
    off_t size;
    int *full_time;
    char *name;
}       t_lattrib;

char *convert_bytes(int size);
void timer(int hours, int minutes, int seconds);

#endif //SKETCHES_HEADER_H
