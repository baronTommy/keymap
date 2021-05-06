#include "dactyl.h"

#define __________ KC_TRNS
#define XXXXXXXXXX KC_NO

// レイヤー
#define BASE 0
#define NUMBER 1
#define SYMBOL1 2
#define SYMBOL2 3
#define FN 4
#define MY_FN 5

// 親指モディファイ
#define MY_KC_LL KC_LSHIFT
#define MY_KC_LR KC_LGUI
#define MY_KC_RL KC_LALT
#define MY_KC_RR KC_RCTRL // KC_LCTRL だとバグ

// レイヤー切り変え
enum custom_keycodes {
  KC_MAKE = SAFE_RANGE,
  MY_KC_FN,
  MY_KC_SYM1,
  MY_KC_SYM2,
  MY_KC_NUM,
  MY_KC_SPEC
};

// OSに渡す用
#define MY_KC_0 KC_KP_0
#define MY_KC_1 KC_KP_1
#define MY_KC_2 KC_KP_2
#define MY_KC_3 KC_KP_3
#define MY_KC_4 KC_KP_4
#define MY_KC_5 KC_KP_5
#define MY_KC_6 KC_KP_6
#define MY_KC_7 KC_KP_7
#define MY_KC_8 KC_KP_8
#define MY_KC_9 KC_KP_9
#define MY_KC_10 KC_KP_PLUS
#define MY_KC_11 KC_KP_EQUAL
#define MY_KC_12 KC_KP_DOT
#define MY_KC_13 KC_KP_MINUS
#define MY_KC_14 KC_KP_SLASH
#define MY_KC_15 KC_KP_ASTERISK
#define MY_KC_16 KC_F13
#define MY_KC_17 KC_F14
#define MY_KC_18 KC_F15
#define MY_KC_19 KC_F16
#define MY_KC_20 KC_F17
#define MY_KC_21 KC_F18
#define MY_KC_22 KC_F19

// エイリアス
#define MY_KC_JP KC_LANG1
#define MY_KC_EN KC_LANG2

// この秒数(ms)以内に、キーアップでワンショット発火
#define ONE_SHOT_TIME 200

