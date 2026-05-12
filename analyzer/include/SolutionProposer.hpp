#pragma once
/*
 * SolutionProposer.hpp - Solution proposal interface.
 * Declares structures and the class that provide action plans
 * and preventive measures for each crash type.
 */

#include <string>
#include <vector>
#include <map>

namespace Analyzer {

struct SolutionProposal {
    std::string crash_type;
    std::string risk_level;
    std::vector<std::string> immediate_actions;
    std::vector<std::string> preventive_measures;
    std::vector<std::string> embedded_specific_solutions;
    std::string estimated_fix_time;
    std::string testing_requirements;
};

class SolutionProposer {
public:
    SolutionProposer();
    ~SolutionProposer();

    // Generate comprehensive solution for a crash
    SolutionProposal GenerateSolution(const std::string& crash_type,
                                    const std::string& severity,
                                    double cpu_usage = 0.0,
                                    double mem_usage = 0.0,
                                    bool embedded_system = false);

    // Get quick fix recommendations
    std::vector<std::string> GetQuickFixes(const std::string& crash_type);

    // Embedded system specific solutions
    std::vector<std::string> GetEmbeddedSolutions(const std::string& crash_type);

    // Risk assessment and mitigation
    std::string AssessSystemImpact(const std::string& crash_type,
                                 double cpu_usage, double mem_usage);

private:
    std::map<std::string, SolutionProposal> solution_database_;

    // Initialize solution database
    void InitializeSolutions();

    // Helper methods
    std::string DetermineRiskLevel(double cpu_usage, double mem_usage);
    std::vector<std::string> GenerateEmbeddedRecommendations(const std::string& crash_type);
};

} // namespace Analyzer