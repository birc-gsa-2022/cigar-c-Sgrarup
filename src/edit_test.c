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

static void test_get_edits(const char *p_row, const char *q_row,
                           const char *expected_p, const char *expected_q,
                           const char *expected_edits)
{
    char *p, *q, *edits;
    get_edits(p_row, q_row, &p, &q, &edits);

    test_eq(p, expected_p);
    test_eq(q, expected_q);
    test_eq(edits, expected_edits);

    free(p);
    free(q);
    free(edits);
}

int main(void)
{
    test_get_edits("acca-aagt--a", "a-caaatgtcca",
                   "accaaagta", "acaaatgtcca", "MDMMIMMMMIIM");
    test_get_edits("acgttcga", "aaa---aa",
                   "acgttcga", "aaaaa", "MMMDDDMM");

    /*
         acca-aagt--a
    ...cga-caaatgtcca...
          *  * *  **  = 5 edits
    */
    assert(edit_dist("accaaagta", "cgacaaatgtcca", 2, "MDMMIMMMMIIM") == 5);

    /*
       acgttcga
    ...aaa---aa...
        ******    = 6 edits
    */
    assert(edit_dist("acgttcga", "aaaaa", 0, "MMMDDDMM") == 6);

    return 0;
}
