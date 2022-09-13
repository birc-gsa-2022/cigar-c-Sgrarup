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
    memset(*cigar, 0,2*n+1);

    char cur = edits[0];
    int no = 1;

    for (int i = 1 ; i <= n ; i++) {
        if (edits[i] == cur) {
            no++;
        }
        else {
            char *num = no + '0';
            strncat(*cigar, &num, 1);
            strncat(*cigar, &cur, 1);
            cur = edits[i];
            no = 1;
        }
    }
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
            char c = cigar[i]; 
            for (int j = 0 ; j < im_len ; j++) {
               strncat(*edits, &c, 1);
            } 
        } 
    } 

}
