#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Virus
{
private:
    string name;
    int malignancy;
    int age;
public:
    Virus()
    {
    };

    void SetName(string _name)
    {
        name = _name;
    };

    void SetMalignancy(int _malignancy)
    {
        malignancy = _malignancy;
    };

    void SetAge(int _age)
    {
        age = _age;
    };

    int getValidMalignancy(int malignancy)
    {
        if(malignancy < 0)
        {
            malignancy = 0;
        }
        if(malignancy > 99)
        {
            malignancy = 99;
        }

        return malignancy;
    }

    void Update()
    {
        age++;

        if(age%3 == 0)
        {
            malignancy++;
        }

        malignancy = getValidMalignancy(malignancy);

        cout << "Nama: " << name << "; Usia: " << age << "; Tingkat Keganasan: " << malignancy << endl;
    };
};

Virus* assignAttributesOfVirus(string virusName, int virusAge, int virusMalignancy)
{
    Virus *virus = new Virus();

    virus->SetName(virusName);
    virus->SetAge(virusAge);
    virus->SetMalignancy(virusMalignancy);

    return virus;
}

Virus* createVirus()
{
    string virusName;
    int virusAge;
    int virusMalignancy;

    cin >> virusName;
    cin >> virusAge;
    cin >> virusMalignancy;

    Virus *virus = new Virus();
    virus = assignAttributesOfVirus(virusName, virusAge, virusMalignancy);

    return virus;
}

vector<Virus*> inputViruses(int numberOfVirus)
{
    vector<Virus*> viruses;

    for(int i=0; i<numberOfVirus; i++)
    {
        Virus *virus = new Virus();
        virus = createVirus();

        viruses.push_back(virus);
    }

    return viruses;
}

int main()
{
    int numberOfVirus;
    int numberOfDay;

    cin >> numberOfVirus;
    cin >> numberOfDay;

    vector<Virus*> viruses = inputViruses(numberOfVirus);

    for(int day=1; day<=numberOfDay; day++)
    {
        cout << "Hari #" << day << endl;
        for(int i=0; i<(int)viruses.size(); i++)
        {
            viruses[i]->Update();
        }
    }
}
