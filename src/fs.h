#ifndef FS_H
#define FS_H

#include <stddef.h> // for size_t

// Initialize repository directory structure
int init_dirs(void);

// Initialize HEAD file
int init_head(void);

// Initialize index file
int init_index(void);

// Check if file exists
int file_exists(const char *path);

// Read entire file into memory
// Returns allocated buffer (caller must free) or NULL on error
// out_size will contain the file size
unsigned char *read_entire_file(const char *path, size_t *out_size);

#endif