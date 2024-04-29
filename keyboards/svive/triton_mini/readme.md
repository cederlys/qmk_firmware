# svive/triton_mini

![svive/triton_mini](imgur.com image replace me!)

A 60% keyboard from Svive with non-hotpluggable mechanical switches
and an RGB matrix.

* Keyboard Maintainer: [Per Cederqvist](https://github.com/cederlys)
* Hardware Supported: Svive Triton Mini, also known as Svive Tritium Mini or Svive Triton 60%
* Hardware Availability: [Svive official website](https://www.svive.gg/products/triton-rgb-mini-black/?v=3)

Make example for this keyboard (after setting up your build environment):

    make svive/triton_mini:default

Flashing example for this keyboard:

    This keyboard must be flashed with an external tool (https://github.com/SonixQMK/sonix-flasher)

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard.
* **Physical reset**: Short the GND and BOOT pads on the PCB while connecting the keyboard. They are accessible if you remove the space keycap. See https://github.com/cederlys/svive-qmk for images and hints.
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available.  In the default keymap, this is mapped to Fn+ESC.
