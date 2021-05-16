#include "initialcondition.hpp"

std::vector<float>
InitialCondition::rectangularPulse(std::vector<float> meshpoints)
{
    std::vector<float> initialcondition{};
    const float meshWidth = (meshpoints[1] - meshpoints[0]);
    for (const auto& elem : meshpoints)
    {
        if (elem + 0.5 * meshWidth >= 0.25F && elem - 0.5 * meshWidth <= 0.5F)
        {
            initialcondition.push_back(1.);
        }
        else
        {
            initialcondition.push_back(0.);
        }
    }
    return initialcondition;
}