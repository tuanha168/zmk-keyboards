if(CONFIG_SHIELD_CHARYBDIS_DONGLE AND CONFIG_SHIELD_DONGLE_SCREEN)
  if(NOT DEFINED ZEPHYR_DONGLE_SCREEN_MODULE_DIR)
    message(FATAL_ERROR "dongle_screen module directory is unavailable")
  endif()

  zephyr_library()
  zephyr_library_include_directories(
    "${ZEPHYR_DONGLE_SCREEN_MODULE_DIR}/boards/shields/dongle_screen/include"
    "${ZEPHYR_DONGLE_SCREEN_MODULE_DIR}/boards/shields/dongle_screen/src"
  )
  zephyr_library_sources(
    src/background_img.c
    src/custom_status_screen.c
  )
  zephyr_ld_options(-Wl,--wrap=zmk_display_status_screen)
endif()
