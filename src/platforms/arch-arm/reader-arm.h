//    Copyright 2017 jmpews
//
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.

#ifndef platforms_arch_arm_reader_arm_h
#define platforms_arch_arm_reader_arm_h

#include "hookzz.h"
#include "kitzz.h"

#include "instructions.h"

typedef enum _ARMInsnType {
    ARM_INS_ADD_register_A1,
    ARM_INS_LDR_literal_A1,
    ARM_INS_ADR_A1,
    ARM_INS_ADR_A2,
    ARM_INS_B_A1,
    ARM_INS_BLBLX_immediate_A1,
    ARM_INS_BLBLX_immediate_A2,
    ARM_UNDEF
} ARMInsnType;

#define MAX_INSN_SIZE 256
typedef struct _ZzARMReader {
    ZzARMInstruction *insns[MAX_INSN_SIZE];
    zz_size_t insn_size;
    zz_ptr_t r_start_address;
    zz_ptr_t r_current_address;
    zz_addr_t pc;
    zz_size_t size;
} ZzARMReader;

ARMInsnType GetARMInsnType(uint32_t insn);

ZzARMReader *zz_arm_reader_new(zz_ptr_t insn_address);
void zz_arm_reader_init(ZzARMReader *self, zz_ptr_t insn_address);
void zz_arm_reader_reset(ZzARMReader *self, zz_ptr_t insn_address);
void zz_arm_reader_free(ZzARMReader *self);
ZzARMInstruction *zz_arm_reader_read_one_instruction(ZzARMReader *self);

#endif