# Set installation path
if (NOT DEFINED CMAKE_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX "/")
endif ()

# Ensure proper install paths using GNUInstallDirs for standardized locations
include(GNUInstallDirs)

# Install header files while maintaining directory structure
install(DIRECTORY ${CMAKE_SOURCE_DIR}/src/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILES_MATCHING
        PATTERN "*.h"
)

# Install static library
install(TARGETS
        ${library_static_name}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} # For static libraries
)

# Install dynamic library
if (build_shared_libs STREQUAL ON)
    install(TARGETS
            ${library_dynamic_name}
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} # For shared libraries
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # For Windows DLLs, if applicable
    )
endif ()

# Install other module
install(TARGETS
        ${other_name}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # For executables
)

# Install testing module
if (build_tests STREQUAL ON)
    install(TARGETS
            ${test_name}
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # For test executables
    )
endif ()

# Install cmake configuration file
#install(FILES
#        ${CMAKE_SOURCE_DIR}/cmake/${project_name}-config.cmake
#        DESTINATION ${CMAKE_INSTALL_DATADIR}/${project_name}/cmake
#)
