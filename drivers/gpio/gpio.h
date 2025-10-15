#ifndef __GPIO_H__
#define __GPIO_H__


#include <stdbool.h>
#include <stdint.h>


typedef uint16_t gpio_id_t;


typedef enum { 
    GPIO_INPUT = 0, 
    GPIO_OUTPUT = 1 
} gpio_dir_t;

typedef enum { 
    GPIO_NOPULL = 0, 
    GPIO_PULLUP = 1, 
    GPIO_PULLDOWN = 2 
} gpio_pull_t;


int  gpio_init (gpio_id_t id, gpio_dir_t dir, gpio_pull_t pull);
void gpio_set (gpio_id_t id);
void gpio_clear (gpio_id_t id);
void gpio_toggle (gpio_id_t id);
bool gpio_read (gpio_id_t id);

struct gpio_ops {
    int  (*init)(gpio_id_t, gpio_dir_t, gpio_pull_t);
    void (*set)(gpio_id_t);
    void (*clear)(gpio_id_t);
    void (*toggle)(gpio_id_t);
    bool (*read)(gpio_id_t);
};

void gpio_register_backend(const struct gpio_ops* ops);


#endif