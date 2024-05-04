find_library(COMMON_LIBRARY common PATHS ../common/lib/)

include_directories(../common/ ../common/log/include/ ./)
# 链接
# find_package(name REQUIRED)
add_executable(delete_appoint_node node_common.cc delete_appoint_node.cc)
target_link_libraries(delete_appoint_node ${COMMON_LIBRARY})

add_executable(find_ring_entrance node_common.cc find_ring_entrance.cc)
target_link_libraries(find_ring_entrance ${COMMON_LIBRARY})
