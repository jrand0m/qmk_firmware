#include QMK_KEYBOARD_H
///#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "process_unicode_common.h"
// readme
// This keyboard layout is based on the [Workman Dead layout](https://github.com/ojbucao/Workman/tree/master/mac#workman-dead-for-programmers), which uses the comma as a dead key to trigger a second layer.
// Since I have more keys at my disposal on the ErgoDox, I moved the dead key to the bottom right. There are still a lot of
// blanks so still discovering what I like.
// If you aren't familiar with a dead key, the idea is that you tap the dead key which switches the layout. the next key you hit
// triggers the key you pressed AND switches the layout back to the original. For now I do this with a super kludgey macro and I
// look forward to learning about a more elegant way to do the same thing. Until then, this will have to do.

enum {
//  TD_SCOL_COLN   = 0,
  TD_LSQBR_PLUS  = 1,
  TD_RSQBR_EQ    = 2,
};

// TODO: Define layer names that make sense for the ErgoDox EZ.
#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define DEAD 3 // dead version of the symbols layer
#define CRYL 4 // Cyryllic layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * | GR_ESC |   1  |   2  |   3  |   4  |   5  |[/DT(+)|           |]/DT(=)|   6  |   7  |   8  |   9  |   0   |   -    |
 * |--------+------+------+------+------+--------------|           |-------+------+------+------+------+-------+--------|
 * | Tab    |   Q  |   D  |   R  |   W  |   B  |  L1   |           |  L4   |   J  |   F  |   U  |   P  |;/TD(:)|   \    |
 * |--------+------+------+------+------+------|       |           |       |------+------+------+------+-------+--------|
 * | BKSpc  |   A  |   S  |   H  |   T  |   G  |-------|           |-------|   Y  |   N  |   E  |   O  |   I   |   '    |
 * |--------+------+------+------+------+------|  L2   |           |  Meh  |------+------+------+------+-------+--------|
 * | LSPCad |   Z  |   X  |   M  |   C  |   V  |       |           |       |   K  |   L  |   ,  |   .  |//Ctrl | RSPCad |
 * `--------+------+------+------+------+--------------'           `--------------+------+------+------+-------+--------'
 *   | CTRL |      |      |  OPT |  CMD |                                        | Left | Down |  Up  | Right |  L3  |
 *   `----------------------------------'                                        `-----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  INS | PRTS |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |\
 *                                 |Space |Delete|------|       |------| Enter  |Space |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GESC,        KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   BL_STEP,
        KC_TAB,         KC_Q,         KC_D,   KC_R,   KC_W,   KC_B,   TG(SYMB),
        KC_BSPC,        KC_A,         KC_S,   KC_H,   KC_T,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_M,   KC_C,   KC_V,   TG(MDIA),
        KC_LCTL,        KC_NO,        KC_NO,KC_LALT,KC_LGUI,
                                               KC_INS,  KC_PSCR,
                                                              KC_HOME,
                                               KC_SPC, KC_DEL,KC_END,
        // right hand
             BL_TOGG,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             	KC_MINS,
             TG(DEAD),            KC_J,   KC_F,   KC_U,   KC_P,   KC_SCLN,		KC_BSLS,
                                  KC_Y,   KC_N,   KC_E,   KC_O,   KC_I,             	KC_QUOT,
             MEH_T(KC_NO),        KC_K,   KC_L,   KC_COMM,KC_DOT, CTL_T(KC_SLSH),   	KC_RSFT,
                                          KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,          	KC_NO,
             TO(CRYL),        KC_NO,
             KC_PGUP,
             KC_PGDN,KC_ENT,KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   %  |   &  |   ?  |   +  |   @  |      |           |      |   $  |   _  |   [  |   ]  |   !  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   /  |   (  |   =  |   0  |   {  |------|           |------|   }  |   1  |   *  |   )  |   -  |   "    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   6  |   7  |   8  |   9  |   |  |      |           |      |   \  |   2  |   3  |   4  |   5  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,   KC_F1,    KC_F2,    KC_F3,          KC_F4,        KC_F5,          KC_TRNS,
       KC_TRNS,   KC_PERC,  KC_AMPR,  LSFT(KC_SLSH),  LSFT(KC_EQL), KC_AT,          KC_TRNS,
       KC_TRNS,   KC_SLSH,  KC_LPRN,  KC_EQL,         KC_0,     LSFT(KC_LBRC),
       KC_TRNS,   KC_6,     KC_7,     KC_8,           KC_9,     KC_PIPE,        KC_TRNS,
       KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,          KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
       KC_TRNS, KC_DLR,         KC_UNDERSCORE,  KC_LBRC,  KC_RBRC,  KC_EXLM,  KC_F12,
                KC_RCBR,        KC_1,     KC_ASTR,  KC_RPRN,  KC_MINS,  KC_QUOT,
       KC_TRNS, KC_SLSH,        KC_2,     KC_3,     KC_4,     KC_5,     KC_TRNS,
                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN1, KC_BTN2, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),

