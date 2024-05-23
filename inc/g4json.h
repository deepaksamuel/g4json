#ifndef G4JSON_H // Include guard using uppercase filename
#define G4JSON_H
#include <string>
#include <json.hpp>
using json = nlohmann::json;
using namespace std;

vector<string> gunKeys = {
    "dimX", "dimY", "dimZ", "gpsshapePlane", "ionA", "ionZ", "nevents",
    "particleSource", "particleType", "posX", "posY", "posZ", "showevents",
    "sourceShape", "angularDist", "dirx", "diry", "dirz", "phi_min", "phi_max",
    "theta_min", "theta_max", "emax", "emin", "espectParam1", "espectParam2",
    "espectParam3", "espectType", "polx", "poly", "polz"};

vector<string> objectKeys = {
    "dim-0", "dim-1", "dim-2", "dim-3", "dim-4", "dim-5", "dim-6", "dim-7", "dim-8", "dim-9",
    "id", "magx", "magy", "magz", "objColor",
    "objMaterial", "objMaterialFormula", "objMaterialProps", "objName",
    "objType", "posx", "posy", "posz", "record_data", "rotx", "roty", "rotz"};

struct GunParameters
{
    // Dimensions
    double dimX;
    double dimY;
    double dimZ;
    std::string gpsshapePlane;
    int ionA; // Atomic number
    int ionZ; // Atomic mass number
    int nevents;
    bool particleSource;
    std::string particleType;
    int posX;
    int posY;
    int posZ;
    bool showevents;
    std::string sourceShape;
    std::string angularDist;
    double dirx;
    double diry;
    double dirz;
    double phi_min;
    double phi_max;
    double theta_min;
    double theta_max;
    double emax;
    double emin;
    double espectParam1;
    double espectParam2;
    double espectParam3;
    std::string espectType;
    double polx;
    double poly;
    double polz;
};

struct ObjectParameters
{
    double dim_0;
    double dim_1;
    double dim_2;
    double dim_3;
    double dim_4;
    double dim_5;
    double dim_6;
    double dim_7;
    double dim_8;
    double dim_9;

    int id;
    double magx;
    double magy;
    double magz;
    std::string objColor;
    std::string objMaterial;
    std::string objMaterialFormula;
    std::string objMaterialProps;
    std::string objName;
    std::string objType;
    double posx;
    double posy;
    double posz;
    bool record_data;
    double rotx;
    double roty;
    double rotz;
};

class g4json
{

public:
    GunParameters gun;
    vector<ObjectParameters> objects;

    json json_data;

    // Constructor to initialize parameters from a JSON object
    g4json(string fileName)
    {
        std::ifstream f(fileName);
        if (f.fail())
        {
            cout << "Error reading input json file: " << fileName << endl;
        }
        else
        {
            cout << "Success reading json file: " << fileName << endl;
            json_data = json::parse(f);
            setGunParameters();
            setObjectParameters();
        }
    }

    void displayJSONGunData()
    {
        cout << "Printing gun data from json file:" << endl;
        cout << json_data["gun"].dump(4) << endl;
    }

    void displayJSONObjectData()
    {
        cout << "Printing object data from json file:" << endl;
        cout << json_data["objects"].dump(4) << endl;
    }

