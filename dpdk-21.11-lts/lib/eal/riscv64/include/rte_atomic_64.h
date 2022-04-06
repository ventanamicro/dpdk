/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2015 Cavium, Inc
 * Copyright(c) 2020 Arm Limited
 * Copyright(c) 2021 Ventana Microsystems
 */

#ifndef _RTE_ATOMIC_RISCV64_H_
#define _RTE_ATOMIC_RISCV64_H_

#ifndef RTE_FORCE_INTRINSICS
#  error Platform must be built with RTE_FORCE_INTRINSICS
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "generic/rte_atomic.h"
#include <rte_branch_prediction.h>
#include <rte_compat.h>
#include <rte_debug.h>

#define rte_mb() asm volatile("fence rw,rw" : : : "memory")

#define rte_wmb() asm volatile("fence w,w" : : : "memory")

#define rte_rmb() asm volatile("fence r,r" : : : "memory")

#define rte_smp_mb() asm volatile("fence rw,rw" : : : "memory")

#define rte_smp_wmb() asm volatile("fence w,w" : : : "memory")

#define rte_smp_rmb() asm volatile("fence r,r" : : : "memory")

#define rte_io_mb() asm volatile("fence iorw,iorw" : : : "memory")

#define rte_io_wmb() asm volatile("fence ow,ow" : : : "memory")

#define rte_io_rmb() asm volatile("fence ir,ir" : : : "memory")

static __rte_always_inline void
rte_atomic_thread_fence(int memorder)
{
	__atomic_thread_fence(memorder);
}

#ifdef __cplusplus
}
#endif

#endif /* _RTE_ATOMIC_RISCV64_H_ */
