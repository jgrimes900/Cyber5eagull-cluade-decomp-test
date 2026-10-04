#!/bin/bash
# Run the original exe (via tools/oracle) and the port on the same input
# script and compare every dumped frame / state.
#   usage: tools/compare.sh path/to/CyberSeagull5.exe tools/tests/t2.txt
# Run from the repository root (scripts use "C ." so resources/ is found).
set -e
EXE=$(realpath "$1"); SCRIPT=$(realpath "$2")
ROOT=$(cd "$(dirname "$0")/.." && pwd)
OUT=$(mktemp -d)
mkdir -p "$OUT/o" "$OUT/p"
[ -x "$ROOT/tools/oracle/pe_oracle" ] || gcc -O1 -g -o "$ROOT/tools/oracle/pe_oracle" "$ROOT/tools/oracle/pe_oracle.c"
cd "$ROOT"
"$ROOT/tools/oracle/pe_oracle" "$EXE" "$SCRIPT" "$OUT/o"
CYBERSEAGULL_SCRIPT="$SCRIPT" CYBERSEAGULL_OUT="$OUT/p" "$ROOT/cyberseagull"
fail=0
for f in "$OUT"/o/*.raw; do
    r=$(python3 "$ROOT/tools/framediff.py" "$f" "$OUT/p/$(basename "$f")")
    echo "$r"; echo "$r" | grep -q "diff pixels 0 " || fail=1
done
for f in "$OUT"/o/state_*.txt; do
    [ -e "$f" ] || continue
    cmp -s "$f" "$OUT/p/$(basename "$f")" || { echo "state differs: $(basename "$f")"; fail=1; }
done
echo "output in $OUT"; [ $fail = 0 ] && echo "ALL IDENTICAL" || { echo "DIFFERENCES FOUND"; exit 1; }
