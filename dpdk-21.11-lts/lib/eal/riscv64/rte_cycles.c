/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2021 Ventana Microsystems
 */

#include "eal_private.h"
#include "rte_cycles.h"

#define RISCV64_TSC_FREQ	1000000

uint64_t
get_tsc_freq_arch(void)
{
	return (uint64_t)RISCV64_TSC_FREQ;
}

