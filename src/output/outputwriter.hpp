#ifndef OUTPUTWRITER_HPP
#define OUTPUTWRITER_HPP
#include <fstream>
#include <vector>

namespace OutputWriter
{
void writeSolutionToTextFile(const std::vector<float>& solution)
{
    std::ofstream file;
    file.open("../../example.txt", std::fstream::out);
    for (int i = 0; i < solution.size(); ++i)
    {
        file << solution[i] << std::endl;
    }
    file.close();
}
} // namespace OutputWriter
#endif // OUTPUTWRITER_HPP
