/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) Cavium, Inc. 2015.
 * Copyright(c) 2015 RehiveTech. All rights reserved.
 * Copyright(c) 2021 Ventana Microsystems
 */

#include "rte_cpuflags.h"

#include <elf.h>
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

#define AT_HWCAP 16

enum cpu_register_t {
	REG_NONE = 0,
	REG_HWCAP, /* MISA CSR */
	REG_MAX
};

typedef uint32_t hwcap_registers_t[REG_MAX];

/**
 * Struct to hold a processor feature entry
 */
struct feature_entry {
	uint32_t reg;
	uint32_t bit;
#define CPU_FLAG_NAME_MAX_LEN 64
	char name[CPU_FLAG_NAME_MAX_LEN];
};

#define FEAT_DEF(name, reg, bit) \
	[RTE_CPUFLAG_##name] = {reg, bit, #name},

const struct feature_entry rte_cpu_feature_table[] = {
	FEAT_DEF(ATOMICS,         REG_HWCAP,    0)
	FEAT_DEF(BIT_MANIP,       REG_HWCAP,    1)
	FEAT_DEF(COMPRESSED,      REG_HWCAP,    2)
	FEAT_DEF(DOUBLE_FP,       REG_HWCAP,    3)
	FEAT_DEF(RV32E,	          REG_HWCAP,    4)
	FEAT_DEF(SINGLE_FP,       REG_HWCAP,    5)
	FEAT_DEF(RES0,            REG_HWCAP,    6)
	FEAT_DEF(HYPERVISOR,      REG_HWCAP,    7)
	FEAT_DEF(RV_32I_64I_128I, REG_HWCAP,    8)
	FEAT_DEF(DTL,             REG_HWCAP,    9)
	FEAT_DEF(RES1,            REG_HWCAP,   10)
	FEAT_DEF(DECIMAL_FP,      REG_HWCAP,   11)
	FEAT_DEF(INT_MUL_DIV,     REG_HWCAP,   12)
	FEAT_DEF(USR_INTR,        REG_HWCAP,   13)
	FEAT_DEF(RES2,            REG_HWCAP,   14)
	FEAT_DEF(SIMD,            REG_HWCAP,   15)
	FEAT_DEF(QUAD_FP,         REG_HWCAP,   16)
	FEAT_DEF(RES3,            REG_HWCAP,   17)
	FEAT_DEF(SUPERVISOR,      REG_HWCAP,   18)
	FEAT_DEF(TM,              REG_HWCAP,   19)
	FEAT_DEF(USER,            REG_HWCAP,   20)
	FEAT_DEF(VECTOR,          REG_HWCAP,   21)
	FEAT_DEF(RES4,            REG_HWCAP,   22)
	FEAT_DEF(NON_STD,         REG_HWCAP,   23)
	FEAT_DEF(RES5,            REG_HWCAP,   24)
	FEAT_DEF(RES6,            REG_HWCAP,   25)
};

/*
 * Read AUXV software register and get cpu features for ARM
 */
static void
rte_cpu_get_features(hwcap_registers_t out)
{
	uint32_t misa;
	asm volatile("csrr %0, misa" : "=r" (misa));
	out[REG_HWCAP] = misa;
}

/*
 * Checks if a particular flag is available on current machine.
 */
int
rte_cpu_get_flag_enabled(enum rte_cpu_flag_t feature)
{
	const struct feature_entry *feat;
	hwcap_registers_t regs = {0};

	if (feature >= RTE_CPUFLAG_NUMFLAGS)
		return -ENOENT;

	feat = &rte_cpu_feature_table[feature];
	if (feat->reg == REG_NONE)
		return -EFAULT;

	rte_cpu_get_features(regs);
	return (regs[feat->reg] >> feat->bit) & 1;
}

const char *
rte_cpu_get_flag_name(enum rte_cpu_flag_t feature)
{
	if (feature >= RTE_CPUFLAG_NUMFLAGS)
		return NULL;
	return rte_cpu_feature_table[feature].name;
}

void
rte_cpu_get_intrinsics_support(struct rte_cpu_intrinsics *intrinsics)
{
	memset(intrinsics, 0, sizeof(*intrinsics));
}