// この秒数(ms)以内に、キー同時押しWワンショット発動の条件
#define W_ONE_SHOT_DOWN_TIME 100

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_dactyl(
    // Left Hand
    XXXXXXXXXX,  XXXXXXXXXX,  XXXXXXXXXX,  XXXXXXXXXX,  XXXXXXXXXX,  XXXXXXXXXX,
    XXXXXXXXXX,  KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,
    KC_SPACE,    KC_A,        KC_S,        KC_D,        KC_F,        KC_G,
    KC_ESCAPE,   KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,
    XXXXXXXXXX,  MY_KC_FN,    MY_KC_SYM2,  MY_KC_SYM1,  MY_KC_NUM,

                 RESET,       XXXXXXXXXX,
                 KC_LALT,
    MY_KC_LL,   MY_KC_LR,     KC_LCTRL,

    // Right Hand
    XXXXXXXXXX,  XXXXXXXXXX,  XXXXXXXXXX,  XXXXXXXXXX,  XXXXXXXXXX,  XXXXXXXXXX,
    KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        XXXXXXXXXX,
    KC_H,        KC_J,        KC_K,        KC_L,        MY_KC_SPEC,  KC_BSPACE,
    KC_N,        KC_M,        KC_UP,       KC_TAB,      KC_DEL,      KC_ENTER,
    KC_LEFT,     KC_DOWN,     KC_RIGHT,    XXXXXXXXXX, XXXXXXXXXX,

    XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX,
    XXXXXXXXXX, MY_KC_RL,    MY_KC_RR
    ),

  [NUMBER] = LAYOUT_dactyl(
    // Left Hand
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, __________, __________, __________, __________,

                 XXXXXXXXXX, XXXXXXXXXX,
                 XXXXXXXXXX,
    __________, __________, XXXXXXXXXX,

    // Right Hand
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, KC_7,       KC_8,       KC_9,       XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, KC_4,       KC_5,       KC_6,       XXXXXXXXXX, XXXXXXXXXX,
    KC_0,       KC_1,       KC_2,       KC_3,       XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,

    XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX,
    XXXXXXXXXX, __________, __________
  ),

  [SYMBOL1] = LAYOUT_dactyl(
    // Left Hand
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, __________, __________, __________, __________,

                 XXXXXXXXXX, XXXXXXXXXX,
                 XXXXXXXXXX,
    __________, __________, XXXXXXXXXX,

    // Right Hand
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    KC_UNDS,    KC_PIPE,    KC_AMPR,    KC_EXLM,    KC_QUESTION, XXXXXXXXXX,
    KC_HASH,    KC_COMMA,   KC_DOT,     KC_SCOLON,  KC_COLON,   KC_AT,
    KC_DQUO,    KC_QUOTE,   KC_GRAVE,   KC_SLASH,   KC_BSLASH,  XXXXXXXXXX,
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,

    XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX,
    XXXXXXXXXX, __________, __________
  ),

  [SYMBOL2] = LAYOUT_dactyl(
    // Left Hand
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, __________, __________, __________, __________,

                 XXXXXXXXXX, XXXXXXXXXX,
                 XXXXXXXXXX,
    __________, __________, XXXXXXXXXX,

    // Right Hand
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    KC_CIRC,    KC_LABK,    KC_RABK,    KC_LBRACKET, KC_RBRACKET, XXXXXXXXXX,
    KC_EQUAL,   KC_PLUS,    KC_MINUS,   KC_ASTR,    KC_PERC,    KC_DLR,
    KC_TILD,    KC_LPRN,    KC_RPRN,    KC_LCBR,    KC_RCBR,    XXXXXXXXXX,
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,

    XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX,
    XXXXXXXXXX, __________, __________
  ),

  [FN] = LAYOUT_dactyl(
    // Left Hand
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, __________, __________, __________, __________,

                 XXXXXXXXXX, XXXXXXXXXX,
                 XXXXXXXXXX,
    __________, __________, XXXXXXXXXX,

    // Right Hand
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, KC_F1,      KC_F2,      KC_F3,      KC_F4,      XXXXXXXXXX,
    XXXXXXXXXX, KC_F5,      KC_F6,      KC_F7,      KC_F8,      XXXXXXXXXX,
    XXXXXXXXXX, KC_F9,      KC_F10,     KC_F11,     KC_F12,     XXXXXXXXXX,
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,

    XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX,
    XXXXXXXXXX, __________, __________
  ),

  [MY_FN] = LAYOUT_dactyl(
    // Left Hand
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, MY_KC_1,    MY_KC_2,    MY_KC_3,    MY_KC_4,    MY_KC_5,
    XXXXXXXXXX, MY_KC_6,    MY_KC_7,    MY_KC_8,    MY_KC_9,    MY_KC_10,
    XXXXXXXXXX, MY_KC_11,   MY_KC_12,   MY_KC_13,   MY_KC_14,   MY_KC_15,
    XXXXXXXXXX, __________, __________, __________, __________,

                 XXXXXXXXXX, XXXXXXXXXX,
                 XXXXXXXXXX,
    __________, __________, XXXXXXXXXX,

    // Right Hand
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, __________, XXXXXXXXXX,
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, __________, __________, XXXXXXXXXX,
    XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX, XXXXXXXXXX,

    XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX,
    XXXXXXXXXX, __________, __________
  ),
};

static bool one_shot_modifiers_through_flg = false;
static bool is_input_mode_en = false;

