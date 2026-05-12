# Project Summary

## CoreDump PFE — Automated Crash Analysis Pipeline v3.0

This repository implements a crash analysis pipeline with three main components:

1. **Simulator** (`crash_simulator`)
   - Generates crash data and Linux `.core` files.
   - Reads `scenario.cfg` for parameters like `crash_count`, `intensity`, `output_dir`, and `output_csv`.
   - Writes `simulator_output/crash_report.csv` and `.core` files under `simulator_output/coredumps`.

2. **Analyzer** (`crash_analyzer`)
   - Reads simulator CSV and optionally `.core` files.
   - Parses crash records and augments them with pattern-based analysis.
   - Exports enriched results to `analyzer_output/analysis_report.csv` and `analyzer_output/analysis_report.csv.json`.
   - Contains an in-memory database abstraction; current code does not persist a real SQLite DB file.

3. **Dashboard** (`dashboard/dashboard.py`)
   - Streamlit web app that displays analysis results.
   - Supports Overview, Timeline, Details, and Core Files tabs.
   - Shows crash counts, severity distribution, event timeline, and raw crash records.
   - Reads data from `analyzer_output/analysis_report.csv` and falls back to SQLite if available.

## Build and Run

### Build
```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . --parallel
cd ..
```

### Run the pipeline
```bash
./build/bin/crash_simulator --config scenario.cfg
./build/bin/crash_analyzer
streamlit run dashboard/dashboard.py
```

## Recent Fix

- Updated `dashboard/dashboard.py` to replace `cpu_usage` values of `0`, `0.0`, or blank with `in use`.
- This prevents the dashboard from showing misleading CPU values when the simulator/analyzer data does not provide a real CPU usage measurement.
- Validated with `python -m py_compile dashboard/dashboard.py`.

## Notes

- The analyzer currently exports CSV and JSON results successfully.
- `crash_analysis.db` is not being written by the analyzer due to the in-memory `DatabaseManager` implementation.
- The dashboard will display `in use` for CPU values that were previously shown as `0` or empty.


















    // ── Step 2: AI analysis pipeline ─────────────────────────────────────────
    // std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    // std::cout << "🤖 Step 2/3: Running ML + Pattern analysis...\n";
    // std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";

    // Analyzer::CoreAnalyzer analyzer(db_path);
    // analyzer.ProcessInput(input_csv, output_csv);
    // analyzer.PrintSummary();