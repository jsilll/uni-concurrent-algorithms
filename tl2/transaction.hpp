#pragma once

#include <map>
#include <memory>
#include <atomic>
#include <unordered_set>

#include "region.hpp"

struct Transaction
{
    bool ro;                                                     // Read Only
    std::uint32_t rv;                                            // Read-Version
    std::uint32_t wv{0};                                         // Write-Version
    std::unordered_set<std::uintptr_t> read_set{};                 // Set Of Read Words
    std::map<std::uintptr_t, std::unique_ptr<char[]>> write_set{}; // Target Word Src Word Mapping
};