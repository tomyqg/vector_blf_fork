find_package(LCOV)

if(LCOV_FOUND)

  add_custom_target(lcov_capture ALL
    ${LCOV_EXECUTABLE}
    --capture
    --directory ${PROJECT_SOURCE_DIR}
    --output-file coverage.info)

  add_custom_target(lcov_genhtml ALL
    ${LCOV_GENHTML_EXECUTABLE}
    coverage.info
    --output-directory lcov)

  install(
    DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lcov
    DESTINATION share/doc/Vector_BLF)

endif()
