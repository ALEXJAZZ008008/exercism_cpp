#pragma once

#include <cstddef>
#include <string>

namespace rna_transcription
{
    char to_rna(char dna_sequence);
    std::string to_rna(std::string dna_sequence);
}  // namespace rna_transcription
