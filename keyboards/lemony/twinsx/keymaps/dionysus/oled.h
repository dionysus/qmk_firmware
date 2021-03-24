#include QMK_KEYBOARD_H

// OLED - Display a bitmap image at the top of the screen
void render_img(void) {
    static const char PROGMEM img_oled[] = { 
        // 'twins', 32x96px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0x70, 0x3c, 0x1c, 0x0e, 0x0e, 0x1f, 0x3f, 0x3f, 
0x7f, 0x7f, 0x7f, 0x7e, 0x7e, 0x7c, 0x7c, 0xf8, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xe0, 0x80, 0x0c, 0x1e, 0x1e, 0x0c, 0x00, 0x60, 
0x00, 0x00, 0x0c, 0x1e, 0x1e, 0x0c, 0x80, 0xc0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x30, 0x7e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xfc, 0xfc, 0xcc, 0xc0, 
0xc4, 0xc4, 0xfc, 0xfc, 0xfe, 0x7e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x38, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xe8, 0x1d, 0x03, 0x03, 0x01, 0xe0, 0x20, 0x00, 0x00, 0x01, 0x01, 0x01, 
0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0xe0, 0x01, 0x03, 0x07, 0x0d, 0xb8, 0x40, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xfe, 0x07, 0x06, 0x9e, 0xff, 0xc0, 0xc0, 0x80, 0xe0, 0xe0, 0xc0, 0x80, 
0x80, 0xc0, 0xe0, 0xe0, 0x80, 0xc0, 0xc1, 0xdf, 0xbc, 0x06, 0x3f, 0xe9, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0xfe, 0x01, 0x00, 0x01, 0x01, 0x05, 0xe7, 0xff, 0x5f, 
0x03, 0xff, 0xff, 0x87, 0x05, 0x01, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xf8, 0x07, 0xff, 0x00, 0x00, 0xdf, 0x30, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 
0x00, 0x91, 0xff, 0xff, 0x00, 0x00, 0x00, 0x20, 0x7f, 0xc0, 0x00, 0xbf, 0x44, 0x1c, 0xe0, 0x00, 
0xe0, 0xfa, 0xfd, 0xf8, 0xfb, 0xf6, 0xf3, 0xf0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc3, 0xe3, 0xc1, 
0xe0, 0xe1, 0xe3, 0xc1, 0xe0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf7, 0xf2, 0xf3, 0xf8, 0xf8, 0xff, 0xc0, 
0x00, 0x03, 0x07, 0x0f, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0xff, 0xbf, 0x3f, 0x3f, 0x3f, 0x3f, 0xbf, 
0x7f, 0xff, 0x3f, 0x3f, 0x3f, 0x3f, 0xbf, 0xff, 0x1f, 0x1f, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x03, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x03, 0x02, 0x02, 0xe2, 0x1f, 
0x00, 0x03, 0xff, 0x02, 0x01, 0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x80, 0x00, 0x00, 0xff, 0x00, 
0x00, 0xc0, 0xbf, 0x00, 0x00, 0xc0, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0xfc, 0xfe, 0x71, 0x79, 0x39, 0x0f, 0x47, 0xf0, 
0xfc, 0xf3, 0x79, 0x39, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(img_oled, sizeof(img_oled));
}