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
    bool isDead;
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

    void SetIsDead(bool _isDead)
    {
        isDead = _isDead;
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

    void updateMalignancy(int divisor, int malignancyChange)
    {
        if(age%divisor == 0)
        {
            malignancy+=malignancyChange;
        }

        malignancy = getValidMalignancy(malignancy);
    }

    int countChangeOfABA81L()
    {
        int perubahan = malignancy/2;
        if(malignancy%2 == 1)
        {
            perubahan++;
        }
        return -perubahan;
    }

    void Update()
    {
        age++;
        if(name[0] != 'D')
        {
            if(age>=365)
            {
                isDead = true;
            }
        }

        if(!isDead)
        {
            if(name != "4L4Y" && name != "B41K")
            {
                if(name != "M4G3R")
                {
                    if(name == "LBHB41K")
                    {
                        updateMalignancy(5, -1);
                    }
                    else if(name == "ABA81L" || name == "ABA81LV2")
                    {
                        if(name == "ABA81LV2")
                        {
                            updateMalignancy(1,1);
                        }

                        if(age < 100)
                        {
                            updateMalignancy(4, 7);
                        }else if(age > 100)
                        {
                            int perubahan = countChangeOfABA81L();
                            updateMalignancy(10, perubahan);
                        }
                    }
                    else
                    {
                        if(age >= 200)
                        {
                            updateMalignancy(5, 2);
                        }
                        else
                        {
                            updateMalignancy(3, 1);
                        }
                    }
                }
            }
            else
            {
                if(name == "4L4Y")
                {
                    updateMalignancy(1, 2);
                }else if(name == "B41K")
                {
                    updateMalignancy(100, 1);
                }
            }

            cout << "Nama: " << name << "; Usia: " << age << "; Tingkat Keganasan: " << malignancy << endl;
        }
        
    }
};

Virus* assignAttributesOfVirus(string virusName, int virusAge, int virusMalignancy)
{
    Virus *virus = new Virus();

    virus->SetName(virusName);
    virus->SetAge(virusAge);
    virus->SetMalignancy(virusMalignancy);
    virus->SetIsDead(false);

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
