#include QMK_KEYBOARD_H
#include "keycodes.c"

#define LAYOUT_crkbd_split_win(...) LAYOUT_split_3x6_3(__VA_ARGS__)

/* Layer 0: BASE (Colemak-DH)
 * ,-----------------------------------------------.                          ,-----------------------------------------------.
 * |TAB_LLW|   Q   |   W   |   F   |   P   |   B   |                          |   J   |   L   |   U   |   Y   |   ;   |Win | \|
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |IME_CTL|   A   |   R   |   S   |   T   |   G   |                          |   M   |   N   |   E   |   I   |   O   |   '   |
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |  Esc  |   Z   |   X   |   C   |   D   |   V   |                          |   K   |   H   |   ,   |   .   |   /   |ENT_FNW|
 * `-------------------------------+-------+-------+-------.          ,-------+-------+-------+-------------------------------'
 *                                 | Lower |BSP_MKW|  Alt  |          | Shift |SPC_NVW| Raise |
 *                                 `-----------------------'          `-----------------------'
 */
#define LAYER_BSW \
TAB_LLW, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, BSL_WIN, \
IME_CTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
KC_ESC,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                               KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, ENT_FNW, \
                                    OSL_NMW, BSP_MKW, KC_LALT,          OSM_SFT, SPC_NVW, OSL_SMW

/* Layer 1: NUMBER (Lower)
 * ,-----------------------------------------------.                          ,-----------------------------------------------.
 * |  Tab  | KP 6  | KP 3  | KP 1  | KP 2  | KP 7  |                          | KP 9  | KP 4  | KP 0  | KP 5  | KP 8  |  Win  |
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * | Ctrl  |   6   |   3   |   1   |   2   |   7   |                          |   9   |   4   |   0   |   5   |   8   | KP =  |
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |  Esc  | KP /  | KP *  | KP -  | KP +  |   (   |                          |   )   | KP .  |   ,   |   %   |   ^   |KPEnter|
 * `-------------------------------+-------+-------+-------.          ,-------+-------+-------+-------------------------------'
 *                                 |SET_NMW| Bksp  |  Alt  |          | Shift |SET_BSW|SET_BSW|
 *                                 `-----------------------'          `-----------------------'
 */
#define LAYER_NMW \
KC_TAB,  KC_P6,   KC_P3,   KC_P1,   KC_P2,   KC_P7,                              KC_P9,   KC_P4,   KC_P0,   KC_P5,   KC_P8,   KC_LWIN, \
KC_LCTL, KC_6,    KC_3,    KC_1,    KC_2,    KC_7,                               KC_9,    KC_4,    KC_0,    KC_5,    KC_8,    KC_PEQL, \
_______, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_LPRN,                            KC_RPRN, KC_PDOT, KC_COMM, KC_PERC, KC_CIRC, KC_PENT, \
                                    SET_NMW, KC_BSPC, _______,          _______, SET_BSW, SET_BSW

/* Layer 2: SYMBOL (Raise)
 * ,-----------------------------------------------.                          ,-----------------------------------------------.
 * |  Tab  |       |   %   |   [   |   ]   |       |                          |       |       |   `   |   $   |       |  Win  |
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * | Ctrl  |   <   |   >   |   (   |   )   |   |   |                          |   ~   |   -   |   +   |   =   |   _   |   "   |
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |  Esc  |   ^   |   @   |   {   |   }   |   &   |                          |   !   |   ?   |   :   |   *   |   #   | Enter |
 * `-------------------------------+-------+-------+-------.          ,-------+-------+-------+-------------------------------'
 *                                 |SET_BSW| Bksp  |  Alt  |          | Shift |SET_BSW|SET_SMW|
 *                                 `-----------------------'          `-----------------------'
 */
#define LAYER_SMW \
KC_TAB,  XXXXXXX, KC_PERC, KC_LBRC, KC_RBRC, XXXXXXX,                            XXXXXXX, XXXXXXX, KC_GRV,  KC_DLR,  XXXXXXX, KC_LWIN, \
KC_LCTL, KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, KC_PIPE,                            KC_TILD, KC_MINS, KC_PLUS, KC_EQL,  KC_UNDS, KC_DQUO, \
_______, KC_CIRC, KC_AT,   KC_LCBR, KC_RCBR, KC_AMPR,                            KC_EXLM, KC_QUES, KC_COLN, KC_ASTR, KC_HASH, KC_ENT, \
                                    SET_BSW, KC_BSPC, _______,          _______, SET_BSW, SET_SMW

/* Layer 3: MOUSE KEYS (Backspace)
 * ,-----------------------------------------------.                          ,-----------------------------------------------.
 * |  Tab  |       |       | MsUp  |       |       |                          |       |MWLeft | MWUp  |MWRight|       |  Win  |
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * | Ctrl  |       |MsLeft |MsDown |MsRight|       |                          |       |MsBtn1 |MsBtn3 |MsBtn2 |       |SET_BSW|
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |  Esc  |       |       |       |       |       |                          |       |MsBtn4 |MWDown |MsBtn5 |       | Enter |
 * `-------------------------------+-------+-------+-------.          ,-------+-------+-------+-------------------------------'
 *                                 |SET_BSW| Bksp  |  Alt  |          | Shift | Space |SET_BSW|
 *                                 `-----------------------'          `-----------------------'
 */
