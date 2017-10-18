/*
 * QEMU model of the RPU Realtime Processing Unit
 *
 * Copyright (c) 2014 Xilinx Inc.
 *
 * Autogenerated by xregqemu.py 2014-02-05.
 * Updated by Edgar E. Iglesias <edgar.iglesias@xilinx.com>
 * Updated by Peter Crosthwaite <peter.crosthwaite@xilinx.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "qemu/osdep.h"
#include "hw/sysbus.h"
#include "hw/register-dep.h"
#include "qemu/bitops.h"
#include "qapi/error.h"
#include "qemu/log.h"
#include "qapi/qmp/qerror.h"

#include "hw/fdt_generic_util.h"
#include "hw/intc/xlnx_scu_gic.h"

#ifndef XLNX_RPU_CTRL_ERR_DEBUG
#define XLNX_RPU_CTRL_ERR_DEBUG 0
#endif

#define TYPE_XLNX_RPU_CTRL "xlnx.rpu-control"

#define XLNX_RPU_CTRL(obj) \
     OBJECT_CHECK(RPU, (obj), TYPE_XLNX_RPU_CTRL)

DEP_REG32(RPU_GLBL_CNTL, 0x0)
    DEP_FIELD(RPU_GLBL_CNTL, GIC_AXPROT, 1, 10)
    DEP_FIELD(RPU_GLBL_CNTL, SLRESETN, 1, 9)
    DEP_FIELD(RPU_GLBL_CNTL, TCM_CLK_CNTL, 1, 8)
    DEP_FIELD(RPU_GLBL_CNTL, TCM_WAIT, 1, 7)
    DEP_FIELD(RPU_GLBL_CNTL, TCM_COMB, 1, 6)
    DEP_FIELD(RPU_GLBL_CNTL, TEINIT, 1, 5)
    DEP_FIELD(RPU_GLBL_CNTL, SLCLAMP, 1, 4)
    DEP_FIELD(RPU_GLBL_CNTL, SLSPLIT, 1, 3)
    DEP_FIELD(RPU_GLBL_CNTL, DBGNOCLKSTOP, 1, 2)
    DEP_FIELD(RPU_GLBL_CNTL, CFGIE, 1, 1)
    DEP_FIELD(RPU_GLBL_CNTL, CFGEE, 1, 0)
DEP_REG32(RPU_GLBL_STATUS, 0x4)
    DEP_FIELD(RPU_GLBL_STATUS, DBGNOPWRDWN, 1, 0)
DEP_REG32(RPU_ERR_CNTL, 0x8)
    DEP_FIELD(RPU_ERR_CNTL, APB_ERR_RES, 1, 0)
DEP_REG32(RPU_RAM, 0xc)
    DEP_FIELD(RPU_RAM, RAMCONTROL1, 8, 8)
    DEP_FIELD(RPU_RAM, RAMCONTROL0, 8, 0)
DEP_REG32(RPU_CACHE_DATA, 0x10)
    DEP_FIELD(RPU_CACHE_DATA, DDIRTY_EMAS, 1, 29)
    DEP_FIELD(RPU_CACHE_DATA, DDIRTY_EMAW, 2, 27)
    DEP_FIELD(RPU_CACHE_DATA, DDIRTY_EMA, 3, 24)
    DEP_FIELD(RPU_CACHE_DATA, DTAG_EMAS, 1, 23)
    DEP_FIELD(RPU_CACHE_DATA, DTAG_EMAW, 2, 21)
    DEP_FIELD(RPU_CACHE_DATA, DTAG_EMA, 3, 18)
    DEP_FIELD(RPU_CACHE_DATA, DDATA_EMAS, 1, 17)
    DEP_FIELD(RPU_CACHE_DATA, DDATA_EMAW, 2, 15)
    DEP_FIELD(RPU_CACHE_DATA, DDATA_EMA, 3, 12)
    DEP_FIELD(RPU_CACHE_DATA, ITAG_EMAS, 1, 11)
    DEP_FIELD(RPU_CACHE_DATA, ITAG_EMAW, 2, 9)
    DEP_FIELD(RPU_CACHE_DATA, ITAG_EMA, 3, 6)
    DEP_FIELD(RPU_CACHE_DATA, IDATA_EMAS, 1, 5)
    DEP_FIELD(RPU_CACHE_DATA, IDATA_EMAW, 2, 3)
    DEP_FIELD(RPU_CACHE_DATA, IDATA_EMA, 3, 0)
DEP_REG32(RPU_CACHE_SYN, 0x14)
    DEP_FIELD(RPU_CACHE_SYN, DDIRTY_EMAS, 1, 29)
    DEP_FIELD(RPU_CACHE_SYN, DDIRTY_EMAW, 2, 27)
    DEP_FIELD(RPU_CACHE_SYN, DDIRTY_EMA, 3, 24)
    DEP_FIELD(RPU_CACHE_SYN, DTAG_EMAS, 1, 23)
    DEP_FIELD(RPU_CACHE_SYN, DTAG_EMAW, 2, 21)
    DEP_FIELD(RPU_CACHE_SYN, DTAG_EMA, 3, 18)
    DEP_FIELD(RPU_CACHE_SYN, DDATA_EMAS, 1, 17)
    DEP_FIELD(RPU_CACHE_SYN, DDATA_EMAW, 2, 15)
    DEP_FIELD(RPU_CACHE_SYN, DDATA_EMA, 3, 12)
    DEP_FIELD(RPU_CACHE_SYN, ITAG_EMAS, 1, 11)
    DEP_FIELD(RPU_CACHE_SYN, ITAG_EMAW, 2, 9)
    DEP_FIELD(RPU_CACHE_SYN, ITAG_EMA, 3, 6)
    DEP_FIELD(RPU_CACHE_SYN, IDATA_EMAS, 1, 5)
    DEP_FIELD(RPU_CACHE_SYN, IDATA_EMAW, 2, 3)
    DEP_FIELD(RPU_CACHE_SYN, IDATA_EMA, 3, 0)
DEP_REG32(RPU_TCM_DATA, 0x18)
    DEP_FIELD(RPU_TCM_DATA, B_EMAS, 1, 17)
    DEP_FIELD(RPU_TCM_DATA, B_EMAW, 2, 15)
    DEP_FIELD(RPU_TCM_DATA, B_EMA, 3, 12)
    DEP_FIELD(RPU_TCM_DATA, A_EMAS, 1, 5)
    DEP_FIELD(RPU_TCM_DATA, A_EMAW, 2, 3)
    DEP_FIELD(RPU_TCM_DATA, A_EMA, 3, 0)
DEP_REG32(RPU_TCM_SYN, 0x1c)
    DEP_FIELD(RPU_TCM_SYN, B_EMAS, 1, 23)
    DEP_FIELD(RPU_TCM_SYN, B_EMAW, 2, 21)
    DEP_FIELD(RPU_TCM_SYN, B_EMA, 3, 18)
    DEP_FIELD(RPU_TCM_SYN, A_EMAS, 1, 11)
    DEP_FIELD(RPU_TCM_SYN, A_EMAW, 2, 9)
    DEP_FIELD(RPU_TCM_SYN, A_EMA, 3, 6)
DEP_REG32(RPU_ERR_INJ, 0x20)
    DEP_FIELD(RPU_ERR_INJ, DCCMINP2, 8, 8)
    DEP_FIELD(RPU_ERR_INJ, DCCMINP, 8, 0)
DEP_REG32(RPU_CCF_MASK, 0x24)
    DEP_FIELD(RPU_CCF_MASK, TEST_MBIST_MODE, 1, 7)
    DEP_FIELD(RPU_CCF_MASK, TEST_SCAN_MODE_LP, 1, 6)
    DEP_FIELD(RPU_CCF_MASK, TEST_SCAN_MODE, 1, 5)
    DEP_FIELD(RPU_CCF_MASK, ISO, 1, 4)
    DEP_FIELD(RPU_CCF_MASK, PGE, 1, 3)
    DEP_FIELD(RPU_CCF_MASK, R50_DBG_RST, 1, 2)
    DEP_FIELD(RPU_CCF_MASK, R50_RST, 1, 1)
    DEP_FIELD(RPU_CCF_MASK, PGE_RST, 1, 0)
DEP_REG32(RPU_INTR_0, 0x28)
DEP_REG32(RPU_INTR_1, 0x2c)
DEP_REG32(RPU_INTR_2, 0x30)
DEP_REG32(RPU_INTR_3, 0x34)
DEP_REG32(RPU_INTR_4, 0x38)
DEP_REG32(RPU_INTR_MASK_0, 0x40)
DEP_REG32(RPU_INTR_MASK_1, 0x44)
DEP_REG32(RPU_INTR_MASK_2, 0x48)
DEP_REG32(RPU_INTR_MASK_3, 0x4c)
DEP_REG32(RPU_INTR_MASK_4, 0x50)
DEP_REG32(RPU_CCF_VAL, 0x54)
    DEP_FIELD(RPU_CCF_VAL, TEST_MBIST_MODE, 1, 7)
    DEP_FIELD(RPU_CCF_VAL, TEST_SCAN_MODE_LP, 1, 6)
    DEP_FIELD(RPU_CCF_VAL, TEST_SCAN_MODE, 1, 5)
    DEP_FIELD(RPU_CCF_VAL, ISO, 1, 4)
    DEP_FIELD(RPU_CCF_VAL, PGE, 1, 3)
    DEP_FIELD(RPU_CCF_VAL, R50_DBG_RST, 1, 2)
    DEP_FIELD(RPU_CCF_VAL, R50_RST, 1, 1)
    DEP_FIELD(RPU_CCF_VAL, PGE_RST, 1, 0)
DEP_REG32(RPU_SAFETY_CHK, 0xf0)
DEP_REG32(RPU, 0xf4)
DEP_REG32(RPU_0_CFG, 0x100)
    DEP_FIELD(RPU_0_CFG, CFGNMFI0, 1, 3)
    DEP_FIELD(RPU_0_CFG, VINITHI, 1, 2)
    DEP_FIELD(RPU_0_CFG, COHERENT, 1, 1)
    DEP_FIELD(RPU_0_CFG, NCPUHALT, 1, 0)
DEP_REG32(RPU_0_STATUS, 0x104)
    DEP_FIELD(RPU_0_STATUS, NVALRESET, 1, 5)
    DEP_FIELD(RPU_0_STATUS, NVALIRQ, 1, 4)
    DEP_FIELD(RPU_0_STATUS, NVALFIQ, 1, 3)
    DEP_FIELD(RPU_0_STATUS, NWFIPIPESTOPPED, 1, 2)
    DEP_FIELD(RPU_0_STATUS, NWFEPIPESTOPPED, 1, 1)
    DEP_FIELD(RPU_0_STATUS, NCLKSTOPPED, 1, 0)
DEP_REG32(RPU_0_PWRDWN, 0x108)
    DEP_FIELD(RPU_0_PWRDWN, EN, 1, 0)
DEP_REG32(RPU_0_ISR, 0x114)
    DEP_FIELD(RPU_0_ISR, FPUFC, 1, 24)
    DEP_FIELD(RPU_0_ISR, FPOFC, 1, 23)
    DEP_FIELD(RPU_0_ISR, FPIXC, 1, 22)
    DEP_FIELD(RPU_0_ISR, FPIOC, 1, 21)
    DEP_FIELD(RPU_0_ISR, FPIDC, 1, 20)
    DEP_FIELD(RPU_0_ISR, FPDZC, 1, 19)
    DEP_FIELD(RPU_0_ISR, TCM_ASLV_CE, 1, 18)
    DEP_FIELD(RPU_0_ISR, TCM_ASLV_FAT, 1, 17)
    DEP_FIELD(RPU_0_ISR, TCM_LST_CE, 1, 16)
    DEP_FIELD(RPU_0_ISR, TCM_PREFETCH_CE, 1, 15)
    DEP_FIELD(RPU_0_ISR, B1TCM_CE, 1, 14)
    DEP_FIELD(RPU_0_ISR, B0TCM_CE, 1, 13)
    DEP_FIELD(RPU_0_ISR, ATCM_CE, 1, 12)
    DEP_FIELD(RPU_0_ISR, B1TCM_UE, 1, 11)
    DEP_FIELD(RPU_0_ISR, B0TCM_UE, 1, 10)
    DEP_FIELD(RPU_0_ISR, ATCM_UE, 1, 9)
    DEP_FIELD(RPU_0_ISR, DTAG_DIRTY_FAT, 1, 8)
    DEP_FIELD(RPU_0_ISR, DDATA_FAT, 1, 7)
    DEP_FIELD(RPU_0_ISR, TCM_LST_FAT, 1, 6)
    DEP_FIELD(RPU_0_ISR, TCM_PREFETCH_FAT, 1, 5)
    DEP_FIELD(RPU_0_ISR, DDATA_CE, 1, 4)
    DEP_FIELD(RPU_0_ISR, DTAG_DIRTY_CE, 1, 3)
    DEP_FIELD(RPU_0_ISR, IDATA_CE, 1, 2)
    DEP_FIELD(RPU_0_ISR, ITAG_CE, 1, 1)
    DEP_FIELD(RPU_0_ISR, APB_ERR, 1, 0)
DEP_REG32(RPU_0_IMR, 0x118)
    DEP_FIELD(RPU_0_IMR, FPUFC, 1, 24)
    DEP_FIELD(RPU_0_IMR, FPOFC, 1, 23)
    DEP_FIELD(RPU_0_IMR, FPIXC, 1, 22)
    DEP_FIELD(RPU_0_IMR, FPIOC, 1, 21)
    DEP_FIELD(RPU_0_IMR, FPIDC, 1, 20)
    DEP_FIELD(RPU_0_IMR, FPDZC, 1, 19)
    DEP_FIELD(RPU_0_IMR, TCM_ASLV_CE, 1, 18)
    DEP_FIELD(RPU_0_IMR, TCM_ASLV_FAT, 1, 17)
    DEP_FIELD(RPU_0_IMR, TCM_LST_CE, 1, 16)
    DEP_FIELD(RPU_0_IMR, TCM_PREFETCH_CE, 1, 15)
    DEP_FIELD(RPU_0_IMR, B1TCM_CE, 1, 14)
    DEP_FIELD(RPU_0_IMR, B0TCM_CE, 1, 13)
    DEP_FIELD(RPU_0_IMR, ATCM_CE, 1, 12)
    DEP_FIELD(RPU_0_IMR, B1TCM_UE, 1, 11)
    DEP_FIELD(RPU_0_IMR, B0TCM_UE, 1, 10)
    DEP_FIELD(RPU_0_IMR, ATCM_UE, 1, 9)
    DEP_FIELD(RPU_0_IMR, DTAG_DIRTY_FAT, 1, 8)
    DEP_FIELD(RPU_0_IMR, DDATA_FAT, 1, 7)
    DEP_FIELD(RPU_0_IMR, TCM_LST_FAT, 1, 6)
    DEP_FIELD(RPU_0_IMR, TCM_PREFETCH_FAT, 1, 5)
    DEP_FIELD(RPU_0_IMR, DDATA_CE, 1, 4)
    DEP_FIELD(RPU_0_IMR, DTAG_DIRTY_CE, 1, 3)
    DEP_FIELD(RPU_0_IMR, IDATA_CE, 1, 2)
    DEP_FIELD(RPU_0_IMR, ITAG_CE, 1, 1)
    DEP_FIELD(RPU_0_IMR, APB_ERR, 1, 0)
DEP_REG32(RPU_0_IEN, 0x11c)
    DEP_FIELD(RPU_0_IEN, FPUFC, 1, 24)
    DEP_FIELD(RPU_0_IEN, FPOFC, 1, 23)
    DEP_FIELD(RPU_0_IEN, FPIXC, 1, 22)
    DEP_FIELD(RPU_0_IEN, FPIOC, 1, 21)
    DEP_FIELD(RPU_0_IEN, FPIDC, 1, 20)
    DEP_FIELD(RPU_0_IEN, FPDZC, 1, 19)
    DEP_FIELD(RPU_0_IEN, TCM_ASLV_CE, 1, 18)
    DEP_FIELD(RPU_0_IEN, TCM_ASLV_FAT, 1, 17)
    DEP_FIELD(RPU_0_IEN, TCM_LST_CE, 1, 16)
    DEP_FIELD(RPU_0_IEN, TCM_PREFETCH_CE, 1, 15)
    DEP_FIELD(RPU_0_IEN, B1TCM_CE, 1, 14)
    DEP_FIELD(RPU_0_IEN, B0TCM_CE, 1, 13)
    DEP_FIELD(RPU_0_IEN, ATCM_CE, 1, 12)
    DEP_FIELD(RPU_0_IEN, B1TCM_UE, 1, 11)
    DEP_FIELD(RPU_0_IEN, B0TCM_UE, 1, 10)
    DEP_FIELD(RPU_0_IEN, ATCM_UE, 1, 9)
    DEP_FIELD(RPU_0_IEN, DTAG_DIRTY_FAT, 1, 8)
    DEP_FIELD(RPU_0_IEN, DDATA_FAT, 1, 7)
    DEP_FIELD(RPU_0_IEN, TCM_LST_FAT, 1, 6)
    DEP_FIELD(RPU_0_IEN, TCM_PREFETCH_FAT, 1, 5)
    DEP_FIELD(RPU_0_IEN, DDATA_CE, 1, 4)
    DEP_FIELD(RPU_0_IEN, DTAG_DIRTY_CE, 1, 3)
    DEP_FIELD(RPU_0_IEN, IDATA_CE, 1, 2)
    DEP_FIELD(RPU_0_IEN, ITAG_CE, 1, 1)
    DEP_FIELD(RPU_0_IEN, APB_ERR, 1, 0)
DEP_REG32(RPU_0_IDS, 0x120)
    DEP_FIELD(RPU_0_IDS, FPUFC, 1, 24)
    DEP_FIELD(RPU_0_IDS, FPOFC, 1, 23)
    DEP_FIELD(RPU_0_IDS, FPIXC, 1, 22)
    DEP_FIELD(RPU_0_IDS, FPIOC, 1, 21)
    DEP_FIELD(RPU_0_IDS, FPIDC, 1, 20)
    DEP_FIELD(RPU_0_IDS, FPDZC, 1, 19)
    DEP_FIELD(RPU_0_IDS, TCM_ASLV_CE, 1, 18)
    DEP_FIELD(RPU_0_IDS, TCM_ASLV_FAT, 1, 17)
    DEP_FIELD(RPU_0_IDS, TCM_LST_CE, 1, 16)
    DEP_FIELD(RPU_0_IDS, TCM_PREFETCH_CE, 1, 15)
    DEP_FIELD(RPU_0_IDS, B1TCM_CE, 1, 14)
    DEP_FIELD(RPU_0_IDS, B0TCM_CE, 1, 13)
    DEP_FIELD(RPU_0_IDS, ATCM_CE, 1, 12)
    DEP_FIELD(RPU_0_IDS, B1TCM_UE, 1, 11)
    DEP_FIELD(RPU_0_IDS, B0TCM_UE, 1, 10)
    DEP_FIELD(RPU_0_IDS, ATCM_UE, 1, 9)
    DEP_FIELD(RPU_0_IDS, DTAG_DIRTY_FAT, 1, 8)
    DEP_FIELD(RPU_0_IDS, DDATA_FAT, 1, 7)
    DEP_FIELD(RPU_0_IDS, TCM_LST_FAT, 1, 6)
    DEP_FIELD(RPU_0_IDS, TCM_PREFETCH_FAT, 1, 5)
    DEP_FIELD(RPU_0_IDS, DDATA_CE, 1, 4)
    DEP_FIELD(RPU_0_IDS, DTAG_DIRTY_CE, 1, 3)
    DEP_FIELD(RPU_0_IDS, IDATA_CE, 1, 2)
    DEP_FIELD(RPU_0_IDS, ITAG_CE, 1, 1)
    DEP_FIELD(RPU_0_IDS, APB_ERR, 1, 0)
DEP_REG32(RPU_0_SLV_BASE, 0x124)
    DEP_FIELD(RPU_0_SLV_BASE, ADDR, 8, 0)
DEP_REG32(RPU_0_AXI_OVER, 0x128)
    DEP_FIELD(RPU_0_AXI_OVER, AWCACHE, 4, 6)
    DEP_FIELD(RPU_0_AXI_OVER, ARCACHE, 4, 2)
    DEP_FIELD(RPU_0_AXI_OVER, AWCACHE_EN, 1, 1)
    DEP_FIELD(RPU_0_AXI_OVER, ARCACHE_EN, 1, 0)
DEP_REG32(RPU_1_CFG, 0x200)
    DEP_FIELD(RPU_1_CFG, CFGNMFI1, 1, 3)
    DEP_FIELD(RPU_1_CFG, VINITHI, 1, 2)
    DEP_FIELD(RPU_1_CFG, COHERENT, 1, 1)
    DEP_FIELD(RPU_1_CFG, NCPUHALT, 1, 0)
DEP_REG32(RPU_1_STATUS, 0x204)
    DEP_FIELD(RPU_1_STATUS, NVALRESET, 1, 5)
    DEP_FIELD(RPU_1_STATUS, NVALIRQ, 1, 4)
    DEP_FIELD(RPU_1_STATUS, NVALFIQ, 1, 3)
    DEP_FIELD(RPU_1_STATUS, NWFIPIPESTOPPED, 1, 2)
    DEP_FIELD(RPU_1_STATUS, NWFEPIPESTOPPED, 1, 1)
    DEP_FIELD(RPU_1_STATUS, NCLKSTOPPED, 1, 0)
DEP_REG32(RPU_1_PWRDWN, 0x208)
    DEP_FIELD(RPU_1_PWRDWN, EN, 1, 0)
DEP_REG32(RPU_1_ISR, 0x214)
    DEP_FIELD(RPU_1_ISR, FPUFC, 1, 24)
    DEP_FIELD(RPU_1_ISR, FPOFC, 1, 23)
    DEP_FIELD(RPU_1_ISR, FPIXC, 1, 22)
    DEP_FIELD(RPU_1_ISR, FPIOC, 1, 21)
    DEP_FIELD(RPU_1_ISR, FPIDC, 1, 20)
    DEP_FIELD(RPU_1_ISR, FPDZC, 1, 19)
    DEP_FIELD(RPU_1_ISR, TCM_ASLV_CE, 1, 18)
    DEP_FIELD(RPU_1_ISR, TCM_ASLV_FAT, 1, 17)
    DEP_FIELD(RPU_1_ISR, TCM_LST_CE, 1, 16)
    DEP_FIELD(RPU_1_ISR, TCM_PREFETCH_CE, 1, 15)
    DEP_FIELD(RPU_1_ISR, B1TCM_CE, 1, 14)
    DEP_FIELD(RPU_1_ISR, B0TCM_CE, 1, 13)
    DEP_FIELD(RPU_1_ISR, ATCM_CE, 1, 12)
    DEP_FIELD(RPU_1_ISR, B1TCM_UE, 1, 11)
    DEP_FIELD(RPU_1_ISR, B0TCM_UE, 1, 10)
    DEP_FIELD(RPU_1_ISR, ATCM_UE, 1, 9)
    DEP_FIELD(RPU_1_ISR, DTAG_DIRTY_FAT, 1, 8)
    DEP_FIELD(RPU_1_ISR, DDATA_FAT, 1, 7)
    DEP_FIELD(RPU_1_ISR, TCM_LST_FAT, 1, 6)
    DEP_FIELD(RPU_1_ISR, TCM_PREFETCH_FAT, 1, 5)
    DEP_FIELD(RPU_1_ISR, DDATA_CE, 1, 4)
    DEP_FIELD(RPU_1_ISR, DTAG_DIRTY_CE, 1, 3)
    DEP_FIELD(RPU_1_ISR, IDATA_CE, 1, 2)
    DEP_FIELD(RPU_1_ISR, ITAG_CE, 1, 1)
    DEP_FIELD(RPU_1_ISR, APB_ERR, 1, 0)
DEP_REG32(RPU_1_IMR, 0x218)
    DEP_FIELD(RPU_1_IMR, FPUFC, 1, 24)
    DEP_FIELD(RPU_1_IMR, FPOFC, 1, 23)
    DEP_FIELD(RPU_1_IMR, FPIXC, 1, 22)
    DEP_FIELD(RPU_1_IMR, FPIOC, 1, 21)
    DEP_FIELD(RPU_1_IMR, FPIDC, 1, 20)
    DEP_FIELD(RPU_1_IMR, FPDZC, 1, 19)
    DEP_FIELD(RPU_1_IMR, TCM_ASLV_CE, 1, 18)
    DEP_FIELD(RPU_1_IMR, TCM_ASLV_FAT, 1, 17)
    DEP_FIELD(RPU_1_IMR, TCM_LST_CE, 1, 16)
    DEP_FIELD(RPU_1_IMR, TCM_PREFETCH_CE, 1, 15)
    DEP_FIELD(RPU_1_IMR, B1TCM_CE, 1, 14)
    DEP_FIELD(RPU_1_IMR, B0TCM_CE, 1, 13)
    DEP_FIELD(RPU_1_IMR, ATCM_CE, 1, 12)
    DEP_FIELD(RPU_1_IMR, B1TCM_UE, 1, 11)
    DEP_FIELD(RPU_1_IMR, B0TCM_UE, 1, 10)
    DEP_FIELD(RPU_1_IMR, ATCM_UE, 1, 9)
    DEP_FIELD(RPU_1_IMR, DTAG_DIRTY_FAT, 1, 8)
    DEP_FIELD(RPU_1_IMR, DDATA_FAT, 1, 7)
    DEP_FIELD(RPU_1_IMR, TCM_LST_FAT, 1, 6)
    DEP_FIELD(RPU_1_IMR, TCM_PREFETCH_FAT, 1, 5)
    DEP_FIELD(RPU_1_IMR, DDATA_CE, 1, 4)
    DEP_FIELD(RPU_1_IMR, DTAG_DIRTY_CE, 1, 3)
    DEP_FIELD(RPU_1_IMR, IDATA_CE, 1, 2)
    DEP_FIELD(RPU_1_IMR, ITAG_CE, 1, 1)
    DEP_FIELD(RPU_1_IMR, APB_ERR, 1, 0)
DEP_REG32(RPU_1_IEN, 0x21c)
    DEP_FIELD(RPU_1_IEN, FPUFC, 1, 24)
    DEP_FIELD(RPU_1_IEN, FPOFC, 1, 23)
    DEP_FIELD(RPU_1_IEN, FPIXC, 1, 22)
    DEP_FIELD(RPU_1_IEN, FPIOC, 1, 21)
    DEP_FIELD(RPU_1_IEN, FPIDC, 1, 20)
    DEP_FIELD(RPU_1_IEN, FPDZC, 1, 19)
    DEP_FIELD(RPU_1_IEN, TCM_ASLV_CE, 1, 18)
    DEP_FIELD(RPU_1_IEN, TCM_ASLV_FAT, 1, 17)
    DEP_FIELD(RPU_1_IEN, TCM_LST_CE, 1, 16)
    DEP_FIELD(RPU_1_IEN, TCM_PREFETCH_CE, 1, 15)
    DEP_FIELD(RPU_1_IEN, B1TCM_CE, 1, 14)
    DEP_FIELD(RPU_1_IEN, B0TCM_CE, 1, 13)
    DEP_FIELD(RPU_1_IEN, ATCM_CE, 1, 12)
    DEP_FIELD(RPU_1_IEN, B1TCM_UE, 1, 11)
    DEP_FIELD(RPU_1_IEN, B0TCM_UE, 1, 10)
    DEP_FIELD(RPU_1_IEN, ATCM_UE, 1, 9)
    DEP_FIELD(RPU_1_IEN, DTAG_DIRTY_FAT, 1, 8)
    DEP_FIELD(RPU_1_IEN, DDATA_FAT, 1, 7)
    DEP_FIELD(RPU_1_IEN, TCM_LST_FAT, 1, 6)
    DEP_FIELD(RPU_1_IEN, TCM_PREFETCH_FAT, 1, 5)
    DEP_FIELD(RPU_1_IEN, DDATA_CE, 1, 4)
    DEP_FIELD(RPU_1_IEN, DTAG_DIRTY_CE, 1, 3)
    DEP_FIELD(RPU_1_IEN, IDATA_CE, 1, 2)
    DEP_FIELD(RPU_1_IEN, ITAG_CE, 1, 1)
    DEP_FIELD(RPU_1_IEN, APB_ERR, 1, 0)
DEP_REG32(RPU_1_IDS, 0x220)
    DEP_FIELD(RPU_1_IDS, FPUFC, 1, 24)
    DEP_FIELD(RPU_1_IDS, FPOFC, 1, 23)
    DEP_FIELD(RPU_1_IDS, FPIXC, 1, 22)
    DEP_FIELD(RPU_1_IDS, FPIOC, 1, 21)
    DEP_FIELD(RPU_1_IDS, FPIDC, 1, 20)
    DEP_FIELD(RPU_1_IDS, FPDZC, 1, 19)
    DEP_FIELD(RPU_1_IDS, TCM_ASLV_CE, 1, 18)
    DEP_FIELD(RPU_1_IDS, TCM_ASLV_FAT, 1, 17)
    DEP_FIELD(RPU_1_IDS, TCM_LST_CE, 1, 16)
    DEP_FIELD(RPU_1_IDS, TCM_PREFETCH_CE, 1, 15)
    DEP_FIELD(RPU_1_IDS, B1TCM_CE, 1, 14)
    DEP_FIELD(RPU_1_IDS, B0TCM_CE, 1, 13)
    DEP_FIELD(RPU_1_IDS, ATCM_CE, 1, 12)
    DEP_FIELD(RPU_1_IDS, B1TCM_UE, 1, 11)
    DEP_FIELD(RPU_1_IDS, B0TCM_UE, 1, 10)
    DEP_FIELD(RPU_1_IDS, ATCM_UE, 1, 9)
    DEP_FIELD(RPU_1_IDS, DTAG_DIRTY_FAT, 1, 8)
    DEP_FIELD(RPU_1_IDS, DDATA_FAT, 1, 7)
    DEP_FIELD(RPU_1_IDS, TCM_LST_FAT, 1, 6)
    DEP_FIELD(RPU_1_IDS, TCM_PREFETCH_FAT, 1, 5)
    DEP_FIELD(RPU_1_IDS, DDATA_CE, 1, 4)
    DEP_FIELD(RPU_1_IDS, DTAG_DIRTY_CE, 1, 3)
    DEP_FIELD(RPU_1_IDS, IDATA_CE, 1, 2)
    DEP_FIELD(RPU_1_IDS, ITAG_CE, 1, 1)
    DEP_FIELD(RPU_1_IDS, APB_ERR, 1, 0)
DEP_REG32(RPU_1_SLV_BASE, 0x224)
    DEP_FIELD(RPU_1_SLV_BASE, ADDR, 8, 0)
DEP_REG32(RPU_1_AXI_OVER, 0x228)
    DEP_FIELD(RPU_1_AXI_OVER, AWCACHE, 4, 6)
    DEP_FIELD(RPU_1_AXI_OVER, ARCACHE, 4, 2)
    DEP_FIELD(RPU_1_AXI_OVER, AWCACHE_EN, 1, 1)
    DEP_FIELD(RPU_1_AXI_OVER, ARCACHE_EN, 1, 0)

#define R_MAX (R_RPU_1_AXI_OVER + 1)

/* Returns the interrupt bank from the register offset. */
#define INT_INJ_BANK_FROM_OFFSET(n) (((n) <= R_RPU_INTR_4)                     \
                                     ? ((n) - R_RPU_INTR_0)                    \
                                     : ((n) - R_RPU_INTR_MASK_0))
