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

# Function to print a section header
print_section() {
    echo -e "${Blue}\n$1\n${Color_Off}"
}

# Function to run a test and print a newline
run_test() {
    ./convert "$1"
    echo
}

print_section "Testing characters"
run_test "'c'"
run_test "' '"
run_test "'*'"
run_test "'$(printf '\017')'"

print_section "Testing integers"
run_test "48"
run_test "-48"
run_test "--48"
run_test "+48"
run_test "++48"
run_test "0"
run_test "300"
run_test "256"
run_test "2147483647"
run_test "2147483648"
run_test "-2147483648"
run_test "123123213213"

print_section "Testing floats"
run_test "48.4f"
run_test "-48.4f"
run_test "+48.4f"
run_test "0.0f"
run_test "48.0f"
run_test "255.0f"
run_test "256.0f"
run_test "300.0f"
run_test "-123.0f"
run_test "255.5f"
run_test "--48.4f"
run_test "++48.4f"
run_test "2147483648.0f"
run_test "-2147483648.0f"
run_test "-2147483648.1f"
run_test "123123213213.0f"
run_test "12321321321321123123213221321321321312321321313.0f"

print_section "Testing doubles"
run_test "48.4"
run_test "-48.4"
run_test "+48.4"
run_test "48.0"
run_test "255.0"
run_test "-123.0"
run_test "255.5"
run_test "0.0"
run_test "--48.0"
run_test "++48.0"
run_test "123123213213.0"
run_test "2147483647.0"
run_test "2147483648.0"
run_test "-2147483648.0"
run_test "-2147483648.1"
run_test "123213213213211231232132132132132131231231232131.0"

print_section "Testing pseudos"
run_test "inf"
run_test "inff"
run_test "-inf"
run_test "-inff"
run_test "+inf"
run_test "+inff"
run_test "nan"
run_test "nanf"

print_section "Testing bad stuff"
run_test "none"
run_test ""
run_test "-"
run_test "+"
run_test "48.4f4"
run_test "48.f"
run_test "48."
run_test "48..2"
run_test "48..2f"
run_test "."
run_test ".1"
run_test ".12f"
run_test "48.5.12f"
run_test "48.5.12"
run_test "48f"
run_test "48.2ff"
run_test "+.123f"
run_test "-.123f"
run_test "+.123"
run_test "-.1233"
