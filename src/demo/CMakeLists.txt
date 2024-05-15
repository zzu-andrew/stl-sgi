








# all cpp files
file(GLOB_RECURSE CPP_SRC_LIST ${CMAKE_CURRENT_LIST_DIR}/*.cpp)

message(STATUS ${CMAKE_CURRENT_LIST_DIR})

# generate target for every cpp file
foreach(v ${CPP_SRC_LIST})
    # file relative path from src/
    string(REGEX MATCH ".*" relative_path ${v})
    # delete string "src/"
#    string(REGEX REPLACE "src/" "" target_name ${relative_path})
    # rename '/' and '.' to '_'
    string(REGEX REPLACE "/|\\." "_" target_name ${relative_path})

    add_executable(${target_name}_cpp ${v})
endforeach()


