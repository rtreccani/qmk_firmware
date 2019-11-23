#include QMK_KEYBOARD_H

enum custom_keycodes {
  EMAIL = SAFE_RANGE,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // 0: Base Layer
  LAYOUT_all(
      KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_GRV,    \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSLS,   \
      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NO,             KC_ENT,    \
      KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_NO  , KC_RSFT,  KC_NO,     \
      KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                          MO(1) ,  KC_LEFT,  KC_UP  , KC_DOWN,  KC_RIGHT),

  // 1: Function Layer
  LAYOUT_all(
      RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_F13,   KC_F14,    \
      KC_NO,   KC_NO ,  KC_NO ,  EMAIL ,  KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_PSCR, KC_NO,    KC_NO,             KC_NO,    \
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO ,  KC_NO,    KC_NO,             KC_NO,    \
      KC_NO  , KC_NO,   KC_NO,   KC_NO,   BL_STEP, KC_NO,  KC_NO,  KC_NO,  KC_MUTE ,KC_NO,   KC_NO ,  KC_NO ,   KC_NO ,   KC_NO,   KC_NO,      \
      KC_NO  , KC_NO ,  KC_NO,                             KC_NO ,                          KC_NO,   KC_NO,    KC_VOLU,    KC_VOLD,   KC_NO),

};

void matrix_init_user(void){

};

// Loop
void matrix_scan_user(void) {
    static int brightness = 0;
    static int direction = 1;
    static int subcount = 0;

    subcount++;

    if(subcount == 400){

        if(direction == 1){
            brightness++;
        }
        else if(direction == 0){
            brightness--;
        }

        if(brightness==22){
            direction = 0;
        }

        if(brightness==3){
            direction = 1;
        }

        backlight_level(brightness);
        subcount=0;
    }

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EMAIL:
      if (record->event.pressed) {
        // when keycode EMAIL is pressed
        SEND_STRING("raphael.treccanichinelli@gmail.com");
      } else {
        // when keycode EMAIL is released
      }
      break;

  }
  return true;
};

