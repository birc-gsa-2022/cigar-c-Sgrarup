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

static void test_align(const char *p, const char *q, const char *edits,
                       const char *expected_p_row, const char *expected_q_row)
{
    char *p_row, *q_row;

    align(p, q, edits, &p_row, &q_row);
    test_eq(p_row, expected_p_row);
    test_eq(q_row, expected_q_row);

    free(p_row);
    free(q_row);
}

static void test_local_align(const char *p, const char *x, int i,
                             const char *edits,
                             const char *expected_p_row,
                             const char *expected_x_row)
{
    char *p_row, *x_row;

    local_align(p, x, i, edits, &p_row, &x_row);
    test_eq(p_row, expected_p_row);
    test_eq(x_row, expected_x_row);

    free(p_row);
    free(x_row);
}

int main(void)
{
    test_align("accaaagta", "acaaatgtcca", "MDMMIMMMMIIM",
               "acca-aagt--a", "a-caaatgtcca");
    test_align("a", "", "D", "a", "-");

    test_local_align("accaaagta", "cgacaaatgtcca", 2,
                     "MDMMIMMMMIIM",
                     "acca-aagt--a", "a-caaatgtcca");
    test_local_align("a", "a", 1, "D", "a", "-");

    return 0;
}
