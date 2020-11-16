#include <iostream>
#include <assert.h>
#include "Version.hpp"

int main() {

    assert(Version("1.2.3")   == Version("1.2.3"));
    assert(Version("1.2.3")   == Version("1.2.3.0"));
    assert(Version("1")       == Version("1.0.0"));
    assert(Version("1.0.0")   == Version("1.0"));

    assert(Version("1.2.3")   != Version("1.2"));
    assert(Version("1.0.0")   != Version("2.0"));
    assert(Version("2.0")     != Version("1.0.0"));

    assert(Version("1.2.3")    < Version("1.2.4"));
    assert(Version("1")        < Version("1.0.1"));
    assert(Version("1.1.9")    < Version("1.2"));
    assert(Version("1.1.9")    < Version("2"));

    assert(Version("1.1.1")    > Version("1.0.0"));
    assert(Version("2.1.9")    > Version("2"));
    assert(Version("1.2.3")    > Version("1.2.2.4"));
    assert(Version("2")        > Version("1.2.3.4"));

    assert(Version("3.1")     >= Version("1.7.9"));
    assert(Version("3")       >= Version("1.7.9"));
    assert(Version("1.7.9")   >= Version("1"));

    assert(Version("1.7.9")   <= Version("3.1"));
    assert(Version("1.7.9")   <= Version("3"));
    assert(Version("1")       <= Version("1.7.9"));

    std::cout << "Ok!\n";
    return 0;
}