    void displayJSONPhysicsList()
    {
        cout << "Printing physics list from json file:" << endl;
        cout << json_data["physics"].dump(4) << endl;
    }
    void displayJSONFileName()
    {
        cout << "Printing output file name from json file:" << endl;
        cout << json_data["misc"][0]["outputFile"].dump(4) << endl;
    }

    
    void displayGunData()
    {
        cout << "Printing gun data:" << endl;
        std::cout << std::left << std::setw(15) << "dimX:" << gun.dimX << std::endl;
        std::cout << std::left << std::setw(15) << "dimY:" << gun.dimY << std::endl;
        std::cout << std::left << std::setw(15) << "dimZ:" << gun.dimZ << std::endl;
        std::cout << std::left << std::setw(15) << "gpsshapePlane:" << gun.gpsshapePlane << std::endl;
        std::cout << std::left << std::setw(15) << "ionA:" << gun.ionA << std::endl;
        std::cout << std::left << std::setw(15) << "ionZ:" << gun.ionZ << std::endl;
        std::cout << std::left << std::setw(15) << "nevents:" << gun.nevents << std::endl;
        std::cout << std::left << std::setw(15) << "particleSource:" << gun.particleSource << std::endl;
        std::cout << std::left << std::setw(15) << "particleType:" << gun.particleType << std::endl;
        std::cout << std::left << std::setw(15) << "posX:" << gun.posX << std::endl;
        std::cout << std::left << std::setw(15) << "posY:" << gun.posY << std::endl;
        std::cout << std::left << std::setw(15) << "posZ:" << gun.posZ << std::endl;
        std::cout << std::left << std::setw(15) << "showevents:" << gun.showevents << std::endl;
        std::cout << std::left << std::setw(15) << "sourceShape:" << gun.sourceShape << std::endl;
        std::cout << std::left << std::setw(15) << "angularDist:" << gun.angularDist << std::endl;
        std::cout << std::left << std::setw(15) << "dirx:" << gun.dirx << std::endl;
        std::cout << std::left << std::setw(15) << "diry:" << gun.diry << std::endl;
        std::cout << std::left << std::setw(15) << "dirz:" << gun.dirz << std::endl;
        std::cout << std::left << std::setw(15) << "phi_min:" << gun.phi_min << std::endl;
        std::cout << std::left << std::setw(15) << "phi_max:" << gun.phi_max << std::endl;
        std::cout << std::left << std::setw(15) << "theta_min:" << gun.theta_min << std::endl;
        std::cout << std::left << std::setw(15) << "theta_max:" << gun.theta_max << std::endl;
        std::cout << std::left << std::setw(15) << "emax:" << gun.emax << std::endl;
        std::cout << std::left << std::setw(15) << "emin:" << gun.emin << std::endl;
        std::cout << std::left << std::setw(15) << "espectParam1:" << gun.espectParam1 << std::endl;
        std::cout << std::left << std::setw(15) << "espectParam2:" << gun.espectParam2 << std::endl;
        std::cout << std::left << std::setw(15) << "espectParam3:" << gun.espectParam3 << std::endl;
        std::cout << std::left << std::setw(15) << "espectType:" << gun.espectType << std::endl;
        std::cout << std::left << std::setw(15) << "polx:" << gun.polx << std::endl;
        std::cout << std::left << std::setw(15) << "poly:" << gun.poly << std::endl;
        std::cout << std::left << std::setw(15) << "polz:" << gun.polz << std::endl;
    }

    void displayObjectData()
    {
        for (int i = 0; i < objects.size(); i++)
        {
            ObjectParameters object = objects.at(i);
            std::cout << "Object Structure: " << i << std::endl;
            std::cout << "dim_0: " << object.dim_0 << std::endl;
            std::cout << "dim_1: " << object.dim_1 << std::endl;
            std::cout << "dim_2: " << object.dim_2 << std::endl;
            std::cout << "id: " << object.id << std::endl;
            std::cout << "magx: " << object.magx << std::endl;
            std::cout << "magy: " << object.magy << std::endl;
            std::cout << "magz: " << object.magz << std::endl;
            std::cout << "objColor: " << object.objColor << std::endl;
            std::cout << "objMaterial: " << object.objMaterial << std::endl;
            std::cout << "objMaterialFormula: " << object.objMaterialFormula << std::endl;
            std::cout << "objMaterialProps: " << object.objMaterialProps << std::endl;
            std::cout << "objName: " << object.objName << std::endl;
            std::cout << "objType: " << object.objType << std::endl;
            std::cout << "posx: " << object.posx << std::endl;
            std::cout << "posy: " << object.posy << std::endl;
            std::cout << "posz: " << object.posz << std::endl;
            std::cout << "record_data: " << object.record_data << std::endl;
            std::cout << "rotx: " << object.rotx << std::endl;
            std::cout << "roty: " << object.roty << std::endl;
            std::cout << "rotz: " << object.rotz << std::endl;
        }
    }

    void displayPhysicsList()
    {
        cout << getPhysicsList() << endl;
    }
    void displayOutputFileName()
    {
        cout << getOutputFile() << endl;
    }

