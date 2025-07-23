/* Einfacher Bootloader für Raspberry Pi 3 */
/* Lädt später das Kernel-Image oder führt direkt kernel_main aus */

.section .text
.global _start

_start:
    /* Interrupts deaktivieren */
    msr daifset, #0xf

    /* Stackpointer setzen */
    ldr x0, =stack_top
    mov sp, x0

    /* Hier könnten weitere Initialisierungen rein (z.B. RAM-Init) */

    /* Springe zum Kernel */
    bl kernel_main

1: wfe
   b 1b

.section .bss
    .space 0x4000
stack_top:
