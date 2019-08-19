#include "rev1.h"


static bool backlight_was_toggled = false;

void suspend_power_down_kb(void) {
    if (is_backlight_enabled()) {
        backlight_disable();
        backlight_was_toggled = true;
    }
}

void suspend_wakeup_init_kb(void) {
    if (backlight_was_toggled) {
        backlight_enable();
        backlight_was_toggled = false;
    }
}

#ifdef PHYSICAL_LEDS_ENABLE
void led_init_kb(void)
{
#ifdef NUM_LOCK_LED_PIN
    setPinOutput(NUM_LOCK_LED_PIN);
    RESET_NUM_LOCK_LED();
#endif // NUM_LOCK_LED_PIN
#ifdef CAPS_LOCK_LED_PIN
    setPinOutput(CAPS_LOCK_LED_PIN);
    RESET_CAPS_LOCK_LED();
#endif // CAPS_LOCK_LED_PIN
#ifdef SCROLL_LOCK_LED_PIN
    setPinOutput(SCROLL_LOCK_LED_PIN);
    RESET_SCROLL_LOCK_LED();
#endif // SCROLL_LOCK_LED_PIN
}
#endif // PHYSICAL_LEDS_ENABLE

void matrix_init_kb(void) {
#ifdef PHYSICAL_LEDS_ENABLE
  led_init_kb();
#endif // PHYSICAL_LEDS_ENABLE
  matrix_init_user();
};

#ifdef PHYSICAL_LEDS_ENABLE
void led_set_kb(uint8_t usb_led)
{
#ifdef NUM_LOCK_LED_PIN
   if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
        SET_NUM_LOCK_LED();
    } else {
        RESET_NUM_LOCK_LED();
    }
#endif // NUM_LOCK_LED_PIN
#ifdef CAPS_LOCK_LED_PIN
    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        SET_CAPS_LOCK_LED();
    } else {
        RESET_CAPS_LOCK_LED();
    }
#endif // CAPS_LOCK_LED_PIN
#ifdef SCROLL_LOCK_LED_PIN
    if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
        SET_SCROLL_LOCK_LED();
    } else {
        RESET_SCROLL_LOCK_LED();
    }
#endif // SCROLL_LOCK_LED_PIN
    led_set_user(usb_led);
}
#endif // PHYSICAL_LEDS_ENABLE
