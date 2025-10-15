#include "gpio.h"

#ifndef GPIO_MAX_IDS
#define GPIO_MAX_IDS 64
#endif

typedef struct {
    bool is_output;
    bool level;
    gpio_pull_t pull;
} mock_pin_t;

static mock_pin_t g_pins[GPIO_MAX_IDS];

static int b_gpio_init(gpio_id_t id, gpio_dir_t dir, gpio_pull_t pull) {
    if (id >= GPIO_MAX_IDS) {
        return -1;
    }
    g_pins[id].is_output = (dir == GPIO_OUTPUT);
    g_pins[id].pull = pull;
    if (!g_pins[id].is_output) {
        g_pins[id].level = (pull == GPIO_PULLUP);
    }
    return 0;
}

static void b_gpio_set(gpio_id_t id) { 
    if (id < GPIO_MAX_IDS) {
        g_pins[id].level = true;
    }
}

static void b_gpio_clear(gpio_id_t id) { 
    if (id < GPIO_MAX_IDS) {
        g_pins[id].level = false; 
    }
}

static void b_gpio_toggle(gpio_id_t id) { 
    if (id < GPIO_MAX_IDS) {
        g_pins[id].level = !g_pins[id].level; 
    }
}

static bool b_gpio_read(gpio_id_t id) { 
    return (id < GPIO_MAX_IDS) ? g_pins[id].level : false; 
}

static const struct gpio_ops ops = {
    .init = b_gpio_init, 
    .set = b_gpio_set, 
    .clear = b_gpio_clear, 
    .toggle = b_gpio_toggle, 
    .read = b_gpio_read
};

void b_gpio_register(void) { 
    gpio_register_backend(&ops); 
}