#define R_RPU_INTR(n) (n + R_RPU_INTR_0)
#define R_RPU_INTR_MASK(n) (n + R_RPU_INTR_MASK_0)

typedef struct RPU {
    SysBusDevice parent_obj;
    MemoryRegion iomem;
    qemu_irq irq_rpu_1;
    qemu_irq irq_rpu_0;

    MemoryRegion *atcm1_for_rpu0;
    MemoryRegion *btcm1_for_rpu0;
    MemoryRegion atcm1_mask;
    MemoryRegion btcm1_mask;
    MemoryRegion *rpu1_for_main_bus;
    /* MemoryRegion for the rpu1 caches. */
    MemoryRegion *icache_for_rpu1;
    MemoryRegion *dcache_for_rpu1;
    /* Second part of the DDR. */
    MemoryRegion *ddr;

    /* GIC associated to the RPUs. */
    XlnxSCUGICState *gic;

    /* WFIs towards PMU. */
    qemu_irq wfi_out[2];
    /* Comparators fault. */
    qemu_irq comp_fault[2];

    bool cpu_in_wfi[2];

    uint32_t regs[R_MAX];
    DepRegisterInfo regs_info[R_MAX];
} RPU;

static void rpu_1_update_irq(RPU *s)
{
    bool pending = s->regs[R_RPU_1_ISR] & ~s->regs[R_RPU_1_IMR];
    qemu_set_irq(s->irq_rpu_1, pending);
}

