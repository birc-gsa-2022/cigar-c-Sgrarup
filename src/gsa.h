#ifndef GSA_H
#define GSA_H

/*
 * All return values, if strings, are freshly allocated buffers. (If you want,
 * you can come up with another memory management strategy, but then you need
 * to update the tests). Since C doesn't natively handle more than one return value,
 * we keep it simple and use char ** to return strings. The new buffer is written
 * to the argument. For the cigar functions, this wouldn't be necessary, but we like
 * consistency (the hobgobling of little minds), so we treat all returned strings
 * the same.
 */

void get_edits(const char *p_row, const char *q_row,
               char **p, char **q, char **edits);
int edit_dist(const char *p, const char *x, int i, const char *edits);
void align(const char *p, const char *q, const char *edits,
           char **p_row, char **q_row);
void local_align(const char *p, const char *x, int i, const char *edits,
                 char **p_row, char **x_row);
void edits_to_cigar(const char *edits, char **cigar);
void cigar_to_edits(const char *cigar, char **edits);

#endif // GSA_H
