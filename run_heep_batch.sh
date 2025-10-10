#!/bin/bash

run_number=$1
events=$2

if [ -z "$run_number" ]; then
    echo "[ERROR] Run number is required."
    exit 1
fi

if [ -z "$events" ]; then
    events=50000
fi

spec="coin"
SPEC="COIN"

# Paths
script="SCRIPTS/${SPEC}/PRODUCTION/replay_production_${spec}_pElec_hProt.C"
analysis="get_good_heep_ev.C"
rootFileDir="./ROOTfiles"
reportFileDir="./REPORT_OUTPUT/${SPEC}/PRODUCTION"
batchOutDir="./REPORT_OUTPUT/${SPEC}/PRODUCTION/BATCH"
monPdfDir="./HISTOGRAMS/${SPEC}/PDF"
reportMonDir="./UTIL_OL/REP_MON"

# File names
replayFile="${spec}_replay_production_${run_number}"
rootFile="${replayFile}_${events}.root"

outExpertFile="summaryPlots_${run_number}_${spec}_production_rsidis"

reportFile="${reportFileDir}/replay_${spec}_production_${run_number}_${events}.report"
replayLog="${batchOutDir}/replay_${spec}_production_${run_number}_${events}.report.log"

echo "[INFO] Replay Log: $replayLog"
# Start logging
{
  echo "=================================================================="
  echo "Running COIN analysis for run $run_number with $events events"
  echo "Start time: $(date)"
  echo "=================================================================="

  sleep 1
  hcana -q "${script}(${run_number}, ${events})"

  echo ""
  echo "------------------------------------------------------------------"
  echo "Calculating good coincidence events"
  echo "------------------------------------------------------------------"

  sleep 1
  hcana -l -b -q "${analysis}(${run_number},${events},100000,\"${rootFileDir}\",\"${reportFileDir}\",\"${monPdfDir}\")"

  echo ""
  echo "------------------------------------------------------------------"
  echo "Analysis complete for run $run_number"
  echo "End time: $(date)"
  echo "=================================================================="
} 2>&1 | tee "${replayLog}"