typedef struct OneShotModifier {
  uint16_t key;
  uint16_t send_key;
  uint16_t down_ms;
  int layer;
  bool is_down;
} one_shot_modifier;
one_shot_modifier one_shot_modifiers[] = {
  {MY_KC_LL, KC_ENTER, MY_KC_LL, BASE, false},
  {MY_KC_LR, KC_BSPACE, MY_KC_LR, BASE, false},
  {MY_KC_RL, KC_ESCAPE, MY_KC_RL, BASE, false},
  {MY_KC_RR, KC_SPACE, MY_KC_RR, BASE, false},
  {MY_KC_FN, MY_KC_0, MY_KC_FN, FN, false},
  {MY_KC_SYM1, MY_KC_0, MY_KC_SYM1, SYMBOL1, false},
  {MY_KC_SYM2, MY_KC_0, MY_KC_SYM2, SYMBOL2, false},
  {MY_KC_NUM, MY_KC_0, MY_KC_NUM, NUMBER, false},
  {MY_KC_SPEC, MY_KC_0, MY_KC_SPEC, MY_FN, false},
};
int one_shot_modifiers_cnt = (sizeof(one_shot_modifiers)/sizeof(one_shot_modifier));

typedef struct SimultaneouslyOneShotModifier {
  uint16_t key1;
  uint16_t key2;
  uint16_t send_key;
  uint16_t down_ms1;
  uint16_t down_ms2;
} simultaneously_one_shot_modifier;
simultaneously_one_shot_modifier simultaneously_one_shot_modifiers[] = {
  // LL LR
  {MY_KC_LL, MY_KC_LR, MY_KC_JP, MY_KC_LL, MY_KC_LR},
  {MY_KC_LR, MY_KC_LL, MY_KC_JP, MY_KC_LR, MY_KC_LL},

  // RL RR
  {MY_KC_RL, MY_KC_RR, MY_KC_EN, MY_KC_LL, MY_KC_LR},
  {MY_KC_RR, MY_KC_RL, MY_KC_EN, MY_KC_LR, MY_KC_LL},

  // LL RR
  {MY_KC_LL, MY_KC_RR, MY_KC_19, MY_KC_LL, MY_KC_RR},
  {MY_KC_RR, MY_KC_LL, MY_KC_19, MY_KC_RR, MY_KC_LL},

  // LR RL
  {MY_KC_LR, MY_KC_RL, MY_KC_20, MY_KC_LR, MY_KC_RL},
  {MY_KC_RL, MY_KC_LR, MY_KC_20, MY_KC_RL, MY_KC_LR},

  // LL RL
  {MY_KC_LL, MY_KC_RL, MY_KC_21, MY_KC_LL, MY_KC_RL},
  {MY_KC_RL, MY_KC_LL, MY_KC_21, MY_KC_RL, MY_KC_LL},

  // LR RR
  {MY_KC_LR, MY_KC_RR, MY_KC_22, MY_KC_LR, MY_KC_RR},
  {MY_KC_RR, MY_KC_LR, MY_KC_22, MY_KC_RR, MY_KC_LR},
};
int simultaneously_one_shot_modifiers_cnt = (sizeof(simultaneously_one_shot_modifiers)/sizeof(simultaneously_one_shot_modifier));

void set_input_mode(uint16_t keycode) {
  if (keycode == MY_KC_EN) {
    is_input_mode_en = true;
  }

  if (keycode == MY_KC_JP) {
    is_input_mode_en = false;
  }
}

void key_send(uint16_t keycode) {
  set_input_mode(keycode);
  one_shot_modifiers_through_flg = true;
  register_code(keycode);
  unregister_code(keycode);
}

uint16_t get_diff_time_ms(uint16_t a, uint16_t b) {
    if (a > b) {
      return a - b;
    }
    return b - a;
}

int find_one_shot_modifier_no(uint16_t keycode) {
  for (int i = 0; i <= one_shot_modifiers_cnt; i++) {
    if (one_shot_modifiers[i].key == keycode) {
      return i;
    }
  }
  return -1;
}

bool is_key_down(uint16_t keycode) {
  int no = find_one_shot_modifier_no(keycode);
  return one_shot_modifiers[no].is_down;
}

bool can_one_shot_modifier(uint16_t keycode) {
  int no = find_one_shot_modifier_no(keycode);
  if (one_shot_modifiers_through_flg) {
    return false;
  }

  if (timer_elapsed(one_shot_modifiers[no].down_ms) > ONE_SHOT_TIME) {
    return false;
  }

  return true;
}

void layer_change(int layer, bool on) {
  if (layer == BASE) {
    return;
  }
  if (on) {
    layer_on(layer);
    return;
  }
  layer_off(layer);
}

void send_one_shot_modifier(uint16_t keycode) {
  int no = find_one_shot_modifier_no(keycode);
  key_send(one_shot_modifiers[no].send_key);
}

void set_modifier_key_down(uint16_t keycode) {
  int no = find_one_shot_modifier_no(keycode);
  layer_change(one_shot_modifiers[no].layer, true);

  one_shot_modifiers[no].down_ms = timer_read();
  one_shot_modifiers[no].is_down = true;
  one_shot_modifiers_through_flg = false;
}

int find_simultaneously_one_shot_modifier_pear_no(uint16_t keycode) {
  for (int i = 0; i <= simultaneously_one_shot_modifiers_cnt; i++) {
    if (simultaneously_one_shot_modifiers[i].key1 != keycode) {
      continue;
    }

    int pear_no = find_one_shot_modifier_no(simultaneously_one_shot_modifiers[i].key2);
    if (pear_no > -1 && !one_shot_modifiers[pear_no].is_down) {
      continue;
    }
    return pear_no;
  }
  return -1;
}

int find_simultaneously_one_shot_modifier_no(uint16_t key1, uint16_t key2) {
  for (int i = 0; i <= simultaneously_one_shot_modifiers_cnt; i++) {
    if (simultaneously_one_shot_modifiers[i].key1 == key1 && simultaneously_one_shot_modifiers[i].key2 == key2) {
      return i;
    }

    if (simultaneously_one_shot_modifiers[i].key1 == key2 && simultaneously_one_shot_modifiers[i].key2 == key1) {
      return i;
    }
  }
  return -1;
}

bool can_simultaneously_one_shot_modifier(uint16_t keycode) {
  if (one_shot_modifiers_through_flg) {
    return false;
  }

  int pear_no = find_simultaneously_one_shot_modifier_pear_no(keycode);
  if (pear_no == -1) {
    return false;
  }

  int current_no = find_one_shot_modifier_no(keycode);
  uint16_t current_down_time = timer_elapsed(one_shot_modifiers[current_no].down_ms);
  if (current_down_time > ONE_SHOT_TIME) {
    return false;
  }

  uint16_t pear_down_time = timer_elapsed(one_shot_modifiers[pear_no].down_ms);
  return get_diff_time_ms(pear_down_time, current_down_time) < W_ONE_SHOT_DOWN_TIME;
}

void send_simultaneously_one_shot_modifier(uint16_t keycode) {
  int current_no = find_one_shot_modifier_no(keycode);
  int pear_no = find_simultaneously_one_shot_modifier_pear_no(keycode);
  int no = find_simultaneously_one_shot_modifier_no(one_shot_modifiers[current_no].key, one_shot_modifiers[pear_no].key);
  unregister_code(one_shot_modifiers[pear_no].key);
  key_send(simultaneously_one_shot_modifiers[no].send_key);
}

void set_modifier_key_up(uint16_t keycode) {
    unregister_code(keycode);
    int no = find_one_shot_modifier_no(keycode);
    layer_change(one_shot_modifiers[no].layer, false);

    if (can_simultaneously_one_shot_modifier(keycode)) {
      one_shot_modifiers[no].is_down = false;
      send_simultaneously_one_shot_modifier(keycode);
      return;
    }

    if (can_one_shot_modifier(keycode)) {
      one_shot_modifiers[no].is_down = false;
      send_one_shot_modifier(keycode);
      return;
    }

    one_shot_modifiers[no].is_down = false;
}

