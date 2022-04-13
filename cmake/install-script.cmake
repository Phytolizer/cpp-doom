file(
    RELATIVE_PATH relative_path
    "/${cpp-doom_INSTALL_CMAKEDIR}"
    "/${CMAKE_INSTALL_BINDIR}/${cpp-doom_NAME}"
)

get_filename_component(prefix "${CMAKE_INSTALL_PREFIX}" ABSOLUTE)
set(config_dir "${prefix}/${cpp-doom_INSTALL_CMAKEDIR}")
set(config_file "${config_dir}/cpp-doomConfig.cmake")

message(STATUS "Installing: ${config_file}")
file(WRITE "${config_file}" "\
get_filename_component(
    _cpp-doom_executable
    \"\${CMAKE_CURRENT_LIST_DIR}/${relative_path}\"
    ABSOLUTE
)
set(
    CPP_DOOM_EXECUTABLE \"\${_cpp-doom_executable}\"
    CACHE FILEPATH \"Path to the cpp-doom executable\"
)
")
list(APPEND CMAKE_INSTALL_MANIFEST_FILES "${config_file}")
