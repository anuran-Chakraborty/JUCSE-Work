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
static const char *ng0 = "D:/VLSILab/Anuran/assgn3/twotofourdecoder4.vhd";



static void work_a_2107415817_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;

LAB0:    xsi_set_current_line(45, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t1 = (t0 + 4531);
    t3 = 1;
    if (2U == 2U)
        goto LAB7;

LAB8:    t3 = 0;

LAB9:    if (t3 != 0)
        goto LAB5;

LAB6:    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t1 = (t0 + 4537);
    t3 = 1;
    if (2U == 2U)
        goto LAB15;

LAB16:    t3 = 0;

LAB17:    if (t3 != 0)
        goto LAB13;

LAB14:    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t1 = (t0 + 4543);
    t3 = 1;
    if (2U == 2U)
        goto LAB23;

LAB24:    t3 = 0;

LAB25:    if (t3 != 0)
        goto LAB21;

LAB22:    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t1 = (t0 + 4549);
    t3 = 1;
    if (2U == 2U)
        goto LAB31;

LAB32:    t3 = 0;

LAB33:    if (t3 != 0)
        goto LAB29;

LAB30:
LAB3:    t1 = (t0 + 2832);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(46, ng0);
    t1 = (t0 + 4527);
    t6 = (t0 + 2912);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 4U);
    xsi_driver_first_trans_fast_port(t6);
    goto LAB3;

LAB5:    xsi_set_current_line(48, ng0);
    t8 = (t0 + 4533);
    t10 = (t0 + 2912);
    t12 = (t10 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t8, 4U);
    xsi_driver_first_trans_fast_port(t10);
    goto LAB3;

LAB7:    t11 = 0;

LAB10:    if (t11 < 2U)
        goto LAB11;
    else
        goto LAB9;

LAB11:    t6 = (t2 + t11);
    t7 = (t1 + t11);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB8;

LAB12:    t11 = (t11 + 1);
    goto LAB10;

LAB13:    xsi_set_current_line(50, ng0);
    t8 = (t0 + 4539);
    t10 = (t0 + 2912);
    t12 = (t10 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t8, 4U);
    xsi_driver_first_trans_fast_port(t10);
    goto LAB3;

LAB15:    t11 = 0;

LAB18:    if (t11 < 2U)
        goto LAB19;
    else
        goto LAB17;

LAB19:    t6 = (t2 + t11);
    t7 = (t1 + t11);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB16;

LAB20:    t11 = (t11 + 1);
    goto LAB18;

LAB21:    xsi_set_current_line(52, ng0);
    t8 = (t0 + 4545);
    t10 = (t0 + 2912);
    t12 = (t10 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t8, 4U);
    xsi_driver_first_trans_fast_port(t10);
    goto LAB3;

LAB23:    t11 = 0;

LAB26:    if (t11 < 2U)
        goto LAB27;
    else
        goto LAB25;

LAB27:    t6 = (t2 + t11);
    t7 = (t1 + t11);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB24;

LAB28:    t11 = (t11 + 1);
    goto LAB26;

LAB29:    xsi_set_current_line(54, ng0);
    t8 = (t0 + 4551);
    t10 = (t0 + 2912);
    t12 = (t10 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t8, 4U);
    xsi_driver_first_trans_fast_port(t10);
    goto LAB3;

LAB31:    t11 = 0;

LAB34:    if (t11 < 2U)
        goto LAB35;
    else
        goto LAB33;

LAB35:    t6 = (t2 + t11);
    t7 = (t1 + t11);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB32;

LAB36:    t11 = (t11 + 1);
    goto LAB34;

}


extern void work_a_2107415817_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2107415817_3212880686_p_0};
	xsi_register_didat("work_a_2107415817_3212880686", "isim/twotofourdecoder4_isim_beh.exe.sim/work/a_2107415817_3212880686.didat");
	xsi_register_executes(pe);
}
