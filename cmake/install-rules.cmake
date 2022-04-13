include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# find_package(<package>) call for consumers to find this project
set(package cpp-doom)

install(
    TARGETS cpp-doom_exe
    RUNTIME COMPONENT cpp-doom_Runtime
)

write_basic_package_version_file(
    "${package}ConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

# Allow package maintainers to freely override the path for the configs
set(
    cpp-doom_INSTALL_CMAKEDIR "${CMAKE_INSTALL_DATADIR}/${package}"
    CACHE PATH "CMake package config location relative to the install prefix"
)
mark_as_advanced(cpp-doom_INSTALL_CMAKEDIR)

install(
    FILES "${PROJECT_BINARY_DIR}/${package}ConfigVersion.cmake"
    DESTINATION "${cpp-doom_INSTALL_CMAKEDIR}"
    COMPONENT cpp-doom_Development
)

# Export variables for the install script to use
install(CODE "
set(cpp-doom_NAME [[$<TARGET_FILE_NAME:cpp-doom_exe>]])
set(cpp-doom_INSTALL_CMAKEDIR [[${cpp-doom_INSTALL_CMAKEDIR}]])
set(CMAKE_INSTALL_BINDIR [[${CMAKE_INSTALL_BINDIR}]])
" COMPONENT cpp-doom_Development)

install(
    SCRIPT cmake/install-script.cmake
    COMPONENT cpp-doom_Development
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
