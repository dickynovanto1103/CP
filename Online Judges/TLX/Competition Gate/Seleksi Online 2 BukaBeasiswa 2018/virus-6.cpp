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
    int malignancyLowerBound;
    int malignancyUpperBound;
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

    void SetMalignancyLowerBound(int lowerBound)
    {
        malignancyLowerBound = lowerBound;
    };

    void SetMalignancyUpperBound(int upperBound)
    {
        malignancyUpperBound = upperBound;
    };

    int getValidMalignancy(int malignancy)
    {
        if(malignancy < malignancyLowerBound)
        {
            malignancy = malignancyLowerBound;
        }
        if(malignancy > malignancyUpperBound)
        {
            malignancy = malignancyUpperBound;
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

    int countChangeHalf()
    {
        int perubahan = malignancy/2;
        if(malignancy%2 == 1)
        {
            perubahan++;
        }else if(malignancy%2 == -1)
        {
            perubahan--;
        }

        return -perubahan;
    }

    void determineIsDead()
    {
        if(name == "DOBBY" || name == "DOBBYTHEHOUSEELF" || name[0] != 'D')
        {
            if(age >= 365)
            {
                isDead = true;
            }
        }
    }

    void Update()
    {
        age++;

        determineIsDead();

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
                            int perubahan = countChangeHalf();
                            updateMalignancy(10, perubahan);
                        }
                    }else if(name == "DARGOMBES")
                    {
                        updateMalignancy(1, 3);
                    }else if(name == "DEWARUCI")
                    {
                        updateMalignancy(2, -5);
                    }else if(name == "DOBBYTHEHOUSEELF" || name == "DOBBY")
                    {
                        if(malignancy > 0)
                        {   
                            if(malignancy > 30)
                            {
                                if(age >= 200)
                                {
                                    updateMalignancy(1, -15);
                                }else
                                {
                                    updateMalignancy(1, -3);
                                }
                            }else
                            {
                                if(age >= 300)
                                {
                                    int perubahan = countChangeHalf();
                                    updateMalignancy(1, perubahan);       
                                }else
                                {
                                    updateMalignancy(1, -3);   
                                }
                            }
                        }
                        else
                        {   
                            if(age >= 110) 
                            {
                                if(malignancy < -600)
                                {
                                    int perubahan = countChangeHalf();
                                    updateMalignancy(1, perubahan);       
                                }else{
                                    updateMalignancy(1, 2);       
                                }
                            }else if(age >= 100)
                            {
                                if(malignancy < -600)
                                {
                                    updateMalignancy(1, 15);
                                }else if(malignancy < 0)
                                {
                                    updateMalignancy(1,7);   
                                }else
                                {
                                    updateMalignancy(1, 2);   
                                }
                            }else
                            {
                                updateMalignancy(1, 2);
                            }

                            
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
    if(virusName == "DARGOMBES")
    {
        virus->SetMalignancyLowerBound(0);
        virus->SetMalignancyUpperBound(9999);
    }else if(virusName == "DEWARUCI") 
    {
        virus->SetMalignancyLowerBound(-9999);
        virus->SetMalignancyUpperBound(0);
    }else if(virusName == "DOBBYTHEHOUSEELF" || virusName == "DOBBY")
    {
        virus->SetMalignancyLowerBound(-666);
        virus->SetMalignancyUpperBound(666);
    }else{
        virus->SetMalignancyLowerBound(0);
        virus->SetMalignancyUpperBound(99);
    }
    

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
