/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2021 Ventana Microsystems
 */

#ifndef _RTE_CPUFLAGS_RISCV64_H_
#define _RTE_CPUFLAGS_RISCV64_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Enumeration of all CPU features supported
 */
enum rte_cpu_flag_t {
	RTE_CPUFLAG_ATOMICS = 0, /* Atomic extension */
	RTE_CPUFLAG_BIT_MANIP, /* Bit-Manipulation extension */
	RTE_CPUFLAG_COMPRESSED, /* Compressed extension */
	RTE_CPUFLAG_DOUBLE_FP, /* Double-precision floating-point extension */
	RTE_CPUFLAG_RV32E, /* RV32E base ISA */
	RTE_CPUFLAG_SINGLE_FP, /* Single-precision floating-point extension */
	RTE_CPUFLAG_RES0, /* Reserved */
	RTE_CPUFLAG_HYPERVISOR, /* Hypervisor extension */
	RTE_CPUFLAG_RV_32I_64I_128I, /* RV32I/64I/128I base ISA */
	RTE_CPUFLAG_DTL, /* Dynamically Translated Languages extension */
	RTE_CPUFLAG_RES1, /* Reserved */
	RTE_CPUFLAG_DECIMAL_FP, /* Decimal Floating-Point extension */
	RTE_CPUFLAG_INT_MUL_DIV, /* Integer Multiply/Divide extension */
	RTE_CPUFLAG_USR_INTR, /* User-level interrupts supported */
	RTE_CPUFLAG_RES2, /* Reserved */
	RTE_CPUFLAG_SIMD, /* Packed-SIMD extension */
	RTE_CPUFLAG_QUAD_FP, /* Quad-precision floating-point extension */
	RTE_CPUFLAG_RES3, /* Reserved */
	RTE_CPUFLAG_SUPERVISOR, /* Supervisor mode implemented */
	RTE_CPUFLAG_TM, /* Transactional Memory extension */
	RTE_CPUFLAG_USER, /* User mode implemented */
	RTE_CPUFLAG_VECTOR, /* Vector extension */
	RTE_CPUFLAG_RES4, /* Reserved */
	RTE_CPUFLAG_NON_STD, /* Non-standard extensions present */
	RTE_CPUFLAG_RES5, /* Reserved */
	RTE_CPUFLAG_RES6, /* Reserved */
	/* The last item */
	RTE_CPUFLAG_NUMFLAGS,/**< This should always be the last! */
};

#include "generic/rte_cpuflags.h"

#ifdef __cplusplus
}
#endif

#endif /* _RTE_CPUFLAGS_RISCV64_H_ */
