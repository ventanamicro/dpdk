# SPDX-License-Identifier: BSD-3-Clause
# Copyright(c) 2021 Ventana Microsystems.

message('Max cores supported: ' + get_option('max_lcores').to_string())
message('Cache Line Size: ' + get_option('cache_line_size').to_string())
message('Vector Support: ' + get_option('vector_support').to_string())

# check if required options are set
if get_option('max_lcores') == 0
    error('Max number of CPU cores not specified. Use option -Dmax_lcores')
endif

if get_option('cache_line_size') == 0
    error('Cache line size for CPU not specified. Use option -Dcache_line_size')
endif

max_lcores = get_option('max_lcores')
cache_line_size = get_option('cache_line_size')
vector_support = get_option('vector_support')

dpdk_conf.set('RTE_MACHINE', 'riscv64')
dpdk_conf.set('RTE_ARCH_RISCV64', 1)
dpdk_conf.set('RTE_ARCH', 'riscv64')
dpdk_conf.set('RTE_FORCE_INTRINSICS', 1)
dpdk_conf.set('RTE_CACHE_LINE_SIZE', cache_line_size)
dpdk_conf.set('RTE_MAX_LCORE', max_lcores)
dpdk_conf.set('RTE_SCHED_VECTOR', vector_support)
dpdk_conf.set('RTE_USE_C11_MEM_MODEL', true)
dpdk_conf.set('RTE_MAX_NUMA_NODES', 1)

machine_args = [] # Clear previous machine args
