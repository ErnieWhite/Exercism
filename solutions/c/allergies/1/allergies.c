#include "allergies.h"
#include <stdio.h>

bool is_allergic_to(allergen_t allergen, int allergen_score) {
    unsigned int allergen_code = 1 << allergen; // shift the bit left allergen times.
    return (allergen_code & allergen_score) == allergen_code;
}

allergen_list_t get_allergens(int allergen_score) {
    allergen_list_t list = {
        .count = 0,
        .allergens = { false }
    };
    for (allergen_t i = 0; i < ALLERGEN_COUNT; i++) {
        if (is_allergic_to(i, allergen_score)) {
            list.allergens[i] = true;
            list.count++;
        }
    }
    return list;
}