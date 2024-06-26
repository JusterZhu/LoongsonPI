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
#ifndef __HAL_TXBF_JAGUAR_H__
#define __HAL_TXBF_JAGUAR_H__
#if ((RTL8812A_SUPPORT == 1) || (RTL8821A_SUPPORT == 1))
#if (BEAMFORMING_SUPPORT == 1)

void hal_txbf_8812a_set_ndpa_rate(
	void			*dm_void,
	u8	BW,
	u8	rate
);


void hal_txbf_jaguar_enter(
	void			*dm_void,
	u8				idx
);


void hal_txbf_jaguar_leave(
	void			*dm_void,
	u8				idx
);


void hal_txbf_jaguar_status(
	void			*dm_void,
	u8				idx
);


void hal_txbf_jaguar_fw_txbf(
	void			*dm_void,
	u8				idx
);


void hal_txbf_jaguar_patch(
	void			*dm_void,
	u8				operation
);


void hal_txbf_jaguar_clk_8812a(
	void			*dm_void
);
#else

#define hal_txbf_8812a_set_ndpa_rate(dm_void,	BW,	rate)
#define hal_txbf_jaguar_enter(dm_void, idx)
#define hal_txbf_jaguar_leave(dm_void, idx)
#define hal_txbf_jaguar_status(dm_void, idx)
#define hal_txbf_jaguar_fw_txbf(dm_void,	idx)
#define hal_txbf_jaguar_patch(dm_void, operation)
#define hal_txbf_jaguar_clk_8812a(dm_void)
#endif
#else

#define hal_txbf_8812a_set_ndpa_rate(dm_void,	BW,	rate)
#define hal_txbf_jaguar_enter(dm_void, idx)
#define hal_txbf_jaguar_leave(dm_void, idx)
#define hal_txbf_jaguar_status(dm_void, idx)
#define hal_txbf_jaguar_fw_txbf(dm_void,	idx)
#define hal_txbf_jaguar_patch(dm_void, operation)
#define hal_txbf_jaguar_clk_8812a(dm_void)
#endif

#endif	/*  #ifndef __HAL_TXBF_JAGUAR_H__ */
