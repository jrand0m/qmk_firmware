#include "simple_visualizer.h"
#include "process_unicode_common.h"
#include <string.h>

static void get_visualizer_layer_and_color(visualizer_state_t* state) {
    uint8_t saturation = 60;
    if (state->status.leds & (1u << USB_LED_CAPS_LOCK)) {
        saturation = 255;
    }
    if (state->status.layer & 0x10) {
        state->target_lcd_color = LCD_COLOR(216, saturation, 0xFF);
        state->layer_text = "go away from here";

    }
    else if (state->status.layer & 0x8) {
        state->target_lcd_color = LCD_COLOR(100, saturation, 0xFF);
        state->layer_text = "Dead";
    }
    else if (state->status.layer & 0x4) {
        state->target_lcd_color = LCD_COLOR(10, saturation, 0xFF);
        state->layer_text = "Media";
    }
    else if (state->status.layer & 0x2) {
        state->target_lcd_color = LCD_COLOR(168, saturation, 0xFF);
        state->layer_text = "Symbol";
    }
    else {
        state->target_lcd_color = LCD_COLOR(84, saturation, 0xFF);
        state->layer_text = "Default";
    }
}
