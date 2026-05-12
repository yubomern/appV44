/*
 * SystemMetrics.hpp - Declaration of collected system metrics.
 * Contains the data structure used to store CPU, memory,
 * thread count, and process information at crash time.
 */

#pragma once

#include "Options.hpp"
#include <cstdint>

// ─── Data Structure ───────────────────────────────────────────────────────────

struct SystemMetrics {
    double   cpu_usage_percent;                // CPU usage [0–100]
    uint64_t memory_used_kb;                   // Used RAM in KB
    uint64_t memory_total_kb;                  // Total RAM in KB
    int      thread_count;                     // Active thread count
    int      process_id;                       // PID
    char     process_name[PROCESS_NAME_LEN];   // Executable name
};

// ─── API ──────────────────────────────────────────────────────────────────────

/// Populate *metrics* with current OS-level values.
void CaptureSystemMetrics(SystemMetrics* metrics);
