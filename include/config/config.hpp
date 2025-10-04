// Copyright (c) 2025 ttldtor.
// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <unordered_map>
#include <string>

namespace org::ttldtor::config {

/**
 * Simple configuration class.
 */
class Config {
  std::unordered_map<std::string, std::string> data{};

 public:
  /**
   * Adds keys and values from the source.
   *
   * @tparam Source The source type.
   * @param source The properties' source.
   */
  template <typename Source>
  void addSource(Source&& source) {
    for (auto&& [key, value] : source) {
      data[key] = value;
    }
  }

  /**
   * Returns the collection of keys and values.
   *
   * @return The collection of keys and values.
   */
  [[nodiscard]] const auto& getData() const& {
    return data;
  }
};

}  // namespace org::ttldtor::config