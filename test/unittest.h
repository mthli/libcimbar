#pragma once
#include "catch.hpp"

#include <bitset>
#include <cstdint>

#define assertMsg(expr,msg) {bool _res_ = expr; if(!_res_) FAIL(msg); REQUIRE(_res_);}
#define assertTrue(expr) REQUIRE(expr)
#define assertFalse(expr) REQUIRE_FALSE(expr)
#define assertEquals(x,y) REQUIRE((x) == (y))
// image hashes are taken after a resize, which rounds differently across OpenCV versions and SIMD paths.
// A few flipped bits out of 64 is still the same image.
#define assertHashNear(x,y) { uint64_t _exp_ = (x); uint64_t _act_ = (y); INFO("expected 0x" << std::hex << _exp_ << ", actual 0x" << _act_); REQUIRE(std::bitset<64>(_exp_ ^ _act_).count() <= 4); }
#define assertMatch(x,y) assertMsg(std::regex_match(y, std::regex(x)), x + std::string(" does not match ") + y)
#define assertIn(x,y) REQUIRE(std::find(y.begin(), y.end(), x) != y.end())
#define assertStringsEqual(x,y) REQUIRE(std::string(x) == std::string(y))
#define assertStringContains(x,y) assertMsg(std::string(y).find(x) != std::string::npos, std::string(y) + " did not contain " + std::string(x))
#define assertInRange(x,y,z) REQUIRE(x <= y); REQUIRE(y <= z)
#define assertAlmostEquals(x,y) assertInRange(x-1,y,x+1)
#define assertNull(expr) REQUIRE(expr == (void*)NULL)
#define assertNotNull(expr) REQUIRE(expr != (void*)NULL)
