#!/bin/bash

Black='\033[0;30m'
Red='\033[0;31m'
Green='\033[0;32m'
Yellow='\033[0;33m'
Blue='\033[0;34m'
Purple='\033[0;35m'
Cyan='\033[0;36m'
White='\033[0;37m'
Color_Off='\033[0m'

make d
echo -e $Blue"\nTesting characters\n"$Color_Off
./convert \'c\'
./convert \'" "\'
./convert \'*\'
./convert \'$(printf '\017')\'
echo -e $Blue"\nTesting integers\n"$Color_Off
./convert 48
./convert -48
./convert --48
./convert +48
./convert ++48
./convert 0
./convert 300
./convert 256
./convert 2147483647
./convert 2147483648
./convert -2147483648
./convert 123123213213
echo -e $Blue"\nTesting floats\n"$Color_Off
./convert 48.4f
./convert -48.4f
./convert +48.4f
./convert 0.0f
./convert 48.0f
./convert 255.0f
./convert 256.0f
./convert 300.0f
./convert -123.0f
./convert 255.5f
./convert --48.4f
./convert ++48.4f
./convert 2147483648.0f
./convert -2147483648.0f
./convert -2147483648.1f
./convert 123123213213.0f
./convert 12321321321321123123213221321321321312321321313.0f
echo -e $Blue"\nTesting doubles\n"$Color_Off
./convert 48.4
./convert -48.4
./convert +48.4
./convert 48.0
./convert 255.0
./convert -123.0
./convert 255.5
./convert 0.0
./convert --48.0
./convert ++48.0
./convert 123123213213.0
./convert 2147483647.0
./convert 2147483648.0
./convert -2147483648.0
./convert -2147483648.1
./convert 123213213213211231232132132132132131231231232131.0
echo -e $Blue"\nTesting pseudos\n"$Color_Off
./convert inf
./convert inff
./convert -inf
./convert -inff
./convert +inf
./convert +inff
./convert nan
./convert nanf
echo -e $Blue"\nTesting bad stuff\n"$Color_Off
./convert none
./convert ""
./convert "-"
./convert "+"
./convert "48.4f4"
./convert "48.f"
./convert "48."
./convert "48..2"
./convert "48..2f"
./convert "."
./convert ".1"
./convert ".12f"
./convert "48.5.12f"
./convert "48.5.12"
./convert "48f"
./convert "48.2ff"
./convert "+.123f"
./convert "-.123f"
./convert "+.123"
./convert "-.1233"