/* Keymap 3: Cirillyc layer
 * So since i want these letters to be agnostic to OS and keylayout of ED i decided to send just codes via macro
 * imitating native insertion of Unicode symbols via means of os.
 * For Win it will be "alt + <code>" for unix
 * For Mac it will be "alt + <code>" for unix
 * For Lin it will be "alt + <code>" for unix
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * | GR_ESC |   1  |   2  |   3  |   4  |   5  |[/DT(+)|           |]/DT(=)|   6  |   7  |   8  |   9  |   0   |   -    |
 * |--------+------+------+------+------+--------------|           |-------+------+------+------+------+-------+--------|
 * | Tab    |   Й  |   Ц  |   У  |   К  |   Е  |       |           |       |   Н  |   Г  |   Ш  |   Щ  |   З   |   Х    |
 * |--------+------+------+------+------+------|       |           |       |------+------+------+------+-------+--------|
 * | Hyper  |   Ф  |   И  |   В  |   А  |   П  |-------|           |-------|   Р  |   О  |   Л  |   Д  |   Ж   |   Є    |
 * |--------+------+------+------+------+------|       |           |       |------+------+------+------+-------+--------|
 * | LSPCad |   Я  |   Ч  |   С  |   М  |   І  |       |           |       |   Т  |   Ь  |   Б  |   Ю  |//Ctrl | RSPCad |
 * `--------+------+------+------+------+--------------'           `--------------+------+------+------+-------+--------'
 *   | CTRL |      |      |  OPT |  CMD |                                        | Left | Down |  Up  | Right |      |
 *   `----------------------------------'                                        `-----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |  INS | PRTS |       |  L0  |SwitchOS|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |BKSpce|Delete|------|       |------| Enter  |Space |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[CRYL] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GESC,        KC_1,         KC_2,         KC_3,         KC_4,         KC_5,         KC_NO,
        KC_TAB,         UC(0x0439),   UC(0x0446),   UC(0x0443),   UC(0x043A),   UC(0x0435),   KC_NO,
        KC_BSPC,	      UC(0x0444),   UC(0x0438),   UC(0x0432),   UC(0x0430),   UC(0x043F),
        KC_LSPO,        UC(0x044F),   UC(0x0447),   UC(0x0441),   UC(0x043C),   UC(0x0456),   KC_NO,
        KC_LCTL,        KC_NO,        KC_NO,        KC_LALT,      KC_LGUI,
                                                                    KC_INS,  KC_PSCR,
                                                                                    KC_HOME,
                                                                    KC_SPC, KC_DEL,KC_END,
        // right hand
             KC_NO,               KC_6,         KC_7,         KC_8,         KC_9,         KC_0,               KC_MINS,
             KC_NO,               UC(0x043D),   UC(0x0433),   UC(0x0448),   UC(0x0449),   UC(0x0437),         UC(0x0445),
                                  UC(0x0440),   UC(0x043E),   UC(0x043B),   UC(0x0434),   UC(0x0436),         UC(0x0454),
             KC_NO,               UC(0x0442),   UC(0x044C),   UC(0x0431),   UC(0x044E),   CTL_T(KC_SLSH),     KC_RSPC,
                                      KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,            KC_NO,
             TO(BASE),        KC_NO,
             KC_PGUP,
             KC_PGDN,KC_ENT,KC_SPC
    ),

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),                // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_ON(BASE,0),                       // FN2 - Go back to the base layer
    [3] = ACTION_LAYER_ON(SYMB,0),
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
};
