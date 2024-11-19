# Set installation path
if (NOT DEFINED CMAKE_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX "/")
endif ()

# Install header files
install(FILES
        ${include_list} # from target_src.cmake
        DESTINATION # to
        ${project_name}/include # install path
)
# Install static library
install(TARGETS
        ${library_static_name}
        DESTINATION
        ${project_name}/lib
)
# Install dynamic library
if (build_shared_libs STREQUAL ON)
    install(TARGETS
            ${library_dynamic_name}
            DESTINATION
            ${project_name}/lib
    )
endif ()

# Install other module
install(TARGETS
        ${other_name}
        DESTINATION
        ${project_name}/bin
)

# Install testing module
if (build_tests STREQUAL ON)
    install(TARGETS
            ${test_name}
            DESTINATION
            ${project_name}/bin # install path
    )
endif ()

# Install cmake file
#install(FILES
#        ${CMAKE_SOURCE_DIR}/cmake/${project_name}-config.cmake
#        DESTINATION
#        ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/cmake
#)

