/* Copyright 2022 @ Keychron (https://www.keychron.com)
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

enum layers { _BASE, _FN1};

enum q0_keycodes {
  BASE = SAFE_RANGE,
  FN1,
  HTN_SINGLE,
  HTN_LOOP,
  DM_SINGLE,
  DM_LOOP,
  CSN_OPEN,
  LINE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_numpad_6x4(
        MO(_FN1), KC_ESC,  KC_BSPC,   KC_TAB,
        _______,  _______, KC_PAST,   KC_PMNS,
        HTN_SINGLE, HTN_LOOP,   KC_P9,
        DM_SINGLE, DM_LOOP,     KC_P6,     KC_PPLS,
        CSN_OPEN, LINE,    KC_P3,
        KC_P0,             _______,   KC_PENT),

    [_FN1] = LAYOUT_numpad_6x4(
        _______,    KC_MUTE, KC_VOLD,   QK_BOOT,
        RGB_MOD,    RGB_VAI, RGB_HUI,   KC_DEL,
        RGB_RMOD,   RGB_VAD, RGB_HUD,
        RGB_SAI,    RGB_SPI, KC_MPRV,   _______,
        RGB_SAD,    RGB_SPD, KC_MPLY,
        RGB_TOG,             KC_MNXT,   _______)



};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case HTN_SINGLE:
          if (record->event.pressed)
          {
            SEND_STRING(

            //Open orders only encounter SS_DELAY(100)
            SS_LCTL("c") SS_DELAY(100)
            SS_LGUI("2") SS_DELAY(500) SS_DELAY(100)
            SS_LCTL("5") SS_DELAY(100)
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_DELAY(100)
            SS_LCTL("v") SS_DELAY(100)
            SS_LALT("fs") SS_DELAY(100)
            SS_DELAY(10000) SS_DELAY(100)
            //Get date of lab test from excel SS_DELAY(100)
            SS_LGUI("1") SS_DELAY(100)
            SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100)
            SS_LCTL("c") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            //Inputting orders SS_DELAY(100)
            SS_LGUI("2") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            SS_LCTL("o") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            "HYPERTENSIVE PANEL" SS_DELAY(100)
            SS_TAP(X_ENTER) SS_DELAY(1000) SS_DELAY(100)
            SS_LALT("f") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            SS_TAP(X_ENTER) SS_DELAY(100)
            SS_DELAY(3500) SS_DELAY(100)
            SS_LCTL("v") SS_DELAY(100)
            //Sending orders SS_DELAY(100)
            SS_LALT("s") SS_DELAY(100)
            SS_DELAY(2000) SS_DELAY(100)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(100)
            SS_DELAY(7000) SS_DELAY(100)
            //Excel file management SS_DELAY(100)
            SS_LGUI("1") SS_DELAY(100)
            SS_TAP(X_RGHT) SS_DELAY(100)
            "HTN single" SS_DELAY(100)
            SS_DELAY(100) SS_DELAY(100)
            SS_LCTL(SS_TAP(X_LEFT)) SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100) SS_DELAY(100)
            SS_LSFT(SS_TAP(X_SPC)) SS_DELAY(100)
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100) SS_DELAY(100)
            SS_TAP(X_DOWN) SS_DELAY(100)
             SS_DELAY(100)
             SS_DELAY(100)
            //#hs_section

	    // #SAVE
            SS_LCTL("s")
            SS_DELAY(5000)

            );
          }
          break;
        case HTN_LOOP:
          if (record->event.pressed)
          {
            SEND_STRING(

            //Open orders only encounter SS_DELAY(100)
            SS_LCTL("c") SS_DELAY(100)
            SS_LGUI("2") SS_DELAY(500) SS_DELAY(100)
            SS_LCTL("5") SS_DELAY(100)
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_DELAY(100)
            SS_LCTL("v") SS_DELAY(100)
            SS_LALT("fs") SS_DELAY(100)
            SS_DELAY(10000) SS_DELAY(100)
            //Get date of lab test from excel SS_DELAY(100)
            SS_LGUI("1") SS_DELAY(100)
            SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100)
            SS_LCTL("c") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            //Inputting orders SS_DELAY(100)
            SS_LGUI("2") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            SS_LCTL("o") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            "HYPERTENSIVE PANEL" SS_DELAY(100)
            SS_TAP(X_ENTER) SS_DELAY(1000) SS_DELAY(100)
            SS_LALT("f") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            SS_TAP(X_ENTER) SS_DELAY(100)
            SS_DELAY(3500) SS_DELAY(100)
            SS_LCTL("v") SS_DELAY(100)
            //Sending orders SS_DELAY(100)
            SS_LALT("s") SS_DELAY(100)
            SS_DELAY(2000) SS_DELAY(100)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(100)
            SS_DELAY(7000) SS_DELAY(100)
            //Excel file management SS_DELAY(100)
            SS_LGUI("1") SS_DELAY(100)
            SS_TAP(X_RGHT) SS_DELAY(100)
            "HTN 01 - loop start" SS_DELAY(100)
            SS_DELAY(100) SS_DELAY(100)
            SS_LCTL(SS_TAP(X_LEFT)) SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100) SS_DELAY(100)
            SS_LSFT(SS_TAP(X_SPC)) SS_DELAY(100)
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100) SS_DELAY(100)
            SS_TAP(X_DOWN) SS_DELAY(100)
             SS_DELAY(100)
             SS_DELAY(100)

             SS_DELAY(2000)//Open orders only encounter SS_DELAY(100)
            SS_LCTL("c") SS_DELAY(100)
            SS_LGUI("2") SS_DELAY(500) SS_DELAY(100)
            SS_LCTL("5") SS_DELAY(100)
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_DELAY(100)
            SS_LCTL("v") SS_DELAY(100)
            SS_LALT("fs") SS_DELAY(100)
            SS_DELAY(10000) SS_DELAY(100)
            //Get date of lab test from excel SS_DELAY(100)
            SS_LGUI("1") SS_DELAY(100)
            SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100)
            SS_LCTL("c") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            //Inputting orders SS_DELAY(100)
            SS_LGUI("2") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            SS_LCTL("o") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            "HYPERTENSIVE PANEL" SS_DELAY(100)
            SS_TAP(X_ENTER) SS_DELAY(1000) SS_DELAY(100)
            SS_LALT("f") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            SS_TAP(X_ENTER) SS_DELAY(100)
            SS_DELAY(3500) SS_DELAY(100)
            SS_LCTL("v") SS_DELAY(100)
            //Sending orders SS_DELAY(100)
            SS_LALT("s") SS_DELAY(100)
            SS_DELAY(2000) SS_DELAY(100)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(100)
            SS_DELAY(7000) SS_DELAY(100)
            //Excel file management SS_DELAY(100)
            SS_LGUI("1") SS_DELAY(100)
            SS_TAP(X_RGHT) SS_DELAY(100)
            "HTN 02" SS_DELAY(100)
            SS_DELAY(100) SS_DELAY(100)
            SS_LCTL(SS_TAP(X_LEFT)) SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100) SS_DELAY(100)
            SS_LSFT(SS_TAP(X_SPC)) SS_DELAY(100)
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100) SS_DELAY(100)
            SS_TAP(X_DOWN) SS_DELAY(100)
             SS_DELAY(100)
             SS_DELAY(100)

             SS_DELAY(2000)//Open orders only encounter SS_DELAY(100)
            SS_LCTL("c") SS_DELAY(100)
            SS_LGUI("2") SS_DELAY(500) SS_DELAY(100)
            SS_LCTL("5") SS_DELAY(100)
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_DELAY(100)
            SS_LCTL("v") SS_DELAY(100)
            SS_LALT("fs") SS_DELAY(100)
            SS_DELAY(10000) SS_DELAY(100)
            //Get date of lab test from excel SS_DELAY(100)
            SS_LGUI("1") SS_DELAY(100)
            SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100)
            SS_LCTL("c") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            //Inputting orders SS_DELAY(100)
            SS_LGUI("2") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            SS_LCTL("o") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            "HYPERTENSIVE PANEL" SS_DELAY(100)
            SS_TAP(X_ENTER) SS_DELAY(1000) SS_DELAY(100)
            SS_LALT("f") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            SS_TAP(X_ENTER) SS_DELAY(100)
            SS_DELAY(3500) SS_DELAY(100)
            SS_LCTL("v") SS_DELAY(100)
            //Sending orders SS_DELAY(100)
            SS_LALT("s") SS_DELAY(100)
            SS_DELAY(2000) SS_DELAY(100)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(100)
            SS_DELAY(7000) SS_DELAY(100)
            //Excel file management SS_DELAY(100)
            SS_LGUI("1") SS_DELAY(100)
            SS_TAP(X_RGHT) SS_DELAY(100)
            "HTN 03 - loop end" SS_DELAY(100)
            SS_DELAY(100) SS_DELAY(100)
            SS_LCTL(SS_TAP(X_LEFT)) SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100) SS_DELAY(100)
            SS_LSFT(SS_TAP(X_SPC)) SS_DELAY(100)
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100) SS_DELAY(100)
            SS_TAP(X_DOWN) SS_DELAY(100)
             SS_DELAY(100)
             SS_DELAY(100)

             SS_DELAY(2000)//#hl_section

	    // #SAVE
            SS_LCTL("s")
            SS_DELAY(5000)

            );
          }
          break;
        case DM_SINGLE:
          if (record->event.pressed)
          {
            SEND_STRING(

            //Open orders only encounter SS_DELAY(100)
            SS_LCTL("c") SS_DELAY(100)
            SS_LGUI("2") SS_DELAY(500) SS_DELAY(100)
            SS_LCTL("5") SS_DELAY(100)
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_DELAY(100)
            SS_LCTL("v") SS_DELAY(100)
            SS_LALT("fs") SS_DELAY(100)
            SS_DELAY(10000) SS_DELAY(100)
            //Get date of lab test from excel SS_DELAY(100)
            SS_LGUI("1") SS_DELAY(100)
            SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100)
            SS_LCTL("c") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            //Inputting orders SS_DELAY(100)
            SS_LGUI("2") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            SS_LCTL("o") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            "DIABETES MONITORING PANEL" SS_DELAY(100)
            SS_TAP(X_ENTER) SS_DELAY(1000) SS_DELAY(100)
            SS_LALT("f") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            SS_TAP(X_ENTER) SS_DELAY(100)
            SS_DELAY(3500) SS_DELAY(100)
            SS_LCTL("v") SS_DELAY(100)
            //Sending orders SS_DELAY(100)
            SS_LALT("s") SS_DELAY(100)
            SS_DELAY(2000) SS_DELAY(100)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(100)
            SS_DELAY(7000) SS_DELAY(100)
            //Excel file management SS_DELAY(100)
            SS_LGUI("1") SS_DELAY(100)
            SS_TAP(X_RGHT) SS_DELAY(100)
            "DM single" SS_DELAY(100)
            SS_DELAY(100) SS_DELAY(100)
            SS_LCTL(SS_TAP(X_LEFT)) SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100) SS_DELAY(100)
            SS_LSFT(SS_TAP(X_SPC)) SS_DELAY(100)
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100) SS_DELAY(100)
            SS_TAP(X_DOWN) SS_DELAY(100)
             SS_DELAY(100)
             SS_DELAY(100)
            //#ds_section

	    // #SAVE
            SS_LCTL("s")
            SS_DELAY(5000)

            );
          }
          break;
        case DM_LOOP:
          if (record->event.pressed)
          {
            SEND_STRING(

            //Open orders only encounter SS_DELAY(100)
            SS_LCTL("c") SS_DELAY(100)
            SS_LGUI("2") SS_DELAY(500) SS_DELAY(100)
            SS_LCTL("5") SS_DELAY(100)
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_DELAY(100)
            SS_LCTL("v") SS_DELAY(100)
            SS_LALT("fs") SS_DELAY(100)
            SS_DELAY(10000) SS_DELAY(100)
            //Get date of lab test from excel SS_DELAY(100)
            SS_LGUI("1") SS_DELAY(100)
            SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100)
            SS_LCTL("c") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            //Inputting orders SS_DELAY(100)
            SS_LGUI("2") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            SS_LCTL("o") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            "DIABETES MONITORING PANEL" SS_DELAY(100)
            SS_TAP(X_ENTER) SS_DELAY(1000) SS_DELAY(100)
            SS_LALT("f") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            SS_TAP(X_ENTER) SS_DELAY(100)
            SS_DELAY(3500) SS_DELAY(100)
            SS_LCTL("v") SS_DELAY(100)
            //Sending orders SS_DELAY(100)
            SS_LALT("s") SS_DELAY(100)
            SS_DELAY(2000) SS_DELAY(100)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(100)
            SS_DELAY(7000) SS_DELAY(100)
            //Excel file management SS_DELAY(100)
            SS_LGUI("1") SS_DELAY(100)
            SS_TAP(X_RGHT) SS_DELAY(100)
            "DM 01 - loop start" SS_DELAY(100)
            SS_DELAY(100) SS_DELAY(100)
            SS_LCTL(SS_TAP(X_LEFT)) SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100) SS_DELAY(100)
            SS_LSFT(SS_TAP(X_SPC)) SS_DELAY(100)
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100) SS_DELAY(100)
            SS_TAP(X_DOWN) SS_DELAY(100)
             SS_DELAY(100)
             SS_DELAY(100)

             SS_DELAY(2000)//Open orders only encounter SS_DELAY(100)
            SS_LCTL("c") SS_DELAY(100)
            SS_LGUI("2") SS_DELAY(500) SS_DELAY(100)
            SS_LCTL("5") SS_DELAY(100)
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_DELAY(100)
            SS_LCTL("v") SS_DELAY(100)
            SS_LALT("fs") SS_DELAY(100)
            SS_DELAY(10000) SS_DELAY(100)
            //Get date of lab test from excel SS_DELAY(100)
            SS_LGUI("1") SS_DELAY(100)
            SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100)
            SS_LCTL("c") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            //Inputting orders SS_DELAY(100)
            SS_LGUI("2") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            SS_LCTL("o") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            "DIABETES MONITORING PANEL" SS_DELAY(100)
            SS_TAP(X_ENTER) SS_DELAY(1000) SS_DELAY(100)
            SS_LALT("f") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            SS_TAP(X_ENTER) SS_DELAY(100)
            SS_DELAY(3500) SS_DELAY(100)
            SS_LCTL("v") SS_DELAY(100)
            //Sending orders SS_DELAY(100)
            SS_LALT("s") SS_DELAY(100)
            SS_DELAY(2000) SS_DELAY(100)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(100)
            SS_DELAY(7000) SS_DELAY(100)
            //Excel file management SS_DELAY(100)
            SS_LGUI("1") SS_DELAY(100)
            SS_TAP(X_RGHT) SS_DELAY(100)
            "DM 02" SS_DELAY(100)
            SS_DELAY(100) SS_DELAY(100)
            SS_LCTL(SS_TAP(X_LEFT)) SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100) SS_DELAY(100)
            SS_LSFT(SS_TAP(X_SPC)) SS_DELAY(100)
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100) SS_DELAY(100)
            SS_TAP(X_DOWN) SS_DELAY(100)
             SS_DELAY(100)
             SS_DELAY(100)

             SS_DELAY(2000)//Open orders only encounter SS_DELAY(100)
            SS_LCTL("c") SS_DELAY(100)
            SS_LGUI("2") SS_DELAY(500) SS_DELAY(100)
            SS_LCTL("5") SS_DELAY(100)
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_DELAY(100)
            SS_LCTL("v") SS_DELAY(100)
            SS_LALT("fs") SS_DELAY(100)
            SS_DELAY(10000) SS_DELAY(100)
            //Get date of lab test from excel SS_DELAY(100)
            SS_LGUI("1") SS_DELAY(100)
            SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100)
            SS_LCTL("c") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            //Inputting orders SS_DELAY(100)
            SS_LGUI("2") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            SS_LCTL("o") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            "DIABETES MONITORING PANEL" SS_DELAY(100)
            SS_TAP(X_ENTER) SS_DELAY(1000) SS_DELAY(100)
            SS_LALT("f") SS_DELAY(100)
            SS_DELAY(1000) SS_DELAY(100)
            SS_TAP(X_ENTER) SS_DELAY(100)
            SS_DELAY(3500) SS_DELAY(100)
            SS_LCTL("v") SS_DELAY(100)
            //Sending orders SS_DELAY(100)
            SS_LALT("s") SS_DELAY(100)
            SS_DELAY(2000) SS_DELAY(100)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(100)
            SS_DELAY(7000) SS_DELAY(100)
            //Excel file management SS_DELAY(100)
            SS_LGUI("1") SS_DELAY(100)
            SS_TAP(X_RGHT) SS_DELAY(100)
            "DM 03 - loop end" SS_DELAY(100)
            SS_DELAY(100) SS_DELAY(100)
            SS_LCTL(SS_TAP(X_LEFT)) SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100) SS_DELAY(100)
            SS_LSFT(SS_TAP(X_SPC)) SS_DELAY(100)
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100) SS_DELAY(100)
            SS_TAP(X_DOWN) SS_DELAY(100)
             SS_DELAY(100)
             SS_DELAY(100)

             SS_DELAY(2000)//#dl_section

	    // #SAVE
            SS_LCTL("s")
            SS_DELAY(5000)

            );
          }
          break;
/*=================================================================================*/
        case LINE:
          if (record->event.pressed)
          {
            SEND_STRING(
            SS_LCTL(SS_TAP(X_LEFT)) SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100)
            SS_LSFT(SS_TAP(X_SPC))
            //highlight row
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100)
            //move down cell to next row
            SS_TAP(X_DOWN)




            );
          }
          break;

        case CSN_OPEN:
          if (record->event.pressed)
          {
            SEND_STRING(
            //to always get to excel
            SS_LGUI("m") SS_DELAY(100)
            SS_LGUI("1") SS_DELAY(100)
            SS_TAP(X_ESC) SS_DELAY(100)
            SS_LCTL(SS_TAP(X_LEFT))
            SS_DELAY(100)
            SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100)

            SS_LCTL("c") SS_DELAY(100)
            SS_LGUI("2") SS_DELAY(100)
            SS_LCTL("w") SS_DELAY(3000)
            SS_LCTL("1") SS_DELAY(100)
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_DELAY(100)
            SS_LCTL("v") SS_DELAY(100)
            SS_LALT("fs") SS_DELAY(100)
            SS_DELAY(10000) SS_DELAY(100)

            );
          }
          break;

      }
    return true;
};
