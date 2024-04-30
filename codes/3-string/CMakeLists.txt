find_library(COMMON_LIBRARY common PATHS ../common/lib/)

include_directories(../common/ ../common/log/include/)
# 链接
# find_package(name REQUIRED)
add_executable(search_anagram search_anagram.cc)
target_link_libraries(search_anagram ${COMMON_LIBRARY})

add_executable(search_anagram_index search_anagram_index.cc)
target_link_libraries(search_anagram_index ${COMMON_LIBRARY})

add_executable(judgement_palindrome judgement_palindrome.cc)
target_link_libraries(judgement_palindrome ${COMMON_LIBRARY})

add_executable(valid_palindrome valid_palindrome.cc)
target_link_libraries(valid_palindrome ${COMMON_LIBRARY})

add_executable(count_palindrome count_palindrome.cc)
target_link_libraries(count_palindrome ${COMMON_LIBRARY})
