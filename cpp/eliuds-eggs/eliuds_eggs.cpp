#include "eliuds_eggs.h"

namespace chicken_coop {

    int positions_to_quantity(int positions) {
        int quantity = 0;

        while (positions > 0) {
            if (positions % 2 == 1) {
                quantity++;
            }

            positions /= 2;
        }

        return quantity;
    }

}  // namespace chicken_coop
