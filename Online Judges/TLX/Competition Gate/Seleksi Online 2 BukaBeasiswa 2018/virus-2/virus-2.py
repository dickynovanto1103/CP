
class Virus:
    def __init__(self):
        self.name = ""
        self.malignancy = 0
        self.age = 0

    def SetName(self, _name):
        self.name = _name

    def SetMalignancy(self, _malignancy):
        self.malignancy = _malignancy

    def SetAge(self, _age):
        self.age = _age

    def Update(self):
        self.age += 1

        if self.name != "4L4Y" and self.name != "B41K":
            if self.name != "M4G3R":
                if self.name == "LBHB41K":
                    if self.age % 5 == 0:
                        self.malignancy -= 1
                    if self.malignancy < 0:
                        self.malignancy = 0
                    if self.malignancy > 99:
                        self.malignancy = 99
                else:
                    if self.age >= 200:
                        if self.age % 5 == 0:
                            self.malignancy += 2
                        if self.malignancy < 0:
                            self.malignancy = 0
                        if self.malignancy > 99:
                            self.malignancy = 99
                    else:
                        if self.age % 3 == 0:
                            self.malignancy += 1
                        if self.malignancy < 0:
                            self.malignancy = 0
                        if self.malignancy > 99:
                            self.malignancy = 99
        else:
            if self.name == "4L4Y":
                self.malignancy += 2
                if self.malignancy < 0:
                    self.malignancy = 0
                if self.malignancy > 99:
                    self.malignancy = 99
            if self.name == "B41K":
                if self.age % 100 == 0:
                    self.malignancy += 1
                if self.malignancy < 0:
                    self.malignancy = 0
                if self.malignancy > 99:
                    self.malignancy = 99

        print("Nama: " + self.name + "; Usia: " + str(self.age) + "; Tingkat Keganasan: " + str(self.malignancy))

if __name__ == "__main__":
    tmp = input().split()
    numberOfVirus = int(tmp[0])
    numberOfDay = int(tmp[1])

    viruses = []
    for i in range(0, numberOfVirus):
        tmp = input().split()
        virusName = tmp[0]
        virusAge = int(tmp[1])
        virusMalignancy = int(tmp[2])

        tmpVirus = Virus()
        tmpVirus.SetName(virusName)
        tmpVirus.SetAge(virusAge)
        tmpVirus.SetMalignancy(virusMalignancy)

        viruses.append(tmpVirus)

    for i in range(0, numberOfDay):
        print("Hari #" + str(i + 1))
        for j in range(0, len(viruses)):
            viruses[j].Update()
