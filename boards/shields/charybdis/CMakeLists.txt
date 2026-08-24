if(CONFIG_SHIELD_CHARYBDIS_DONGLE AND CONFIG_SHIELD_DONGLE_SCREEN)
  if(NOT DEFINED ZEPHYR_DONGLE_SCREEN_MODULE_DIR)
    message(FATAL_ERROR "dongle_screen module directory is unavailable")
  endif()

  set(dongle_screen_status_source
      "${ZEPHYR_DONGLE_SCREEN_MODULE_DIR}/boards/shields/dongle_screen/src/custom_status_screen.c")
  cmake_language(DEFER DIRECTORY "${CMAKE_SOURCE_DIR}" CALL set_source_files_properties
    "${dongle_screen_status_source}"
    TARGET_DIRECTORY "..__zmk-dongle-screen__boards__shields__dongle_screen"
    PROPERTIES HEADER_FILE_ONLY TRUE
  )

  zephyr_library()
  zephyr_library_include_directories(
    "${ZEPHYR_DONGLE_SCREEN_MODULE_DIR}/boards/shields/dongle_screen/include"
    "${ZEPHYR_DONGLE_SCREEN_MODULE_DIR}/boards/shields/dongle_screen/src"
  )
  zephyr_library_sources(
    src/background_img.c
    src/custom_status_screen.c
  )
endif()
