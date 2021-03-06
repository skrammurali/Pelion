//----------------------------------------------------------------------------
//   The confidential and proprietary information contained in this file may
//   only be used by a person authorised under and to the extent permitted
//   by a subsisting licensing agreement from ARM Limited or its affiliates.
//
//          (C) COPYRIGHT 2017 ARM Limited or its affiliates.
//              ALL RIGHTS RESERVED
//
//   This entire notice must be reproduced on all copies of this file
//   and copies of this file may only be made by a person if such person is
//   permitted to do so under the terms of a subsisting license agreement
//   from ARM Limited or its affiliates.
//----------------------------------------------------------------------------

#ifndef ARM_UC_PAL_BLOCKDEVICE_PLATFORM_H
#define ARM_UC_PAL_BLOCKDEVICE_PLATFORM_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum {
    ARM_UC_BLOCKDEVICE_SUCCESS = 0,
    ARM_UC_BLOCKDEVICE_FAIL    = -1
};

#define ARM_UC_BLOCKDEVICE_INVALID_SIZE 0xFFFFFFFF

/** Initialize a block device
 *
 *  @return         0 on success or a negative error code on failure
 */
int32_t arm_uc_blockdevice_init(void);

/** Erase blocks on a block device
 *
 *  The state of an erased block is undefined until it has been programmed
 *
 *  @param address  Address of block to begin erasing
 *  @param size     Size to erase in bytes, must be a multiple of erase block size
 *  @return         0 on success, negative error code on failure
 */
int32_t arm_uc_blockdevice_erase(uint64_t address, uint64_t size);

/** Program blocks to a block device
 *
 *  The blocks must have been erased prior to being programmed
 *
 *  If a failure occurs, it is not possible to determine how many bytes succeeded
 *
 *  @param buffer   Buffer of data to write to blocks
 *  @param address  Address of block to begin writing to
 *  @param size     Size to write in bytes, must be a multiple of program block size
 *  @return         0 on success, negative error code on failure
 */
int32_t arm_uc_blockdevice_program(const uint8_t* buffer,
                                   uint64_t address,
                                   uint32_t size);

/** Read blocks from a block device
 *
 *  If a failure occurs, it is not possible to determine how many bytes succeeded
 *
 *  @param buffer   Buffer to write blocks to
 *  @param address  Address of block to begin reading from
 *  @param size     Size to read in bytes, must be a multiple of read block size
 *  @return         0 on success, negative error code on failure
 */
int32_t arm_uc_blockdevice_read(uint8_t* buffer,
                                uint64_t address,
                                uint32_t size);

/** Get the size of a programable block
 *
 *  @return         Size of a programable block in bytes
 *  @note Must be a multiple of the read size
 */
uint32_t arm_uc_blockdevice_get_program_size(void);

/** Get the size of a eraseable block
 *
 *  @return         Size of a eraseable block in bytes
 *  @note Must be a multiple of the program size
 */
uint32_t arm_uc_blockdevice_get_erase_size(void);

#ifdef __cplusplus
}
#endif

#endif /* ARM_UC_PAL_BLOCKDEVICE_PLATFORM_H */
