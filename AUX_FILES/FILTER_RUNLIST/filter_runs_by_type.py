#!/usr/bin/env python3

import re

# Ask for input
input_filename = "../rsidis_runlist.dat"
# input_filename = input("Enter the input filename: ").strip()
selected_type = input("Enter the run type (options:HOLE, OPTICS, HEEP, HEE, HMSDIS, SHMSDIS, PI-SIDIS, PI+SIDIS, JUNK): ").strip().lower()
output_filename = f"{selected_type}_runs.dat"

with open(input_filename, "r") as infile:
    lines = infile.readlines()

# Header lines
header_lines = []
run_lines = []

for line in lines:
    if line.strip().startswith("#") or re.match(r"^\s*!?[-=*]", line):
        header_lines.append(line)
    else:
        run_lines.append(line)

# Pattern to match the Run_type field
def extract_run_type(line):
    parts = re.split(r'\s{2,}|\t+', line.strip())
    if len(parts) >= 12:
        return parts[11].lower()
    return ""

filtered_lines = []

for line in run_lines:
    run_type = extract_run_type(line)
    if selected_type == run_type:
        filtered_lines.append(line)

# Write output
with open(output_filename, "w") as outfile:
    outfile.writelines(header_lines)
    outfile.writelines(filtered_lines)

print(f"\n✅ Wrote {len(filtered_lines)} matching lines to {output_filename}")
