#include "correction.h"

int correct(int pix)
{
    int corrected_pix = 0;
    if (pix > 255) {
        corrected_pix = 255;
    } else if (pix < 0) {
        corrected_pix = 0;
    } else {
        corrected_pix = pix;
    }
    return corrected_pix;
}
