/*
 * Copyright (C) 2007-2012 Allwinner Technology Co., Ltd.
 * modified: Martin.Ostertag@gmx.de in 2015
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef _SUNXI_DISP_H_
#define _SUNXI_DISP_H_

typedef struct {
	__u32 lcd_x;
	__u32 lcd_y;
	__u32 lcd_dclk_freq;
	__u32 lcd_pwm_not_used;
	__u32 lcd_pwm_ch;
	__u32 lcd_pwm_freq;
	__u32 lcd_pwm_pol;
	__u32 lcd_srgb;
	__u32 lcd_swap;

	__u32 lcd_if; /* 0:hv(sync+de); 1:8080; 2:ttl; 3:lvds */

	__u32 lcd_uf;
	__u32 lcd_vt;
	__u32 lcd_ht;
	__u32 lcd_vbp;
	__u32 lcd_hbp;

	__u32 lcd_hv_if;
	__u32 lcd_hv_smode;
	__u32 lcd_hv_s888_if;
	__u32 lcd_hv_syuv_if;
	__u32 lcd_hv_vspw;
	__u32 lcd_hv_hspw;
	__u32 lcd_hv_lde_used;
	__u32 lcd_hv_lde_iovalue;

	__u32 lcd_ttl_stvh;
	__u32 lcd_ttl_stvdl;
	__u32 lcd_ttl_stvdp;
	__u32 lcd_ttl_ckvt;
	__u32 lcd_ttl_ckvh;
	__u32 lcd_ttl_ckvd;
	__u32 lcd_ttl_oevt;
	__u32 lcd_ttl_oevh;
	__u32 lcd_ttl_oevd;
	__u32 lcd_ttl_sthh;
	__u32 lcd_ttl_sthd;
	__u32 lcd_ttl_oehh;
	__u32 lcd_ttl_oehd;
	__u32 lcd_ttl_revd;
	__u32 lcd_ttl_datarate;
	__u32 lcd_ttl_revsel;
	__u32 lcd_ttl_datainv_en;
	__u32 lcd_ttl_datainv_sel;

	__u32 lcd_lvds_ch; /*  0: single channel; 1:dual channel */
	__u32 lcd_lvds_mode; /*  0:NS mode; 1:JEIDA mode */
	__u32 lcd_lvds_bitwidth; /*  0:24bit; 1:18bit */
	__u32 lcd_lvds_io_cross; /*  0:normal; 1:pn cross */

	/*
	 * 0:18bit;
	 * 1:16bit mode0;
	 * 2:16bit mode1;
	 * 3:16bit mode2;
	 * 4:16bit mode3;
	 * 5:9bit;
	 * 6:8bit 256K;
	 * 7:8bit 65K
	 */
	__u32 lcd_cpu_if;
	__u32 lcd_cpu_da;
	__u32 lcd_frm;

	__u32 lcd_io_cfg0;
	__u32 lcd_io_cfg1;
	__u32 lcd_io_strength;

	__u32 lcd_gamma_correction_en;
	__u32 lcd_gamma_tbl[256];

	__u32 lcd_hv_srgb_seq0;
	__u32 lcd_hv_srgb_seq1;
	__u32 lcd_hv_syuv_seq;
	__u32 lcd_hv_syuv_fdly;

	__u32 port_index;
	__u32 start_delay; /* not need to config for user */
	__u32 tcon_index; /* not need to config for user */
} __panel_para_t;

typedef struct {
	__u32 base_lcdc0;
	__u32 base_lcdc1;
	__u32 base_pioc;
	__u32 base_ccmu;
	__u32 base_pwm;
} __reg_bases_t;

typedef void (*LCD_FUNC) (__u32 sel);
typedef struct lcd_function {
	LCD_FUNC func;
	__u32 delay; /* ms */
} __lcd_function_t;

typedef struct lcd_flow {
	__lcd_function_t func[5];
	__u32 func_num;
} __lcd_flow_t;

typedef struct {
	void (*cfg_panel_info) (__panel_para_t *info);
	 __s32(*cfg_open_flow) (__u32 sel);
	 __s32(*cfg_close_flow) (__u32 sel);
	 __s32(*lcd_user_defined_func) (__u32 sel, __u32 para1, __u32 para2,
					__u32 para3);
} __lcd_panel_fun_t;

typedef struct {
	__s32(*hdmi_wait_edid) (void);
	__s32(*Hdmi_open) (void);
	__s32(*Hdmi_close) (void);
	__s32(*hdmi_set_mode) (__disp_tv_mode_t mode);
	__s32(*hdmi_set_videomode) (const struct __disp_video_timing *mode);
	__s32(*hdmi_mode_support) (__disp_tv_mode_t mode);
	__s32(*hdmi_get_video_timing) (__disp_tv_mode_t mode,
				struct __disp_video_timing *video_timing);
	__s32(*hdmi_get_HPD_status) (void);
	__s32(*hdmi_set_pll) (__u32 pll, __u32 clk);
} __disp_hdmi_func;

#endif

