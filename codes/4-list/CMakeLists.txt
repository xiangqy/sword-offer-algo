find_library(COMMON_LIBRARY common PATHS ../common/lib/)

include_directories(../common/ ../common/log/include/ ./)
# 链接
# find_package(name REQUIRED)
add_executable(guard_node_cuad guard_node_cuad.cc)
target_link_libraries(guard_node_cuad ${COMMON_LIBRARY})
