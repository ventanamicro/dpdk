/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2015 Cavium, Inc
 * Copyright(c) 2020 Arm Limited
 * Copyright(c) 2021 Ventana Microsystems
 */

#ifndef _RTE_CYCLES_RISCV64_H_
#define _RTE_CYCLES_RISCV64_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "generic/rte_cycles.h"

/**
 * Read the time base register.
 *
 * @return
 *   The time base for this lcore.
 */
static inline uint64_t
rte_rdtsc(void)
{
	uint64_t cycles;

	asm volatile("rdtime %0" : "=r" (cycles));
	return cycles;
}

static inline uint64_t
rte_rdtsc_precise(void)
{
	rte_mb();
	return rte_rdtsc();
}

static inline uint64_t
rte_get_tsc_cycles(void)
{
	return rte_rdtsc();
}

#ifdef __cplusplus
}
#endif

#endif /* _RTE_CYCLES_RISCV64_H_ */
