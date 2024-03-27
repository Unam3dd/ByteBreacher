#include "file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int read_file(const char *filename, file_t *f)
{
    struct stat s;
    int fd = 0;

    if (!f || !filename) return (1);

    memset(f, 0, sizeof(file_t));
    memset(&s, 0, sizeof(struct stat));

    if (stat(filename, &s) < 0) {
        perror("stat");
        return (1);
    }

    f->name = filename;
    f->size = s.st_size;
    f->mode = s.st_mode;
    f->u8 = (uint8_t *)calloc(sizeof(char), s.st_size+1);

    if (!f->u8) { memset(f, 0, sizeof(file_t)); return (1); }

    fd = open(filename, O_RDONLY);

    if (fd < 0) {
        perror("open");
        return (1);
    }

    if (read(fd, f->u8, s.st_size) < 0) {
        perror("read");
        return (1);
    }

    close(fd);

    return (0);
}

void    free_file(file_t *f)
{
    if (!f) return ;

    free(f->ptr);
    f->ptr = NULL;

    memset(f, 0, sizeof(file_t));
}
