/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2017 Cavium, Inc
 * Copyright(c) 2021 Ventana Microsystems
 */

#ifndef _RTE_PAUSE_RISCV_H_
#define _RTE_PAUSE_RISCV_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef RTE_ARCH_64
#include <rte_pause_64.h>
#else
#include <rte_pause_32.h>
#endif

#ifdef __cplusplus
}
#endif

#endif /* _RTE_PAUSE_RISCV_H_ */
