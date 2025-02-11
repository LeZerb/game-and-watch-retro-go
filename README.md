![](assets/gnw.gif)

# NewUI howto
Please run `make help` to see more information.

最新 Game Genie 以及基于 Game Genie 基础之上的 PCE Rom Patcher 已经可以支持中文化。从 [https://github.com/olderzeus/game-genie-codes-nes/tree/zh_cn](https://github.com/olderzeus/game-genie-codes-nes/tree/zh_cn) 可以查阅或自定义相关文件。

:exclamation::exclamation::exclamation: 任何时候都 **不要** 连接 stlink 的 VCC 和 Game & Watch 主板的 VDD 脚 :exclamation::exclamation::exclamation:

一般情况下只需要连接 GND，SWDIO，SWCLK 3个针脚即可。

来自[apple524](https://github.com/apple524)的 ubuntu 刷机攻略：
[Game & Watch 刷机完全教程](https://apple524.github.io/2022/04/03/g-w-hack/)

來自[maxxkao](http://maxxkao.blogspot.com/)的刷機攻略：

[Nintendo Game & Watch 刷機完全攻略](https://maxxkao.blogspot.com/2022/01/game-watch.html)

[Zelda Game & Watch Dual System 薩爾達機刷雙系統完全攻略](https://maxxkao.blogspot.com/2022/02/zelda-game-watch-dual-boot-wip.html)

## **Undocumented 256k BANK used by default**
 Now NewUI used BANK as undocumented size 256k by default, It's required [patched version of openocd](https://github.com/kbeckmann/ubuntu-openocd-git-builder) to work. You can set `BIG_BANK=0` disabled it to use 128k BANK size.

:exclamation: 128k internal is too small to enough Coverflow UI | i18n | multi font and program more game rom, So [patched version of openocd](https://github.com/kbeckmann/ubuntu-openocd-git-builder) is recommend.

### i18n support
`make CODEPAGE=lang` Sets codepage to configures default display language.(default=1252 as English);
Expert `UICODEPAGE=lang` set the ui display language, default `UICODEPAGE=CODEPAGE`;
- 1252 : English
- 936 : 简体中文
- 950 : 繁體中文
- 949  : 한국어 (translation by [Augen(히힛마스터)](https://github.com/#))
- 12521 : Español (translation by [Icebox2](https://github.com/Icebox2))
- 12522 : Portuguese (translation by [DefKorns](https://github.com/DefKorns))
- 12523 : Français (translation by [Narkoa](https://github.com/Narkoa))
- 12524 : Italiano (translation by [SantX27](https://github.com/SantX27))
- 12525 : German (translation by [LeZerb](https://github.com/LeZerb))
- 932 : 日本語(Wait for translate support)

You can set `[OPT]=[0|1]` to include or exclude some language, List of `OPT` parameter:
`EN_US`  English; `ES_ES`  Español; `PT_PT` Portuguese; `FR_FR` Français;`IT_IT` Italiano; `ZH_CN` 简体中文;`ZH_TW` 繁體中文;`KO_KR` 한국어;`JA_JP` 日本語; `DE_DE` Deutsch;

other : Wait your support to translate

### Coverflow support
`make COVERFLOW=1 JPG_QUALITY=(90)`  set `COVERFLOW=1` to support show cover art. support `.png` `.bmp` `.jpg` file which filename same as rom's filename and same floder. CFW will convet it to jpg format file `.img` and pack it into firmware, you can custom jpg's quality use `JPG_QUALITY`.

### Other features
Here some other features you can edit the rom define file to custom by youself.
Before you run `make flash`, please run `make romdef` then you can get some romdef file in `roms` folder as `gb.json` `nes.json` ..etc. Edit this files then you can custom the follow feature.

Use `make ROMINFOCODE=[ascii|?]` to set charset of rominfo sourcecode to enabled local language support.

- Game display title(Set `name` value, title's charset be must your custom language supported)
- Pack or don't pack rom to firmware (Set `publish` to `1` or `0`)
- Enable save for single game even `STATE_SAVING=0` (Set `enable_save` to `1`, if `STATE_SAVING=1` all games will be save enabled)
- Emulator system cover image size(Set `_cover_width` and `_cover_height`, 180>=`_cover_width`>=64 and 136>=`_cover_height`>=64)

`make romdef` is run patched mode for `*emu*.json` if the file already exist, each time only append new rom's information when command execute.

### FONT
`FONT=[num]` Allow you only persist one font and set the font number.
All the font effect you can see in: `Core\Inc\retro-go\fonts\font_un_xx.h`

***********
# Emulator collection for Nintendo® Game & Watch™

This is a port of the [retro-go](https://github.com/ducalex/retro-go) emulator collection that runs on the Nintendo® Game & Watch™: Super Mario Bros. system.

Supported emulators:

- ColecoVision (col)
- Gameboy / Gameboy Color (gb/gbc)
- Game & Watch / LCD Games (gw)
- Nintendo Entertainment System (nes)
- PC Engine / TurboGrafx-16 (pce)
- Sega Game Gear (gg)
- Sega Master System (sms)
- Sega SG-1000 (sg)

## Table of Contents
- [Emulator collection for Nintendo® Game & Watch™](#emulator-collection-for-nintendo-game--watch)
  - [Table of Contents](#table-of-contents)
  - [Controls](#controls)
    - [Macros](#macros)
  - [Troubleshooting / FAQ](#troubleshooting--faq)
  - [How to build](#how-to-build)
    - [Prerequisites](#prerequisites)
    - [Building](#building)
    - [Information for developers](#information-for-developers)
  - [Build and flash using Docker](#build-and-flash-using-docker)
  - [Backing up and restoring save state files](#backing-up-and-restoring-save-state-files)
  - [Screenshots](#screenshots)
  - [Game Genie](#game-genie)
    - [Game Genie on PCE System](#game-genie-on-pce-system)
  - [Upgrading the flash](#upgrading-the-flash)
  - [Advanced Flash Examples](#advanced-flash-examples)
    - [Custom Firmware (CFW)](#custom-firmware-cfw)
  - [Discord, support and discussion](#discord-support-and-discussion)
  - [LICENSE](#license)

## Controls

Buttons are mapped as you would expect for each emulator. `GAME` is mapped to `START`,
and `TIME` is mapped to `SELECT`. `PAUSE/SET` brings up the emulator menu.

By default, pressing the power-button while in a game will automatically trigger
a save-state prior to putting the system to sleep. Note that this WILL overwrite
the previous save-state for the current game.

### Macros

Holding the `PAUSE/SET` button while pressing other buttons have the following actions:

| Button combination    | Action                                                                 |
| --------------------- | ---------------------------------------------------------------------- |
| `PAUSE/SET` + `GAME`  | Store a screenshot. (Disabled by default on 1MB flash builds)          |
| `PAUSE/SET` + `TIME`  | Toggle speedup between 1x and the last non-1x speed. Defaults to 1.5x. |
| `PAUSE/SET` + `UP`    | Brightness up.                                                         |
| `PAUSE/SET` + `DOWN`  | Brightness down.                                                       |
| `PAUSE/SET` + `RIGHT` | Volume up.                                                             |
| `PAUSE/SET` + `LEFT`  | Volume down.                                                           |
| `PAUSE/SET` + `B`     | Load state.                                                            |
| `PAUSE/SET` + `A`     | Save state.                                                            |
| `PAUSE/SET` + `POWER` | Poweroff WITHOUT save-stating.                                         |

## Troubleshooting / FAQ

- Run `make help` to get a list of options to configure the build, and targets to perform various actions.
- Add `STATE_SAVING=0` as a parameter to `make` to disable save state support if more space is required.
- Do you have any changed files, even if you didn't intentionally change them? Please run `git reset --hard` to ensure an unchanged state.
- Did you run `git pull` but forgot to update the submodule? Run `git submodule update --init --recursive` to ensure that the submodules are in sync or run `git pull --recurse-submodules` instead.
- Run `make clean` and then build again. The makefile should handle incremental builds, but please try this first before reporting issues.
- If you have limited resources on your computer, remove the `-j$(nproc)` flag from the `make` command, i.e. run `make flash`.
- If you have changed the external flash and are having problems:
  - Run `make flash_test` to test it. This will erase the flash, write, read and verify the data.
  - If your chip was bought from e.g. ebay, aliexpress or similar places, you might have gotten a fake or bad clone chip. You can set `EXTFLASH_FORCE_SPI=1` to disable quad mode which seems to help for some chips.
- It is still not working? Try the classic trouble shooting methods: Disconnect power to your debugger and G&W and connect again. Try programming the [Base](https://github.com/ghidraninja/game-and-watch-base) project first to ensure you can actually program your device.
- Still not working? Ok, head over to #support on the discord and let's see what's going on.

## How to build

### Prerequisites

- You will need version 10 or later of [arm-gcc-none-eabi toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads). **10.2.0 and later are known to work well**. Please make sure it's installed either in your PATH, or set the environment variable `GCC_PATH` to the `bin` directory inside the extracted directory (e.g. `/opt/gcc-arm-none-eabi-10-2020-q4-major/bin`, `/Applications/ARM/bin` for macOS).
- In order to run this on a Nintendo® Game & Watch™ [you need to first unlock it](https://github.com/ghidraninja/game-and-watch-backup/).

### Building

Note: `make -j8` is used as an example. You may use `make -j$(nproc)` on Linux or `make -j$(sysctl -n hw.logicalcpu)` on Mac, or just write the number of threads you want to use, e.g. `make -j8`.

```bash
# Configure the debug adapter you want to use.
# stlink is also the default, but you may set it to something else:
# export ADAPTER=jlink
# export ADAPTER=rpi
export ADAPTER=stlink

# Clone this repo with submodules:

git clone --recurse-submodules https://github.com/kbeckmann/game-and-watch-retro-go

cd game-and-watch-retro-go

# Install python dependencies, this is optional for basic uses (but recommended!)
python3 -m pip install -r requirements.txt

# Place roms in the appropriate folders:
# cp /path/to/rom.gb ./roms/gb/
# cp /path/to/rom.nes ./roms/nes/
# etc. for each rom-emulator combination.

# On a Mac running make < v4 you have to manually download the HAL package by running:
# make download_sdk

# Build and program external and internal flash.
# Notes:
#     * If you are using a modified unit with a larger external flash,
#       set the EXTFLASH_SIZE_MB to its size in megabytes (MB) (16MB used in the example):
#           make -j8 EXTFLASH_SIZE_MB=16 flash
#     * If you have the Zelda version you can set GNW_TARGET=zelda to have the appropriate
#       flash size and theme set. If you want to stick with the red theme you can set
#       EXTFLASH_SIZE_MB=4 on your Zelda model.

make -j8 flash
```

### Information for developers

If you need to change the project settings and generate c-code from stm32cubemx, make sure to not have a dirty working copy as the tool will overwrite files that will need to be perhaps partially reverted. Also update Makefile.common in case new drivers are used.

## Build and flash using Docker

<details>
  <summary>
    If you are familiar with Docker and prefer a solution where you don't have to manually install toolchains and so on, expand this section and read on.
  </summary>

  To reduce the number of potential pitfalls in installation of various software, a Dockerfile is provided containing everything needed to compile and flash retro-go to your Nintendo® Game & Watch™: Super Mario Bros. system. This Dockerfile is written tageting an x86-64 machine running Linux.

  Steps to build and flash from a docker container (running on Linux, e.g. Archlinux or Ubuntu):

  ```bash
  # Clone this repo
  git clone --recursive https://github.com/kbeckmann/game-and-watch-retro-go

  # cd into it
  cd game-and-watch-retro-go

  # Place roms in the appropriate directory inside ./roms/

  # Build the docker image (takes a while)
  make docker_build

  # Run the container.
  # The current directory will be mounted into the container and the current user/group will be used.
  # In order to be able to flash the device, the container is started with --priviliged and also mounts
  # in /dev/bus/usb. See Makefile.common for the exact command line that is executed if curious.
  make docker

  # Build and flash from inside the container:
  docker@76f83f2fc562:/opt/workdir$ make ADAPTER=stlink EXTFLASH_SIZE_MB=1 -j$(nproc) flash
  ```

</details>

## Backing up and restoring save state files

Save states can be backed up using either `./scripts/saves_backup.sh build/gw_retro_go.elf` or by running `make flash_saves_backup`. Make sure to use the elf file that matches what is running on your device! It is a good idea to keep this elf file in case you want to back up at a later time.

:exclamation: Note the same variables that were used to flash have to be set here as well, i.e. `ADAPTER`, `EXTFLASH_SIZE_MB`, `EXTFLASH_OFFSET`, `INTFLASH_BANK` etc. This is best done with `export VARIABLE=value`.

This downloads all save states to the local directory `./save_states`. Each save state will be located in `./save_states/<emu>/<rom name>.save`.

:exclamation: Make sure to keep a backup of your elf file (`build/gw_retro_go.elf`) if you intend to make backups at a later time. The elf file has to match what's running on the device.

After this, it's safe to change roms, pull new code and build & flash the device.

Save states can then be programmed to the device using a newer elf file with new code and roms. To do this, run `./scripts/saves_restore.sh build/gw_retro_go.elf` - this time with the _new_ elf file that matches what's running on the device. Save this elf file for backup later on. This can also be achieved with `make flash_saves_restore`.

`saves_restore.sh` will upload all save state files that you have backed up that are also included in the elf file. E.g Let's say you back up saves for rom A, B and C. Later on, you add a new rom D but remove A, then build and flash. When running the script, the save states for B and C will be programmed and nothing else.

You can also erase all of the save slots by running `make flash_saves_erase`.

## Screenshots

Screenshots can be captured by pressing `PAUSE/SET` + `GAME`. This feature is disabled by default if the external flash is 1MB (stock units), because it takes up 150kB in the external flash.

Screenshots can be downloaded by running `make dump_screenshot`, and will be saved as a 24-bit RGB PNG.

## Game Genie

Note: Currently Game Genie codes are only working with NES games.

To enable, add GAME_GENIE=1 to your make command. If you have already compiled without GAME_GENIE=1, I recommend running make clean first.

To add Game Genie codes, create a file ending in .ggcodes in the same directory as your rom with the same name as your rom. For instance, for
"roms/nes/Super Mario Bros.nes" make a file called "roms/nes/Super Mario Bros.ggcodes". In that file, each line can have up to 3 Game Genie codes and a maximum
of 16 lines of active codes (for a max of 3 x 16 = 48 codes). Each line can also have a description (up to 25 characters long).
You can comment out a line by prefixing with # or //. For example:
```
SXIOPO, Inf lives
APZLGG+APZLTG+GAZUAG, Mega jump
YSAOPE+YEAOZA+YEAPYA, Start on World 8-1
YSAOPE+YEAOZA+LXAPYA, Start on World -1
GOZSXX, Invincibility
# TVVOAE, Circus music
```
When you re-flash, you can enable / disable each of your codes in the game selection screen.

A collection of codes can be found here: [https://github.com/martaaay/game-and-watch-retro-go-game-genie-codes](https://github.com/martaaay/game-and-watch-retro-go-game-genie-codes).

### Game Genie on PCE System

Now you can define rom patch for PCE Roms. You can found patch info from [Here](https://krikzz.com/forum/index.php?topic=1004.0).
To add PCE rom patcher, create a file ending in .pceplus in the same directory as your rom with the same name as your rom. For instance, for
"roms/pce/1943 Kai (J).pce" make a file called "roms/pce/1943 Kai (J).pceplus".
A collection of codes file can be found [here](https://github.com/olderzeus/game-genie-codes-nes/tree/master/pceplus).

Each line of pceplus is defined as:
```
01822fbd,018330bd,0188fcbd,	Hacked Version
[patchcommand],[...], patch desc

```

Each patch command is a hex string defined as:
```
01822fbd
_
|how much byte to patched
 _____
   |patch start address, subtract pce rom header size if had.
      __...
       |bytes data to patched from start address

```


## Upgrading the flash

The Nintendo® Game & Watch™ comes with a 1MB external flash. This can be upgraded.

The flash operates at 1.8V so make sure the one you change to also matches this.

The recommended flash to upgrade to is MX25U12835FM2I-10G. It's 16MB, the commands are compatible with the stock firmware and it's also the largest flash that comes in the same package as the original.

:exclamation: Make sure to backup and unlock your device before changing the external flash. The backup process requires the external flash to contain the original data.

## Advanced Flash Examples

### Custom Firmware (CFW)
In order to install both the CFW (modified stock rom) and retro-go at the same time, a [patched version of openocd](https://github.com/kbeckmann/ubuntu-openocd-git-builder) needs to be installed and used.

In this example, we'll be compiling retro-go to be used with a 64MB (512Mb) `MX25U51245GZ4I00` flash chip and [custom firmware](https://github.com/BrianPugh/game-and-watch-patch). The internal custom firmware will be located at `0x08000000`, which corresponds to `INTFLASH_BANK=1`. The internal retro-go firmware will be flashed to `0x08100000`, which corresponds to `INTFLASH_BANK=2`. The configuration of custom firmware described below won't use any extflash, so no `EXTFLASH_OFFSET` is specified. We can now build and flash the firmware with the following command:

```bash
make clean
make -j8 EXTFLASH_SIZE_MB=64 INTFLASH_BANK=2 flash
```

To flash the custom firmware, [follow the CFW README](https://github.com/BrianPugh/game-and-watch-patch#retro-go). But basically, after you install the dependencies and place the correct files in the directory, run:
```bash
# In the game-and-watch-patch folder
make PATCH_PARAMS="--internal-only" flash_patched_int
```

## Discord, support and discussion

Please join the [Discord](https://discord.gg/vVcwrrHTNJ).

## LICENSE

This project is licensed under the GPLv2. Some components are also available under the MIT license. Respective copyrights apply to each component.
