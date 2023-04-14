/* Copyright 2019 Danny Nguyen <danny@keeb.io>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

enum layer_names {
	_BASE_LR = 0,
	_G_LR,
	_B_LR,
	_R_LR
};

void keyboard_post_init_user(void){
	rgb_matrix_mode(RGB_MATRIX_JELLYBEAN_RAINDROPS);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE_LR] = LAYOUT(
		MO(_G_LR), MO(_B_LR), KC_MUTE,
		KC_F14, C(KC_F14), LCA(KC_F14),
		KC_F15, C(KC_F15), LCA(KC_F15)
	),
	[_G_LR] = LAYOUT(
		_______, MO(_R_LR), _______,
		KC_F16, C(KC_F16), LCA(KC_F16),
		KC_F17, C(KC_F17), LCA(KC_F17)
	),
	[_B_LR] = LAYOUT(
		MO(_R_LR), _______, _______,
		KC_F18, C(KC_F18), LCA(KC_F18),
		RGB_TOG, _______, _______
	),
	[_R_LR] = LAYOUT(
		_______, _______, _______,
		_______, _______, _______,
		QK_BOOT, EE_CLR, _______
	),
};


layer_state_t layer_state_set_user(layer_state_t state) {
	uint8_t layer = get_highest_layer(state);
	switch (layer) {
		case _BASE_LR:
			rgblight_reload_from_eeprom();
			rgb_matrix_mode_noeeprom(RGB_MATRIX_JELLYBEAN_RAINDROPS);
			break;
		case _R_LR:
			rgblight_sethsv_noeeprom(HSV_RED);
			rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
			break;
		case _G_LR:
			rgblight_sethsv_noeeprom(HSV_GREEN);
			rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
			break;
		case _B_LR:
			rgblight_sethsv_noeeprom(HSV_BLUE);
			rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
			break;
		default:
			rgblight_reload_from_eeprom();
			break;
	}
	return state;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
	if (index == _RIGHT) {
		if (clockwise) {
			tap_code(KC_VOLU);
		} else {
			tap_code(KC_VOLD);
		}
	}
	/*
	else if (index == _LEFT) {
		if (clockwise) {
			rgb_matrix_increase_hue();
		} else {
			rgb_matrix_decrease_hue();
		}
	}
	else if (index == _MIDDLE) {
		if (clockwise) {
			rgblight_increase_val();
		} else {
			rgblight_decrease_val();
		}
	}*/
	return false;
}
