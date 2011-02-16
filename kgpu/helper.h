#ifndef __HELPER_H__
#define __HELPER_H__

#include "kgpu.h"
#include "list.h"

struct service;

struct service_request {
    struct ku_request kureq;
    struct service *s;
    int block_x, block_y;
    int grid_x, grid_y;
    int state;
    int errno;
    int stream_id;
    void *dinput;
    void *doutput;
    void *data;
    struct list_head glist;
    struct list_head list;
};

/* service request states: */
#define REQ_INIT 1
#define REQ_MEM_DONE 2
#define REQ_PREPARED 3
#define REQ_RUNNING 4
#define REQ_POST_EXEC 5
#define REQ_DONE 6

int alloc_gpu_mem(struct service_request *sreq);
void free_gpu_mem(struct service_request *sreq);
int alloc_stream(struct service_request *sreq);
void free_stream(struct service_request *sreq);
struct service_request* alloc_service_request();
void free_service_request(struct service_request *sreq);

int alloc_gpu_buffers(struct gpu_buffer gbufs[], int n, unsigned long size);
void free_gpu_buffers(struct gpu_buffer gbufs[], int n);

#include "service.h"
   
#endif