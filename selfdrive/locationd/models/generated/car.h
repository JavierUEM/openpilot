#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_2771274575233247039);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_548323043716483702);
void car_H_mod_fun(double *state, double *out_8570486747549339471);
void car_f_fun(double *state, double dt, double *out_8933804598269306029);
void car_F_fun(double *state, double dt, double *out_7737514082128804716);
void car_h_25(double *state, double *unused, double *out_5287664803644509823);
void car_H_25(double *state, double *unused, double *out_3669831213457745278);
void car_h_24(double *state, double *unused, double *out_3224452809064638417);
void car_H_24(double *state, double *unused, double *out_1492616789850595305);
void car_h_30(double *state, double *unused, double *out_4294967845172020607);
void car_H_30(double *state, double *unused, double *out_1151498254950496651);
void car_h_26(double *state, double *unused, double *out_706705422488825038);
void car_H_26(double *state, double *unused, double *out_7411334532331801502);
void car_h_27(double *state, double *unused, double *out_8324450855088842508);
void car_H_27(double *state, double *unused, double *out_1072095816233446566);
void car_h_29(double *state, double *unused, double *out_3351457992270358172);
void car_H_29(double *state, double *unused, double *out_641266910636104467);
void car_h_28(double *state, double *unused, double *out_3926498773807213496);
void car_H_28(double *state, double *unused, double *out_5723665927705635041);
void car_h_31(double *state, double *unused, double *out_2172893960604378502);
void car_H_31(double *state, double *unused, double *out_3639185251580784850);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}