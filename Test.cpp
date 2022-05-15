#include "OrgChart.hpp"
#include "doctest.h"
using namespace ariel;

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
using namespace std;
TEST_CASE("add_root + add_sub") {
    OrgChart organization1;
    organization1.add_root("CEO").add_sub("CEO","CTF").add_sub("CTF","CTO").add_sub("CTF","CFO");
    CHECK("CEO" == organization1.root->pos);
    // cout << organization1.poses.size() << endl;
    // for(unsigned long i = 0; i < organization1.poses.size(); i++){
    //     cout << organization1.poses.at(i) << endl;
    // }
    cout <<organization1 << endl;
    CHECK("CEO" == organization1.root->child.at(0)->parent->pos);
    CHECK("CTF" == organization1.root->child.at(0)->pos);
    CHECK("CTO" == organization1.root->child.at(0)->child.at(0)->pos);
    CHECK("CFO" == organization1.root->child.at(0)->child.at(1)->pos);
    organization1.add_root("CEOO");
    CHECK("CEOO" == organization1.root->child.at(0)->parent->pos);
    CHECK("CTF" == organization1.root->child.at(0)->pos);
    CHECK("CTO" == organization1.root->child.at(0)->child.at(0)->pos);
    CHECK("CFO" == organization1.root->child.at(0)->child.at(1)->pos);
    organization1.add_root("CEOF");
    CHECK("CEOF" == organization1.root->child.at(0)->parent->pos);
    CHECK("CTF" == organization1.root->child.at(0)->pos);
    CHECK("CTO" == organization1.root->child.at(0)->child.at(0)->pos);
    CHECK("CFO" == organization1.root->child.at(0)->child.at(1)->pos);
    organization1.add_root("CEOE");
    CHECK("CEOE" == organization1.root->child.at(0)->parent->pos);
    CHECK("CTF" == organization1.root->child.at(0)->pos);
    CHECK("CTO" == organization1.root->child.at(0)->child.at(0)->pos);
    CHECK("CFO" == organization1.root->child.at(0)->child.at(1)->pos);
    organization1.add_root("CEOD");
    CHECK("CEOD" == organization1.root->child.at(0)->parent->pos);
    CHECK("CTF" == organization1.root->child.at(0)->pos);
    CHECK("CTO" == organization1.root->child.at(0)->child.at(0)->pos);
    CHECK("CFO" == organization1.root->child.at(0)->child.at(1)->pos);
    // cout << organization1.poses.size() << endl;
}

