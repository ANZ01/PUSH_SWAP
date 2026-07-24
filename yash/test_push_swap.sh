#!/bin/bash
# ==============================================================================
#  test_push_swap.sh
#
#  Validates ./push_swap against your official 42 checker binary.
#
#  Usage:
#    ./test_push_swap.sh                    (defaults to ./checker_linux)
#    ./test_push_swap.sh ./fedora_checker
#    ./test_push_swap.sh ./checker_Mac
# ==============================================================================

CHECKER="${1:-./checker_linux}"
PUSH_SWAP="./push_swap"

if [ ! -x "$PUSH_SWAP" ]; then
	echo "Error: $PUSH_SWAP not found or not executable. Run 'make' first."
	exit 1
fi
if [ ! -x "$CHECKER" ]; then
	echo "Error: $CHECKER not found or not executable."
	echo "Usage: $0 [path-to-checker-binary]"
	exit 1
fi

PASS=0
FAIL=0

# ------------------------------------------------------------------------
# run_case <label> <args...>
# ------------------------------------------------------------------------
run_case() {
	local label="$1"
	shift
	local result
	result=$("$PUSH_SWAP" "$@" | "$CHECKER" "$@" 2>/dev/null)
	if [ "$result" = "OK" ]; then
		PASS=$((PASS + 1))
	else
		FAIL=$((FAIL + 1))
		echo "FAIL [$label]: args=($*)  checker said: '$result'"
	fi
}

# run_case_flag <label> <flag> <nums...>
# The checker binary doesn't understand strategy flags (--simple etc),
# so the flag must only go to push_swap, never to the checker.
run_case_flag() {
	local label="$1"
	local flag="$2"
	shift 2
	local result
	result=$("$PUSH_SWAP" "$flag" "$@" | "$CHECKER" "$@" 2>/dev/null)
	if [ "$result" = "OK" ]; then
		PASS=$((PASS + 1))
	else
		FAIL=$((FAIL + 1))
		echo "FAIL [$label]: flag=$flag args=($*)  checker said: '$result'"
	fi
}

# random_nums <count> <spread>  -- prints <count> unique ints in
# roughly [-spread, spread], space separated
random_nums() {
	shuf -i "0-$(( $2 * 2 ))" -n "$1" | awk -v s="$2" '{print $1 - s}' | tr '\n' ' '
}

echo "=== Edge cases ==="
run_case "one"        5
run_case "two-sorted" 1 2
run_case "two-rev"    2 1

echo
echo "=== All 6 permutations of 3 ==="
for combo in "1 2 3" "1 3 2" "2 1 3" "2 3 1" "3 1 2" "3 2 1"; do
	run_case "perm3" $combo
done

echo
echo "=== Sizes 4-9, multiple random draws each ==="
for n in 4 5 6 7 8 9; do
	for i in 1 2 3 4 5; do
		nums=$(random_nums "$n" 1000)
		run_case "n=$n" $nums
	done
done

echo
echo "=== Each forced strategy, n=50 ==="
for flag in --simple --medium --complex --adaptive; do
	nums=$(random_nums 50 9999)
	run_case_flag "$flag n=50" "$flag" $nums
done

echo
echo "=== Subject's performance benchmarks ==="
nums100=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')
ops100=$("$PUSH_SWAP" $nums100 | wc -l)
run_case "n=100 perf" $nums100
echo "  n=100 -> $ops100 ops (pass<2000  good<1500  excellent<700)"

nums500=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
ops500=$("$PUSH_SWAP" $nums500 | wc -l)
run_case "n=500 perf" $nums500
echo "  n=500 -> $ops500 ops (pass<12000 good<8000  excellent<5500)"

echo
echo "=== Behavioural checks (not piped to checker) ==="
"$PUSH_SWAP" 1 two 3 >/dev/null 2>&1
[ $? -eq 1 ] && echo "OK: non-integer rejected" || echo "FAIL: non-integer NOT rejected"
"$PUSH_SWAP" 1 2 2 >/dev/null 2>&1
[ $? -eq 1 ] && echo "OK: duplicate rejected" || echo "FAIL: duplicate NOT rejected"
"$PUSH_SWAP" 1 99999999999 >/dev/null 2>&1
[ $? -eq 1 ] && echo "OK: overflow rejected" || echo "FAIL: overflow NOT rejected"
"$PUSH_SWAP" >/dev/null 2>&1
[ $? -eq 0 ] && echo "OK: no-args exits 0, no output" || echo "FAIL: no-args did not exit 0"

echo
echo "=============================================="
echo "  RESULTS: $PASS passed, $FAIL failed"
echo "=============================================="
[ "$FAIL" -eq 0 ] && exit 0 || exit 1
