

#ifndef M_4D_HPP_
#define M_4D_HPP_
#include <eigen2/Eigen/Core>
#include <math.h>

Eigen::Matrix4d M_4D(Eigen::Vector4d x) /* x denoted the four joint positions */
{

Eigen::Matrix4d M;

M(0,0) = ((((((((((((((((((((((((((((((((((((0.0141 * sin(2.0 * x[1] + x[2]) -
0.0411 * cos(2.0 * x[1] + x[3])) - 0.00332 * sin((2.0 * x[1] - x[2]) - x[3]))
- 0.0083 * sin(2.0 * x[1] + x[3])) - 0.00166 * sin(2.0 * x[2] + x[3])) -
0.00447 * cos((2.0 * x[1] + x[2]) + 2.0 * x[3])) + 0.00274 * cos(2.0 * x[1]
- 2.0 * x[2])) - 0.0411 * cos(2.0 * x[1] - x[3])) - 0.00671 * cos(2.0 * x[1]
- 2.0 * x[3])) + 0.00223 * cos(2.0 * x[2] - 2.0 * x[3])) + 0.0141 * sin(2.0 *
x[1] - x[2])) + 0.0083 * sin(2.0 * x[1] - x[3])) + 0.0012 * sin(2.0 * x[1] -
2.0 * x[3])) + 0.00166 * sin(2.0 * x[2] - x[3])) - 0.294 * cos(2.0 * x[1]))
- 0.00549 * cos(2.0 * x[2])) - 0.00447 * cos(2.0 * x[3])) - 0.00447 * cos
((2.0 * x[1] - x[2]) + 2.0 * x[3])) - 0.00111 * cos((2.0 * x[1] + 2.0 * x[2])
- 2.0 * x[3])) - 0.00111 * cos((2.0 * x[1] - 2.0 * x[2]) + 2.0 * x[3])) -
0.0208 * cos((2.0 * x[1] + x[2]) + x[3])) - 0.00332 * sin((2.0 * x[1] + x[2])
+ x[3])) + 0.0791 * cos(x[3])) + 0.0207 * cos((2.0 * x[1] + x[2]) - x[3])) -
0.0207 * cos((2.0 * x[1] - x[2]) + x[3])) + 0.00447 * cos
((2.0 * x[1] + x[2]) - 2.0 * x[3])) + 0.00274 * cos(2.0 *
x[1] + 2.0 * x[2])) - 0.00671 * cos(2.0 * x[1] + 2.0 * x[3])) + 0.00223 *
cos(2.0 * x[2] + 2.0 * x[3])) + 0.0299 * sin(x[3])) - 0.00331 *
sin((2.0 * x[1] + x[2]) - x[3])) - 0.00331 * sin((2.0 * x[1] -
x[2]) + x[3])) - 0.0012 * sin(2.0 * x[1] + 2.0 * x[3])) + 0.0208 * cos((2.0 *
x[1] - x[2]) - x[3])) + 0.00447 * cos((2.0 * x[1] - x[2]) - 2.0 * x[3])) -
0.00111 * cos((2.0 * x[1] + 2.0 * x[2]) + 2.0 * x[3])) - 0.00111 *
cos((2.0 * x[1] - 2.0 * x[2]) - 2.0 * x[3])) + 0.438;

M(0,1) = (((((((((((((((((((((((0.0208 * cos((x[1] + x[2]) + x[3]) + 0.00332 *
sin((x[1] + x[2]) + x[3])) - 0.0207 * cos((x[1] + x[2]) - x[3])) - 0.0207 *
cos((x[1] - x[2]) + x[3])) - 0.00447 * cos((x[1] + x[2]) - 2.0 * x[3])) -
0.00549 * cos(x[1] + 2.0 * x[2])) + 0.00331 * sin((x[1] + x[2]) - x[3])) -
0.00331 * sin((x[1] - x[2]) + x[3])) + 0.00166 * sin((x[1] - 2.0 * x[2]) +
x[3])) + 0.0208 * cos((x[1] - x[2]) - x[3])) + 0.00447 * cos((x[1] - x[2]) -
2.0 * x[3])) + 0.00223 * cos((x[1] + 2.0 * x[2]) + 2.0 * x[3])) - 0.00223 *
cos((x[1] - 2.0 * x[2]) - 2.0 * x[3])) - 0.00332 * sin((x[1]
- x[2]) - x[3])) - 0.00166 * sin((x[1] - 2.0 * x[2]) - x[3])) - 0.0141 * sin
(x[1] + x[2])) + 0.00447 * cos((x[1] + x[2]) + 2.0 * x[3])) +
0.00549 * cos(x[1] - 2.0 * x[2])) - 0.00166 * sin((x[1] + 2.0 *
x[2]) + x[3])) + 0.0141 * sin(x[1] - x[2])) + 0.00273 * cos(x[1])) - 0.00447
* cos((x[1] - x[2]) + 2.0 * x[3])) + 0.00223 * cos((x[1] + 2.0 * x[2])
- 2.0 * x[3])) - 0.00223 * cos((x[1] - 2.0 * x[2]) + 2.0 * x[3])) +
0.00166 * sin((x[1] + 2.0 * x[2]) - x[3]);

M(0,2) = (((((((((((((((((((((0.0207 * cos((x[1] + x[2]) - x[3]) - 0.00332 * sin
((x[1] + x[2]) + x[3])) - 0.0208 * cos((x[1] + x[2]) + x[3])) - 0.0207 * cos
((x[1] - x[2]) + x[3])) + 0.00447 * cos((x[1] + x[2])
- 2.0 * x[3])) - 0.00895 * cos(x[1] + 2.0 * x[3])) - 0.00331 * sin((x[1] +
x[2]) - x[3])) - 0.00331 * sin((x[1] - x[2]) + x[3])) - 0.0016 * sin(x[1] +
2.0 * x[3])) + 0.0208 * cos((x[1] - x[2]) - x[3])) + 0.00447 * cos((x[1] -
x[2]) - 2.0 * x[3])) - 0.00332 * sin((x[1] - x[2]) - x[3])) - 0.00163 * cos
(x[1] + x[3])) + 0.0141 * sin(x[1] + x[2])) + 0.00667 * sin
(x[1] + x[3])) - 0.00447 * cos((x[1] + x[2]) + 2.0 * x[3])) -
0.00163 * cos(x[1] - x[3])) - 0.00895 * cos(x[1] - 2.0 * x[3])) +
0.0141 * sin(x[1] - x[2])) - 0.00667 * sin(x[1] - x[3])) + 0.0016 *
sin(x[1] - 2.0 * x[3])) + 0.0265 * cos(x[1])) - 0.00447 * cos((x[1] -
x[2]) + 2.0 * x[3]);

M(0,3) = ((((((((0.0199 * cos((x[1] - x[2]) + x[3]) - 0.00665 * sin((x[1] + x[2])
+ x[3])) - 0.0199 * cos((x[1] + x[2]) - x[3])) - 0.0199 * cos((x[1] + x[2])
+ x[3])) + 0.00665 * sin((x[1] + x[2]) - x[3])) + 0.00665 * sin((x[1] - x[2])
+ x[3])) + 0.0199 * cos((x[1] - x[2]) - x[3])) - 0.00665 * sin((x
[1] - x[2]) - x[3])) - 0.0203 * cos(x[1] + x[2])) + 0.0203 * cos(x
[1] - x[2]);

M(1,0) = M(0,1);

M(1,1) = ((((((((0.00333 * sin(2.0 * x[2] + x[3]) - 0.00447 * cos(2.0 * x[2] -
2.0 * x[3])) - 0.00333 * sin(2.0 * x[2] - x[3])) + 0.0109 * cos(2.0 * x[2]))
+ 0.00895 * cos(2.0 * x[3])) + 0.0016 * sin(2.0 * x[3])) + 0.161 *
cos(x[3])) - 0.00447 * cos(2.0 * x[2] + 2.0 * x[3])) + 0.0465 * sin
(x[3])) + 0.63;

M(1,2) = (((((((0.00895 * cos(x[2] + 2.0 * x[3]) + 0.0016 * sin(x[2] + 2.0 * x[3]))
+ 0.0416 * cos(x[2] + x[3])) + 0.00664 * sin(x[2] + x[3])) -
0.0415 * cos(x[2] - x[3])) - 0.00895 * cos(x[2] - 2.0 * x[3])) +
0.00663 * sin(x[2] - x[3])) + 0.0016 * sin(x[2] - 2.0 * x[3])) -
0.0282 * sin(x[2]);

M(1,3) = (((0.0399 * cos(x[2] + x[3]) + 0.0133 * sin(x[2] + x[3])) + 0.0399 *
cos(x[2] - x[3])) - 0.0133 * sin(x[2] - x[3])) + 0.0407 * cos(x[2]);

M(2,0) = M(0,2);

M(2,1) = M(1,2);

M(2,2) = (((0.0133 * sin(x[3]) - 0.0032 * sin(2.0 * x[3])) - 0.00326 * cos(x[3]))
- 0.0179 * cos(2.0 * x[3])) + 0.0265;

M(2,3) = 0.0;

M(3,0) = M(0,3);

M(3,1) = M(1,3);

M(3,2) = M(2,3);

M(3,3) = 0.0407;

return M;

}