static void ronaldo_rpu_err_inj(DepRegisterInfo *reg, uint64_t val64)
{
    RPU *s = XLNX_RPU_CTRL(reg->opaque);
    bool comp_0 = DEP_AF_EX32(s->regs, RPU_ERR_INJ, DCCMINP);
    bool comp_1 = DEP_AF_EX32(s->regs, RPU_ERR_INJ, DCCMINP2);

    /* Inject an error in the comparator
     * Works even if the CLAMP bit is cleared.
     */
    qemu_set_irq(s->comp_fault[0], comp_0);
    qemu_set_irq(s->comp_fault[1], comp_1);
}

static void rpu_1_isr_postw(DepRegisterInfo *reg, uint64_t val64)
{
    RPU *s = XLNX_RPU_CTRL(reg->opaque);
    rpu_1_update_irq(s);
}

static void ronaldo_rpu_update_irq_injection(DepRegisterInfo *reg, uint64_t val)
{
    RPU *s = XLNX_RPU_CTRL(reg->opaque);

    uint8_t bank = INT_INJ_BANK_FROM_OFFSET(reg->access->decode.addr >> 2);
    uint32_t irqs = s->regs[R_RPU_INTR(bank)] &
                    s->regs[R_RPU_INTR_MASK(bank)];

    xlnx_scu_gic_set_intr(s->gic, bank, irqs, 0);
}

