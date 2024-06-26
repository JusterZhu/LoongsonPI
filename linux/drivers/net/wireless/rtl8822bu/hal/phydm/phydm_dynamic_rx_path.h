/******************************************************************************
 *
 * Copyright(c) 2007 - 2017  Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * The full GNU General Public License is included in this distribution in the
 * file called LICENSE.
 *
 * Contact Information:
 * wlanfae <wlanfae@realtek.com>
 * Realtek Corporation, No. 2, Innovation Road II, Hsinchu Science Park,
 * Hsinchu 300, Taiwan.
 *
 * Larry Finger <Larry.Finger@lwfinger.net>
 *
 *****************************************************************************/

#ifndef	__PHYDMDYMICRXPATH_H__
#define    __PHYDMDYMICRXPATH_H__

#define DYNAMIC_RX_PATH_VERSION	"1.0"  /*2016.07.15  Dino */


#define	DRP_RSSI_TH	35

#define INIT_DRP_TIMMER		0
#define CANCEL_DRP_TIMMER		1
#define RELEASE_DRP_TIMMER		2

#if (RTL8822B_SUPPORT == 1)
struct drp_rtl8822b_struct {
	enum bb_path	path_judge;
	u16	path_a_cck_fa;
	u16	path_b_cck_fa;

};
#endif

#ifdef CONFIG_DYNAMIC_RX_PATH

enum drp_state {
	DRP_INIT_STATE				= 0,
	DRP_TRAINING_STATE_0	= 1,
	DRP_TRAINING_STATE_1		= 2,
	DRP_TRAINING_STATE_2		= 3,
	DRP_DECISION_STATE		= 4
};

enum adjustable_value {
	DRP_TRAINING_TIME		= 0,
	DRP_TRAINING_PERIOD	= 1,
	DRP_RSSI_THRESHOLD	= 2,
	DRP_FA_THRESHOLD		= 3,
	DRP_FA_DIFF_THRESHOLD = 4
};

struct _DYNAMIC_RX_PATH_ {
	u8			curr_rx_path;
	u8			drp_state;
	u16			training_time;
	u8			rssi_threshold;
	u32			fa_count_thresold;
	u32			fa_diff_threshold;
	u32			curr_cca_all_cnt_0;
	u32			curr_fa_all_cnt_0;
	u32			curr_cca_all_cnt_1;
	u32			curr_fa_all_cnt_1;
	u32			curr_cca_all_cnt_2;
	u32			curr_fa_all_cnt_2;
	u8			drp_skip_counter;
	u8			drp_period;
	u8			drp_init_finished;

#if (DM_ODM_SUPPORT_TYPE == ODM_WIN)
#if USE_WORKITEM
	RT_WORK_ITEM	phydm_dynamic_rx_path_workitem;
#endif
#endif
	struct phydm_timer_list		phydm_dynamic_rx_path_timer;

};



void phydm_process_phy_status_for_dynamic_rx_path(
	void			*dm_void,
	void			*phy_info_void,
	void			*pkt_info_void
);

void phydm_dynamic_rx_path(
	void			*dm_void
);

#if (DM_ODM_SUPPORT_TYPE == ODM_WIN)
void phydm_dynamic_rx_path_callback(
	struct phydm_timer_list		*timer
);

void phydm_dynamic_rx_path_workitem_callback(
	void		*context
);

#else if (DM_ODM_SUPPORT_TYPE == ODM_CE)

void phydm_dynamic_rx_path_callback(
	void *function_context
);

#endif

void phydm_dynamic_rx_path_timers(
	void		*dm_void,
	u8		state
);

void phydm_dynamic_rx_path_init(
	void			*dm_void
);

void phydm_drp_debug(
	void		*dm_void,
	u32		*const dm_value,
	u32		*_used,
	char			*output,
	u32		*_out_len
);

void phydm_dynamic_rx_path_caller(
	void			*dm_void
);

#endif
#endif
