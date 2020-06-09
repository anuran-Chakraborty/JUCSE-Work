/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
extern char *STD_STANDARD;
static const char *ng1 = "D:/VLSILab/Anuran/assgn4/fbrcaprocess.vhd";



void work_a_1522476185_3212880686_sub_2198929628_3057020925(char *t0, char *t1, unsigned char t2, unsigned char t3, char *t4, char *t5)
{
    char t7[24];
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned char t12;
    char *t13;

LAB0:    t8 = (t7 + 4U);
    *((unsigned char *)t8) = t2;
    t9 = (t7 + 5U);
    *((unsigned char *)t9) = t3;
    t10 = (t7 + 6U);
    *((char **)t10) = t4;
    t11 = (t7 + 14U);
    *((char **)t11) = t5;
    t12 = (t2 ^ t3);
    t13 = (t4 + 0);
    *((unsigned char *)t13) = t12;
    if (t2 == 1)
        goto LAB2;

LAB3:    t12 = (unsigned char)0;

LAB4:    t13 = (t5 + 0);
    *((unsigned char *)t13) = t12;

LAB1:    return;
LAB2:    t12 = t3;
    goto LAB4;

}

void work_a_1522476185_3212880686_sub_838273568_3057020925(char *t0, char *t1, unsigned char t2, unsigned char t3, unsigned char t4, char *t5, char *t6)
{
    char t7[488];
    char t8[24];
    char t12[8];
    char t18[8];
    char t24[8];
    char t30[8];
    char *t9;
    char *t10;
    char *t11;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    unsigned char t42;
    unsigned char t43;
    unsigned char t44;

LAB0:    t9 = (t7 + 4U);
    t10 = ((STD_STANDARD) + 96);
    t11 = (t9 + 88U);
    *((char **)t11) = t10;
    t13 = (t9 + 56U);
    *((char **)t13) = t12;
    xsi_type_set_default_value(t10, t12, 0);
    t14 = (t9 + 80U);
    *((unsigned int *)t14) = 1U;
    t15 = (t7 + 124U);
    t16 = ((STD_STANDARD) + 96);
    t17 = (t15 + 88U);
    *((char **)t17) = t16;
    t19 = (t15 + 56U);
    *((char **)t19) = t18;
    xsi_type_set_default_value(t16, t18, 0);
    t20 = (t15 + 80U);
    *((unsigned int *)t20) = 1U;
    t21 = (t7 + 244U);
    t22 = ((STD_STANDARD) + 96);
    t23 = (t21 + 88U);
    *((char **)t23) = t22;
    t25 = (t21 + 56U);
    *((char **)t25) = t24;
    xsi_type_set_default_value(t22, t24, 0);
    t26 = (t21 + 80U);
    *((unsigned int *)t26) = 1U;
    t27 = (t7 + 364U);
    t28 = ((STD_STANDARD) + 96);
    t29 = (t27 + 88U);
    *((char **)t29) = t28;
    t31 = (t27 + 56U);
    *((char **)t31) = t30;
    xsi_type_set_default_value(t28, t30, 0);
    t32 = (t27 + 80U);
    *((unsigned int *)t32) = 1U;
    t33 = (t8 + 4U);
    *((unsigned char *)t33) = t2;
    t34 = (t8 + 5U);
    *((unsigned char *)t34) = t3;
    t35 = (t8 + 6U);
    *((unsigned char *)t35) = t4;
    t36 = (t8 + 7U);
    *((char **)t36) = t5;
    t37 = (t8 + 15U);
    *((char **)t37) = t6;
    t38 = (t9 + 56U);
    t39 = *((char **)t38);
    t38 = (t39 + 0);
    t40 = (t21 + 56U);
    t41 = *((char **)t40);
    t40 = (t41 + 0);
    work_a_1522476185_3212880686_sub_2198929628_3057020925(t0, t1, t3, t4, t38, t40);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t42 = *((unsigned char *)t11);
    t10 = (t15 + 56U);
    t13 = *((char **)t10);
    t10 = (t13 + 0);
    t14 = (t27 + 56U);
    t16 = *((char **)t14);
    t14 = (t16 + 0);
    work_a_1522476185_3212880686_sub_2198929628_3057020925(t0, t1, t2, t42, t10, t14);
    t10 = (t15 + 56U);
    t11 = *((char **)t10);
    t42 = *((unsigned char *)t11);
    t10 = (t5 + 0);
    *((unsigned char *)t10) = t42;
    t10 = (t21 + 56U);
    t11 = *((char **)t10);
    t43 = *((unsigned char *)t11);
    if (t43 == 1)
        goto LAB2;

LAB3:    t10 = (t27 + 56U);
    t13 = *((char **)t10);
    t44 = *((unsigned char *)t13);
    t42 = t44;

LAB4:    t10 = (t6 + 0);
    *((unsigned char *)t10) = t42;

LAB1:    return;
LAB2:    t42 = (unsigned char)1;
    goto LAB4;

}

