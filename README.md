# 🍬 Candy Crush Clone


🎮 A basic Candy Crush-style game built using **C++** and the **Windows API** (Win32 GDI), compiled via MinGW.

![250528_12h22m57s_screenshot](https://github.com/user-attachments/assets/a640dd84-fef7-43b9-ab3d-fc83bed13af3)
---

## 🛠️ Built With

<p align="left">
  <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/cplusplus/cplusplus-original.svg" alt="C++" width="50"/>
</p>

---

## 🧱 Features

- Candy swap animations
- Match-3 mechanics
- Score and lives system
- Smooth (relatively) WinAPI rendering

---

## 🚀 How to Run (on Linux)

> ⚠️ Wine and MinGW are required. Performance may vary.

```bash
sudo pacman -S mingw-w64-gcc wine
x86_64-w64-mingw32-g++ -o program.exe main.cpp -lgdi32
wine ./program.exe
