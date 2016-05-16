//#define DOCTEST_CONFIG_DISABLE

#include "doctest.h"

#include <cstdio>

#include <exception>
#include <string>
#include <vector>
#include <ostream>

template <typename T>
std::ostream& operator<<(std::ostream& s, const std::vector<T>& in) {
    s << "[";
    for(size_t i = 0; i < in.size(); ++i)
        if(i < in.size() - 1)
            s << in[i] << ", ";
        else
            s << in[i];
    s << "]";
    return s;
}

template<typename T, typename T2>
struct myType { T data; T2 op; };

//struct myType2 : myType<int, float> {};

template<typename T, typename T2>
bool operator==(const myType<T, T2>&, const myType<T, T2>&) { return false; }

template<typename T, typename T2>
std::ostream& operator<<(std::ostream& s, const myType<T, T2>&) { s << "myType"; return s; }

TEST_SUITE("MAIN");
TEST_CASE("zzz") {
    CHECK(std::string("OMG2") == std::string("OMG"));

    std::vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);

    std::vector<int> vec2;
    vec2.push_back(1);
    vec2.push_back(2);
    vec2.push_back(4);

    myType<int, float> op1;
    myType<int, float> op2;

    CHECK(op1 == op2);

    CHECK(vec1 == vec2);
    //CHECK(vec1 == vec2);

    REQUIRE(true == false);
    //
    //printf("main\n");
    //SUBCASE("") {
    //    printf("1\n");
    //    SUBCASE("") { printf("1-1\n"); }
    //    SUBCASE("") { printf("1-2\n"); }
    //}
    //SUBCASE("") { printf("2\n"); }
}
TEST_SUITE_END();

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Weffc++"
#endif

struct Empty
{};

TEST_CASE_FIXTURE(Empty, "trololo") { printf("Help?\n"); }

// to silence GCC "-Wmissing-declarations"
// and the attribute is to silence "-Wmissing-noreturn" on clang
#ifdef __clang__
void throws() __attribute__((noreturn));
#else
void throws();
#endif

void throws() { throw std::exception(); }
void nothrows(); // to silence GCC "-Wmissing-declarations"
void nothrows() {}

TEST_CASE("zzz") {
    int a = 5;
    int b = 5;
    CHECK(&a == &b);

    CHECK(1);

    CHECK(1 == 1);
    REQUIRE(1 == 1);

    CHECK_FALSE(0);
    REQUIRE_FALSE(0);

    CHECK_THROWS(throws());
    REQUIRE_THROWS(throws());

    CHECK_THROWS_AS(throws(), std::exception);
    REQUIRE_THROWS_AS(throws(), std::exception);

    CHECK_NOTHROW(nothrows());
    REQUIRE_NOTHROW(nothrows());
}

// testing randomness
TEST_SUITE("randomness");
TEST_CASE("") { printf("TEST %d\n", __LINE__ - 100); }
TEST_CASE("") { printf("TEST %d\n", __LINE__ - 100); }
TEST_CASE("") { printf("TEST %d\n", __LINE__ - 100); }
TEST_CASE("") { printf("TEST %d\n", __LINE__ - 100); }
TEST_CASE("") { printf("TEST %d\n", __LINE__ - 100); }
TEST_CASE("") { printf("TEST %d\n", __LINE__ - 100); }
TEST_CASE("") { printf("TEST %d\n", __LINE__ - 100); }
TEST_CASE("") { printf("TEST %d\n", __LINE__ - 100); }
TEST_CASE("") { printf("TEST %d\n", __LINE__ - 100); }
TEST_CASE("") { printf("TEST %d\n", __LINE__ - 100); }
TEST_SUITE_END();
