#include "initialcondition.hpp"

std::vector<float>
InitialCondition::rectangularPulse(std::vector<float> meshpoints)
{
    std::vector<float> initialcondition{};
    for (const auto& elem : meshpoints)
    {
        if (elem >= 0.25F && elem < 0.5F)
        {
            initialcondition.push_back(1.F);
        }
        else
        {
            initialcondition.push_back(0.F);
        }
    }
    return initialcondition;
}