/* ********************************************************************************************** */
/*                                                                                                */
/*   ESP32 Hard Fault Tests                                            :::::::::        :::       */
/*   functions.h                                                      :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2025/01/14 15:00:00                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2025/01/14 15:00:00                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/* ********************************************************************************************** */

#include "ESP32_Hard_Fault_Tests.h"


/*
 *  Dividing by zero may result in
 *  a hard fault in many systems.
*/
int divide_by_zero(void)      
{
    int a = 1;
    int c = 0;
    int b = a / c;
    return (b);                                                 // forces compiler to actually run this
}


/*
 *  Uninitalized globals ends up 
 *  initialized to 0.
 *  Writing to null or uninitialized
 *  pointers will cause a hard fault.
*/
int* global_ptr_to_null = NULL;
int* global_ptr_unitialized;
int write_to_null(void)
{
    int* ptr_to_null = NULL;
    int* ptr_unitialized;

    *global_ptr_to_null  = 10;                                  // tries to write to address zero
    *global_ptr_unitialized = 10;                               // tries to write to address zero
    *ptr_to_null  = 10;                                         // tries to write to address zero
    *ptr_unitialized = 10;                                      // tries to write ?? somewhere ??

    return (*global_ptr_to_null + *global_ptr_unitialized +
          *ptr_to_null + *ptr_unitialized);                     // forces compiler to actually run this
}


/*
 *  Invalid Function Pointer:
 *  calling an invalid function pointer
 *  can cause a hard fault.
*/
int illegal_instruction_execution(void)
{
    int instruction = 0xFFFFFFFF;                               // Assuming 0xFFFFFFFF is a bad address
    int (*bad_instruction)(void) = (int(*)())(&instruction);
    return (bad_instruction());
}


/*
 *  Accessing Invalid Memory:
 *  accessing memory outside the valid
 *  range can trigger a hard fault.
*/
int illegal_address_execution(void)
{
    int (*illegal_address)(void) = (int(*)())0xFFFFFFFF;
    return (illegal_address());
}


/*
 *  This function will execute code at the address
 *  zero, which is often the reset code.
 *  Anyway, calling a function pointer
 *  that is null will cause a hard fault.
*/
void (*fun_ptr)(void);
void call_null_pointer_function(void)
{
    fun_ptr();
}


/*
 *  This function will eventually
 *  cause a stack overflow, leading
 *  to a hard fault.
*/
void recursive_function(void)
{
    recursive_function();  
}


/*
 *  Returning a pointer to the stack
 *  allocated memory may cause undefined
 *  behavior but not necessarily a hard fault.
*/
int* dont_return_stack_memory(void)
{
    int stack_memory[100];
    return (stack_memory);
}


/*
 *  Returning a pointer to the heap allocated
 *  and freed memory may cause undefined
 *  behavior but not necessarily a hard fault.
*/
int* dont_return_malloc_and_freed_memory(void)
{
    int *memory = (int *)malloc(100);
    free(memory);
    return (memory);
}


/*
 *  Freeing the same memory twice can cause
 *  undefined behavior and potentially a crash.
*/
void double_free(void)
{
    int *ptr = (int *)malloc(100);
    free(ptr);
    free(ptr); // Double free
}


/*
 *  Assigning a 32-bit value to an 8-bit variable
 *  leads to data truncation and potential data loss,
 *  but not to a crash or to a hard fault.
*/
uint8_t unaligned_access_ok(void)
{
    uint32_t bigVariable = 0xAABBCCDD;
    uint32_t  *ptr = &bigVariable;
    uint8_t  smallVariable = *ptr;
    return (smallVariable);
}


/*
 *  &buffer[i] gets the address of the i-th element in the buffer array.
 *  This address is then cast to a uint32_t * (pointer to a 32-bit integer).
 *  Dereferencing this pointer (*((uint32_t *)( &buffer[i] ))) reads 4 bytes
 *  starting from the address &buffer[i].
 *  The potential issue here is that the address &buffer[i] may not be aligned
 *  to a 4-byte boundary, which is required for 32-bit accesses on many architectures.
 *  Accessing unaligned memory can lead to undefined behavior, including hard faults.
 *  For example index 1 and 2 would cause the system to read addresses, 
 *  which are not aligned to a 4-byte boundary.
*/
uint32_t unaligned_access_bad(int index)
{
    uint8_t buffer[6] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};
    uint8_t i = index;
    uint32_t val_BB_to_EE = *((uint32_t *)( &buffer[i] ));
    return (val_BB_to_EE);
}

 