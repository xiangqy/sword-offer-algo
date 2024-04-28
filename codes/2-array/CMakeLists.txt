find_library(COMMON_LIBRARY common PATHS ../common/lib/)

include_directories(../common/ ../common/log/include/)
# 链接
# find_package(name REQUIRED)
add_executable(search_sum_index search_sum_index.cc)
target_link_libraries(search_sum_index ${COMMON_LIBRARY})

add_executable(sum_for_fixed sum_for_fixed.cc)
target_link_libraries(sum_for_fixed ${COMMON_LIBRARY})

add_executable(sum_shortest_array sum_shortest_array.cc)
target_link_libraries(sum_shortest_array ${COMMON_LIBRARY})

add_executable(sub_array sub_array.cc)
target_link_libraries(sub_array ${COMMON_LIBRARY})
