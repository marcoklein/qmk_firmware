# Marco Plus

An opinionated, carefully optimized, custom keyboard layout for small keyboard sizes.

## Getting Started

From `qmk_firmware` folder run

```bash
util/docker_build.sh preonic/rev3:marco-plus
```

Run [QMK Toolbox](https://github.com/qmk/qmk_toolbox) to flash onto your keyboard.

---

Install on MacOS:

```sh
brew install qmk/qmk/qmk
```

Compilation

```sh
qmk compile -kb preonic/rev3 -km marco-plus
```

Flash

```sh
qmk flash -kb preonic/rev3 -km marco-plus
```

# Features

## Ergonomic Design
Leveraging thumb keys for `SPACE`, `BACKSPACE`, `ENTER`, and layer switches.
Home Row mods to avoid pinkey overuse and unnecessary stretches.

## Caps Word
`CAPS_WORD` capitalizes the next word. It activates caps lock and deactivates caps lock if any non-character key gets pressed.
Very useful to write constants.

## Home Row Mods
Inspired by [A guide to home row mods](https://precondition.github.io/home-row-mods) key modifiers like gui, alt, control, and shift sit on the home row.

If you accidentially activate the mods instead of the keys you can configure the `TAPPING_TERM` or even a tapping term for individual keys.
For me the initial challange was typing `io` without triggering the key mod (io is right next to each other on Colemak).

## Umlauts
As I write German from time to time I had the requirement of writing umlauts like `äöü` and special characters like `ß`.
However, I wanted to keep the ANSI layout (like `@` on `SHIFT-2`). Therefore, I employed a custom shift layer and you must select a German key layout on your PC to properly us this layout.

## Navigation

# More

## Limitations and Issues
- if you are using a German keyboard layout on you host, then applications might adopt German based shortcuts

## Ideas
- build in a timer