static uint64_t rpu_1_ien_prew(DepRegisterInfo *reg, uint64_t val64)
{
    RPU *s = XLNX_RPU_CTRL(reg->opaque);
    uint32_t val = val64;

    s->regs[R_RPU_1_IMR] &= ~val;
    rpu_1_update_irq(s);
    return 0;
}

static uint64_t rpu_1_ids_prew(DepRegisterInfo *reg, uint64_t val64)
{
    RPU *s = XLNX_RPU_CTRL(reg->opaque);
    uint32_t val = val64;

    s->regs[R_RPU_1_IMR] |= val;
    rpu_1_update_irq(s);
    return 0;
}

static void rpu_0_update_irq(RPU *s)
{
    bool pending = s->regs[R_RPU_0_ISR] & ~s->regs[R_RPU_0_IMR];
    qemu_set_irq(s->irq_rpu_0, pending);
}

static void rpu_0_isr_postw(DepRegisterInfo *reg, uint64_t val64)
{
    RPU *s = XLNX_RPU_CTRL(reg->opaque);
    rpu_0_update_irq(s);
}

static uint64_t rpu_0_ien_prew(DepRegisterInfo *reg, uint64_t val64)
{
    RPU *s = XLNX_RPU_CTRL(reg->opaque);
    uint32_t val = val64;

    s->regs[R_RPU_0_IMR] &= ~val;
    rpu_0_update_irq(s);
    return 0;
}

