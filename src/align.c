#include "gsa.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void local_align(const char *p, const char *x, int i, const char *edits,
                 char **p_row, char **x_row)
{
    size_t n = strlen(edits);
    *p_row = malloc(n + 1);
    *x_row = malloc(n + 1);
    assert(*p_row && *x_row); // Don't want to handle allocation failures

    // Compute the alignment rows
}

void align(const char *p, const char *q, const char *edits,
           char **p_row, char **q_row)
{
    size_t n = strlen(edits);
    *p_row = malloc(n + 1);
    *q_row = malloc(n + 1);
    // Compute the alignment rows
}
