/*
 * Copyright(c) 2012-2021 Intel Corporation
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */
#ifndef __EVICTION_LRU_H__
#define __EVICTION_LRU_H__

#include "eviction.h"
#include "lru_structs.h"

struct ocf_part;
struct ocf_user_part;
struct ocf_part_runtime;
struct ocf_part_cleaning_ctx;
struct ocf_request;

void evp_lru_init_cline(ocf_cache_t cache, ocf_cache_line_t cline);
void evp_lru_rm_cline(struct ocf_cache *cache, ocf_cache_line_t cline);
bool evp_lru_can_evict(struct ocf_cache *cache);
uint32_t evp_lru_req_clines(struct ocf_request *req,
		struct ocf_part *src_part, uint32_t cline_no);
void evp_lru_hot_cline(struct ocf_cache *cache, ocf_cache_line_t cline);
void evp_lru_init_evp(struct ocf_cache *cache, struct ocf_part *part);
void evp_lru_dirty_cline(struct ocf_cache *cache, struct ocf_part *part,
		ocf_cache_line_t cline);
void evp_lru_clean_cline(struct ocf_cache *cache, struct ocf_part *part,
		ocf_cache_line_t cline);
void evp_lru_clean(ocf_cache_t cache, struct ocf_user_part *user_part,
		ocf_queue_t io_queue, uint32_t count);
void ocf_lru_repart(ocf_cache_t cache, ocf_cache_line_t cline,
		struct ocf_part *src_upart, struct ocf_part *dst_upart);
uint32_t ocf_lru_num_free(ocf_cache_t cache);
void ocf_lru_populate(ocf_cache_t cache, ocf_cache_line_t num_free_clines);

#endif