static uint64_t rpu_0_ids_prew(DepRegisterInfo *reg, uint64_t val64)
{
    RPU *s = XLNX_RPU_CTRL(reg->opaque);
    uint32_t val = val64;

    s->regs[R_RPU_0_IMR] |= val;
    rpu_0_update_irq(s);
    return 0;
}

static void rpu_rpu_glbl_cntl_postw(DepRegisterInfo *reg, uint64_t val64)
{
    RPU *s = XLNX_RPU_CTRL(reg->opaque);
    bool tcm_comb = DEP_AF_EX32(s->regs, RPU_GLBL_CNTL, TCM_COMB);
    bool sls_split = DEP_AF_EX32(s->regs, RPU_GLBL_CNTL, SLSPLIT);

    memory_region_set_enabled(&s->atcm1_mask, !tcm_comb);
    memory_region_set_enabled(&s->btcm1_mask, !tcm_comb);

    memory_region_set_enabled(s->icache_for_rpu1, sls_split);
    memory_region_set_enabled(s->dcache_for_rpu1, sls_split);
    memory_region_set_enabled(s->ddr, sls_split);
}

static void update_wfi_out(void *opaque)
{
    RPU *s = XLNX_RPU_CTRL(opaque);
    unsigned int i, wfi_pending;
    unsigned int pwrdnreq[2];

    pwrdnreq[0] = DEP_AF_EX32(s->regs, RPU_0_PWRDWN, EN);
    pwrdnreq[1] = DEP_AF_EX32(s->regs, RPU_1_PWRDWN, EN);

    for (i = 0; i < 2; i++) {
        wfi_pending = pwrdnreq[i] && s->cpu_in_wfi[i];
        qemu_set_irq(s->wfi_out[i], wfi_pending);
    }
}

