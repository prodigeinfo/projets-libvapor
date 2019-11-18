#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <vapor/vpunsignedshort.hpp>


using namespace std;
using namespace vapor;

BOOST_AUTO_TEST_SUITE(test_suite1)

BOOST_AUTO_TEST_CASE(vpunsignedshort_serialize)
{
    vparchive_t expect, result;
    vpunsignedshort vpn;

    expect = "unsignedShort;5;12345";
    vpn = 12345;
    result = vpn.serialize();
    BOOST_REQUIRE_EQUAL(expect, result);
}

BOOST_AUTO_TEST_CASE(vpunsignedshort_deserialize)
{
    unsigned short expect;
    vpunsignedshort result;
    vparchive_t s;

    try {
        result.deserialize("void;5;12345");
        BOOST_FAIL("bad type shoud fail [" + boost::lexical_cast<std::string>(result) + "]");
    }
    catch (invalid_argument ex) {}

    s = "unsignedShort;5;12345";
    expect = 12345;
    result.deserialize(s.c_str());
    BOOST_REQUIRE_EQUAL(expect, result);
}

BOOST_AUTO_TEST_SUITE_END()
