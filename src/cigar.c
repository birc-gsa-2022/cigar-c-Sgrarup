#include "gsa.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void edits_to_cigar(const char *edits, char **cigar)
{
    size_t n = strlen(edits);
    *cigar = malloc(2 * n + 1); // maximal length for a cigar
    // Compute the CIGAR string
}

static inline int count_edits(const char *cigar)
{
    int n = strlen(cigar);
    int len = 0;
    for (int i = 0 ; i < n ; i++ ) {
        if (i % 2 == 0 ) {
            len += atoi(&cigar[i]);
        }
    }
    return len; // Work out how long the string will be
}

void cigar_to_edits(const char *cigar, char **edits)
{
    int no_edits = count_edits(cigar);
    *edits = malloc(no_edits + 1);

    // construct the edits sequence

    int n = strlen(cigar);
    int im_len = 0;

    memset(*edits, 0, no_edits+1);

    for (int i = 0 ; i < n ; i++) {
        if (i % 2 == 0 ) {
            im_len = atoi(&cigar[i]);
        }
        else {
            char *c = cigar[i]; 
            for (int j = 0 ; j < im_len ; j++) {
               strcat(*edits, &c);
            } 
        } 
    } 

}
