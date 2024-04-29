find_library(COMMON_LIBRARY common PATHS ../common/lib/)

include_directories(../common/ ../common/log/include/)
# 链接
# find_package(name REQUIRED)
add_executable(division_method division_method.cc)
target_link_libraries(division_method ${COMMON_LIBRARY})

add_executable(binary_addition binary_addition.cc
        ../3-string/search_anagram.cc)
target_link_libraries(binary_addition ${COMMON_LIBRARY})

add_executable(statistics_binary statistics_binary.cc)
target_link_libraries(statistics_binary ${COMMON_LIBRARY})

add_executable(search_appear_once search_appear_once.cc)
target_link_libraries(search_appear_once ${COMMON_LIBRARY})

add_executable(word_max_accumulate word_max_accumulate.cc)
target_link_libraries(word_max_accumulate ${COMMON_LIBRARY})