#define LAYER_MKW \
KC_TAB,  XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_WH_L, KC_WH_U, KC_WH_R, XXXXXXX, KC_LWIN, \
KC_LCTL, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                            XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, SET_BSW, \
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_BTN4, KC_WH_D, KC_BTN5, XXXXXXX, KC_ENT, \
                                    SET_BSW, KC_BSPC, _______,          _______, KC_SPC,  SET_BSW

/* Layer 4: NAVIGATION + MEDIA (Space)
 * ,-----------------------------------------------.                          ,-----------------------------------------------.
 * |  Tab  |  Ins  | PgUp  |  Up   | PgDn  |  Del  |                          |       | Prev  | Vol+  | Next  |       |  Win  |
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * | Ctrl  | Home  | Left  | Down  | Right |  End  |                          |       | Play  | Mute  | Stop  |       |SET_BSW|
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |  Esc  |DEL_LSW|MOV_PWW|DEL_LNW|MOV_NWW|DEL_LEW|                          |       |       | Vol-  |       |       | Enter |
 * `-------------------------------+-------+-------+-------.          ,-------+-------+-------+-------------------------------'
 *                                 |SET_BSW|DEL_PWW|  Alt  |          | Shift |SET_BSW|SET_BSW|
 *                                 `-----------------------'          `-----------------------'
 */
#define LAYER_NVW \
KC_TAB,  KC_INS,  KC_PGUP, KC_UP,   KC_PGDN, KC_DEL,                             XXXXXXX, KC_MPRV, KC_VOLU, KC_MNXT, XXXXXXX, KC_LWIN, \
KC_LCTL, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,                             XXXXXXX, KC_MPLY, KC_MUTE, KC_MSTP, XXXXXXX, SET_BSW, \
_______, DEL_LSW, MOV_PWW, DEL_LNW, MOV_NWW, DEL_LEW,                            XXXXXXX, XXXXXXX, KC_VOLD, XXXXXXX, XXXXXXX, KC_ENT, \
                                    SET_BSW, DEL_PWW, _______,          _______, SET_BSW, SET_BSW

/* Layer 5: FUNCTION (Enter)
 * ,-----------------------------------------------.                          ,-----------------------------------------------.
 * |  Tab  |       | Brt+  | CAPS  | Brt-  |       |                          |       | Print | Menu  | Calc  |       |  Win  |
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * | Ctrl  |  F6   |  F3   |  F1   |  F2   |  F7   |                          |  F9   |  F4   |  F10  |  F5   |  F8   |SET_BSW|
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |  Esc  |LYT_MAC|       |  F11  |  F12  |       |                          |       |       | Pause | NLCK  | SLCK  | Enter |
 * `-------------------------------+-------+-------+-------.          ,-------+-------+-------+-------------------------------'
 *                                 |SET_BSW| Bksp  |  Alt  |          | Shift |SET_BSW|SET_BSW|
 *                                 `-----------------------'          `-----------------------'
 */
#define LAYER_FNW \
KC_TAB,  XXXXXXX, KC_BRIU, KC_CAPS, KC_BRID, XXXXXXX,                            XXXXXXX, KC_PSCR, KC_APP,  KC_CALC, XXXXXXX, KC_LWIN, \
KC_LCTL, KC_F6,   KC_F3,   KC_F1,   KC_F2,   KC_F7,                              KC_F9,   KC_F4,   KC_F10,  KC_F5,   KC_F8,   SET_BSW, \
_______, LYT_MAC, XXXXXXX, KC_F11,  KC_F12,  XXXXXXX,                            XXXXXXX, XXXXXXX, KC_PAUS, KC_NUM,  KC_SCRL, KC_ENT, \
                                    SET_BSW, KC_BSPC, _______,          _______, SET_BSW, SET_BSW

/* Layer 6: LAYER LOCKS (Tab)
 * ,-----------------------------------------------.                          ,-----------------------------------------------.
 * |SET_BSW| Boot  | EECLR | Debug | Wake  | Sleep |                          |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |                          |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |                          |       |       |       |       |       |SET_FNW|
 * `-------------------------------+-------+-------+-------.          ,-------+-------+-------+-------------------------------'
 *                                 |SET_NMW|SET_MKW|       |          |       |SET_NVW|SET_SMW|
 *                                 `-----------------------'          `-----------------------'
 */
#define LAYER_LLW \
SET_BSW, QK_BOOT, EE_CLR,  DB_TOGG, KC_WAKE, KC_SLEP,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SET_FNW, \
                                    SET_NMW, SET_MKW, XXXXXXX,          XXXXXXX, SET_NVW, SET_SMW
