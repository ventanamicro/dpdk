/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2017 Cavium, Inc
 * Copyright(c) 2019 Arm Limited
 * Copyright(c) 2021 Ventana Microsystems
 */

#ifndef _RTE_PAUSE_RISCV64_H_
#define _RTE_PAUSE_RISCV64_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <rte_common.h>
#include "generic/rte_pause.h"

static inline void rte_pause(void)
{
	asm volatile("nop" ::: "memory");
}

#ifdef __cplusplus
}
#endif

#endif /* _RTE_PAUSE_RISCV64_H_ */