void pre_send_hankaku(void) {
    for (int i = 0; i <= one_shot_modifiers_cnt; i++) {
      if (one_shot_modifiers[i].is_down) {
        unregister_code(one_shot_modifiers[i].key);
      }
    }

    key_send(MY_KC_EN);

    for (int i = 0; i <= one_shot_modifiers_cnt; i++) {
      if (one_shot_modifiers[i].is_down) {
        register_code(one_shot_modifiers[i].key);
      }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // 親指モディファイ
    case MY_KC_LL:
    case MY_KC_LR:
    case MY_KC_RL:
    case MY_KC_RR:
      if (record->event.pressed) {
        register_code(keycode);
        set_modifier_key_down(keycode);
        return true;
      }
      unregister_code(keycode);
      set_modifier_key_up(keycode);
      return true;

    // レイヤー切り変え
    case MY_KC_FN:
    case MY_KC_SYM1:
    case MY_KC_SYM2:
    case MY_KC_NUM:
    case MY_KC_SPEC:
      if (record->event.pressed) {
        set_modifier_key_down(keycode);
        return true;
      }
      set_modifier_key_up(keycode);
      return true;

    // 記号, 数値 ime off
    case KC_0:
    case KC_1:
    case KC_2:
    case KC_3:
    case KC_4:
    case KC_5:
    case KC_6:
    case KC_7:
    case KC_8:
    case KC_9:
    case KC_UNDS:
    case KC_PIPE:
    case KC_AMPR:
    case KC_EXLM:
    case KC_QUESTION:
    case KC_HASH:
    case KC_COMMA:
    case KC_DOT:
    case KC_SCOLON:
    case KC_COLON:
    case KC_AT:
    case KC_DQUO:
    case KC_QUOTE:
    case KC_GRAVE:
    case KC_SLASH:
    case KC_BSLASH:
    case KC_CIRC:
    case KC_LABK:
    case KC_RABK:
    case KC_LBRACKET:
    case KC_RBRACKET:
    case KC_EQUAL:
    case KC_PLUS:
    case KC_MINUS:
    case KC_ASTR:
    case KC_PERC:
    case KC_DLR:
    case KC_TILD:
    case KC_LPRN:
    case KC_RPRN:
    case KC_LCBR:
    case KC_RCBR:
      if (!record->event.pressed) {
        return true;
      }
      one_shot_modifiers_through_flg = true;

      if (is_input_mode_en) {
        return true;
      }

      is_input_mode_en = true;

      register_code(KC_LSHIFT);
      register_code(KC_LCTRL);
      register_code(KC_SCOLON);
      unregister_code(KC_SCOLON);
      unregister_code(KC_LCTRL);
      unregister_code(KC_LSHIFT);

      // pre_send_hankaku を使用するとバグがある為ハードコーディング
      // pre_send_hankaku();
      return true;

    // shift ダウン時に ime off
    case KC_A:
    case KC_B:
    case KC_C:
    case KC_D:
    case KC_E:
    case KC_F:
    case KC_G:
    case KC_H:
    case KC_I:
    case KC_J:
    case KC_K:
    case KC_L:
    case KC_M:
    case KC_N:
    case KC_O:
    case KC_P:
    case KC_Q:
    case KC_R:
    case KC_S:
    case KC_T:
    case KC_U:
    case KC_V:
    case KC_W:
    case KC_X:
    case KC_Y:
    case KC_Z:
      if (!record->event.pressed) {
        return true;
      }
      one_shot_modifiers_through_flg = true;

      if (is_input_mode_en) {
        return true;
      }

      if (!is_key_down(MY_KC_LL)) {
        return true;
      }

      is_input_mode_en = true;
      pre_send_hankaku();
      return true;
  }

  one_shot_modifiers_through_flg = true;
  return true;
}
