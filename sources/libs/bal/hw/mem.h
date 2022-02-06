#pragma once

#include <bal/abi.h>
#include <brutal/base.h>
#include <brutal/text.h>

/** @file */

typedef struct
{
    size_t len;
    void *buf;
    BrHandle handle;
    uintptr_t paddr;
} BalMem;

/**
 *  @brief Get the handle of a memory object .
 *  @param self Memory object to get the handle.
 *  @return Memory object handle.
 */
static inline BrHandle bal_mem_handle(BalMem const *self)
{
    return self->handle;
}

/**
 * @brief Create a new memory object from a memory handle.
 * @warning **the ownerships of the handle is given to the memory object**.
 * @note This function calls the `bal_mem_init_mobj_offset` function.
 * @param self Memory object to create.
 * @param handle Handle to give to the created memory object.
 * @returns This function may return an error if we weren't able to map the \p handle.
 */
MaybeError bal_mem_init_mobj(BalMem *self, BrHandle handle);

/**
 * @brief Create a new memory object from a memory handle with an offset and a length.
 * @warning **the ownerships of the handle is given to the memory object**
 * @param self The memory object to create.
 * @param handle The handle to give to the created memory object.
 * @param offset, len The offset and the length of the memory object to create.
 * @returns This function may return an error if we weren't able to map the \p handle.
 */
MaybeError bal_mem_init_mobj_offset(BalMem *self, BrHandle handle, size_t offset, size_t len);

/**
 * @brief Create a new memory object with a specific physical address and size.
 * @note This also map the physical memory address. You can access it using `BalMem.buf`
 * @param self The memory object to create.
 * @param addr, size The physical memory range to use when creating the object.
 * @returns This function may return an error if we weren't able to map or create the memory.
 */
MaybeError bal_mem_init_pmm(BalMem *self, uintptr_t addr, size_t size);

/**
 * @brief Create a new memory object with a specified size.
 * @note This is the same as calling bal_mem_init_pmm but instead of using a physical address,
 *       we create a new one ourself.
 * @param self The memory object to create.
 * @param size The size of the memory to create.
 * @returns This function may return an error if we weren't able to map or create the memory.
 */
MaybeError bal_mem_init_size(BalMem *self, size_t size);

/**
 * @brief Deinitialize a memory object. This frees the memory object and close the handle.
 * @param self The memory object to deinitialize.
 * @returns This function may return an error if we weren't able to unmap or close the handle.
 */
MaybeError bal_mem_deinit(BalMem *self);

/**
 * @brief Get the physical address of an handle.
 * @param self The memory object to get the physical addr.
 * @param[out] paddr The physical address of the memory object.
 * @returns This function may return an error if we weren't able to inspect the handle.
 */
MaybeError bal_memobj_paddr(BrHandle obj, uintptr_t *paddr);
