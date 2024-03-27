#ifndef FILE_H
#define FILE_H

///////////////////////////////////////
//
//             INCLUDES
//
//////////////////////////////////////

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

///////////////////////////////////////
//
//             TYPEDEFS
//
//////////////////////////////////////

typedef struct file_t file_t;

///////////////////////////////////////
//
//           STRUCT
//
//////////////////////////////////////

struct file_t
{
    const char      *name;
    union {
        void        *ptr;
        char        *data;
        uint64_t    *u64;
        int64_t     *i64;
        uint32_t    *u32;
        int32_t     *i32;
        uint16_t    *u16;
        int16_t     *i16;
        uint8_t     *u8;
        int8_t      *i8;
    };
    size_t  size;
    mode_t  mode;
};

int     read_file(const char *filename, file_t *f);
void    free_file(file_t *f);

#endif
