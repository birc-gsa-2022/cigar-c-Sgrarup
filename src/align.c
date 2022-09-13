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
    x = x + i;

    align(p, x, edits, p_row, x_row);
}

void align(const char *p, const char *q, const char *edits,
           char **p_row, char **q_row)
{
    size_t n = strlen(edits);
    *p_row = malloc(n + 1);
    *q_row = malloc(n + 1);

    // Compute the alignment rows
    memset(*p_row, 0, n+1);
    memset(*q_row, 0, n+1);

    int j = 0;
    int k = 0;
    for (int i = 0; i <= n ; i++) {
        if (edits[i] == 'M') {
            strncat(*p_row, &p[j], 1); 
            strncat(*q_row, &q[k], 1); 
            j++;
            k++;
        }
        else if (edits[i] == 'I') {
            strncat(*p_row, "-", 1);
            strncat(*q_row, &q[k], 1);
            k++;
        }
        else if (edits[i] == 'D') {
            strncat(*p_row, &p[j], 1);
            strncat(*q_row, "-", 1);
            j++;
        } 
    }
}
