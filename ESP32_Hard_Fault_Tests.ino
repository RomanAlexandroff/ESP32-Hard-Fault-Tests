
/* ********************************************************************************************** */
/*                                                                                                */
/*   ESP32 Hard Fault Tests                                            :::::::::        :::       */
/*   ESP32_Hard_Fault_Tests.ino                                       :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2025/01/14 15:00:00                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2025/01/14 15:00:00                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   This project consists of functions which sole purpose is to crash or hard-fail an ESP32      */
/*   in as many ways as possible. The project is created as an educational material to learn      */
/*   potential threats for an embedded software execution, so they can be avoided during          */
/*   the future development.                                                                      */
/*   Featured:                                                                                    */
/*      - dividing by 0,                                                                          */
/*      - writing to a memory address pointed to by an uninitalized global pointer,               */
/*      - writing to a memory address pointed to by a null pointer,                               */
/*      - calling an invalid function pointer,                                                    */
/*      - trying to access memory outside the valid range,                                        */
/*      - causing a stack overflow with a recursive function with no limit,                       */
/*      - returning a pointer to the stack allocated memory,                                      */
/*      - returning a pointer to the heap allocated and freed memory,                             */
/*      - freeing the same memory twice,                                                          */
/*      - assigning a 32-bit value to an 8-bit variable,                                          */
/*      - unaligned memory access.                                                                */
/*                                                                                                */
/* ********************************************************************************************** */

#include "ESP32_Hard_Fault_Tests.h"

void setup()
{
    Serial.begin(115200);
    int i = 20;
    while (i > 0)
    {
        Serial.printf("-");
        i--;
    }
}

void loop()
{
    Serial.printf("divide_by_zero result: %d\n", divide_by_zero());                           // Crash without error message
//    write_to_null();                                                                            // Guru Meditation Error: Core  0 panic'ed (Store access fault). Exception was unhandled. Rebooting...
//    illegal_instruction_execution();                                                                // Guru Meditation Error: Core  0 panic'ed (Illegal instruction). Exception was unhandled. Rebooting...
//    Serial.printf("illegal_address_execution result: %d\n", illegal_address_execution());               // Crash without error message
//    call_null_pointer_function();                                                                           // Crash without error message
//    recursive_function();                                                                                       // nothing
//    Serial.printf("dont_return_stack_memory result: %p\n", dont_return_stack_memory());                             // Outputs 0x0, but keeps on running the execution
//    Serial.printf("dont_return_malloc_and_freed_memory result: %p\n", dont_return_malloc_and_freed_memory());           // Outputs 0x4081229c, but keeps on running the execution
//    double_free();                                                                                                  // Keeps on running the execution

    /* UNALIGNED ACCESS */
//    unaligned_access_ok();                                                                              // nothing
//    unaligned_access_bad(0);                                                                        // nothing
//    unaligned_access_bad(1);                                                                    // nothing
//    unaligned_access_bad(2);                                                                // nothing
    delay(3000);
    Serial.printf("- - -");
    delay(3000);
}