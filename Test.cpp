//
// Created by elad on 5/15/22.
//

#include "doctest.h"
#include "sources/OrgChart.hpp"

TEST_CASE("Valid Operations") {
    ariel::OrgChart organization;

    CHECK_NOTHROW(organization.add_root("CPO"));
    CHECK_EQ(*(organization.begin_level_order()), "CPO"); // check if the root is CPO
    CHECK_NOTHROW(organization.add_root("CEO")); // should replace the CPO
    CHECK_EQ(*(organization.begin_level_order()), "CEO"); // check if the root actually changed to CEO

    CHECK_NOTHROW(organization.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(organization.add_sub("CEO", "COO"));
    CHECK_NOTHROW(organization.add_root("CPO")); // should replace the CEO
    CHECK_EQ(*(organization.begin_level_order()), "CPO"); // check if the root actually changed to CPO
    CHECK_NOTHROW(organization.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(organization.add_sub("COO", "VP_BI"));
}

TEST_CASE("Invalid Operations") {
    ariel::OrgChart organization;
    CHECK_THROWS(organization.add_sub("dad", "son"));
    CHECK_NOTHROW(organization.add_root("mom"));
    CHECK_THROWS(organization.add_sub("dad", "son")); // steel the doesnt exist
}

TEST_CASE("Methods Correctness") {
/*
       1
       |--------|--------|
       2        3        7
       |
       4
       |--------|
       5        6
 */
    ariel::OrgChart organization;
    CHECK_NOTHROW(organization.add_root("1"));
    CHECK_NOTHROW(organization.add_sub("1", "2"));
    CHECK_NOTHROW(organization.add_sub("1", "3"));
    CHECK_NOTHROW(organization.add_sub("1", "7"));
    CHECK_NOTHROW(organization.add_sub("2", "4"));
    CHECK_NOTHROW(organization.add_sub("4", "5"));
    CHECK_NOTHROW(organization.add_sub("4", "6"));

    SUBCASE("level order") {

        auto iter_level = organization.begin_level_order();
        CHECK_EQ(*iter_level, "1");
        CHECK_NOTHROW(++iter_level);
        CHECK_EQ(*iter_level, "2");
        CHECK_NOTHROW(++iter_level);
        CHECK_EQ(*iter_level, "3");
        CHECK_NOTHROW(++iter_level);
        CHECK_EQ(*iter_level, "7");
        CHECK_NOTHROW(++iter_level);
        CHECK_EQ(*iter_level, "4");
        CHECK_NOTHROW(++iter_level);
        CHECK_EQ(*iter_level, "5");
        CHECK_NOTHROW(++iter_level);
        CHECK_EQ(*iter_level, "6");
        CHECK_EQ(++iter_level, organization.end_level_order());
    }

    SUBCASE("revers order") {
        auto iter_reverse = organization.begin_reverse_order();
        CHECK_EQ(*iter_reverse, "5");
        CHECK_NOTHROW(++iter_reverse);
        CHECK_EQ(*iter_reverse, "6");
        CHECK_NOTHROW(++iter_reverse);
        CHECK_EQ(*iter_reverse, "4");
        CHECK_NOTHROW(++iter_reverse);
        CHECK_EQ(*iter_reverse, "2");
        CHECK_NOTHROW(++iter_reverse);
        CHECK_EQ(*iter_reverse, "3");
        CHECK_NOTHROW(++iter_reverse);
        CHECK_EQ(*iter_reverse, "7");
        CHECK_NOTHROW(++iter_reverse);
        CHECK_EQ(*iter_reverse, "1");
        CHECK_EQ(++iter_reverse, organization.end_level_order());
    }

    SUBCASE("pre order") {
        auto iter_pre = organization.begin_preorder();
        CHECK_EQ(*iter_pre, "1");
        CHECK_NOTHROW(++iter_pre);
        CHECK_EQ(*iter_pre, "2");
        CHECK_NOTHROW(++iter_pre);
        CHECK_EQ(*iter_pre, "4");
        CHECK_NOTHROW(++iter_pre);
        CHECK_EQ(*iter_pre, "5");
        CHECK_NOTHROW(++iter_pre);
        CHECK_EQ(*iter_pre, "6");
        CHECK_NOTHROW(++iter_pre);
        CHECK_EQ(*iter_pre, "3");
        CHECK_NOTHROW(++iter_pre);
        CHECK_EQ(*iter_pre, "7");
        CHECK_EQ(++iter_pre, organization.end_preorder());
    }
}