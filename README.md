# hellsinker-notes

Snippets of discoveries about [Hellsinker](https://store.steampowered.com/app/1067720/Hellsinker/) (PC), for potentially snowballing into a future decompilation project (one day) or just understanding some intricacies of the game.

Many of the findings are thanks to [Beetle-Omiwatari](https://www.youtube.com/@beetle_omiwatari/posts) who did a fair bit of his own reverse-engineering.

No disrespect intended towards Ruminant's Whimper. No assets aside from screenshots and *unused content* should be in this repository.

[![Fluxer badge](https://img.shields.io/badge/Fluxer-4641D9.svg?style=for-the-badge&logo=Fluxer&logoColor=white)](https://fluxer.gg/NporEBmI)

## Info

Here is some base information on how Hellsinker was (probably) developed:

- Language: Delphi (Object Pascal)
- IDE/Suite: Either Borland **Delphi 4.0** Professional (according to datamine) or Borland **Developer Studio 2006** Professional (according to [DIE](https://github.com/horsicq/Detect-It-Easy), also considering the former is OLD)
  - Linker: Turbo Linker (2.25)?
- Libraries:
  - DirectX9
  - [Quadruple D](http://karen.saiin.net/~hayase/dddd/index.html) (API for DirectX components)
  - libvorbis
  
Do note that there are many different versions of Hellsinker. This does include the different patches and updates, but more importantly, there are three categories of the game worth mentioning:

- [Booth.PM (DRM-less)](https://booth.pm/ja/items/1187721) (Purely JP release that needs patches)
- [Steam Version](https://store.steampowered.com/app/1067720) (Has localizations enabled and was ahead in terms of updates, has Steam API/DRM)
- [Hellsinker 0.95](https://www.vector.co.jp/download/file/win95/game/fh325441.html) ("Prototype" pre-release with lots of hidden unfinished content and almost unrecognizable)

As you can see, things are a bit jumbled in terms of releases. These three are important to state due to the type of previous decompilation, which has been split between the "booth" v1.009 version and v0.95 and do not have parity with either the current 2024 Booth update or the Steam version (TODO: a timeline of versions).

**Until this repo's attitude changes, newly-found/carry-over information will be based on the latest Booth.PM version of Hellsinker, which is important for static addresses and function parity.**

## How-to

### Decomp

Following tools are of importance:

- [Dhrake](https://github.com/huettenhain/dhrake), scripts to help for decompilation on Ghidra
- [Interactive Delphi Reconstructor](https://github.com/crypto2011/IDR), a special decompiler, pre-built version included in the repo above
- [Ghidra](https://github.com/NationalSecurityAgency/ghidra) for disassembly project management

Follow instructions to import mappings into Ghidra, it's pretty handy but IDR itself is also pretty nifty for figuring out some things. For example, it knows the forms made in Delphi and can simulate them:

<img width="1920" height="1200" alt="%pn_2026_0519-172117" src="https://github.com/user-attachments/assets/251cb3d3-9282-433f-b5ae-c5431dcef385" />

Alternatively, I've included the IDC file in /tools.

#### Ghidra Shared Server

one day

#### Models

Simplified X format from Direct3D 9. Convert with [MrSoup678/QuardupleD_ModelConverter](https://github.com/MrSoup678/QuardupleD_ModelConverter)

#### backboneteller pak (bbt)

Check the bms file in /tools for use in [QuickBMS](https://aluigi.altervista.org/quickbms.htm) to unpack.
