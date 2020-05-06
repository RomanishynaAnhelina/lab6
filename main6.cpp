#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <Windows.h>

using namespace std;

class Conditioner
{
public:
  Conditioner(const char* set_Model)
  {
    Model = new char[strlen(set_Model) + 1];
    strcpy(Model, set_Model);
  }
  Conditioner()
  {
    Model = new char[strlen("None") + 1];
    strcpy(Model, "None");
  }
  virtual ~Conditioner()
  {
    delete[] Model;
  }
  virtual void setModel(const char* set_Model)
  {
    Model = new char[strlen(set_Model) + 1];
    strcpy(Model, set_Model);
  }
  virtual void ON()
  {
    IsWork = 1;
  }
  virtual void OFF()
  {
    IsWork = 0;
  }
  virtual char* Mode() = 0;
  virtual void setMode(bool k) = 0;
  virtual bool Status()
  {
    return IsWork;
  }
protected:
  char* Model;
  bool IsWork = 0;
};

class ClimateControl : public Conditioner
{
public:
  ClimateControl(const char* set_Model) : Conditioner(set_Model)
  {

  }
  ClimateControl() : Conditioner()
  {

  }
  virtual ~ClimateControl()
  {

  }
  virtual void Set_Temperature(int Temperature)
  {
    this->Temperature = Temperature;
  }
  virtual char* Mode()
  {
    char* curMode = new char[10];
    if (mode == 0)
    {
      strcpy(curMode, "Colling");
    }
    else
    {
      strcpy(curMode, "Heating");
    }
    return curMode;
  }
  virtual void setMode(bool k)
  {
    mode = k;
  }
  virtual int Get_Temperature()
  {
    return Temperature;
  }
  ClimateControl& operator = (const ClimateControl& Climate)
  {
    this->Temperature = Climate.Temperature;
    this->mode = Climate.mode;
    this->Model = Climate.Model;
    this->IsWork = Climate.IsWork;
    return *this;
  }
private:
  int Temperature = 0;
  bool mode = 0;
};



int main()
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  ClimateControl Control("Samsung"), Control2;
  Control.Set_Temperature(25);
  Control.setMode(1);

  Control2 = Control;

  Control.Set_Temperature(20);
  Control.setMode(0);
  cout << "Control info:" << endl;
  cout << "Поточна температура: " << Control.Get_Temperature() << endl;
  cout << "Поточний режим: " << Control.Mode() << endl;

  cout << "Control2 info:" << endl;
  cout << "Поточна температура: " << Control2.Get_Temperature() << endl;
  cout << "Поточний режим: " << Control2.Mode() << endl;
  system("pause");
  return 0;
}
