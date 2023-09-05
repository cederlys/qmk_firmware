# svive/triton_full

![svive/triton_full](imgur.com image replace me!)

A fullsized keyboard from Svive with hotpluggable mechanical switches
and an RGB matrix.

* Keyboard Maintainer: [Per Cederqvist](https://github.com/cederlys)
* Hardware Supported: Svive Triton Full, also known as Svive Tritium Full or Svive Triton Pro RGB
* Hardware Availability: [Svive official website](https://www.svive.gg/products/triton-full-rgb-keyboard-black/?v=3)

Make example for this keyboard (after setting up your build environment):

    make svive/triton_full:default

Flashing example for this keyboard:

    This keyboard must be flashed with an external tool (https://github.com/SonixQMK/sonix-flasher)

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard.
* **Physical reset**: Short the GND and BOOT pads on the PCB while connecting the keyboard. See https://github.com/cederlys/svive-qmk for images and hints.
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available.  In the default keymap, this is mapped to Fn+ESC.
