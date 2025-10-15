#include "gpio.h"

static const struct gpio_ops* s_ops = 0;

void gpio_register_backend(const struct gpio_ops* ops) { 
    s_ops = ops; 
}

static inline int ready(void) { return s_ops != 0; }

int gpio_init(gpio_id_t id, gpio_dir_t dir, gpio_pull_t pull) {
    if (!ready() || !s_ops->init) {
        return -1;
    }
    return s_ops->init(id, dir, pull);
}

void gpio_set(gpio_id_t id) { 
    if (ready() && s_ops->set) {
        s_ops->set(id); 
    }
}

void gpio_clear(gpio_id_t id) { 
    if (ready() && s_ops->clear) {
        s_ops->clear(id);
    } 
}

void gpio_toggle(gpio_id_t id) { 
    if (ready() && s_ops->toggle) {
        s_ops->toggle(id); 
    }
}

bool gpio_read(gpio_id_t id) { 
    return (ready() && s_ops->read) ? s_ops->read(id) : false; 
}