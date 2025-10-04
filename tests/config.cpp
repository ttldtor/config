// Copyright (c) 2025 ttldtor.
// SPDX-License-Identifier: BSL-1.0

#include <doctest/doctest.h>

#include <config/config.hpp>
#include <map>
#include <string>
#include <utility>

using namespace org::ttldtor::config;

TEST_CASE("Dummy test case") {
  SUBCASE("Dummy test") {
    CHECK(true);
  }
}

template <typename M1, typename M2>
bool equals(M1&& m1, M2&& m2) {
  for (auto& [key, value] : m1) {
    if (m2.find(key) == m2.end()) {
      return false;
    }

    if (m2.at(key) != value) {
      return false;
    }
  }

  for (auto& [key, value] : m2) {
    if (m1.find(key) == m1.end()) {
      return false;
    }

    if (m1.at(key) != value) {
      return false;
    }
  }

  return true;
}

TEST_CASE("Config") {
  SUBCASE("Adding keys and values.") {
    std::map<std::string, std::string> properties{{"Key1", "Value1"}, {"Key2", "Value2"}};
    auto config = Config();

    config.addSource(properties);

    CHECK(equals(properties, config.getData()));
  }

  SUBCASE("Subsequent additions of values with the same keys overwrite the old values.") {
    std::map<std::string, std::string> properties{{"Key1", "Value1"}, {"Key2", "Value2"}};
    std::map<std::string, std::string> properties2{{"Key2", "ValueX"}, {"Key3", "Value3"}};
    auto config = Config();

    config.addSource(properties);
    config.addSource(properties2);

    CHECK(
      equals(std::unordered_map<std::string, std::string>{{"Key1", "Value1"}, {"Key2", "ValueX"}, {"Key3", "Value3"}},
             config.getData()));
  }
}