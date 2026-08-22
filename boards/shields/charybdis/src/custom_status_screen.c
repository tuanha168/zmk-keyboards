/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include "custom_status_screen.h"

extern const lv_image_dsc_t background_img;
lv_obj_t *__real_zmk_display_status_screen(void);

static void make_widget_transparent(lv_obj_t *obj) {
    lv_obj_set_style_bg_opa(obj, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN);
}

static void add_background(lv_obj_t *screen) {
    lv_obj_t *background = lv_image_create(screen);
    lv_image_set_src(background, &background_img);
    lv_obj_align(background, LV_ALIGN_CENTER, 0, 0);
    lv_obj_move_to_index(background, 0);
}

lv_obj_t *__wrap_zmk_display_status_screen(void) {
    lv_obj_t *screen = __real_zmk_display_status_screen();
    uint32_t child_count = lv_obj_get_child_count(screen);

    lv_obj_set_style_bg_opa(screen, LV_OPA_TRANSP, LV_PART_MAIN);
    for (uint32_t index = 0; index < child_count; index++) {
        make_widget_transparent(lv_obj_get_child(screen, index));
    }
    add_background(screen);

    return screen;
}
