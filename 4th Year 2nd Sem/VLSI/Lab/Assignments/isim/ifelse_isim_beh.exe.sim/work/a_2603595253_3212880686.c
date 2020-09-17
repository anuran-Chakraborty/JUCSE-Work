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
static const char *ng0 = "D:/JUCSE WORK/4th Year 2nd Sem/VLSI/Lab/Assignments/vivaa3.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_1605435078_503743352(char *, unsigned char , unsigned char );
unsigned char ieee_p_2592010699_sub_1690584930_503743352(char *, unsigned char );
unsigned char ieee_p_2592010699_sub_2507238156_503743352(char *, unsigned char , unsigned char );


static void work_a_2603595253_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    unsigned char t8;
    char *t9;
    unsigned char t10;
    unsigned char t11;
    unsigned char t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    unsigned char t17;

LAB0:    xsi_set_current_line(41, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 1192U);
    t4 = *((char **)t1);
    t5 = *((unsigned char *)t4);
    t6 = (t3 == t5);
    if (t6 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 1192U);
    t4 = *((char **)t1);
    t5 = *((unsigned char *)t4);
    t6 = (t3 > t5);
    if (t6 != 0)
        goto LAB5;

LAB6:    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 1192U);
    t4 = *((char **)t1);
    t5 = *((unsigned char *)t4);
    t6 = (t3 == t5);
    if (t6 != 0)
        goto LAB7;

LAB8:    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 1192U);
    t4 = *((char **)t1);
    t5 = *((unsigned char *)t4);
    t6 = (t3 < t5);
    if (t6 != 0)
        goto LAB9;

LAB10:
LAB3:    t1 = (t0 + 2832);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(42, ng0);
    t1 = (t0 + 1032U);
    t7 = *((char **)t1);
    t8 = *((unsigned char *)t7);
    t1 = (t0 + 1192U);
    t9 = *((char **)t1);
    t10 = *((unsigned char *)t9);
    t11 = ieee_p_2592010699_sub_2507238156_503743352(IEEE_P_2592010699, t8, t10);
    t12 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t11);
    t1 = (t0 + 2912);
    t13 = (t1 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    *((unsigned char *)t16) = t12;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB3;

LAB5:    xsi_set_current_line(44, ng0);
    t1 = (t0 + 1032U);
    t7 = *((char **)t1);
    t8 = *((unsigned char *)t7);
    t1 = (t0 + 2976);
    t9 = (t1 + 56U);
    t13 = *((char **)t9);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = t8;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(45, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 2912);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t9 = (t7 + 56U);
    t13 = *((char **)t9);
    *((unsigned char *)t13) = t3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB3;

LAB7:    xsi_set_current_line(47, ng0);
    t1 = (t0 + 1192U);
    t7 = *((char **)t1);
    t8 = *((unsigned char *)t7);
    t1 = (t0 + 2912);
    t9 = (t1 + 56U);
    t13 = *((char **)t9);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = t8;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB3;

LAB9:    xsi_set_current_line(49, ng0);
    t1 = (t0 + 1032U);
    t7 = *((char **)t1);
    t8 = *((unsigned char *)t7);
    t10 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t8);
    t1 = (t0 + 1192U);
    t9 = *((char **)t1);
    t11 = *((unsigned char *)t9);
    t12 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t11);
    t17 = ieee_p_2592010699_sub_1605435078_503743352(IEEE_P_2592010699, t10, t12);
    t1 = (t0 + 2912);
    t13 = (t1 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    *((unsigned char *)t16) = t17;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB3;

}


extern void work_a_2603595253_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2603595253_3212880686_p_0};
	xsi_register_didat("work_a_2603595253_3212880686", "isim/ifelse_isim_beh.exe.sim/work/a_2603595253_3212880686.didat");
	xsi_register_executes(pe);
}
