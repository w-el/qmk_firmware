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
  HTN,
  LINE,
  DM,
  DM_SINGLE,
  CSN_OPEN,
  CHECK,
  INR,
  HEP_CAR,
  HEP_DIAG,
  HEP_SCR,
  NAK,
  HTN_SINGLE,
  TFT,
  TEST

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_numpad_6x4(
        MO(_FN1), KC_ESC,  KC_BSPC,   KC_TAB,
        _______,  _______, KC_PAST,   KC_PMNS,
        HTN_SINGLE, HTN,   KC_P9,
        DM_SINGLE, DM,     KC_P6,     KC_PPLS,
        CSN_OPEN, LINE,    KC_P3,
        KC_P0,             TEST,   KC_PENT),

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
        case NAK:
          if (record->event.pressed)
          {
            SEND_STRING(
            //set win 1 as excel window and win 2 as the epic window
            //In excel: highlight cell of patient UID
            SS_LCTL("c") SS_DELAY(100) SS_LGUI("m") SS_DELAY(100)
            //Switch to epic and open orders only enounter
            SS_LGUI("2") SS_DELAY(100) SS_LCTL("w") SS_DELAY(4000) SS_LCTL("5")
            //Fill in the details for orders only encounter
            //this next line is  tabbing to the CSN x10¸
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) //Clinic
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
            //SS_LSFT(SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)) //Corp laptop

            // Pasting in the CSN and then opening the orders only encounter
            SS_DELAY(1000) SS_LCTL("v") SS_DELAY(1000) SS_LALT("fs") SS_DELAY(1500)
            //switching back to excel to copy the date
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("1") SS_DELAY(100) SS_TAP(X_ESC) SS_DELAY(100) SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100) SS_LCTL("c")
            //Delay excel -> epic opening orders field
            SS_DELAY(4000)
            //switch back to epic and open up orders
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("2") SS_DELAY(1000) SS_LCTL("o") SS_DELAY(1000)

             //at order specific section
            "nak" SS_DELAY(200) SS_TAP(X_ENTER) SS_DELAY(2000) SS_LALT("a") SS_DELAY(3500)
            SS_LCTL("v") SS_DELAY(200) //paste back the date for sodium
            SS_LALT("n") SS_DELAY(2500)
            SS_LCTL("v") SS_DELAY(200) //paste back the date for potassium
            SS_DELAY(2000)

            //sending order
            SS_LALT("s") SS_DELAY(1000)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(3000)

            //MOVING BACK TO EXCEL AND SORTING THE FILE
            //switch to excel
            SS_LGUI("m") SS_LGUI("2") SS_DELAY(1000) SS_LGUI("1") SS_DELAY(1000) SS_TAP(X_ESC) SS_DELAY(100)
            //add comment of what lab it is
            SS_TAP(X_RGHT) "NA, K panel"
            //shift cursor back to left most cell
            SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100)
            // //select row
            SS_LSFT(SS_TAP(X_SPC))
            //highlight row
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100)
            //move down cell to next row
            SS_TAP(X_DOWN)
            //save the file
            SS_LCTL("s")
            SS_DELAY(1000)



            );
          }
          break;
        case HEP_SCR:
          if (record->event.pressed)
          {
            SEND_STRING(
            //set win 1 as excel window and win 2 as the epic window
            //In excel: highlight cell of patient UID
            SS_LCTL("c") SS_DELAY(100) SS_LGUI("m") SS_DELAY(100)
            //Switch to epic and open orders only enounter
            SS_LGUI("2") SS_DELAY(100) SS_LCTL("w") SS_DELAY(4000) SS_LCTL("5")
            //Fill in the details for orders only encounter
            //this next line is  tabbing to the CSN x10¸
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) //Clinic
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
            //SS_LSFT(SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)) //Corp laptop

            // Pasting in the CSN and then opening the orders only encounter
            SS_DELAY(1000) SS_LCTL("v") SS_DELAY(1000) SS_LALT("fs") SS_DELAY(1500)
            //switching back to excel to copy the date
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("1") SS_DELAY(100) SS_TAP(X_ESC) SS_DELAY(100) SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100) SS_LCTL("c")
            //Delay excel -> epic opening orders field
            SS_DELAY(4000)
            //switch back to epic and open up orders
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("2") SS_DELAY(1000) SS_LCTL("o") SS_DELAY(1000)

            //at order specific section
            "hepatitis b panel" SS_DELAY(200) SS_TAP(X_ENTER) SS_DELAY(2000)
            SS_LALT("f") SS_DELAY(2000) SS_TAP(X_ENTER) SS_DELAY(3500)
            SS_LCTL("v") SS_DELAY(200) //paste back the date for LFTs
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
            SS_TAP(X_ENTER) //already on the "screening" button so just hit enter
            SS_DELAY(2000)

            //sending order
            SS_LALT("s") SS_DELAY(1000)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(3000)

            //MOVING BACK TO EXCEL AND SORTING THE FILE
            //switch to excel
            SS_LGUI("m") SS_LGUI("2") SS_DELAY(1000) SS_LGUI("1") SS_DELAY(1000) SS_TAP(X_ESC) SS_DELAY(100)
            //add comment of what lab it is
            SS_TAP(X_RGHT) "Hep B screening panel"
            //shift cursor back to left most cell
            SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100)
            // //select row
            SS_LSFT(SS_TAP(X_SPC))
            //highlight row
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100)
            //move down cell to next row
            SS_TAP(X_DOWN)
            //save the file
            SS_LCTL("s")



            );
          }
          break;
        case HEP_DIAG:
          if (record->event.pressed)
          {
            SEND_STRING(
            //set win 1 as excel window and win 2 as the epic window
            //In excel: highlight cell of patient UID
            SS_LCTL("c") SS_DELAY(100) SS_LGUI("m") SS_DELAY(100)
            //Switch to epic and open orders only enounter
            SS_LGUI("2") SS_DELAY(100) SS_LCTL("w") SS_DELAY(4000) SS_LCTL("5")
            //Fill in the details for orders only encounter
            //this next line is  tabbing to the CSN x10¸
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) //Clinic
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
            //SS_LSFT(SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)) //Corp laptop

            // Pasting in the CSN and then opening the orders only encounter
            SS_DELAY(1000) SS_LCTL("v") SS_DELAY(1000) SS_LALT("fs") SS_DELAY(1500)
            //switching back to excel to copy the date
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("1") SS_DELAY(100) SS_TAP(X_ESC) SS_DELAY(100) SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100) SS_LCTL("c")
            //Delay excel -> epic opening orders field
            SS_DELAY(4000)
            //switch back to epic and open up orders
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("2") SS_DELAY(1000) SS_LCTL("o") SS_DELAY(1000)

            //at order specific section
            "hepatitis b panel" SS_DELAY(200) SS_TAP(X_ENTER) SS_DELAY(2000)
            SS_LALT("f") SS_DELAY(2000) SS_TAP(X_ENTER) SS_DELAY(3500)
            SS_LCTL("v") SS_DELAY(200) //paste back the date for LFTs
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
            SS_TAP(X_RGHT) SS_TAP(X_ENTER) //tap right to go to diagnostic
            SS_DELAY(2000)

            //sending order
            SS_LALT("s") SS_DELAY(1000)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(3000)

            //MOVING BACK TO EXCEL AND SORTING THE FILE
            //switch to excel
            SS_LGUI("m") SS_LGUI("2") SS_DELAY(1000) SS_LGUI("1") SS_DELAY(1000) SS_TAP(X_ESC) SS_DELAY(100)
            //add comment of what lab it is
            SS_TAP(X_RGHT) "Hep B diagnostic panel"
            //shift cursor back to left most cell
            SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100)
            // //select row
            SS_LSFT(SS_TAP(X_SPC))
            //highlight row
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100)
            //move down cell to next row
            SS_TAP(X_DOWN)
            //save the file
            SS_LCTL("s")



            );
          }
          break;
        case HEP_CAR:
          if (record->event.pressed)
          {
            SEND_STRING(
            //set win 1 as excel window and win 2 as the epic window
            //In excel: highlight cell of patient UID
            SS_LCTL("c") SS_DELAY(100) SS_LGUI("m") SS_DELAY(100)
            //Switch to epic and open orders only enounter
            SS_LGUI("2") SS_DELAY(100) SS_LCTL("w") SS_DELAY(4000) SS_LCTL("5")
            //Fill in the details for orders only encounter
            //this next line is  tabbing to the CSN x10¸
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) //Clinic
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
            //SS_LSFT(SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)) //Corp laptop

            // Pasting in the CSN and then opening the orders only encounter
            SS_DELAY(1000) SS_LCTL("v") SS_DELAY(1000) SS_LALT("fs") SS_DELAY(1500)
            //switching back to excel to copy the date
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("1") SS_DELAY(100) SS_TAP(X_ESC) SS_DELAY(100) SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100) SS_LCTL("c")
            //Delay excel -> epic opening orders field
            SS_DELAY(4000)
            //switch back to epic and open up orders
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("2") SS_DELAY(1000) SS_LCTL("o") SS_DELAY(1000)

            //at order specific section
            "hepatitis b carrier panel" SS_DELAY(200) SS_TAP(X_ENTER) SS_DELAY(2000)
            SS_LALT("f") SS_DELAY(2000) SS_TAP(X_ENTER) SS_DELAY(3500)
            SS_LCTL("v") SS_DELAY(200) //paste back the date for LFTs
            SS_LALT("s") SS_DELAY(2500)
            SS_LCTL("v") SS_DELAY(200) //paste back the date for AFP
            SS_DELAY(2000)

            //sending order
            SS_LALT("s") SS_DELAY(1000)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(3000)

            //MOVING BACK TO EXCEL AND SORTING THE FILE
            //switch to excel
            SS_LGUI("m") SS_LGUI("2") SS_DELAY(1000) SS_LGUI("1") SS_DELAY(1000) SS_TAP(X_ESC) SS_DELAY(100)
            //add comment of what lab it is
            SS_TAP(X_RGHT) "Hep B Carrier panel"
            //shift cursor back to left most cell
            SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100)
            // //select row
            SS_LSFT(SS_TAP(X_SPC))
            //highlight row
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100)
            //move down cell to next row
            SS_TAP(X_DOWN)
            //save the file
            SS_LCTL("s")
            SS_DELAY(1000)



            );
          }
          break;
        case INR:
          if (record->event.pressed)
          {
            SEND_STRING(
            //set win 1 as excel window and win 2 as the epic window
            //In excel: highlight cell of patient UID
            SS_LCTL("c") SS_DELAY(100) SS_LGUI("m") SS_DELAY(100)
            //Switch to epic and open orders only enounter
            SS_LGUI("2") SS_DELAY(100) SS_LCTL("w") SS_DELAY(4000) SS_LCTL("5")
            //Fill in the details for orders only encounter
            //this next line is  tabbing to the CSN x10¸
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) //Clinic
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
            //SS_LSFT(SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)) //Corp laptop

            // Pasting in the CSN and then opening the orders only encounter
            SS_DELAY(1000) SS_LCTL("v") SS_DELAY(1000) SS_LALT("fs") SS_DELAY(1500)
            //switching back to excel to copy the date
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("1") SS_DELAY(100) SS_TAP(X_ESC) SS_DELAY(100) SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100) SS_LCTL("c")
            //Delay excel -> epic opening orders field
            SS_DELAY(4000)
            //switch back to epic and open up orders
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("2") SS_DELAY(1000) SS_LCTL("o") SS_DELAY(1000)

            //at order specific section
            "INR POCT" SS_DELAY(200) SS_TAP(X_ENTER) SS_DELAY(2000)
            SS_LALT("f") SS_DELAY(2000) SS_TAP(X_ENTER) SS_DELAY(4000)
            SS_LCTL("v") SS_DELAY(200) //paste back the date
            SS_TAP(X_TAB) "on" //for "on arrival"
            SS_DELAY(2000)

            //sending order
            SS_LALT("s") SS_DELAY(1000)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(3000)

            //MOVING BACK TO EXCEL AND SORTING THE FILE
            //switch to excel
            SS_LGUI("m") SS_LGUI("2") SS_DELAY(1000) SS_LGUI("1") SS_DELAY(1000) SS_TAP(X_ESC) SS_DELAY(100)
            //add comment of what lab it is
            SS_TAP(X_RGHT) "INR OA"
            //shift cursor back to left most cell
            SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100)
            // //select row
            SS_LSFT(SS_TAP(X_SPC))
            //highlight row
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100)
            //move down cell to next row
            SS_TAP(X_DOWN)
            //save the file
            SS_LCTL("s")

            );
          }
          break;


        case HTN_SINGLE:
          if (record->event.pressed)
          {
            SEND_STRING(
            //set win 1 as excel window and win 2 as the epic window
            //In excel: highlight cell of patient UID
            SS_LCTL("c") SS_DELAY(100) SS_LGUI("m") SS_DELAY(100)
            //Switch to epic and open orders only enounter
            SS_LGUI("2") SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LCTL("w") SS_DELAY(4000) SS_LCTL("5")
            //Fill in the details for orders only encounter
            //this next line is  tabbing to the CSN x10¸
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) //Clinic
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
            //SS_LSFT(SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)) //Corp laptop

            // Pasting in the CSN and then opening the orders only encounter
            SS_DELAY(1000) SS_LCTL("v") SS_DELAY(1000) SS_LALT("fs") SS_DELAY(1500)
            //switching back to excel to copy the date
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("1") SS_DELAY(100) SS_TAP(X_ESC) SS_DELAY(100) SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100) SS_LCTL("c")
            //Delay excel -> epic opening orders field
            SS_DELAY(4000)
            //switch back to epic and open up orders
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("2") SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(1000) SS_LCTL("o") SS_DELAY(1000)

            //at order specific section
            "hypertensive panel" SS_DELAY(200) SS_TAP(X_ENTER) SS_DELAY(2000)
            SS_LALT("f") SS_DELAY(2000) SS_TAP(X_ENTER) SS_DELAY(4000)
            SS_LCTL("v") //paste back the date
            SS_DELAY(2000)

            //sending order
            SS_LALT("s") SS_DELAY(1000)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(3000)

            //MOVING BACK TO EXCEL AND SORTING THE FILE
            //switch to excel
            SS_LGUI("m") SS_LGUI("2") SS_DELAY(1000) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))
            SS_DELAY(1000) SS_LGUI("1") SS_DELAY(1000) SS_TAP(X_ESC) SS_DELAY(100)
            //add comment of what lab it is
            SS_TAP(X_RGHT) "HTN panel"
            //shift cursor back to left most cell
            SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100)
            // //select row
            SS_LSFT(SS_TAP(X_SPC))
            //highlight row
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100)
            //move down cell to next row
            SS_TAP(X_DOWN)
            //save the file
            SS_LCTL("s")
            SS_DELAY(1000)



            );
          }
          break;


        case HTN:
          if (record->event.pressed)
          {
            SEND_STRING(
            //set win 1 as excel window and win 2 as the epic window
            //In excel: highlight cell of patient UID
            SS_LCTL("c") SS_DELAY(100) SS_LGUI("m") SS_DELAY(100)
            //Switch to epic and open orders only enounter
            SS_LGUI("2") SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LCTL("w") SS_DELAY(1000) SS_LCTL("5")
            //Fill in the details for orders only encounter
            //this next line is  tabbing to the CSN x10¸
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) //Clinic
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
            //SS_LSFT(SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)) //Corp laptop

            // Pasting in the CSN and then opening the orders only encounter
            SS_DELAY(1000) SS_LCTL("v") SS_DELAY(1000) SS_LALT("fs") SS_DELAY(3000)
            //switching back to excel to copy the date
            SS_LGUI("1") SS_DELAY(100) SS_TAP(X_ESC) SS_DELAY(100) SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100) SS_LCTL("c") SS_DELAY(100)
            //Delay excel -> epic opening orders field
            SS_DELAY(6000)
            //switch back to epic and open up
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("2") SS_DELAY(100)
            SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100)
            SS_LGUI(SS_TAP(X_UP))SS_DELAY(1000)
            SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100)
            SS_LCTL("o") SS_DELAY(100)

            //at order specific section
            "hypertensive panel" SS_DELAY(200) SS_TAP(X_ENTER) SS_DELAY(2000)
            SS_LALT("f") SS_DELAY(1000) SS_TAP(X_ENTER) SS_DELAY(3500)
            SS_LCTL("v") //paste back the date
            SS_DELAY(2000)

            //sending order
            SS_LALT("s") SS_DELAY(2000)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(2000)

            //MOVING BACK TO EXCEL AND SORTING THE FILE
            //switch to excel
            // SS_LGUI("m") SS_LGUI("2") SS_DELAY(1000) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))
            // SS_DELAY(1000)
            SS_LGUI("1") SS_DELAY(1000) SS_TAP(X_ESC) SS_DELAY(100)
            //add comment of what lab it is
            SS_TAP(X_RGHT) "HTN 01 - loop start"
            //shift cursor back to left most cell
            SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100)
            // //select row
            SS_LSFT(SS_TAP(X_SPC))
            //highlight row
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100)
            //move down cell to next row
            SS_TAP(X_DOWN)
            //save the file
            // SS_LCTL("s")
            SS_DELAY(2000)

 //set win 1 as excel window and win 2 as the epic window
            //In excel: highlight cell of patient UID
            SS_LCTL("c") SS_DELAY(100) SS_LGUI("m") SS_DELAY(100)
            //Switch to epic and open orders only enounter
            SS_LGUI("2") SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LCTL("w") SS_DELAY(1000) SS_LCTL("5")
            //Fill in the details for orders only encounter
            //this next line is  tabbing to the CSN x10¸
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) //Clinic
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
            //SS_LSFT(SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)) //Corp laptop

            // Pasting in the CSN and then opening the orders only encounter
            SS_DELAY(1000) SS_LCTL("v") SS_DELAY(1000) SS_LALT("fs") SS_DELAY(3000)
            //switching back to excel to copy the date
            SS_LGUI("1") SS_DELAY(100) SS_TAP(X_ESC) SS_DELAY(100) SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100) SS_LCTL("c") SS_DELAY(100)
            //Delay excel -> epic opening orders field
            SS_DELAY(6000)
            //switch back to epic and open up
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("2") SS_DELAY(100)
            SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100)
            SS_LGUI(SS_TAP(X_UP))SS_DELAY(1000)
            SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100)
            SS_LCTL("o") SS_DELAY(100)

            //at order specific section
            "hypertensive panel" SS_DELAY(200) SS_TAP(X_ENTER) SS_DELAY(2000)
            SS_LALT("f") SS_DELAY(1000) SS_TAP(X_ENTER) SS_DELAY(3500)
            SS_LCTL("v") //paste back the date
            SS_DELAY(2000)

            //sending order
            SS_LALT("s") SS_DELAY(2000)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(2000)

            //MOVING BACK TO EXCEL AND SORTING THE FILE
            //switch to excel
            // SS_LGUI("m") SS_LGUI("2") SS_DELAY(1000) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))
            // SS_DELAY(1000)
            SS_LGUI("1") SS_DELAY(1000) SS_TAP(X_ESC) SS_DELAY(100)
            //add comment of what lab it is
            SS_TAP(X_RGHT) "HTN 02"
            //shift cursor back to left most cell
            SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100)
            // //select row
            SS_LSFT(SS_TAP(X_SPC))
            //highlight row
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100)
            //move down cell to next row
            SS_TAP(X_DOWN)
            //save the file
            // SS_LCTL("s")
            SS_DELAY(2000)

 //set win 1 as excel window and win 2 as the epic window
            //In excel: highlight cell of patient UID
            SS_LCTL("c") SS_DELAY(100) SS_LGUI("m") SS_DELAY(100)
            //Switch to epic and open orders only enounter
            SS_LGUI("2") SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LCTL("w") SS_DELAY(1000) SS_LCTL("5")
            //Fill in the details for orders only encounter
            //this next line is  tabbing to the CSN x10¸
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) //Clinic
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
            //SS_LSFT(SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)) //Corp laptop

            // Pasting in the CSN and then opening the orders only encounter
            SS_DELAY(1000) SS_LCTL("v") SS_DELAY(1000) SS_LALT("fs") SS_DELAY(3000)
            //switching back to excel to copy the date
            SS_LGUI("1") SS_DELAY(100) SS_TAP(X_ESC) SS_DELAY(100) SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100) SS_LCTL("c") SS_DELAY(100)
            //Delay excel -> epic opening orders field
            SS_DELAY(6000)
            //switch back to epic and open up
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("2") SS_DELAY(100)
            SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100)
            SS_LGUI(SS_TAP(X_UP))SS_DELAY(1000)
            SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100)
            SS_LCTL("o") SS_DELAY(100)

            //at order specific section
            "hypertensive panel" SS_DELAY(200) SS_TAP(X_ENTER) SS_DELAY(2000)
            SS_LALT("f") SS_DELAY(1000) SS_TAP(X_ENTER) SS_DELAY(3500)
            SS_LCTL("v") //paste back the date
            SS_DELAY(2000)

            //sending order
            SS_LALT("s") SS_DELAY(2000)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(2000)

            //MOVING BACK TO EXCEL AND SORTING THE FILE
            //switch to excel
            // SS_LGUI("m") SS_LGUI("2") SS_DELAY(1000) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))
            // SS_DELAY(1000)
            SS_LGUI("1") SS_DELAY(1000) SS_TAP(X_ESC) SS_DELAY(100)
            //add comment of what lab it is
            SS_TAP(X_RGHT) "HTN 03"
            //shift cursor back to left most cell
            SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100)
            // //select row
            SS_LSFT(SS_TAP(X_SPC))
            //highlight row
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100)
            //move down cell to next row
            SS_TAP(X_DOWN)
            //save the file
            // SS_LCTL("s")
            SS_DELAY(2000)

 //set win 1 as excel window and win 2 as the epic window
            //In excel: highlight cell of patient UID
            SS_LCTL("c") SS_DELAY(100) SS_LGUI("m") SS_DELAY(100)
            //Switch to epic and open orders only enounter
            SS_LGUI("2") SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LCTL("w") SS_DELAY(1000) SS_LCTL("5")
            //Fill in the details for orders only encounter
            //this next line is  tabbing to the CSN x10¸
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) //Clinic
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
            //SS_LSFT(SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)) //Corp laptop

            // Pasting in the CSN and then opening the orders only encounter
            SS_DELAY(1000) SS_LCTL("v") SS_DELAY(1000) SS_LALT("fs") SS_DELAY(3000)
            //switching back to excel to copy the date
            SS_LGUI("1") SS_DELAY(100) SS_TAP(X_ESC) SS_DELAY(100) SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100) SS_LCTL("c") SS_DELAY(100)
            //Delay excel -> epic opening orders field
            SS_DELAY(6000)
            //switch back to epic and open up
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("2") SS_DELAY(100)
            SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100)
            SS_LGUI(SS_TAP(X_UP))SS_DELAY(1000)
            SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100)
            SS_LCTL("o") SS_DELAY(100)

            //at order specific section
            "hypertensive panel" SS_DELAY(200) SS_TAP(X_ENTER) SS_DELAY(2000)
            SS_LALT("f") SS_DELAY(1000) SS_TAP(X_ENTER) SS_DELAY(3500)
            SS_LCTL("v") //paste back the date
            SS_DELAY(2000)

            //sending order
            SS_LALT("s") SS_DELAY(2000)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(2000)

            //MOVING BACK TO EXCEL AND SORTING THE FILE
            //switch to excel
            // SS_LGUI("m") SS_LGUI("2") SS_DELAY(1000) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))
            // SS_DELAY(1000)
            SS_LGUI("1") SS_DELAY(1000) SS_TAP(X_ESC) SS_DELAY(100)
            //add comment of what lab it is
            SS_TAP(X_RGHT) "HTN 04"
            //shift cursor back to left most cell
            SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100)
            // //select row
            SS_LSFT(SS_TAP(X_SPC))
            //highlight row
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100)
            //move down cell to next row
            SS_TAP(X_DOWN)
            //save the file
            // SS_LCTL("s")
            SS_DELAY(2000)

 //set win 1 as excel window and win 2 as the epic window
            //In excel: highlight cell of patient UID
            SS_LCTL("c") SS_DELAY(100) SS_LGUI("m") SS_DELAY(100)
            //Switch to epic and open orders only enounter
            SS_LGUI("2") SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LCTL("w") SS_DELAY(1000) SS_LCTL("5")
            //Fill in the details for orders only encounter
            //this next line is  tabbing to the CSN x10¸
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) //Clinic
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
            //SS_LSFT(SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)) //Corp laptop

            // Pasting in the CSN and then opening the orders only encounter
            SS_DELAY(1000) SS_LCTL("v") SS_DELAY(1000) SS_LALT("fs") SS_DELAY(3000)
            //switching back to excel to copy the date
            SS_LGUI("1") SS_DELAY(100) SS_TAP(X_ESC) SS_DELAY(100) SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100) SS_LCTL("c") SS_DELAY(100)
            //Delay excel -> epic opening orders field
            SS_DELAY(6000)
            //switch back to epic and open up
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("2") SS_DELAY(100)
            SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100)
            SS_LGUI(SS_TAP(X_UP))SS_DELAY(1000)
            SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100)
            SS_LCTL("o") SS_DELAY(100)

            //at order specific section
            "hypertensive panel" SS_DELAY(200) SS_TAP(X_ENTER) SS_DELAY(2000)
            SS_LALT("f") SS_DELAY(1000) SS_TAP(X_ENTER) SS_DELAY(3500)
            SS_LCTL("v") //paste back the date
            SS_DELAY(2000)

            //sending order
            SS_LALT("s") SS_DELAY(2000)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(2000)

            //MOVING BACK TO EXCEL AND SORTING THE FILE
            //switch to excel
            // SS_LGUI("m") SS_LGUI("2") SS_DELAY(1000) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))
            // SS_DELAY(1000)
            SS_LGUI("1") SS_DELAY(1000) SS_TAP(X_ESC) SS_DELAY(100)
            //add comment of what lab it is
            SS_TAP(X_RGHT) "HTN 05 - loop end"
            //shift cursor back to left most cell
            SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100)
            // //select row
            SS_LSFT(SS_TAP(X_SPC))
            //highlight row
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100)
            //move down cell to next row
            SS_TAP(X_DOWN)

            SS_DELAY(100) SS_LCTL("s")


            );
          }
          break;
        case DM_SINGLE:
          if (record->event.pressed)
          {
            SEND_STRING(
            //set win 1 as excel window and win 2 as the epic window
            //In excel: highlight cell of patient UID
            SS_LCTL("c") SS_DELAY(100) SS_LGUI("m") SS_DELAY(100)
            //Switch to epic and open orders only enounter
            SS_LGUI("2") SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LCTL("w") SS_DELAY(4000) SS_LCTL("5")
            //Fill in the details for orders only encounter
            //this next line is  tabbing to the CSN x10¸
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) //Clinic
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
            //SS_LSFT(SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)) //Corp laptop

            // Pasting in the CSN and then opening the orders only encounter
            SS_DELAY(1000) SS_LCTL("v") SS_DELAY(1000) SS_LALT("fs") SS_DELAY(1500)
            //switching back to excel to copy the date
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("1") SS_DELAY(100) SS_TAP(X_ESC) SS_DELAY(100) SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100) SS_LCTL("c")
            //Delay excel -> epic opening orders field
            SS_DELAY(4000)
            //switch back to epic and open up orders
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("2") SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(1000) SS_LCTL("o") SS_DELAY(1000)

            //at order specific section
            "diabetes monitoring panel" SS_DELAY(200) SS_TAP(X_ENTER) SS_DELAY(2000)
            SS_LALT("f") SS_DELAY(2000) SS_TAP(X_ENTER) SS_DELAY(4000)
            SS_LCTL("v") //paste back the date
            SS_DELAY(2000)

            //sending order
            SS_LALT("s") SS_DELAY(1000)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(3000)

            //MOVING BACK TO EXCEL AND SORTING THE FILE
            //switch to excel
            SS_LGUI("m") SS_LGUI("2") SS_DELAY(1000) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))
            SS_DELAY(1000) SS_LGUI("1") SS_DELAY(1000) SS_TAP(X_ESC) SS_DELAY(100)
            //add comment of what lab it is
            SS_TAP(X_RGHT) "DM"
            //shift cursor back to left most cell
            SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100)
            // //select row
            SS_LSFT(SS_TAP(X_SPC))
            //highlight row
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100)
            //move down cell to next row
            SS_TAP(X_DOWN)
            //save the file
            SS_LCTL("s")
            SS_DELAY(1000)



            );
          }
          break;


        case DM:
          if (record->event.pressed)
          {
            SEND_STRING(
             //set win 1 as excel window and win 2 as the epic window
            //In excel: highlight cell of patient UID
            SS_LCTL("c") SS_DELAY(100) SS_LGUI("m") SS_DELAY(100)
            //Switch to epic and open orders only enounter
            SS_LGUI("2") SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LCTL("w") SS_DELAY(1000) SS_LCTL("5")
            //Fill in the details for orders only encounter
            //this next line is  tabbing to the CSN x10¸
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) //Clinic
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
            //SS_LSFT(SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)) //Corp laptop

            // Pasting in the CSN and then opening the orders only encounter
            SS_DELAY(1000) SS_LCTL("v") SS_DELAY(1000) SS_LALT("fs") SS_DELAY(3000)
            //switching back to excel to copy the date
            SS_LGUI("1") SS_DELAY(100) SS_TAP(X_ESC) SS_DELAY(100) SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100) SS_LCTL("c") SS_DELAY(100)
            //Delay excel -> epic opening orders field
            SS_DELAY(6000)
            //switch back to epic and open up
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("2") SS_DELAY(100)
            SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100)
            SS_LGUI(SS_TAP(X_UP))SS_DELAY(1000)
            SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100)
            SS_LCTL("o") SS_DELAY(100)

            //at order specific section
            "diabetes monitoring panel" SS_DELAY(200) SS_TAP(X_ENTER) SS_DELAY(2000)
            SS_LALT("f") SS_DELAY(1000) SS_TAP(X_ENTER) SS_DELAY(3500)
            SS_LCTL("v") //paste back the date
            SS_DELAY(2000)

            //sending order
            SS_LALT("s") SS_DELAY(2000)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(2000)

            //MOVING BACK TO EXCEL AND SORTING THE FILE
            //switch to excel
            // SS_LGUI("m") SS_LGUI("2") SS_DELAY(1000) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))
            // SS_DELAY(1000)
            SS_LGUI("1") SS_DELAY(1000) SS_TAP(X_ESC) SS_DELAY(100)
            //add comment of what lab it is
            SS_TAP(X_RGHT) "DM 01 - loop start"
            //shift cursor back to left most cell
            SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100)
            // //select row
            SS_LSFT(SS_TAP(X_SPC))
            //highlight row
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100)
            //move down cell to next row
            SS_TAP(X_DOWN)
            //save the file
            // SS_LCTL("s")
            SS_DELAY(2000)

 //set win 1 as excel window and win 2 as the epic window
            //In excel: highlight cell of patient UID
            SS_LCTL("c") SS_DELAY(100) SS_LGUI("m") SS_DELAY(100)
            //Switch to epic and open orders only enounter
            SS_LGUI("2") SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LCTL("w") SS_DELAY(1000) SS_LCTL("5")
            //Fill in the details for orders only encounter
            //this next line is  tabbing to the CSN x10¸
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) //Clinic
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
            //SS_LSFT(SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)) //Corp laptop

            // Pasting in the CSN and then opening the orders only encounter
            SS_DELAY(1000) SS_LCTL("v") SS_DELAY(1000) SS_LALT("fs") SS_DELAY(3000)
            //switching back to excel to copy the date
            SS_LGUI("1") SS_DELAY(100) SS_TAP(X_ESC) SS_DELAY(100) SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100) SS_LCTL("c") SS_DELAY(100)
            //Delay excel -> epic opening orders field
            SS_DELAY(6000)
            //switch back to epic and open up
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("2") SS_DELAY(100)
            SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100)
            SS_LGUI(SS_TAP(X_UP))SS_DELAY(1000)
            SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100)
            SS_LCTL("o") SS_DELAY(100)

            //at order specific section
            "diabetes monitoring panel" SS_DELAY(200) SS_TAP(X_ENTER) SS_DELAY(2000)
            SS_LALT("f") SS_DELAY(1000) SS_TAP(X_ENTER) SS_DELAY(3500)
            SS_LCTL("v") //paste back the date
            SS_DELAY(2000)

            //sending order
            SS_LALT("s") SS_DELAY(2000)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(2000)

            //MOVING BACK TO EXCEL AND SORTING THE FILE
            //switch to excel
            // SS_LGUI("m") SS_LGUI("2") SS_DELAY(1000) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))
            // SS_DELAY(1000)
            SS_LGUI("1") SS_DELAY(1000) SS_TAP(X_ESC) SS_DELAY(100)
            //add comment of what lab it is
            SS_TAP(X_RGHT) "DM 02"
            //shift cursor back to left most cell
            SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100)
            // //select row
            SS_LSFT(SS_TAP(X_SPC))
            //highlight row
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100)
            //move down cell to next row
            SS_TAP(X_DOWN)
            //save the file
            // SS_LCTL("s")
            SS_DELAY(2000)

 //set win 1 as excel window and win 2 as the epic window
            //In excel: highlight cell of patient UID
            SS_LCTL("c") SS_DELAY(100) SS_LGUI("m") SS_DELAY(100)
            //Switch to epic and open orders only enounter
            SS_LGUI("2") SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LCTL("w") SS_DELAY(1000) SS_LCTL("5")
            //Fill in the details for orders only encounter
            //this next line is  tabbing to the CSN x10¸
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) //Clinic
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
            //SS_LSFT(SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)) //Corp laptop

            // Pasting in the CSN and then opening the orders only encounter
            SS_DELAY(1000) SS_LCTL("v") SS_DELAY(1000) SS_LALT("fs") SS_DELAY(3000)
            //switching back to excel to copy the date
            SS_LGUI("1") SS_DELAY(100) SS_TAP(X_ESC) SS_DELAY(100) SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100) SS_LCTL("c") SS_DELAY(100)
            //Delay excel -> epic opening orders field
            SS_DELAY(6000)
            //switch back to epic and open up
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("2") SS_DELAY(100)
            SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100)
            SS_LGUI(SS_TAP(X_UP))SS_DELAY(1000)
            SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100)
            SS_LCTL("o") SS_DELAY(100)

            //at order specific section
            "diabetes monitoring panel" SS_DELAY(200) SS_TAP(X_ENTER) SS_DELAY(2000)
            SS_LALT("f") SS_DELAY(1000) SS_TAP(X_ENTER) SS_DELAY(3500)
            SS_LCTL("v") //paste back the date
            SS_DELAY(2000)

            //sending order
            SS_LALT("s") SS_DELAY(2000)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(2000)

            //MOVING BACK TO EXCEL AND SORTING THE FILE
            //switch to excel
            // SS_LGUI("m") SS_LGUI("2") SS_DELAY(1000) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))
            // SS_DELAY(1000)
            SS_LGUI("1") SS_DELAY(1000) SS_TAP(X_ESC) SS_DELAY(100)
            //add comment of what lab it is
            SS_TAP(X_RGHT) "DM 03"
            //shift cursor back to left most cell
            SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100)
            // //select row
            SS_LSFT(SS_TAP(X_SPC))
            //highlight row
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100)
            //move down cell to next row
            SS_TAP(X_DOWN)
            //save the file
            // SS_LCTL("s")
            SS_DELAY(2000)

 //set win 1 as excel window and win 2 as the epic window
            //In excel: highlight cell of patient UID
            SS_LCTL("c") SS_DELAY(100) SS_LGUI("m") SS_DELAY(100)
            //Switch to epic and open orders only enounter
            SS_LGUI("2") SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LCTL("w") SS_DELAY(1000) SS_LCTL("5")
            //Fill in the details for orders only encounter
            //this next line is  tabbing to the CSN x10¸
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) //Clinic
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
            //SS_LSFT(SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)) //Corp laptop

            // Pasting in the CSN and then opening the orders only encounter
            SS_DELAY(1000) SS_LCTL("v") SS_DELAY(1000) SS_LALT("fs") SS_DELAY(3000)
            //switching back to excel to copy the date
            SS_LGUI("1") SS_DELAY(100) SS_TAP(X_ESC) SS_DELAY(100) SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100) SS_LCTL("c") SS_DELAY(100)
            //Delay excel -> epic opening orders field
            SS_DELAY(6000)
            //switch back to epic and open up
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("2") SS_DELAY(100)
            SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100)
            SS_LGUI(SS_TAP(X_UP))SS_DELAY(1000)
            SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100)
            SS_LCTL("o") SS_DELAY(100)

            //at order specific section
            "diabetes monitoring panel" SS_DELAY(200) SS_TAP(X_ENTER) SS_DELAY(2000)
            SS_LALT("f") SS_DELAY(1000) SS_TAP(X_ENTER) SS_DELAY(3500)
            SS_LCTL("v") //paste back the date
            SS_DELAY(2000)

            //sending order
            SS_LALT("s") SS_DELAY(2000)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(2000)

            //MOVING BACK TO EXCEL AND SORTING THE FILE
            //switch to excel
            // SS_LGUI("m") SS_LGUI("2") SS_DELAY(1000) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))
            // SS_DELAY(1000)
            SS_LGUI("1") SS_DELAY(1000) SS_TAP(X_ESC) SS_DELAY(100)
            //add comment of what lab it is
            SS_TAP(X_RGHT) "DM 04"
            //shift cursor back to left most cell
            SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100)
            // //select row
            SS_LSFT(SS_TAP(X_SPC))
            //highlight row
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100)
            //move down cell to next row
            SS_TAP(X_DOWN)
            //save the file
            // SS_LCTL("s")
            SS_DELAY(2000)

 //set win 1 as excel window and win 2 as the epic window
            //In excel: highlight cell of patient UID
            SS_LCTL("c") SS_DELAY(100) SS_LGUI("m") SS_DELAY(100)
            //Switch to epic and open orders only enounter
            SS_LGUI("2") SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LCTL("w") SS_DELAY(1000) SS_LCTL("5")
            //Fill in the details for orders only encounter
            //this next line is  tabbing to the CSN x10¸
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) //Clinic
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
            //SS_LSFT(SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)) //Corp laptop

            // Pasting in the CSN and then opening the orders only encounter
            SS_DELAY(1000) SS_LCTL("v") SS_DELAY(1000) SS_LALT("fs") SS_DELAY(3000)
            //switching back to excel to copy the date
            SS_LGUI("1") SS_DELAY(100) SS_TAP(X_ESC) SS_DELAY(100) SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100) SS_LCTL("c") SS_DELAY(100)
            //Delay excel -> epic opening orders field
            SS_DELAY(6000)
            //switch back to epic and open up
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("2") SS_DELAY(100)
            SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))SS_DELAY(100)
            SS_LGUI(SS_TAP(X_UP))SS_DELAY(1000)
            SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100) SS_LCTL("o") SS_DELAY(100)
            SS_LCTL("o") SS_DELAY(100)

            //at order specific section
            "diabetes monitoring panel" SS_DELAY(200) SS_TAP(X_ENTER) SS_DELAY(2000)
            SS_LALT("f") SS_DELAY(1000) SS_TAP(X_ENTER) SS_DELAY(3500)
            SS_LCTL("v") //paste back the date
            SS_DELAY(2000)

            //sending order
            SS_LALT("s") SS_DELAY(2000)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(2000)

            //MOVING BACK TO EXCEL AND SORTING THE FILE
            //switch to excel
            // SS_LGUI("m") SS_LGUI("2") SS_DELAY(1000) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP)) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))
            // SS_DELAY(1000)
            SS_LGUI("1") SS_DELAY(1000) SS_TAP(X_ESC) SS_DELAY(100)
            //add comment of what lab it is
            SS_TAP(X_RGHT) "DM 05 - loop end"
            //shift cursor back to left most cell
            SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100)
            // //select row
            SS_LSFT(SS_TAP(X_SPC))
            //highlight row
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100)
            //move down cell to next row
            SS_TAP(X_DOWN)

            SS_DELAY(100) SS_LCTL("s")


            );
          }
          break;
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
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("1") SS_DELAY(100) SS_TAP(X_ESC) SS_DELAY(100)
            SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100) SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100)

            //set win 1 as excel window and win 2 as the epic window
            //In excel: highlight cell of patient UID
            SS_LCTL("c") SS_DELAY(100)
            // SS_LSFT(SS_TAP(X_SPC)) SS_DELAY(100)
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("1") SS_DELAY(100)
            //Switch to epic and open patient lookup
            SS_LGUI("2") SS_DELAY(100) SS_LCTL("w") SS_DELAY(2000) SS_LCTL("1")
            //Fill in the details for orders only encounter
            //this next line is  tabbing to the CSN x10¸
            SS_DELAY(200) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) //Clinic
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
            //SS_LSFT(SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)) //Corp laptop

            // Pasting in the CSN and then opening the orders only encounter
            SS_DELAY(1000) SS_LCTL("v") SS_DELAY(1000) SS_LALT("fs") SS_DELAY(1500)

            );
          }
          break;

        case CHECK:
          if (record->event.pressed)
          {
            SEND_STRING(
            //to always get to excel
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("1") SS_DELAY(100) SS_TAP(X_ESC) SS_DELAY(100)

            //shift cursor back to right most cell
            SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100)
            //shift right then add comment
            SS_TAP(X_RGHT) "checked - ok"
            //shift left most cell
            SS_TAP(X_LEFT) SS_LCTL(SS_TAP(X_LEFT))
            SS_LSFT(SS_TAP(X_SPC)) SS_LSFT(SS_TAP(X_SPC))
            //highlight row
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100)
            //move down cell to next row
            SS_TAP(X_DOWN)




            );
          }
          break;
        case TFT:
          if (record->event.pressed)
          {
            SEND_STRING(
            //set win 1 as excel window and win 2 as the epic window
            //In excel: highlight cell of patient UID
            SS_LCTL("c") SS_DELAY(100) SS_LGUI("m") SS_DELAY(100)
            //Switch to epic and open orders only enounter
            SS_LGUI("2") SS_DELAY(100) SS_LCTL("w") SS_DELAY(4000) SS_LCTL("5")
            //Fill in the details for orders only encounter
            //this next line is  tabbing to the CSN x10¸
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) //Clinic
            SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
            //SS_LSFT(SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)) //Corp laptop

            // Pasting in the CSN and then opening the orders only encounter
            SS_DELAY(1000) SS_LCTL("v") SS_DELAY(1000) SS_LALT("fs") SS_DELAY(1500)
            //switching back to excel to copy the date
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("1") SS_DELAY(100) SS_TAP(X_ESC) SS_DELAY(100) SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(100) SS_LCTL("c")
            //Delay excel -> epic opening orders field
            SS_DELAY(4000)
            //switch back to epic and open up orders
            SS_LGUI("m") SS_DELAY(100) SS_LGUI("2") SS_DELAY(1000) SS_LCTL("o") SS_DELAY(1000)

            //at order specific section

            //at order specific section
            SS_LCTL("o") SS_DELAY(1000)
            "thyroid panel" SS_DELAY(200) SS_TAP(X_ENTER) SS_DELAY(2000)
            SS_LALT("f") SS_DELAY(200) SS_TAP(X_ENTER) SS_DELAY(5000)
            SS_LCTL("v") SS_DELAY(200) //paste back the date
            SS_LALT("a") SS_DELAY(1000)
            SS_LALT("s") SS_DELAY(5000)
            SS_LALT("o") SS_DELAY(200)
            SS_LCTL("s")

            //sending orders
            SS_LALT("s") SS_DELAY(1000)
            SS_LCTL(SS_LSFT("e")) SS_DELAY(3000)

            //MOVING BACK TO EXCEL AND SORTING THE FILE
            //switch to excel
            SS_LGUI("m") SS_LGUI("2") SS_DELAY(1000) SS_LGUI("1") SS_DELAY(1000) SS_TAP(X_ESC) SS_DELAY(100)
            //add comment of what lab it is
            SS_TAP(X_RGHT) "thyroid panel"
            //shift cursor back to left most cell
            SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(100)
            // //select row
            SS_LSFT(SS_TAP(X_SPC))
            //highlight row
            SS_LALT("h") SS_DELAY(100) "h" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100)
            //move down cell to next row
            SS_TAP(X_DOWN)
            //save the file
            // SS_LCTL("s")



            );
          }
          break;
          case TEST:
          if (record->event.pressed)
          {
            SEND_STRING(
            "test"

            );
          }
          break;




      }
    return true;
};
