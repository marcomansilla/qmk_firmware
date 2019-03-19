#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COLEMAK_DH_ANSI 0
#define _QWERTY 1
#define _FN1 2
#define _FN2 3
#define _FN3 4
#define _NAV 5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_FN1 MO(_FN1)
#define KC_FN2 MO(_FN2)
#define KC_FN3 OSL(_FN3)
#define KC_NAV TT(_NAV)
#define KC_SPFN1 LT(_FN1, KC_SPACE)
#define KC_BSFN2 LT(_FN2, KC_BSPC)
#define KC_BSFN1 LT(_FN1, KC_BSPC)
#define KC_SPFN2 LT(_FN2, KC_SPACE)
#define KC_LCHO LCTL_T(KC_HOME)
#define DF_CDHA DF(_COLEMAK_DH_ANSI)
#define DF_QWER DF(_QWERTY)
#define KC_CT_L LCTL(KC_LEFT)
#define KC_CT_R LCTL(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK_DH_ANSI] =
  LAYOUT(
         KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,   /**/    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS, KC_QUOT,
         KC_TAB,   KC_A,    KC_R,    KC_S,    KC_T,    KC_G,  /**/     KC_K,    KC_N,    KC_E,    KC_I,    KC_O,        KC_ENT,
         KC_LSPO,     KC_X,    KC_C,    KC_D,    KC_V,    KC_Z, /**/     KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
         KC_LCHO, OSM(MOD_LALT), KC_LGUI, KC_NAV, KC_BSFN1,     /**/    KC_SPFN2,      OSM(MOD_RALT), KC_RGUI, KC_FN3,  KC_BSLS
        ),

  [_QWERTY] =
  LAYOUT(
         KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   /**/  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, KC_QUOT,
         KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  /**/   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,     KC_ENT,
         KC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, /**/   KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
         KC_LCHO, OSM(MOD_LALT), KC_LGUI, KC_NAV,  KC_BSFN1,   /**/       KC_SPFN2,                  OSM(MOD_RALT), KC_RGUI, KC_FN3,  KC_BSLS
         ),

  [_FN1] =
  LAYOUT(
         KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    /**/  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
         _______,  RGB_HUI, RGB_SAI, RGB_VAI, KC_VOLU, KC_LBRC, /**/  KC_RBRC, KC_4,    KC_5,    KC_6,    KC_QUOT,   _______,
         _______,    RGB_HUD, RGB_SAD, RGB_VAD, KC_VOLD, KC_LCBR,  /**/ KC_RCBR, KC_1,    KC_2,    KC_3,    _______, _______,
         _______, _______, _______, _______, _______,            /**/  KC_DEL,         KC_0,    KC_DOT,  _______, _______
         ),

  [_FN2] =
  LAYOUT(
         KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  /**/ KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS,
         RESET,    _______, KC_PSCR, KC_INS,  _______, KC_HOME,  /**/ _______, _______, _______, _______, KC_DQUO,     _______,
         _______,    _______, _______, KC_DEL,  _______, KC_END,   /**/  _______,  _______, _______, _______, _______, _______,
         _______, _______, _______, _______, KC_DEL,             /**/ _______,          _______, _______, _______, _______
         ),

  [_FN3] =
  LAYOUT(
         _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,   /**/  KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10 , KC_F11 , KC_F12 ,
         _______,  DF_CDHA, DF_QWER, _______, _______, _______,  /**/   _______, _______, _______, _______, _______, _______,
         _______,   RGB_TOG, RGB_MOD, RGB_RMOD, _______, _______, /**/    _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______,             /**/   _______,       _______, _______, _______, _______
         ),

  [_NAV] =
  LAYOUT(
         _______, _______, _______, _______, _______, _______, /**/   _______, KC_CT_L,  KC_UP , KC_CT_R, _______, _______, _______,
         _______,  _______, _______, _______, _______, _______, /**/   KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, _______,
         _______,    _______, _______, _______, _______, _______, /**/   _______, _______, KC_PGUP, KC_PGDN, _______, _______,
         _______, _______, _______, _______, _______,            /**/  _______,         _______, _______, _______, _______
         ),
};
