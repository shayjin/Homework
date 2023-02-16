/*  Name:  Jay Shin                              */
/*  Date:  10/19/2020                            */
/*  Assignment:  APP B23-2                       */
/*  Seat: 00 Instructor: Brooke Morin 12:40-2:45 */
#include  <stdio.h>
#include  <math.h>
int main ( ){
int a, b, c ;
float w, x, y = 2, z ;
int e = 8, f = 0.50, g = 1, h = 10.999 ;
float q = 6, r = .75, s = 7, t = 9/4 ;
w = g / e -110 * f;     /* w = 0.00 */
printf("w = %f\n", w);
w += h;                 /* w = 10.00 */
printf("w = %f\n", w);
a = t + pow (g, q);     /* a = 3      */
printf("a = %d\n", a);
b = --w + t;            /* b = 11     */
printf("b = %d\n", b);
x = h % e++;            /* x = 2.0    */
printf("x = %f\n", x);
y = (e + w) * y;        /* y = 36.00 */
printf("y = %f\n", y);
c = (++s);              /* c = 8     */
printf("c = %d\n", c);
z = r * s + h / e + q;  /* z = 13.00  */
printf("z = %f\n", z);
h = pow (c,2);          /* h = 64    */
printf("h = %d\n", h);
}

