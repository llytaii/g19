Based on g19daemon [https://github.com/mortendynamite/g19daemon]

Added plugin that sets a wallpaper on lcd./
These can be changed via the telegram bot.

build instructions:

g19daemon
```
sudo apt install cmake build-essential qt libusb-1.0-0-dev libpulse-dev qtbase5-dev
./mb.sh && cd build && sudo make install
```

telegram bot
```
sudo apt install python3-python-telegram-bot
```
in bot/ add token.txt with bot token
