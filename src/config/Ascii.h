// Copyright (c) 2019, ZumCoin Development Team
//
// Please see the included LICENSE file for more information

#pragma once

const std::string windowsAsciiArt =

        "\n d88888D db    db .88b  d88.  .o88b.  .d88b.  d888888b d8b   db \n"
        " YP  d8' 88    88 88'YbdP`88 d8P  Y8 .8P  Y8.   `88'   888o  88 \n"
        "    d8'  88    88 88  88  88 8P      88    88    88    88V8o 88 \n"
        "   d8'   88    88 88  88  88 8b      88    88    88    88 V8o88 \n"
        "  d8' db 88b  d88 88  88  88 Y8b  d8 `8b  d8'   .88.   88  V888 \n"
        " d88888P ~Y8888P' YP  YP  YP  `Y88P'  `Y88P'  Y888888P VP   V8P \n";
                                                                                                                                                                                                                


const std::string nonWindowsAsciiArt = 
        "\n                                                        \n"
        "███████╗██╗   ██╗███╗   ███╗ ██████╗ ██████╗ ██╗███╗   ██╗\n"
        "╚══███╔╝██║   ██║████╗ ████║██╔════╝██╔═══██╗██║████╗  ██║\n"
        "  ███╔╝ ██║   ██║██╔████╔██║██║     ██║   ██║██║██╔██╗ ██║\n"
        " ███╔╝  ██║   ██║██║╚██╔╝██║██║     ██║   ██║██║██║╚██╗██║\n"
        "███████╗╚██████╔╝██║ ╚═╝ ██║╚██████╗╚██████╔╝██║██║ ╚████║\n"
        "╚══════╝ ╚═════╝ ╚═╝     ╚═╝ ╚═════╝ ╚═════╝ ╚═╝╚═╝  ╚═══╝\n";

/* Windows has some characters it won't display in a terminal. If your ascii
   art works fine on Windows and Linux terminals, just replace 'asciiArt' with
   the art itself, and remove these two #ifdefs and above ascii arts */
#ifdef _WIN32
const std::string asciiArt = windowsAsciiArt;
#else
const std::string asciiArt = nonWindowsAsciiArt;
#endif
