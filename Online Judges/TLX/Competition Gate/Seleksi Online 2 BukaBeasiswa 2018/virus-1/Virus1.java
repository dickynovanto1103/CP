/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class Virus {
  private String name;
  private int malignancy;
  private int age;

  Virus() {}

  void SetName(String _name) {
    name = _name;
  }

  void SetMalignancy(int _malignancy) {
    malignancy = _malignancy;
  }

  void SetAge(int _age) {
    age = _age;
  }

  void Update() {
    age++;

    if (age % 3 == 0) {
      malignancy++;
    }

    if (malignancy < 0) {
      malignancy = 0;
    }

    if (malignancy > 99) {
      malignancy = 99;
    }

    System.out.println("Nama: " + name + "; Usia: " + age + "; Tingkat Keganasan: " + malignancy);
  }
}

public class Virus1 {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    int numberOfVirus;
    int numberOfDay;

    String virusName;
    int virusAge;
    int virusMalignancy;

    List<Virus> viruses = new ArrayList<Virus>();

    String[] tmp = in.nextLine().split(" ");
    numberOfVirus = Integer.parseInt(tmp[0]);
    numberOfDay = Integer.parseInt(tmp[1]);

    for (int i = 0; i < numberOfVirus; i++) {
      tmp = in.nextLine().split(" ");
      virusName = tmp[0];
      virusAge = Integer.parseInt(tmp[1]);
      virusMalignancy = Integer.parseInt(tmp[2]);

      Virus tmpVirus = new Virus();
      tmpVirus.SetName(virusName);
      tmpVirus.SetAge(virusAge);
      tmpVirus.SetMalignancy(virusMalignancy);

      viruses.add(tmpVirus);
    }

    for (int i = 0; i < numberOfDay; i++) {
      System.out.println("Hari #" + (i + 1));
      for (int j = 0; j < viruses.size(); j++) {
        viruses.get(j).Update();
      }
    }
  }
}
