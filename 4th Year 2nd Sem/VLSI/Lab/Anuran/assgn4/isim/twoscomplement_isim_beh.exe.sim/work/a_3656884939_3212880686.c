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
static const char *ng0 = "D:/VLSILab/Anuran/assgn4/twoscomplement.vhd";



static void work_a_3656884939_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    int t4;
    char *t5;
    char *t6;
    unsigned char t7;
    unsigned char t8;
    char *t9;
    int t10;
    int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned char t16;
    unsigned char t17;
    char *t18;
    int t19;
    int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;

LAB0:    xsi_set_current_line(46, ng0);
    t1 = (t0 + 1608U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((unsigned char *)t1) = (unsigned char)0;
    xsi_set_current_line(47, ng0);
    t1 = (t0 + 4669);
    *((int *)t1) = 0;
    t2 = (t0 + 4673);
    *((int *)t2) = 7;
    t3 = 0;
    t4 = 7;

LAB2:    if (t3 <= t4)
        goto LAB3;

LAB5:    t1 = (t0 + 2912);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(49, ng0);
    t5 = (t0 + 1608U);
    t6 = *((char **)t5);
    t7 = *((unsigned char *)t6);
    t8 = (t7 == (unsigned char)1);
    if (t8 != 0)
        goto LAB6;

LAB8:    xsi_set_current_line(52, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t1 = (t0 + 4669);
    t10 = *((int *)t1);
    t11 = (t10 - 7);
    t12 = (t11 * -1);
    xsi_vhdl_check_range_of_index(7, 0, -1, *((int *)t1));
    t13 = (1U * t12);
    t14 = (0 + t13);
    t5 = (t2 + t14);
    t7 = *((unsigned char *)t5);
    t6 = (t0 + 4669);
    t19 = *((int *)t6);
    t20 = (t19 - 7);
    t21 = (t20 * -1);
    t22 = (1 * t21);
    t23 = (0U + t22);
    t9 = (t0 + 2992);
    t15 = (t9 + 56U);
    t18 = *((char **)t15);
    t24 = (t18 + 56U);
    t25 = *((char **)t24);
    *((unsigned char *)t25) = t7;
    xsi_driver_first_trans_delta(t9, t23, 1, 0LL);

LAB7:    xsi_set_current_line(54, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t1 = (t0 + 4669);
    t10 = *((int *)t1);
    t11 = (t10 - 7);
    t12 = (t11 * -1);
    xsi_vhdl_check_range_of_index(7, 0, -1, *((int *)t1));
    t13 = (1U * t12);
    t14 = (0 + t13);
    t5 = (t2 + t14);
    t7 = *((unsigned char *)t5);
    t8 = (t7 == (unsigned char)1);
    if (t8 != 0)
        goto LAB9;

LAB11:
LAB10:
LAB4:    t1 = (t0 + 4669);
    t3 = *((int *)t1);
    t2 = (t0 + 4673);
    t4 = *((int *)t2);
    if (t3 == t4)
        goto LAB5;

LAB12:    t10 = (t3 + 1);
    t3 = t10;
    t5 = (t0 + 4669);
    *((int *)t5) = t3;
    goto LAB2;

LAB6:    xsi_set_current_line(50, ng0);
    t5 = (t0 + 1032U);
    t9 = *((char **)t5);
    t5 = (t0 + 4669);
    t10 = *((int *)t5);
    t11 = (t10 - 7);
    t12 = (t11 * -1);
    xsi_vhdl_check_range_of_index(7, 0, -1, *((int *)t5));
    t13 = (1U * t12);
    t14 = (0 + t13);
    t15 = (t9 + t14);
    t16 = *((unsigned char *)t15);
    t17 = (!(t16));
    t18 = (t0 + 4669);
    t19 = *((int *)t18);
    t20 = (t19 - 7);
    t21 = (t20 * -1);
    t22 = (1 * t21);
    t23 = (0U + t22);
    t24 = (t0 + 2992);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    *((unsigned char *)t28) = t17;
    xsi_driver_first_trans_delta(t24, t23, 1, 0LL);
    goto LAB7;

LAB9:    xsi_set_current_line(55, ng0);
    t6 = (t0 + 1608U);
    t9 = *((char **)t6);
    t6 = (t9 + 0);
    *((unsigned char *)t6) = (unsigned char)1;
    goto LAB10;

}


extern void work_a_3656884939_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3656884939_3212880686_p_0};
	xsi_register_didat("work_a_3656884939_3212880686", "isim/twoscomplement_isim_beh.exe.sim/work/a_3656884939_3212880686.didat");
	xsi_register_executes(pe);
}
