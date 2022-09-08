#include "gsa.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_edits(const char *p_row, const char *q_row,
               char **p_buf, char **q_buf, char **edits_buf)
{
    size_t n = strlen(p_row);
    assert(n == strlen(q_row));

    // For p and q we might be allocating more than needed, but
    // it is hard to make efficient without being a little wasteful
    char *p = *p_buf = malloc(n + 1);
    char *q = *q_buf = malloc(n + 1);
    char *edits = *edits_buf = malloc(n + 1);
    assert(p && q && edits); // Don't want to handle allocation failures

    // FIXME: do the actual calculations here
    int j = 0; // for the p variable
    int k = 0; // for the q variable
   for (int i = 0 ; i < n ; i ++) {
        if (p_row[i] != '-' && q_row[i] == '-') {
            edits[i] = 'D';
            p[j] = p_row[i]; 
            j++;
        }
        else if (p_row[i] == '-' && q_row[i] != '-') {
            edits[i] = 'I';
            q[k] = q_row[i];
            k++; 
        }
        else if (p_row[i] ==q_row[i]) {
            edits[i] = 'M';
            p[j] = p_row[i];
            q[k] = q_row[i];
            j++;
            k++;
        } 
    }
    printf("%s", "accaaagta \n");
    printf("%s", p);
    printf("%c", '\n');
    printf("%s", "acaaatgtcca \n");
    printf("%s", q);
    printf("%c", '\n');
    printf("%s", edits);

   /* p[0] = '\0';     // for now we just make
    q[0] = '\0';     // empty strings
    edits[0] = '\0'; // so at least we can run tests. */
}

int edit_dist(const char *p, const char *x, int i, const char *edits)
{
    int dist = 0;
    // Compute the edit distance
    return dist;
}
