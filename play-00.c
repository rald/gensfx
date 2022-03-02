// play.c
// C#->k D#->l F#->n G#->o/h A#->i

#include <stdio.h>
int main() {
  float f; /* note frequency */
  char c; /* "cdefgab" for notes or "pr" for pause */
  int d, o; /* d = duration, o = octave */
  while (scanf("%d%c%d ", &d, &c, &o) > 0) {
    /* convert note to lowercase */
    c &= 31;
    /* c>>4 is 0 for CDEFGAB and 1 for "PR" */
    /* so, for pauses f would be zero, for notes - 55 */
    f = !(c >> 4) * 55;
    /* a trick we used in Nokia Composer post to conver note letter to note index */
    c = (c * 8 / 5 + 8) % 12 + o * 12 - 22;
    /* Note `x` frequency is 2^(x/12), or (2^(1/12))^x */
    while (c--) {
      f *= 1.0595; /* 1.0595 is 2^(1/12) */
    }
    /* Play sawtooth wave for the given duration with given pitch */
    for (d = 16e3 / d; d--; putchar(d * f * .032));
  }
}
