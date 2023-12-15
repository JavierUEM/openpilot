#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_2771274575233247039) {
   out_2771274575233247039[0] = delta_x[0] + nom_x[0];
   out_2771274575233247039[1] = delta_x[1] + nom_x[1];
   out_2771274575233247039[2] = delta_x[2] + nom_x[2];
   out_2771274575233247039[3] = delta_x[3] + nom_x[3];
   out_2771274575233247039[4] = delta_x[4] + nom_x[4];
   out_2771274575233247039[5] = delta_x[5] + nom_x[5];
   out_2771274575233247039[6] = delta_x[6] + nom_x[6];
   out_2771274575233247039[7] = delta_x[7] + nom_x[7];
   out_2771274575233247039[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_548323043716483702) {
   out_548323043716483702[0] = -nom_x[0] + true_x[0];
   out_548323043716483702[1] = -nom_x[1] + true_x[1];
   out_548323043716483702[2] = -nom_x[2] + true_x[2];
   out_548323043716483702[3] = -nom_x[3] + true_x[3];
   out_548323043716483702[4] = -nom_x[4] + true_x[4];
   out_548323043716483702[5] = -nom_x[5] + true_x[5];
   out_548323043716483702[6] = -nom_x[6] + true_x[6];
   out_548323043716483702[7] = -nom_x[7] + true_x[7];
   out_548323043716483702[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_8570486747549339471) {
   out_8570486747549339471[0] = 1.0;
   out_8570486747549339471[1] = 0;
   out_8570486747549339471[2] = 0;
   out_8570486747549339471[3] = 0;
   out_8570486747549339471[4] = 0;
   out_8570486747549339471[5] = 0;
   out_8570486747549339471[6] = 0;
   out_8570486747549339471[7] = 0;
   out_8570486747549339471[8] = 0;
   out_8570486747549339471[9] = 0;
   out_8570486747549339471[10] = 1.0;
   out_8570486747549339471[11] = 0;
   out_8570486747549339471[12] = 0;
   out_8570486747549339471[13] = 0;
   out_8570486747549339471[14] = 0;
   out_8570486747549339471[15] = 0;
   out_8570486747549339471[16] = 0;
   out_8570486747549339471[17] = 0;
   out_8570486747549339471[18] = 0;
   out_8570486747549339471[19] = 0;
   out_8570486747549339471[20] = 1.0;
   out_8570486747549339471[21] = 0;
   out_8570486747549339471[22] = 0;
   out_8570486747549339471[23] = 0;
   out_8570486747549339471[24] = 0;
   out_8570486747549339471[25] = 0;
   out_8570486747549339471[26] = 0;
   out_8570486747549339471[27] = 0;
   out_8570486747549339471[28] = 0;
   out_8570486747549339471[29] = 0;
   out_8570486747549339471[30] = 1.0;
   out_8570486747549339471[31] = 0;
   out_8570486747549339471[32] = 0;
   out_8570486747549339471[33] = 0;
   out_8570486747549339471[34] = 0;
   out_8570486747549339471[35] = 0;
   out_8570486747549339471[36] = 0;
   out_8570486747549339471[37] = 0;
   out_8570486747549339471[38] = 0;
   out_8570486747549339471[39] = 0;
   out_8570486747549339471[40] = 1.0;
   out_8570486747549339471[41] = 0;
   out_8570486747549339471[42] = 0;
   out_8570486747549339471[43] = 0;
   out_8570486747549339471[44] = 0;
   out_8570486747549339471[45] = 0;
   out_8570486747549339471[46] = 0;
   out_8570486747549339471[47] = 0;
   out_8570486747549339471[48] = 0;
   out_8570486747549339471[49] = 0;
   out_8570486747549339471[50] = 1.0;
   out_8570486747549339471[51] = 0;
   out_8570486747549339471[52] = 0;
   out_8570486747549339471[53] = 0;
   out_8570486747549339471[54] = 0;
   out_8570486747549339471[55] = 0;
   out_8570486747549339471[56] = 0;
   out_8570486747549339471[57] = 0;
   out_8570486747549339471[58] = 0;
   out_8570486747549339471[59] = 0;
   out_8570486747549339471[60] = 1.0;
   out_8570486747549339471[61] = 0;
   out_8570486747549339471[62] = 0;
   out_8570486747549339471[63] = 0;
   out_8570486747549339471[64] = 0;
   out_8570486747549339471[65] = 0;
   out_8570486747549339471[66] = 0;
   out_8570486747549339471[67] = 0;
   out_8570486747549339471[68] = 0;
   out_8570486747549339471[69] = 0;
   out_8570486747549339471[70] = 1.0;
   out_8570486747549339471[71] = 0;
   out_8570486747549339471[72] = 0;
   out_8570486747549339471[73] = 0;
   out_8570486747549339471[74] = 0;
   out_8570486747549339471[75] = 0;
   out_8570486747549339471[76] = 0;
   out_8570486747549339471[77] = 0;
   out_8570486747549339471[78] = 0;
   out_8570486747549339471[79] = 0;
   out_8570486747549339471[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_8933804598269306029) {
   out_8933804598269306029[0] = state[0];
   out_8933804598269306029[1] = state[1];
   out_8933804598269306029[2] = state[2];
   out_8933804598269306029[3] = state[3];
   out_8933804598269306029[4] = state[4];
   out_8933804598269306029[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_8933804598269306029[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_8933804598269306029[7] = state[7];
   out_8933804598269306029[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7737514082128804716) {
   out_7737514082128804716[0] = 1;
   out_7737514082128804716[1] = 0;
   out_7737514082128804716[2] = 0;
   out_7737514082128804716[3] = 0;
   out_7737514082128804716[4] = 0;
   out_7737514082128804716[5] = 0;
   out_7737514082128804716[6] = 0;
   out_7737514082128804716[7] = 0;
   out_7737514082128804716[8] = 0;
   out_7737514082128804716[9] = 0;
   out_7737514082128804716[10] = 1;
   out_7737514082128804716[11] = 0;
   out_7737514082128804716[12] = 0;
   out_7737514082128804716[13] = 0;
   out_7737514082128804716[14] = 0;
   out_7737514082128804716[15] = 0;
   out_7737514082128804716[16] = 0;
   out_7737514082128804716[17] = 0;
   out_7737514082128804716[18] = 0;
   out_7737514082128804716[19] = 0;
   out_7737514082128804716[20] = 1;
   out_7737514082128804716[21] = 0;
   out_7737514082128804716[22] = 0;
   out_7737514082128804716[23] = 0;
   out_7737514082128804716[24] = 0;
   out_7737514082128804716[25] = 0;
   out_7737514082128804716[26] = 0;
   out_7737514082128804716[27] = 0;
   out_7737514082128804716[28] = 0;
   out_7737514082128804716[29] = 0;
   out_7737514082128804716[30] = 1;
   out_7737514082128804716[31] = 0;
   out_7737514082128804716[32] = 0;
   out_7737514082128804716[33] = 0;
   out_7737514082128804716[34] = 0;
   out_7737514082128804716[35] = 0;
   out_7737514082128804716[36] = 0;
   out_7737514082128804716[37] = 0;
   out_7737514082128804716[38] = 0;
   out_7737514082128804716[39] = 0;
   out_7737514082128804716[40] = 1;
   out_7737514082128804716[41] = 0;
   out_7737514082128804716[42] = 0;
   out_7737514082128804716[43] = 0;
   out_7737514082128804716[44] = 0;
   out_7737514082128804716[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7737514082128804716[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7737514082128804716[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7737514082128804716[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7737514082128804716[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7737514082128804716[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7737514082128804716[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7737514082128804716[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7737514082128804716[53] = -9.8000000000000007*dt;
   out_7737514082128804716[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7737514082128804716[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7737514082128804716[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7737514082128804716[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7737514082128804716[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7737514082128804716[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7737514082128804716[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7737514082128804716[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7737514082128804716[62] = 0;
   out_7737514082128804716[63] = 0;
   out_7737514082128804716[64] = 0;
   out_7737514082128804716[65] = 0;
   out_7737514082128804716[66] = 0;
   out_7737514082128804716[67] = 0;
   out_7737514082128804716[68] = 0;
   out_7737514082128804716[69] = 0;
   out_7737514082128804716[70] = 1;
   out_7737514082128804716[71] = 0;
   out_7737514082128804716[72] = 0;
   out_7737514082128804716[73] = 0;
   out_7737514082128804716[74] = 0;
   out_7737514082128804716[75] = 0;
   out_7737514082128804716[76] = 0;
   out_7737514082128804716[77] = 0;
   out_7737514082128804716[78] = 0;
   out_7737514082128804716[79] = 0;
   out_7737514082128804716[80] = 1;
}
void h_25(double *state, double *unused, double *out_5287664803644509823) {
   out_5287664803644509823[0] = state[6];
}
void H_25(double *state, double *unused, double *out_3669831213457745278) {
   out_3669831213457745278[0] = 0;
   out_3669831213457745278[1] = 0;
   out_3669831213457745278[2] = 0;
   out_3669831213457745278[3] = 0;
   out_3669831213457745278[4] = 0;
   out_3669831213457745278[5] = 0;
   out_3669831213457745278[6] = 1;
   out_3669831213457745278[7] = 0;
   out_3669831213457745278[8] = 0;
}
void h_24(double *state, double *unused, double *out_3224452809064638417) {
   out_3224452809064638417[0] = state[4];
   out_3224452809064638417[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1492616789850595305) {
   out_1492616789850595305[0] = 0;
   out_1492616789850595305[1] = 0;
   out_1492616789850595305[2] = 0;
   out_1492616789850595305[3] = 0;
   out_1492616789850595305[4] = 1;
   out_1492616789850595305[5] = 0;
   out_1492616789850595305[6] = 0;
   out_1492616789850595305[7] = 0;
   out_1492616789850595305[8] = 0;
   out_1492616789850595305[9] = 0;
   out_1492616789850595305[10] = 0;
   out_1492616789850595305[11] = 0;
   out_1492616789850595305[12] = 0;
   out_1492616789850595305[13] = 0;
   out_1492616789850595305[14] = 1;
   out_1492616789850595305[15] = 0;
   out_1492616789850595305[16] = 0;
   out_1492616789850595305[17] = 0;
}
void h_30(double *state, double *unused, double *out_4294967845172020607) {
   out_4294967845172020607[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1151498254950496651) {
   out_1151498254950496651[0] = 0;
   out_1151498254950496651[1] = 0;
   out_1151498254950496651[2] = 0;
   out_1151498254950496651[3] = 0;
   out_1151498254950496651[4] = 1;
   out_1151498254950496651[5] = 0;
   out_1151498254950496651[6] = 0;
   out_1151498254950496651[7] = 0;
   out_1151498254950496651[8] = 0;
}
void h_26(double *state, double *unused, double *out_706705422488825038) {
   out_706705422488825038[0] = state[7];
}
void H_26(double *state, double *unused, double *out_7411334532331801502) {
   out_7411334532331801502[0] = 0;
   out_7411334532331801502[1] = 0;
   out_7411334532331801502[2] = 0;
   out_7411334532331801502[3] = 0;
   out_7411334532331801502[4] = 0;
   out_7411334532331801502[5] = 0;
   out_7411334532331801502[6] = 0;
   out_7411334532331801502[7] = 1;
   out_7411334532331801502[8] = 0;
}
void h_27(double *state, double *unused, double *out_8324450855088842508) {
   out_8324450855088842508[0] = state[3];
}
void H_27(double *state, double *unused, double *out_1072095816233446566) {
   out_1072095816233446566[0] = 0;
   out_1072095816233446566[1] = 0;
   out_1072095816233446566[2] = 0;
   out_1072095816233446566[3] = 1;
   out_1072095816233446566[4] = 0;
   out_1072095816233446566[5] = 0;
   out_1072095816233446566[6] = 0;
   out_1072095816233446566[7] = 0;
   out_1072095816233446566[8] = 0;
}
void h_29(double *state, double *unused, double *out_3351457992270358172) {
   out_3351457992270358172[0] = state[1];
}
void H_29(double *state, double *unused, double *out_641266910636104467) {
   out_641266910636104467[0] = 0;
   out_641266910636104467[1] = 1;
   out_641266910636104467[2] = 0;
   out_641266910636104467[3] = 0;
   out_641266910636104467[4] = 0;
   out_641266910636104467[5] = 0;
   out_641266910636104467[6] = 0;
   out_641266910636104467[7] = 0;
   out_641266910636104467[8] = 0;
}
void h_28(double *state, double *unused, double *out_3926498773807213496) {
   out_3926498773807213496[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5723665927705635041) {
   out_5723665927705635041[0] = 1;
   out_5723665927705635041[1] = 0;
   out_5723665927705635041[2] = 0;
   out_5723665927705635041[3] = 0;
   out_5723665927705635041[4] = 0;
   out_5723665927705635041[5] = 0;
   out_5723665927705635041[6] = 0;
   out_5723665927705635041[7] = 0;
   out_5723665927705635041[8] = 0;
}
void h_31(double *state, double *unused, double *out_2172893960604378502) {
   out_2172893960604378502[0] = state[8];
}
void H_31(double *state, double *unused, double *out_3639185251580784850) {
   out_3639185251580784850[0] = 0;
   out_3639185251580784850[1] = 0;
   out_3639185251580784850[2] = 0;
   out_3639185251580784850[3] = 0;
   out_3639185251580784850[4] = 0;
   out_3639185251580784850[5] = 0;
   out_3639185251580784850[6] = 0;
   out_3639185251580784850[7] = 0;
   out_3639185251580784850[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_2771274575233247039) {
  err_fun(nom_x, delta_x, out_2771274575233247039);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_548323043716483702) {
  inv_err_fun(nom_x, true_x, out_548323043716483702);
}
void car_H_mod_fun(double *state, double *out_8570486747549339471) {
  H_mod_fun(state, out_8570486747549339471);
}
void car_f_fun(double *state, double dt, double *out_8933804598269306029) {
  f_fun(state,  dt, out_8933804598269306029);
}
void car_F_fun(double *state, double dt, double *out_7737514082128804716) {
  F_fun(state,  dt, out_7737514082128804716);
}
void car_h_25(double *state, double *unused, double *out_5287664803644509823) {
  h_25(state, unused, out_5287664803644509823);
}
void car_H_25(double *state, double *unused, double *out_3669831213457745278) {
  H_25(state, unused, out_3669831213457745278);
}
void car_h_24(double *state, double *unused, double *out_3224452809064638417) {
  h_24(state, unused, out_3224452809064638417);
}
void car_H_24(double *state, double *unused, double *out_1492616789850595305) {
  H_24(state, unused, out_1492616789850595305);
}
void car_h_30(double *state, double *unused, double *out_4294967845172020607) {
  h_30(state, unused, out_4294967845172020607);
}
void car_H_30(double *state, double *unused, double *out_1151498254950496651) {
  H_30(state, unused, out_1151498254950496651);
}
void car_h_26(double *state, double *unused, double *out_706705422488825038) {
  h_26(state, unused, out_706705422488825038);
}
void car_H_26(double *state, double *unused, double *out_7411334532331801502) {
  H_26(state, unused, out_7411334532331801502);
}
void car_h_27(double *state, double *unused, double *out_8324450855088842508) {
  h_27(state, unused, out_8324450855088842508);
}
void car_H_27(double *state, double *unused, double *out_1072095816233446566) {
  H_27(state, unused, out_1072095816233446566);
}
void car_h_29(double *state, double *unused, double *out_3351457992270358172) {
  h_29(state, unused, out_3351457992270358172);
}
void car_H_29(double *state, double *unused, double *out_641266910636104467) {
  H_29(state, unused, out_641266910636104467);
}
void car_h_28(double *state, double *unused, double *out_3926498773807213496) {
  h_28(state, unused, out_3926498773807213496);
}
void car_H_28(double *state, double *unused, double *out_5723665927705635041) {
  H_28(state, unused, out_5723665927705635041);
}
void car_h_31(double *state, double *unused, double *out_2172893960604378502) {
  h_31(state, unused, out_2172893960604378502);
}
void car_H_31(double *state, double *unused, double *out_3639185251580784850) {
  H_31(state, unused, out_3639185251580784850);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