static void work_a_1522476185_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    int t9;
    char *t10;
    char *t11;
    int t12;
    int t13;
    char *t14;
    char *t15;
    char *t16;
    int t17;
    int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    unsigned char t23;
    char *t24;
    char *t25;
    int t26;
    int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    unsigned char t32;
    char *t33;
    char *t34;
    int t35;
    int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;
    char *t42;
    int t43;
    int t44;
    int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    char *t49;

LAB0:    xsi_set_current_line(65, ng1);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 1968U);
    t4 = *((char **)t1);
    t5 = (0 - 4);
    t6 = (t5 * -1);
    t7 = (1U * t6);
    t8 = (0 + t7);
    t1 = (t4 + t8);
    *((unsigned char *)t1) = t3;
    xsi_set_current_line(67, ng1);
    t1 = (t0 + 5378);
    *((int *)t1) = 0;
    t2 = (t0 + 5382);
    *((int *)t2) = 3;
    t5 = 0;
    t9 = 3;

LAB2:    if (t5 <= t9)
        goto LAB3;

LAB5:    xsi_set_current_line(70, ng1);
    t1 = (t0 + 2088U);
    t2 = *((char **)t1);
    t1 = (t0 + 3488);
    t4 = (t1 + 56U);
    t10 = *((char **)t4);
    t11 = (t10 + 56U);
    t14 = *((char **)t11);
    memcpy(t14, t2, 4U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(71, ng1);
    t1 = (t0 + 1968U);
    t2 = *((char **)t1);
    t5 = (4 - 4);
    t6 = (t5 * -1);
    t7 = (1U * t6);
    t8 = (0 + t7);
    t1 = (t2 + t8);
    t3 = *((unsigned char *)t1);
    t4 = (t0 + 3552);
    t10 = (t4 + 56U);
    t11 = *((char **)t10);
    t14 = (t11 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = t3;
    xsi_driver_first_trans_fast_port(t4);
    t1 = (t0 + 3392);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(68, ng1);
    t4 = (t0 + 2880);
    t10 = (t0 + 1032U);
    t11 = *((char **)t10);
    t10 = (t0 + 5378);
    t12 = *((int *)t10);
    t13 = (t12 - 3);
    t6 = (t13 * -1);
    xsi_vhdl_check_range_of_index(3, 0, -1, *((int *)t10));
    t7 = (1U * t6);
    t8 = (0 + t7);
    t14 = (t11 + t8);
    t3 = *((unsigned char *)t14);
    t15 = (t0 + 1192U);
    t16 = *((char **)t15);
    t15 = (t0 + 5378);
    t17 = *((int *)t15);
    t18 = (t17 - 3);
    t19 = (t18 * -1);
    xsi_vhdl_check_range_of_index(3, 0, -1, *((int *)t15));
    t20 = (1U * t19);
    t21 = (0 + t20);
    t22 = (t16 + t21);
    t23 = *((unsigned char *)t22);
    t24 = (t0 + 1968U);
    t25 = *((char **)t24);
    t24 = (t0 + 5378);
    t26 = *((int *)t24);
    t27 = (t26 - 4);
    t28 = (t27 * -1);
    xsi_vhdl_check_range_of_index(4, 0, -1, *((int *)t24));
    t29 = (1U * t28);
    t30 = (0 + t29);
    t31 = (t25 + t30);
    t32 = *((unsigned char *)t31);
    t33 = (t0 + 2088U);
    t34 = *((char **)t33);
    t33 = (t0 + 5378);
    t35 = *((int *)t33);
    t36 = (t35 - 3);
    t37 = (t36 * -1);
    xsi_vhdl_check_range_of_index(3, 0, -1, *((int *)t33));
    t38 = (1U * t37);
    t39 = (0 + t38);
    t40 = (t34 + t39);
    t41 = (t0 + 1968U);
    t42 = *((char **)t41);
    t41 = (t0 + 5378);
    t43 = *((int *)t41);
    t44 = (t43 + 1);
    t45 = (t44 - 4);
    t46 = (t45 * -1);
    xsi_vhdl_check_range_of_index(4, 0, -1, t44);
    t47 = (1U * t46);
    t48 = (0 + t47);
    t49 = (t42 + t48);
    work_a_1522476185_3212880686_sub_838273568_3057020925(t0, t4, t3, t23, t32, t40, t49);

LAB4:    t1 = (t0 + 5378);
    t5 = *((int *)t1);
    t2 = (t0 + 5382);
    t9 = *((int *)t2);
    if (t5 == t9)
        goto LAB5;

LAB6:    t12 = (t5 + 1);
    t5 = t12;
    t4 = (t0 + 5378);
    *((int *)t4) = t5;
    goto LAB2;

}


extern void work_a_1522476185_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1522476185_3212880686_p_0};
	static char *se[] = {(void *)work_a_1522476185_3212880686_sub_2198929628_3057020925,(void *)work_a_1522476185_3212880686_sub_838273568_3057020925};
	xsi_register_didat("work_a_1522476185_3212880686", "isim/fbrcaprocess_isim_beh.exe.sim/work/a_1522476185_3212880686.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
