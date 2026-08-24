if(CONFIG_SHIELD_CHARYBDIS_DONGLE AND CONFIG_SHIELD_DONGLE_SCREEN)
  zephyr_library()
  zephyr_library_sources(src/background_img.c)
endif()
