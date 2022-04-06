/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2015 RehiveTech. All rights reserved.
 * Copyright(c) 2021 Ventana Microsystems
 */

#ifndef _RTE_PREFETCH_RISCV_H_
#define _RTE_PREFETCH_RISCV_H_

#ifdef RTE_ARCH_64
#include <rte_prefetch_64.h>
#else
#include <rte_prefetch_32.h>
#endif

#endif /* _RTE_PREFETCH_RISCV_H_ */
