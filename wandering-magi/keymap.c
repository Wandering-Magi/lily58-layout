#include QMK_KEYBOARD_H

enum layer_number {
  ENGR = 0,
  QWERTY,
  NUMPAD,
  NAV,
  FUNC,
};

enum custom_keycodes {
  DOT_CLN,
  COM_SCLN
};

/* 
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |       |     | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  /* ENGRAM
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * | ESC  |   1  |   2  |   3  |  4   |  5{  |                    |  6}  |  7   |   8  |   9  |   0  | DEL  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * | TAB  |   B  |   Y  |   O  |   U  |  '[  |                    |  "]  |   L  |   D  |   W  |   V  |  Z   |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |   C  |   I  |   E  |   A  |  ,(  |-------.    ,-------|  .)  |   H  |   T  |   S  |   N  |  Q   |
  * |------+------+------+------+------+------| LOWER |    | RAISE |------+------+------+------+------+------|
  * |      |   G  |   X  |   J  |   K  |  -_  |-------|    |-------|  ?!  |   R  |   M  |   F  |   P  |      |
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   |      | LCTRL| LALT | /Space  /       \LSHIFT\  |BackSP| NUM  | ESC  |
  *                   |      |      |      |/ ENTER /         \      \ |      |      |  `   |
  *                   `----------------------------'           '------''--------------------'
  */
  [ENGR] = LAYOUT(
    KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
    KC_TAB , KC_B   , KC_Y   , KC_O   , KC_U   , KC_QUOT,                   KC_DQUO, KC_L   , KC_D   , KC_W   , KC_V   , KC_Z   ,
    XXXXXXX, KC_C   , KC_I   , KC_E   , KC_A   , KC_COMM,                   KC_DOT , KC_H   , KC_T   , KC_S   , KC_N   , KC_Q   ,
    KC_LSFT, KC_G   , KC_X   , KC_J   , KC_K   , KC_MINS,XXXXXXX,DF(QWERTY),KC_QUES, KC_R   , KC_M   , KC_F   , KC_P   , KC_ENT ,
                              TT(NAV), KC_LCTL, KC_LALT, KC_SPC , OSM(MOD_LSFT), KC_BSPC, TT(NUMPAD), GE_SWAP
  ),

  /* QWERTY
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
  * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
  * |      |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |      |
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   |      | LCTRL| LALT | /Space  /       \RSHIFT\  |BackSP| NUM  |      |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [QWERTY] = LAYOUT(
    KC_ESC ,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_TAB ,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    XXXXXXX,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, DF(ENGR),  XXXXXXX,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT,
                              _______, KC_LCTL, KC_LALT, KC_SPC , KC_RSFT, KC_BSPC, _______, XXXXXXX
  ),

  /* NUMPAD
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * |   ~  |      |      |      |      |   |  |                    |      |  7   |  8   |   9  |  /   |      |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      |   %  |  #   |   $  |   <  |                    |   >  |  4   |  5   |   6  |  *   |      |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      |   ^  |  &   |   @  |   (  |-------.    ,-------|   )  |  1   |  2   |   3  |  -   |      |
  * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
  * |      |      |   /  |  *   |  +   |  -   |-------|    |-------|      |      |  0   |   .  |  +   |      |
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   |      |       |     | /       /       \ ENTER\  |      |      |      |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [NUMPAD] = LAYOUT(
    KC_TILD, _______, _______, _______, _______, KC_PIPE,                   _______, KC_P7  , KC_P8  , KC_P9  , KC_PSLS, _______,
    _______, _______, KC_PERC, KC_HASH, KC_DLR , KC_LT  ,                   KC_GT  , KC_P4  , KC_P5  , KC_P6  , KC_PAST, _______,
    _______, _______, KC_CIRC, KC_AMPR, KC_AT  , KC_LPRN,                   KC_RPRN, KC_P1  , KC_P2  , KC_P3  , KC_PMNS, _______,
    _______, _______, KC_PSLS, KC_ASTR, KC_PLUS, KC_PMNS, _______, _______, _______, _______, KC_P0  , KC_PDOT, KC_PPLS, _______,
                              _______, _______, _______, _______, _______,  _______, _______, _______
  ),

  /* NAV 
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      | MCl  |  MU  |  RCl |  SCU |                    |  PUP | HOME |  UP  |  END |      |      |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      | ML   |  MD  |  MR  |  SCD |-------.    ,-------|  PDN | LEFT | DOWN | RIGHT|      |      |
  * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
  * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   |      |       |     | /   LCl /       \  ENT \  |      |      |      |
  *                   |      |      |CTRL+W|/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [NAV] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, KC_BTN3, KC_MS_U, KC_BTN2, KC_WH_U,                   KC_PGUP, KC_HOME, KC_UP  , KC_END , _______, _______,
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                               _______, _______, LCTL(KC_W), KC_BTN1, KC_ENT , _______, _______, _______

  ),

  /* Function
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * |NUMLK |SCRLK |INSERT|      |      |      |                    |      |  F7  |  F8  |  F9  |      |      |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      |      |      |      |      |                    |      |  F4  |  F5  |  F6  |      |      |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      | SAVE |      |      |      |-------.    ,-------|      |  F1  |  F2  |  F3  |      |      |
  * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
  * |      |UNDO | CUT  | COPY | PASTE|       |-------|    |-------|      |  F10 | F11  | F12  |      |      |
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   |      |       |     | /       /       \      \  |      |      |      |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [FUNC] = LAYOUT(
    KC_NUM , KC_SCRL, KC_INS , _______, _______, _______,                   _______, KC_F7  , KC_F8  , KC_F9  , _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, KC_F4  , KC_F5  , KC_F6  , _______, _______,
    _______, _______, LCTL(KC_S), _______, _______, _______,                   _______, KC_F1  , KC_F2  , KC_F3  , _______, _______,
    _______, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), _______, _______, _______, _______, KC_F10 , KC_F11 , KC_F12 , _______, _______,
                              _______, _______, _______, _______, _______,  _______, _______, _______

  )
};

/**
  Key Overrides  
**/
#define layer_mask 0b1
const key_override_t Question_Exclemation = ko_make_with_layers( MOD_MASK_SHIFT, KC_QUES, KC_EXLM, layer_mask );
const key_override_t Space_ENT = ko_make_with_layers( MOD_MASK_SHIFT, KC_SPC, KC_ENT, layer_mask );
const key_override_t COMM_LPAREN = ko_make_with_layers( MOD_MASK_SHIFT, KC_COMM, KC_LPRN, layer_mask );
const key_override_t DOT_RPAREN = ko_make_with_layers( MOD_MASK_SHIFT, KC_DOT, KC_RPRN, layer_mask );
const key_override_t QUOT_LBRAC = ko_make_with_layers( MOD_MASK_SHIFT, KC_QUOT, KC_LBRC, layer_mask );
const key_override_t DQUO_RBRAC = ko_make_with_layers( MOD_MASK_SHIFT, KC_DQUO, KC_RBRC, layer_mask );
const key_override_t N5_LCBR = ko_make_with_layers( MOD_MASK_SHIFT, KC_5, KC_LCBR, layer_mask );
const key_override_t N6_LCBR = ko_make_with_layers( MOD_MASK_SHIFT, KC_6, KC_RCBR, layer_mask );
const key_override_t N4_LABK = ko_make_with_layers( MOD_MASK_SHIFT, KC_4, KC_LABK, layer_mask );
const key_override_t N7_RABK = ko_make_with_layers( MOD_MASK_SHIFT, KC_7, KC_RABK, layer_mask );

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
  &Question_Exclemation,
  &Space_ENT,
  &COMM_LPAREN,
  &DOT_RPAREN,
  &QUOT_LBRAC,
  &DQUO_RBRAC,
  &N5_LCBR,
  &N6_LCBR,
  &N4_LABK,
  &N7_RABK,
  NULL // Null terminate the array of overrides!
};

// Using Tri-Layer to access the function layer from Nav and Numpad combo
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, NAV, NUMPAD, FUNC);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}


/**
TAP DANCE HANDLING 
Building the Tap-Hold Functionality
*/
typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

    switch (keycode) {
      // list all tap dance keycodes with tap-hold configurations
        // case TD(CT_CLN):  
        //     action = &tap_dance_actions[TD_INDEX(keycode)];
        //     if (!record->event.pressed && action->state.count && !action->state.finished) {
        //         tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
        //         tap_code16(tap_hold->tap);
        //     }
        case TD(DOT_CLN):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(COM_SCLN):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
    }
    return true;
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

// Finish tap-hold configurations here
tap_dance_action_t tap_dance_actions[] = {
    //[CT_CLN] = ACTION_TAP_DANCE_TAP_HOLD(KC_COLN, KC_SCLN),
    [DOT_CLN] = ACTION_TAP_DANCE_TAP_HOLD(KC_DOT, KC_COLN),
    [COM_SCLN] = ACTION_TAP_DANCE_TAP_HOLD(KC_COMMA, KC_SCLN),
};

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE
