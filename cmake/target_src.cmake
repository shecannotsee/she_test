# set: target name
set(library_static_name "${project_name}_static")
if (build_shared_libs STREQUAL ON)
    set(library_dynamic_name "${project_name}_dynamic")
endif ()

# Static Library
add_library(${library_static_name} STATIC ${src})
# Rename the generated static library
set_target_properties(${library_static_name} PROPERTIES OUTPUT_NAME ${project_name})
target_link_libraries(${library_static_name} PRIVATE ${src_link_dependency})

# Dynamic Library
if (build_shared_libs STREQUAL ON)
    add_library(${library_dynamic_name} SHARED ${src})
    # Rename the generated dynamic library
    set_target_properties(${library_dynamic_name} PROPERTIES OUTPUT_NAME ${project_name})
    target_link_libraries(${library_dynamic_name} PRIVATE ${src_link_dependency})
endif ()
