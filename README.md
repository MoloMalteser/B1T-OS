# B1TOS

Eigenes OS für Raspberry Pi 3, um ein neuronales lernfähiges System zu realisieren.

## Features

- Kleiner Bootloader in Assembly
- Einfacher Kernel in C
- GPIO für zwei Buttons
- Einfaches Neuronenfeld (64 Neuronen)
- Belohnung & Bestrafung per Buttons steuerbar

## Setup

- Toolchain: arm-none-eabi-gcc
- Build: `make`
- Image auf SD-Karte schreiben (z.B. mit dd)
- Raspberry Pi mit Buttons an GPIO17 & GPIO27 starten
