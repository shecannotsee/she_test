
########################################################################################################################
# Install module                                                                                                       #
########################################################################################################################

# local debug
set(CMAKE_INSTALL_PREFIX "./")
# Release Code
# set(CMAKE_INSTALL_PREFIX "/")

message(STATUS "The default installation path is ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Please use \"make install DESTDIR=./PATH\" to set install path")

# test install
install(TARGETS
    ${test_name} DESTINATION ${PROJECT_NAME}/bin
    )

install(FILES
        ${CMAKE_SOURCE_DIR}/src/command_line_parser/command_line.h
        ${CMAKE_SOURCE_DIR}/src/command_line_parser/options.h
        DESTINATION # to
        ${PROJECT_NAME}/include/command_line_parser # target dir
)

install(FILES
        ${CMAKE_SOURCE_DIR}/src/output_format/common.h
        ${CMAKE_SOURCE_DIR}/src/output_format/gtest_format.h
        ${CMAKE_SOURCE_DIR}/src/output_format/she_test_v1.h
        DESTINATION # to
        ${PROJECT_NAME}/include/output_format # target dir
)

install(FILES
        ${CMAKE_SOURCE_DIR}/src/template_support/equal.h
        DESTINATION # to
        ${PROJECT_NAME}/include/template_support # target dir
)

install(FILES
        ${CMAKE_SOURCE_DIR}/src/test_case_registry/register_center.h
        ${CMAKE_SOURCE_DIR}/src/test_case_registry/test_case.h
        DESTINATION # to
        ${PROJECT_NAME}/include/test_case_registry # target dir
)

install(FILES
        ${CMAKE_SOURCE_DIR}/src/print_color.h
        ${CMAKE_SOURCE_DIR}/src/she_test.h
        DESTINATION # to
        ${PROJECT_NAME}/include # target dir
)

if (generate_lib STREQUAL "ON")
    # include install
    install(FILES
        ${CMAKE_SOURCE_DIR}/src/she_test.h
            ${CMAKE_SOURCE_DIR}/src/print_color.h
            ${CMAKE_SOURCE_DIR}/src/test_case_manager.h
        DESTINATION # to
        ${PROJECT_NAME}/include # target dir
        )
    # lib install
    install(TARGETS
        ${library_static_name} ${library_dynamic_name}
        DESTINATION ${PROJECT_NAME}/lib
        )
    # cmake install
    install(FILES
            ${CMAKE_SOURCE_DIR}/cmake/${project_name}-config.cmake
            DESTINATION ${PROJECT_NAME}/cmake
            )
endif ()


