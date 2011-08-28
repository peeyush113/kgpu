/*
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the GPL-COPYING file in the top-level directory.
 *
 * Copyright (c) 2010-2011 University of Utah and the Flux Group.
 * All rights reserved.
 *
 */
 
#ifndef __HELPER_H__
#define __HELPER_H__

#include "kgpu.h"

#define kgpu_log(level, ...) kgpu_do_log(level, "helper", ##__VA_ARGS__)
#define dbg(...) kgpu_log(KGPU_LOG_DEBUG, ##__VA_ARGS__)

extern struct kgpu_gpu_mem_info hostbufs[KGPU_BUF_NR];
extern struct kgpu_gpu_mem_info devbufs[KGPU_BUF_NR];

#ifdef __cplusplus
extern "C" {
#endif

    void init_gpu(void);
    void finit_gpu(void);

    void *alloc_pinned_mem(unsigned long size);
    void free_pinned_mem(void *p);

    int alloc_gpu_mem(struct kgpu_service_request *sreq);
    void free_gpu_mem(struct kgpu_service_request *sreq);
    int alloc_stream(struct kgpu_service_request *sreq);
    void free_stream(struct kgpu_service_request *sreq);

    int execution_finished(struct kgpu_service_request *sreq);
    int post_finished(struct kgpu_service_request *sreq);

    unsigned long get_stream(int sid);

#ifdef __cplusplus
}
#endif
   
#endif