static void zynqmp_rpu_pwrctl_post_write(DepRegisterInfo *reg, uint64_t val)
{
    RPU *s = XLNX_RPU_CTRL(reg->opaque);
    update_wfi_out(s);
}

static uint64_t rpu_1_cfg_pw(DepRegisterInfo *reg, uint64_t val)
{
    RPU *s = XLNX_RPU_CTRL(reg->opaque);

    /* Split-Mode: Remove R5-1 from hold upon request
     * LockStep-Mode: Keep R5-1 under hold, to make only R5-0 run
     *                in Lockstep.
     */
    if (!DEP_AF_EX32(s->regs, RPU_GLBL_CNTL, SLSPLIT)) {
        /* Lock-Step Mode, Clear the hold bit to keep the
         *  core in HOLD state.
         */
        val &= ~(R_RPU_1_CFG_NCPUHALT_MASK);
    }
    return val;
}

static DepRegisterAccessInfo rpu_regs_info[] = {
    {   .name = "RPU_GLBL_CNTL",  .decode.addr = A_RPU_GLBL_CNTL,
        .gpios = (DepRegisterGPIOMapping[]) {
            { .name = "R5_SLSPLIT",
              .bit_pos = R_RPU_GLBL_CNTL_SLSPLIT_SHIFT, .width = 1,
              .polarity = REG_GPIO_POL_LOW },
            {},
        },
        .reset = 0x250,
        .post_write = rpu_rpu_glbl_cntl_postw,
        .inhibit_reset = 1u << 31,
    },{ .name = "RPU_GLBL_STATUS",  .decode.addr = A_RPU_GLBL_STATUS,
        .ro = 0x1,
    },{ .name = "RPU_ERR_CNTL",  .decode.addr = A_RPU_ERR_CNTL,
    },{ .name = "RPU_RAM",  .decode.addr = A_RPU_RAM,
    },{ .name = "RPU_CACHE_DATA",  .decode.addr = A_RPU_CACHE_DATA,
        .reset = 0xa28a28a,
    },{ .name = "RPU_CACHE_SYN",  .decode.addr = A_RPU_CACHE_SYN,
        .reset = 0xa28a28a,
    },{ .name = "RPU_TCM_DATA",  .decode.addr = A_RPU_TCM_DATA,
        .reset = 0xa00a,
    },{ .name = "RPU_TCM_SYN",  .decode.addr = A_RPU_TCM_SYN,
        .reset = 0x280280,
    },{ .name = "RPU_ERR_INJ",  .decode.addr = A_RPU_ERR_INJ,
        .post_write = ronaldo_rpu_err_inj,
    },{ .name = "RPU_CCF_MASK",  .decode.addr = A_RPU_CCF_MASK,
    },{ .name = "RPU_INTR_0",  .decode.addr = A_RPU_INTR_0,
        .post_write = ronaldo_rpu_update_irq_injection,
    },{ .name = "RPU_INTR_1",  .decode.addr = A_RPU_INTR_1,
        .post_write = ronaldo_rpu_update_irq_injection,
    },{ .name = "RPU_INTR_2",  .decode.addr = A_RPU_INTR_2,
        .post_write = ronaldo_rpu_update_irq_injection,
    },{ .name = "RPU_INTR_3",  .decode.addr = A_RPU_INTR_3,
        .post_write = ronaldo_rpu_update_irq_injection,
    },{ .name = "RPU_INTR_4",  .decode.addr = A_RPU_INTR_4,
        .post_write = ronaldo_rpu_update_irq_injection,
    },{ .name = "RPU_INTR_MASK_0",  .decode.addr = A_RPU_INTR_MASK_0,
        .post_write = ronaldo_rpu_update_irq_injection,
    },{ .name = "RPU_INTR_MASK_1",  .decode.addr = A_RPU_INTR_MASK_1,
        .post_write = ronaldo_rpu_update_irq_injection,
    },{ .name = "RPU_INTR_MASK_2",  .decode.addr = A_RPU_INTR_MASK_2,
        .post_write = ronaldo_rpu_update_irq_injection,
    },{ .name = "RPU_INTR_MASK_3",  .decode.addr = A_RPU_INTR_MASK_3,
        .post_write = ronaldo_rpu_update_irq_injection,
    },{ .name = "RPU_INTR_MASK_4",  .decode.addr = A_RPU_INTR_MASK_4,
        .post_write = ronaldo_rpu_update_irq_injection,
    },{ .name = "RPU_CCF_VAL",  .decode.addr = A_RPU_CCF_VAL,
        .reset = 0x7,
    },{ .name = "RPU_SAFETY_CHK",  .decode.addr = A_RPU_SAFETY_CHK,
    },{ .name = "RPU",  .decode.addr = A_RPU,
    },{ .name = "RPU_0_CFG",  .decode.addr = A_RPU_0_CFG,
        .reset = 0x5,
        .gpios = (DepRegisterGPIOMapping[]) {
            { .name = "R5_0_HALT",
              .bit_pos = R_RPU_0_CFG_NCPUHALT_SHIFT, .width = 1,
              .polarity = REG_GPIO_POL_LOW },
            { .name = "R5_0_VINITHI",
              .bit_pos = R_RPU_0_CFG_VINITHI_SHIFT, .width = 1 },
            {},
        },
    },{ .name = "RPU_0_STATUS",  .decode.addr = A_RPU_0_STATUS,
        .reset = 0x3f,
        .ro = 0x3f,
    },{ .name = "RPU_0_PWRDWN",  .decode.addr = A_RPU_0_PWRDWN,
        .gpios = (DepRegisterGPIOMapping[]) {
            { .name = "R5_0_PWRDWN_REQ",
              .bit_pos = R_RPU_0_PWRDWN_EN_SHIFT, .width = 1 },
            {},
        },
        .post_write = zynqmp_rpu_pwrctl_post_write,
    },{ .name = "RPU_0_ISR",  .decode.addr = A_RPU_0_ISR,
        .w1c = 0x1ffffff,
        .post_write = rpu_0_isr_postw,
    },{ .name = "RPU_0_IMR",  .decode.addr = A_RPU_0_IMR,
        .reset = 0x1ffffff,
        .ro = 0x1ffffff,
    },{ .name = "RPU_0_IEN",  .decode.addr = A_RPU_0_IEN,
        .pre_write = rpu_0_ien_prew,
    },{ .name = "RPU_0_IDS",  .decode.addr = A_RPU_0_IDS,
        .pre_write = rpu_0_ids_prew,
    },{ .name = "RPU_0_SLV_BASE",  .decode.addr = A_RPU_0_SLV_BASE,
    },{ .name = "RPU_0_AXI_OVER",  .decode.addr = A_RPU_0_AXI_OVER,
    },{ .name = "RPU_1_CFG",  .decode.addr = A_RPU_1_CFG,
        .reset = 0x5,
        .gpios = (DepRegisterGPIOMapping[]) {
            { .name = "R5_1_HALT",
              .bit_pos = R_RPU_1_CFG_NCPUHALT_SHIFT, .width = 1,
              .polarity = REG_GPIO_POL_LOW },
            { .name = "R5_1_VINITHI",
              .bit_pos = R_RPU_1_CFG_VINITHI_SHIFT, .width = 1 },
            {},
        },
        .pre_write = rpu_1_cfg_pw,
    },{ .name = "RPU_1_STATUS",  .decode.addr = A_RPU_1_STATUS,
        .reset = 0x3f,
        .ro = 0x3f,
    },{ .name = "RPU_1_PWRDWN",  .decode.addr = A_RPU_1_PWRDWN,
        .gpios = (DepRegisterGPIOMapping[]) {
            { .name = "R5_1_PWRDWN_REQ",
              .bit_pos = R_RPU_1_PWRDWN_EN_SHIFT, .width = 1 },
            {},
        },
        .post_write = zynqmp_rpu_pwrctl_post_write,
    },{ .name = "RPU_1_ISR",  .decode.addr = A_RPU_1_ISR,
        .w1c = 0x1ffffff,
        .post_write = rpu_1_isr_postw,
    },{ .name = "RPU_1_IMR",  .decode.addr = A_RPU_1_IMR,
        .reset = 0x1ffffff,
        .ro = 0x1ffffff,
    },{ .name = "RPU_1_IEN",  .decode.addr = A_RPU_1_IEN,
        .pre_write = rpu_1_ien_prew,
    },{ .name = "RPU_1_IDS",  .decode.addr = A_RPU_1_IDS,
        .pre_write = rpu_1_ids_prew,
    },{ .name = "RPU_1_SLV_BASE",  .decode.addr = A_RPU_1_SLV_BASE,
    },{ .name = "RPU_1_AXI_OVER",  .decode.addr = A_RPU_1_AXI_OVER,
    }
};

