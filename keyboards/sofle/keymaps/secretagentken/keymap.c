#include QMK_KEYBOARD_H

enum sofle_layers {
    _DEFAULTS = 0,
    _BASE = 0,
    _SYMBOLS,
    _EXTEND
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_GRV,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSLS,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  RGB_TOG,    KC_MUTE,KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 KC_LCTL, KC_LGUI, KC_LALT, MO(_SYMBOLS),MO(_EXTEND),KC_ENT,KC_SPC, TO(_BASE),TO(_SYMBOLS),TO(_EXTEND)
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),
[_SYMBOLS] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS,KC_TRNS, KC_MINS, KC_EQL,  KC_DEL,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS, KC_LPRN,                   KC_RPRN, KC_TRNS, KC_UP,  KC_LBRC, KC_RBRC, KC_TRNS,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_TRNS,  KC_TRNS,KC_HOME,KC_PGDN,  KC_END,  KC_LCBR,                   KC_RCBR, KC_LEFT,KC_DOWN, KC_RIGHT,KC_TRNS, KC_TRNS,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  KC_TRNS,  KC_TRNS,KC_TRNS, KC_MINS, KC_EQL,  KC_LBRC,KC_TRNS,   KC_TRNS,KC_RBRC, KC_UNDS,KC_PLUS, KC_TRNS,  KC_TRNS, KC_TRNS,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),
[_EXTEND] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  KC_TRNS,  KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_TRNS,  KC_F11, KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_TRNS,  KC_EXLM,KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR,KC_ASTR, KC_LPRN,  KC_RPRN, KC_TRNS,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  KC_TRNS,  KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS,  KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

};

RGB get_rgb(uint8_t hue, uint8_t brightness) {
    HSV hsv = {hue, 255, brightness};
    if (hsv.v > rgb_matrix_get_val()){
        hsv.v = rgb_matrix_get_val();
    }
    return hsv_to_rgb(hsv);
}

#ifdef RGB_MATRIX_ENABLE

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
	uint8_t layer = get_highest_layer(layer_state);
    RGB colorVal;
	switch (layer) {
		case _SYMBOLS:
            colorVal = get_rgb(0,75);
            rgb_matrix_set_color(0, colorVal.r, colorVal.g, colorVal.b);
            rgb_matrix_set_color(RGB_HALF_LED_COUNT, colorVal.r, colorVal.g, colorVal.b);
            break;
        case _EXTEND:
            colorVal = get_rgb(170,75);
            rgb_matrix_set_color(0, colorVal.r, colorVal.g, colorVal.b);
            rgb_matrix_set_color(RGB_HALF_LED_COUNT, colorVal.r, colorVal.g, colorVal.b);
            break;
        default:
            rgb_matrix_set_color(0, 0, 0, 0);
            rgb_matrix_set_color(RGB_HALF_LED_COUNT, 0, 0, 0);
            break;
	}
	return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
	}
    return true;
}
#endif

#ifdef OLED_ENABLE

static void print_right(void) {
    oled_write_ln_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Base \n"), false);
            oled_write_ln_P(PSTR("     \n"),false);
            oled_write_ln_P(PSTR("     \n"),false);
            oled_write_ln_P(PSTR("     \n"),false);
            oled_write_ln_P(PSTR("     "),false);
            break;
        case _SYMBOLS:
            oled_write_ln_P(PSTR("Symbl\n"), false);
            oled_write_ln_P(PSTR(" -= d\n"),false);
            oled_write_ln_P(PSTR(") u[]\n"),false);
            oled_write_ln_P(PSTR("}ldr \n"),false); 
            oled_write_ln_P(PSTR("]_+  "),false);
            break;
        case _EXTEND:
            oled_write_ln_P(PSTR("Extnd\n"), false);
            oled_write_ln_P(PSTR("F6 - \n"),false);
            oled_write_ln_P(PSTR("     \n"),false);
            oled_write_ln_P(PSTR("^&*()\n"),false);
            oled_write_ln_P(PSTR("     "),false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef\n"), false);
    }
}

static void print_left(void){
    oled_write_ln_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Base \n"), false);
            oled_write_ln_P(PSTR("     \n"),false);
            oled_write_ln_P(PSTR("     \n"),false);
            oled_write_ln_P(PSTR("     \n"),false);
            break;
        case _SYMBOLS:
            oled_write_ln_P(PSTR("Symbl\n"), false);
            oled_write_ln_P(PSTR("pU ( \n"),false);
            oled_write_ln_P(PSTR("HDE{ \n"),false); 
            oled_write_ln_P(PSTR("- = [\n"),false);
            break;
        case _EXTEND:
            oled_write_ln_P(PSTR("Extnd\n"), false);
            oled_write_ln_P(PSTR("F1 - \n"),false);
            oled_write_ln_P(PSTR("F11 -\n"),false);
            oled_write_ln_P(PSTR("!@#$%\n"),false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    if (is_keyboard_left()) {
        print_left();
    } else {
        print_right();
    }
    return false;
}

#endif
 
