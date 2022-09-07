add_library(gsa align.c edit.c cigar.c)

add_executable(align_test align_test.c)
target_link_libraries(align_test gsa)
add_test(align_test align_test)

add_executable(edit_test edit_test.c)
target_link_libraries(edit_test gsa)
add_test(edit_test edit_test)

add_executable(cigar_test cigar_test.c)
target_link_libraries(cigar_test gsa)
add_test(cigar_test cigar_test)
