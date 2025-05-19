#!/bin/bash

EXEC=./RPN

tests=(
	"8 9 * 9 - 9 - 9 - 4 - 1 +:42"
	"7 7 * 7 -:42"
    "1 2 * 2 / 2 * 2 4 - +:0"
    "(1 + 1):Error"
    "4 0 /:Error"
    "2 +:Error"
    "1 2 3 +:Error"
    "1 a +:Error"
)

echo "Tests RPN"
passing=0
failing=0

for test in "${tests[@]}"; do
	input="${test%%:*}"
	expected="${test##*:}"
	output=$($EXEC "$input" 2>&1)

	if [[ "$output" == "$expected" ]]; then
		echo "\"$input\" -> $output (PASS)"
		((passing++))
	else
		echo "\"$input\" -> $output (FAIL, expected $expected)"
		((failing++))
	fi
done

echo "Passed: $passing"
echo "Failed: $failing"
