#pragma once
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

 // Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

/* fixes modtap rolls */
#define PERMISSIVE_HOLD_PER_KEY

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      9
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    40
#define MK_COMBINED
#define MK_MOMENTARY_ACCEL

// This prevents accidental repeats of the tap-hold keys when typing quickly.
#define TAPPING_FORCE_HOLD

// This prevents short hold periods to be interpreted as individual taps when typing quickly.
#define PERMISSIVE_HOLD

/* combo  */
#define COMBO_ONLY_FROM_LAYER 0