static void rpu_reset(DeviceState *dev)
{
    RPU *s = XLNX_RPU_CTRL(dev);
    unsigned int i;

    for (i = 0; i < ARRAY_SIZE(s->regs_info); ++i) {
        dep_register_reset(&s->regs_info[i]);
    }

    rpu_1_update_irq(s);
    rpu_0_update_irq(s);

    for (i = 0; i < 2; i++) {
        s->cpu_in_wfi[i] = false;
    }
    update_wfi_out(s);
}

static uint64_t rpu_read(void *opaque, hwaddr addr, unsigned size)
{
    RPU *s = XLNX_RPU_CTRL(opaque);
    DepRegisterInfo *r = &s->regs_info[addr / 4];

    if (!r->data) {
        qemu_log_mask(LOG_GUEST_ERROR,
                 "%s: Decode error: read from %" HWADDR_PRIx "\n",
                 object_get_canonical_path(OBJECT(s)),
                 addr);
        return 0;
    }
    return dep_register_read(r);
}

static void rpu_write(void *opaque, hwaddr addr, uint64_t value,
                      unsigned size)
{
    RPU *s = XLNX_RPU_CTRL(opaque);
    DepRegisterInfo *r = &s->regs_info[addr / 4];

    if (!r->data) {
        qemu_log_mask(LOG_GUEST_ERROR,
                 "%s: Decode error: write to %" HWADDR_PRIx "=%" PRIx64 "\n",
                 object_get_canonical_path(OBJECT(s)),
                 addr, value);
        return;
    }
    dep_register_write(r, value, ~0);
}

static const MemoryRegionOps rpu_ops = {
    .read = rpu_read,
    .write = rpu_write,
    .endianness = DEVICE_LITTLE_ENDIAN,
    .valid = {
        .min_access_size = 4,
        .max_access_size = 4,
    },
};

static uint64_t disabled_tcm_read(void *opaque, hwaddr addr, unsigned size)
{
    Object *obj = OBJECT(opaque);

    qemu_log_mask(LOG_GUEST_ERROR, "%s: Read to unmapped TCM while RPU is in"
                  " lockstep mode @%" HWADDR_PRIx "\n",
                  object_get_canonical_path(obj), addr);
    return 0;
}

static void disabled_tcm_write(void *opaque, hwaddr addr, uint64_t value,
                               unsigned size)
{
    Object *obj = OBJECT(opaque);

    qemu_log_mask(LOG_GUEST_ERROR, "%s: Write to unmapped TCM while RPU is in"
                  " lockstep mode @%" HWADDR_PRIx "\n",
                  object_get_canonical_path(obj), addr);
}

static const MemoryRegionOps disabled_tcm_ops = {
    .read = disabled_tcm_read,
    .write = disabled_tcm_write,
};

static void zynqmp_rpu_0_handle_wfi(void *opaque, int irq, int level)
{
    RPU *s = XLNX_RPU_CTRL(opaque);

    s->cpu_in_wfi[0] = level;
    update_wfi_out(s);
}

static void zynqmp_rpu_1_handle_wfi(void *opaque, int irq, int level)
{
    RPU *s = XLNX_RPU_CTRL(opaque);

    s->cpu_in_wfi[1] = level;
    update_wfi_out(s);
}

static void rpu_realize(DeviceState *dev, Error **errp)
{
    RPU *s = XLNX_RPU_CTRL(dev);
    const char *prefix = object_get_canonical_path(OBJECT(dev));
    unsigned int i;
    hwaddr region_addr;
    MemoryRegion *region_container;
    uint32_t region_priority;

    for (i = 0; i < ARRAY_SIZE(rpu_regs_info); ++i) {
        DepRegisterInfo *r = &s->regs_info[rpu_regs_info[i].decode.addr/4];

        *r = (DepRegisterInfo) {
            .data = (uint8_t *)&s->regs[
                    rpu_regs_info[i].decode.addr/4],
            .data_size = sizeof(uint32_t),
            .access = &rpu_regs_info[i],
            .debug = XLNX_RPU_CTRL_ERR_DEBUG,
            .prefix = prefix,
            .opaque = s,
        };
        dep_register_init(r);
        qdev_pass_all_gpios(DEVICE(r), dev);
    }

    if (!s->atcm1_for_rpu0) {
        error_setg(errp, "atcm1-for-rpu0");
        return;
    }

    if (!s->btcm1_for_rpu0) {
        error_setg(errp, "btcm1-for-rpu0");
        return;
    }

    if (!s->icache_for_rpu1) {
        error_setg(errp, "icache-for-rpu1");
        return;
    }

    if (!s->dcache_for_rpu1) {
        error_setg(errp, "dcache-for-rpu1");
        return;
    }

    if (!s->ddr) {
        error_setg(errp, "ddr-mem-for-rpu");
        return;
    }

    if (!s->gic) {
        error_setg(errp, "gic-for-rpu");
        return;
    }

    /* RPUs starts in lockstep mode, so the rpu1 caches are not accessible. */
    memory_region_set_enabled(s->icache_for_rpu1, false);
    memory_region_set_enabled(s->dcache_for_rpu1, false);
    memory_region_set_enabled(s->ddr, false);

    /* This initialize some "mask" memory region
     * Basically they hide what is behind so the *tcm are not accessible.
     */
    memory_region_init_io(&s->atcm1_mask, OBJECT(s), &disabled_tcm_ops, s,
                          "atcm1_mask", memory_region_size(s->atcm1_for_rpu0));
    region_container = MEMORY_REGION(object_property_get_link(
                                                OBJECT(s->atcm1_for_rpu0),
                                                "container", NULL));
    region_addr = object_property_get_int(OBJECT(s->atcm1_for_rpu0), "addr",
                                          NULL);
    region_priority = object_property_get_int(OBJECT(s->atcm1_for_rpu0),
                                              "priority", NULL) + 1;
    object_property_set_int(OBJECT(&s->atcm1_mask), region_priority, "priority",
                            NULL);
    memory_region_add_subregion(region_container, region_addr, &s->atcm1_mask);

    memory_region_init_io(&s->btcm1_mask, OBJECT(s), &disabled_tcm_ops, s,
                          "btcm1_mask", memory_region_size(s->btcm1_for_rpu0));
    region_container = MEMORY_REGION(object_property_get_link(
                                                OBJECT(s->btcm1_for_rpu0),
                                                "container", NULL));
    region_addr = object_property_get_int(OBJECT(s->btcm1_for_rpu0), "addr",
                                          NULL);
    region_priority = object_property_get_int(OBJECT(s->btcm1_for_rpu0),
                                              "priority", NULL) + 1;
    object_property_set_int(OBJECT(&s->btcm1_mask), region_priority, "priority",
                            NULL);
    memory_region_add_subregion(region_container, region_addr, &s->btcm1_mask);
}

