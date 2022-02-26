/*
 * 版权属于：yitter(yitter@126.com)
 * 开源地址：https://gitee.com/yitter/idgenerator
 */
#pragma once

#include <errno.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#include "IdGenOptions.h"
#include "SnowWorkerM1.h"
#include "SnowWorkerM2.h"

typedef struct IdGenerator {
  SnowFlakeWorker *Worker;

  uint64_t (*NextId)();

} IdGenerator;

static IdGenerator *_idGenerator = NULL;

extern IdGenerator *GetIdGenInstance();

extern void SetOptions(IdGeneratorOptions options);
