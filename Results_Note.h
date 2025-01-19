

    Wokwi (simulated) ESP32-C6

  test:           dividing by 0
  optimisation:   default
  result:         crash without error message

  test:           writing to a memory address pointed to by an uninitalized global pointer
  optimisation:   default
  result:         crash with error "Guru Meditation Error: Core  0 panic'ed (Store access fault). Exception was unhandled.", rebooted itself afterwards

  test:           writing to a memory address pointed to by a null pointer
  optimisation:   default
  result:         crash with error "Guru Meditation Error: Core  0 panic'ed (Illegal instruction). Exception was unhandled.", rebooted itself afterwards

  test:           calling an invalid function pointer
  optimisation:   default
  result:         crash without error message

  test:           trying to access memory outside the valid range
  optimisation:   default
  result:         crash without error message

  test:           causing a stack overflow with a recursive function with no limit
  optimisation:   default
  result:         no crash or other negative consequences after 5 minutes of running
                  the test should be configured and run again

  test:           returning a pointer to the stack allocated memory
  optimisation:   default
  result:         outputs 0x0, but keeps on running the execution

  test:           returning a pointer to the heap allocated and freed memory
  optimisation:   default
  result:         outputs 0x4081229c, but keeps on running the execution

  test:           freeing the same memory twice
  optimisation:   default
  result:         no crash or other negative consequences

  test:           assigning a 32-bit value to an 8-bit variable
  optimisation:   default
  result:         no crash or other negative consequences
  
  test:           unaligned memory access
  optimisation:   default
  result:         no crash or other negative consequences

  test:           trying to delete a watchdog task that does not exist / is already deleted
  optimisation:   default
  result:         yet to be tested

  test:           overloading an ISR (Interrupt Service Routine)
  optimisation:   default
  result:         yet to be tested











  
