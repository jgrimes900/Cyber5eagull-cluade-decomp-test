# Cyber5eagull — Linux port

A native x86-64 Linux build of the Windows game **CyberSeagull5.exe**, produced by
decompiling the original executable and rewriting it as portable C on top of SDL2.

The game logic, rendering and UI are a function-by-function translation of the
original machine code (addresses of the original functions are noted in the
source). The port is checked against the original: a test harness runs the
real Windows executable on Linux with scripted input, and the port produces
**pixel-identical frames and identical simulation state** for the same input
(see [Verification](#verification)).

## Building on Linux Mint (or any Debian/Ubuntu)

```sh
sudo apt install build-essential libsdl2-dev
make
./cyberseagull
```

The game reads its art and sounds from `resources/` (included in this repo). It
looks in the current directory first and otherwise next to the executable, so
it can also be started from a file manager. To install elsewhere, copy
`cyberseagull` together with the `resources/` folder.

## Controls

| Input | Action |
| --- | --- |
| Left click | Dismiss tutorial pages; order seagulls to harvest ore / flowers / nests; place the selected building (drag for conveyor lines) |
| Right click / drag | Cancel an order, or demolish with a building selected; on a machine: open its recipe picker |
| `1`–`9`, `0`, `-`, `=` | Build-menu slots (`0` buys a seagull) |
| `Tab` | Show/hide the build menu |
| `R` / `Shift+R` | Rotate the building being placed |
| `Q` | Pick the building under the cursor |
| `Esc` | Clear the selection |
| Hold `Ctrl` | Work on the upper layer (chutes / elevators) |
| `W` `A` `S` `D`, screen edges | Scroll |
| `Shift`+drag, middle drag | Pan |
| Mouse wheel / `Shift`+wheel | Zoom / scroll sideways |
| Click an inventory item, then a conveyor | Have seagulls deliver that item |
| Hold `Space` | Show hive ranges |
| Hold `C` | Show the controls card |
| `CapsLock` held + `R` / `Tab` / `E` | Restart / sandbox palette / 50 of every item (developer keys present in the original) |

Deliver 20 cyber seagulls to the dock to win.

## Layout

| Path | Contents |
| --- | --- |
| `src/` | The port. `game.c` (startup, main loop, building simulation), `seagull.c` (workers), `jobs.c`/`orders.c` (tasks, path finding), `worldgen.c`, `nests.c`, `entity.c`, `items.c`, `place.c` (placement tools, preview), `input.c`, `ui.c`, `render*.c`, `assets.c` (textures, WAV, mixer), `png.c` (decoder), `platform_sdl.c` (window/input/audio) |
| `resources/` | The game's original textures and sounds |
| `decomp/` | Ghidra decompilation of the original and helper scripts used during the port |
| `tools/oracle/` | Harness that runs the original `.exe` natively on Linux (headless) for comparison |
| `tools/compare.sh`, `tools/tests/` | Frame/state comparison between the original and the port |
| `tools/RE_NOTES.md` | Reverse-engineering notes |

## Faithfulness notes

Behaviour is kept identical to the original, including its quirks:

* The random number generator is xoshiro256++ with the original's mixing step
  `(x << 23) | (x >> 31)` instead of a 23-bit rotate.
* Floating point follows the original's instruction sequence (explicit `fmaf`
  where it used FMA, `-ffp-contract=off` elsewhere, flush-to-zero/denormals-are-zero).
* The original's own PNG decoder handled greyscale images unusually (they come out
  red); the port's decoder reproduces that. The game's own assets are RGBA, so this
  only matters for modded art.
* Sound effects are scaled by 0.5 while the window has focus and by 20 when it
  doesn't (so they get loud and clip while the game is in the background). This is
  what the original does.

Platform differences: SDL2 replaces Win32/GDI/WASAPI/raw input. The window is
created with a 960×540 client area (the original asked Windows for a 960×540 window
including borders) and is resizable, as before.

## Verification

`tools/compare.sh` runs the original executable (not included; pass its path) and
the port on the same input script and compares every dumped frame and state:

```sh
make
tools/compare.sh /path/to/CyberSeagull5.exe tools/tests/t6.txt
```

Script lines are `<frame> M x y` (cursor), `<frame> K vk down` (Windows key code),
`<frame> B button down`, `<frame> W delta` (wheel), `<frame> D` (dump frame),
`<frame> S` (dump state), `<frame> Q` (quit). In test mode the port runs headless
with a fixed 1/60 s clock and a fixed random seed (`CYBERSEAGULL_SCRIPT=script
CYBERSEAGULL_OUT=dir ./cyberseagull`).

The included scripts cover the tutorial, harvesting, conveyors, every building
type with rotations, item delivery and pickup, layer-1 placement, the recipe
picker, demolition, buying seagulls and several thousand simulated frames; all
are identical to the original. The full win sequence (20 cyber seagulls) has not
been played through by a script.
