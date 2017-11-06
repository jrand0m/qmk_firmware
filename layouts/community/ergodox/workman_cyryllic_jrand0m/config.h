#ifndef CONFIG_H_
#define CONFIG_H_

#include QMK_KEYBOARD_CONFIG_H

#undef TAPPING_TERM
#define TAPPING_TERM 300
#define LSPO_KEY KC_LBRACKET
#define RSPC_KEY KC_RBRACKET
#undef NO_DEBUG
#define NO_DEBUG
#define FORCE_NKRO
#endif
