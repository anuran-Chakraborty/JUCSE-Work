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
static const char *ng0 = "D:/VLSILab/Anuran/assgn3/twotofourdecoder3.vhd";
extern char *IEEE_P_2592010699;



static void work_a_3824683178_3212880686_p_0(char *t0)
{
    char t6[16];
    char *t1;
    char *t2;
    char *t3;
    unsigned char t4;
    char *t5;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    int t11;
    char *t12;
    int t14;
    char *t15;
    int t17;
    char *t18;
    int t20;
    char *t21;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;

LAB0:    t1 = (t0 + 2512U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(42, ng0);
    t2 = (t0 + 1032U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t2 = (t0 + 1192U);
    t5 = *((char **)t2);
    t7 = ((IEEE_P_2592010699) + 4024);
    t8 = (t0 + 4472U);
    t2 = xsi_base_array_concat(t2, t6, t7, (char)99, t4, (char)97, t5, t8, (char)101);
    t9 = (t0 + 4515);
    t11 = xsi_mem_cmp(t9, t2, 3U);
    if (t11 == 1)
        goto LAB5;

LAB10:    t12 = (t0 + 4518);
    t14 = xsi_mem_cmp(t12, t2, 3U);
    if (t14 == 1)
        goto LAB6;

LAB11:    t15 = (t0 + 4521);
    t17 = xsi_mem_cmp(t15, t2, 3U);
    if (t17 == 1)
        goto LAB7;

LAB12:    t18 = (t0 + 4524);
    t20 = xsi_mem_cmp(t18, t2, 3U);
    if (t20 == 1)
        goto LAB8;

LAB13:
LAB9:    xsi_set_current_line(43, ng0);
    t2 = (t0 + 4543);
    t5 = (t0 + 2912);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 4U);
    xsi_driver_first_trans_fast_port(t5);

LAB4:    xsi_set_current_line(42, ng0);

LAB17:    t2 = (t0 + 2832);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB18;

LAB1:    return;
LAB5:    xsi_set_current_line(43, ng0);
    t21 = (t0 + 4527);
    t23 = (t0 + 2912);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    memcpy(t27, t21, 4U);
    xsi_driver_first_trans_fast_port(t23);
    goto LAB4;

LAB6:    xsi_set_current_line(43, ng0);
    t2 = (t0 + 4531);
    t5 = (t0 + 2912);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 4U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB4;

LAB7:    xsi_set_current_line(43, ng0);
    t2 = (t0 + 4535);
    t5 = (t0 + 2912);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 4U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB4;

LAB8:    xsi_set_current_line(43, ng0);
    t2 = (t0 + 4539);
    t5 = (t0 + 2912);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 4U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB4;

LAB14:;
LAB15:    t3 = (t0 + 2832);
    *((int *)t3) = 0;
    goto LAB2;

LAB16:    goto LAB15;

LAB18:    goto LAB16;

}


extern void work_a_3824683178_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3824683178_3212880686_p_0};
	xsi_register_didat("work_a_3824683178_3212880686", "isim/twotofourdecoder3_isim_beh.exe.sim/work/a_3824683178_3212880686.didat");
	xsi_register_executes(pe);
}