static void rpu_init(Object *obj)
{
    RPU *s = XLNX_RPU_CTRL(obj);
    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);

    memory_region_init_io(&s->iomem, obj, &rpu_ops, s,
                          TYPE_XLNX_RPU_CTRL, R_MAX * 4);
    sysbus_init_mmio(sbd, &s->iomem);
    sysbus_init_irq(sbd, &s->irq_rpu_1);
    sysbus_init_irq(sbd, &s->irq_rpu_0);

    /* xtcm1-for-rpu0 are the aliases for the tcm in lockstep mode.
     * This link allows to enable/disable those aliases when we are in
     * lock-step/normal mode.
     */
    object_property_add_link(obj, "atcm1-for-rpu0", TYPE_MEMORY_REGION,
                             (Object **)&s->atcm1_for_rpu0,
                             qdev_prop_allow_set_link_before_realize,
                             OBJ_PROP_LINK_UNREF_ON_RELEASE,
                             &error_abort);
    object_property_add_link(obj, "btcm1-for-rpu0", TYPE_MEMORY_REGION,
                             (Object **)&s->btcm1_for_rpu0,
                             qdev_prop_allow_set_link_before_realize,
                             OBJ_PROP_LINK_UNREF_ON_RELEASE,
                             &error_abort);
    object_property_add_link(obj, "rpu1-for-main-bus", TYPE_MEMORY_REGION,
                             (Object **)&s->atcm1_for_rpu0,
                             qdev_prop_allow_set_link_before_realize,
                             OBJ_PROP_LINK_UNREF_ON_RELEASE,
                             &error_abort);

    /* This link allows to enable/disable those memory region when we are in
     * lock-step/normal mode.
     */
    object_property_add_link(obj, "icache-for-rpu1", TYPE_MEMORY_REGION,
                             (Object **)&s->icache_for_rpu1,
                             qdev_prop_allow_set_link_before_realize,
                             OBJ_PROP_LINK_UNREF_ON_RELEASE,
                             &error_abort);
    object_property_add_link(obj, "dcache-for-rpu1", TYPE_MEMORY_REGION,
                             (Object **)&s->dcache_for_rpu1,
                             qdev_prop_allow_set_link_before_realize,
                             OBJ_PROP_LINK_UNREF_ON_RELEASE,
                             &error_abort);

    /* Link to the second part of the DDR which is enabled in split mode and
     * disabled in lockstep mode.
     */
    object_property_add_link(obj, "ddr-mem-for-rpu", TYPE_MEMORY_REGION,
                             (Object **)&s->ddr,
                             qdev_prop_allow_set_link_before_realize,
                             OBJ_PROP_LINK_UNREF_ON_RELEASE,
                             &error_abort);

    /* Link to the GIC which allow to inject irq through rpu_intr/rpu_mask
     * registers
     */
    object_property_add_link(obj, "gic-for-rpu", TYPE_XLNX_SCU_GIC,
                             (Object **)&s->gic,
                             qdev_prop_allow_set_link_before_realize,
                             OBJ_PROP_LINK_UNREF_ON_RELEASE,
                             &error_abort);

    /* comp_fault gpios are connected to the PMU. */
    qdev_init_gpio_out_named(DEVICE(obj), s->comp_fault, "comp_fault", 2);
    /* wfi_out is used to connect to PMU GPIs. */
    qdev_init_gpio_out_named(DEVICE(obj), s->wfi_out, "wfi_out", 2);
    /* wfi_in is used as input from CPUs as wfi request. */
    qdev_init_gpio_in_named(DEVICE(obj), zynqmp_rpu_0_handle_wfi, "wfi_in_0", 1);
    qdev_init_gpio_in_named(DEVICE(obj), zynqmp_rpu_1_handle_wfi, "wfi_in_1", 1);
}

static const VMStateDescription vmstate_rpu = {
    .name = TYPE_XLNX_RPU_CTRL,
    .version_id = 1,
    .minimum_version_id = 1,
    .minimum_version_id_old = 1,
    .fields = (VMStateField[]) {
        VMSTATE_UINT32_ARRAY(regs, RPU, R_MAX),
        VMSTATE_END_OF_LIST(),
    }
};

static const FDTGenericGPIOSet rpu_controller_gpios [] = {
    {
        .names = &fdt_generic_gpio_name_set_gpio,
        .gpios = (FDTGenericGPIOConnection [])  {
            { .name = "R5_0_HALT",          .fdt_index = 0 },
            { .name = "R5_1_HALT",          .fdt_index = 1 },
            { .name = "R5_SLSPLIT",         .fdt_index = 2 },
            { .name = "R5_0_PWRDWN_REQ",    .fdt_index = 3 },
            { .name = "R5_1_PWRDWN_REQ",    .fdt_index = 4 },
            { .name = "R5_0_VINITHI",       .fdt_index = 5 },
            { .name = "R5_1_VINITHI",       .fdt_index = 6 },
            { .name = "wfi_in_0",           .fdt_index = 7 },
            { .name = "wfi_in_1",           .fdt_index = 8 },
            { },
        },
    },
    { },
};

static const FDTGenericGPIOSet rpu_client_gpios [] = {
    {
        .names = &fdt_generic_gpio_name_set_gpio,
        .gpios = (FDTGenericGPIOConnection [])  {
            { .name = "comp_fault",         .fdt_index = 0, .range = 2 },
            { .name = "wfi_out",            .fdt_index = 2, .range = 2 },
            { },
        },
    },
    { },
};

static void rpu_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    FDTGenericGPIOClass *fggc = FDT_GENERIC_GPIO_CLASS(klass);

    dc->reset = rpu_reset;
    dc->realize = rpu_realize;
    dc->vmsd = &vmstate_rpu;
    fggc->controller_gpios = rpu_controller_gpios;
    fggc->client_gpios = rpu_client_gpios;
}

static const TypeInfo rpu_info = {
    .name          = TYPE_XLNX_RPU_CTRL,
    .parent        = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(RPU),
    .class_init    = rpu_class_init,
    .instance_init = rpu_init,
    .interfaces    = (InterfaceInfo[]) {
        { TYPE_FDT_GENERIC_GPIO },
        { }
    },
};

static void rpu_register_types(void)
{
    type_register_static(&rpu_info);
}

type_init(rpu_register_types)
