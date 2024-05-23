#include <iostream>
#include <fstream>
#include <json.hpp>
#include <g4json.h>
// using namespace std;

// using json = nlohmann::json;

int main(int argc, char *argv[])
{
    g4json *j = new g4json(argv[1]);
    // j->display();
    j->displayGunData();
    j->displayObjectData();
    j->displayPhysicsList();
    j->displayOutputFileName();

   GunParameters gun = j->getGun();
   vector<ObjectParameters> objects = j->getObjects();
   string physicsList = j->getPhysicsList();

    return 0;
}