    GunParameters getGun() { return gun; }
    vector<ObjectParameters> getObjects() { return objects; }
    string getPhysicsList() { return json_data["physics"]; }
    string getOutputFile() { return json_data["misc"][0]["outputFile"]; }
    

private:
    void setGunParameters()
    {
        int indx = 0;
        for (auto it = gunKeys.begin(); it != gunKeys.end(); it++)
        {

            if (*it == "angularDist")
            { // angular distribution is the second array
                indx = 1;
            }
            if (*it == "emax")
            { // energy spects is the last array
                indx = 2;
            }

            if (*it == "dimX")
                gun.dimX = json_data["gun"][indx][*it];
            if (*it == "dimY")
                gun.dimY = json_data["gun"][indx][*it];
            if (*it == "dimZ")
                gun.dimZ = json_data["gun"][indx][*it];
            if (*it == "gpsshapePlane")
                gun.gpsshapePlane = json_data["gun"][indx][*it];
            if (*it == "ionA")
                gun.ionA = json_data["gun"][indx][*it];
            if (*it == "ionZ")
                gun.ionZ = json_data["gun"][indx][*it];
            if (*it == "nevents")
                gun.nevents = json_data["gun"][indx][*it];
            if (*it == "particleSource")
                gun.particleSource = json_data["gun"][indx][*it];
            if (*it == "particleType")
                gun.particleType = json_data["gun"][indx][*it];
            if (*it == "posX")
                gun.posX = json_data["gun"][indx][*it];
            if (*it == "posY")
                gun.posY = json_data["gun"][indx][*it];
            if (*it == "posZ")
                gun.posZ = json_data["gun"][indx][*it];
            if (*it == "showevents")
                gun.showevents = json_data["gun"][indx][*it];
            if (*it == "sourceShape")
                gun.sourceShape = json_data["gun"][indx][*it];
            if (*it == "angularDist")
                gun.angularDist = json_data["gun"][indx][*it];
            if (*it == "dirx")
                gun.dirx = json_data["gun"][indx][*it];
            if (*it == "diry")
                gun.diry = json_data["gun"][indx][*it];
            if (*it == "dirz")
                gun.dirz = json_data["gun"][indx][*it];
            if (*it == "phi_min")
                gun.phi_min = json_data["gun"][indx][*it];
            if (*it == "phi_max")
                gun.phi_max = json_data["gun"][indx][*it];
            if (*it == "theta_min")
                gun.theta_min = json_data["gun"][indx][*it];
            if (*it == "theta_max")
                gun.theta_max = json_data["gun"][indx][*it];
            if (*it == "emax")
                gun.emax = json_data["gun"][indx][*it];
            if (*it == "emin")
                gun.emin = json_data["gun"][indx][*it];
            if (*it == "espectParam1")
                gun.espectParam1 = json_data["gun"][indx][*it];
            if (*it == "espectParam2")
                gun.espectParam2 = json_data["gun"][indx][*it];
            if (*it == "espectParam3")
                gun.espectParam3 = json_data["gun"][indx][*it];
            if (*it == "espectType")
                gun.espectType = json_data["gun"][indx][*it];
            if (*it == "polx")
                gun.polx = json_data["gun"][indx][*it];
            if (*it == "poly")
                gun.poly = json_data["gun"][indx][*it];
            if (*it == "polz")
                gun.polz = json_data["gun"][indx][*it];
        }
    }

    void setObjectParameters()
    {
        int indx = 0;
        int size = json_data["objects"].size();

        for (int i = 0; i < size; i++)
        {
            ObjectParameters object;

            for (auto it = objectKeys.begin(); it != objectKeys.end(); it++)
            {
                if (*it == "dim-0")
                    object.dim_0 = (json_data["objects"][indx][*it]);
                if (*it == "dim-1")
                    object.dim_1 = (json_data["objects"][indx][*it]);
                if (*it == "dim-2")
                    object.dim_2 = (json_data["objects"][indx][*it]);

                if (*it == "dim-3")
                    object.dim_3 = (json_data["objects"][indx][*it]);
                if (*it == "dim-4")
                    object.dim_4 = (json_data["objects"][indx][*it]);
                if (*it == "dim-5")
                    object.dim_5 = (json_data["objects"][indx][*it]);

                if (*it == "dim-6")
                    object.dim_6 = (json_data["objects"][indx][*it]);
                if (*it == "dim-7")
                    object.dim_7 = (json_data["objects"][indx][*it]);
                if (*it == "dim-8")
                    object.dim_8 = (json_data["objects"][indx][*it]);

                if (*it == "dim-9")
                    object.dim_9 = (json_data["objects"][indx][*it]);

                if (*it == "id")
                    object.id = (json_data["objects"][indx][*it]);
                if (*it == "magx")
                    object.magx = (json_data["objects"][indx][*it]);
                if (*it == "magy")
                    object.magy = (json_data["objects"][indx][*it]);
                if (*it == "magz")
                    object.magz = (json_data["objects"][indx][*it]);

                if (*it == "objColor")
                    object.objColor = json_data["objects"][indx][*it];
                if (*it == "objMaterial")
                    object.objMaterial = json_data["objects"][indx][*it];
                if (*it == "objMaterialFormula")
                    object.objMaterialFormula = json_data["objects"][indx][*it];
                if (*it == "objMaterialProps")
                    object.objMaterialProps = json_data["objects"][indx][*it];
                if (*it == "objName")
                    object.objName = json_data["objects"][indx][*it];
                if (*it == "objType")
                    object.objType = json_data["objects"][indx][*it];

                if (*it == "posx")
                    object.posx = (json_data["objects"][indx][*it]);
                if (*it == "posy")
                    object.posy = (json_data["objects"][indx][*it]);
                if (*it == "posz")
                    object.posz = (json_data["objects"][indx][*it]);

                if (*it == "record_data")
                    object.record_data = json_data["objects"][indx][*it] == "true";
                if (*it == "rotx")
                    object.rotx = (json_data["objects"][indx][*it]);
                if (*it == "roty")
                    object.roty = (json_data["objects"][indx][*it]);
                if (*it == "rotz")
                    object.rotz = (json_data["objects"][indx][*it]);
            }
            objects.push_back(object);
            indx++;
        }
    }
};

#endif // G4JSON_H