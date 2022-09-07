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
    return 42; // Work out how long the string will be
}

void cigar_to_edits(const char *cigar, char **edits)
{
    int no_edits = count_edits(cigar);
    *edits = malloc(no_edits + 1);

    // construct the edits sequence
}
