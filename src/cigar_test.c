#include "gsa.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void test_eq(const char *a, const char *b)
{
    if (strcmp(a, b) != 0)
    {
        fprintf(stderr, "%s != %s\n", a, b);
        exit(1);
    }
}

static void test_cigar_to_edits(const char *cigar, const char *expected_edits)
{
    char *edits;
    cigar_to_edits(cigar, &edits);
    test_eq(edits, expected_edits);
    free(edits);
}

static void test_edits_to_cigar(const char *edits, const char *expected_cigar)
{
    char *cigar;
    edits_to_cigar(edits, &cigar);
    test_eq(cigar, expected_cigar);
    free(cigar);
}

int main(void)
{
    test_edits_to_cigar("MDIMID", "1M1D1I1M1I1D");
    test_edits_to_cigar("MMDDIIMMIIDD", "2M2D2I2M2I2D");
    test_edits_to_cigar("MDDIIIMMIDD", "1M2D3I2M1I2D");
    test_edits_to_cigar("", "");

    test_cigar_to_edits("1M1D1I1M1I1D", "MDIMID");
    test_cigar_to_edits("2M2D2I2M2I2D", "MMDDIIMMIIDD");
    test_cigar_to_edits("1M2D3I2M1I2D", "MDDIIIMMIDD");
    test_cigar_to_edits("", "");

    return 0;
}
