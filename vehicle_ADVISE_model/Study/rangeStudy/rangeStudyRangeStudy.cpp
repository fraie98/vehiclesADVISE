
#include "Study/rangeStudy/rangeStudyRangeStudy.h"

//******************************************************
//Global Variables
//******************************************************
Char attacker;
Float costWeight;

//********************************************************
//rangeStudyRangeStudy Constructor
//********************************************************
rangeStudyRangeStudy::rangeStudyRangeStudy() {

  // define arrays of global variable names and types
  NumGVs = 2;
  NumExps = 9;

  GVNames = new char*[NumGVs];
  GVTypes = new char*[NumGVs];
  GVNames[0]=strdup("attacker");
  GVTypes[0]=strdup("char");
  GVNames[1]=strdup("costWeight");
  GVTypes[1]=strdup("float");

  // create the arrays to store the values of each gv
  attackerValues = new char[NumExps];
  costWeightValues = new float[NumExps];

  // call methods to assign values to each gv
  SetValues_attacker();
  SetValues_costWeight();
  SetDefaultMobiusRoot(MOBIUSROOT);
}


//******************************************************
//rangeStudyRangeStudy Destructor
//******************************************************
rangeStudyRangeStudy::~rangeStudyRangeStudy() {
  delete [] attackerValues;
  delete [] costWeightValues;
  delete ThePVModel;
}


//******************************************************
// set values for attacker
//******************************************************
void rangeStudyRangeStudy::SetValues_attacker() {
  attackerValues[0] = 'P';
  attackerValues[1] = 'H';
  attackerValues[2] = 'I';
  attackerValues[3] = 'P';
  attackerValues[4] = 'H';
  attackerValues[5] = 'I';
  attackerValues[6] = 'P';
  attackerValues[7] = 'H';
  attackerValues[8] = 'I';
}


//******************************************************
// set values for costWeight
//******************************************************
void rangeStudyRangeStudy::SetValues_costWeight() {
  costWeightValues[0] = 0;
  costWeightValues[1] = 0;
  costWeightValues[2] = 0;
  costWeightValues[3] = 0.1;
  costWeightValues[4] = 0.1;
  costWeightValues[5] = 0.1;
  costWeightValues[6] = 0.5;
  costWeightValues[7] = 0.5;
  costWeightValues[8] = 0.5;
}



//******************************************************
//print values of gv (for debugging)
//******************************************************
void rangeStudyRangeStudy::PrintGlobalValues(int expNum) {
  if (NumGVs == 0) {
    cout<<"There are no global variables."<<endl;
    return;
  }

  SetGVs(expNum);

  cout<<"The Global Variable values for experiment "<<
    GetExpName(expNum)<<" are:"<<endl;
  cout << "attacker\tchar\t" << attacker << endl;
  cout << "costWeight\tfloat\t" << costWeight << endl;
}


//******************************************************
//retrieve the value of a global variable
//******************************************************
void *rangeStudyRangeStudy::GetGVValue(char *TheGVName) {
  if (strcmp("attacker", TheGVName) == 0)
    return &attacker;
  else if (strcmp("costWeight", TheGVName) == 0)
    return &costWeight;
  else 
    cerr<<"!! rangeStudyRangeStudy::GetGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
  return NULL;
}


//******************************************************
//override the value of a global variable
//******************************************************
void rangeStudyRangeStudy::OverrideGVValue(char *TheGVName,void *TheGVValue) {
  if (strcmp("attacker", TheGVName) == 0)
    SetGvValue(attacker, *(char *)TheGVValue);
  else if (strcmp("costWeight", TheGVName) == 0)
    SetGvValue(costWeight, *(float *)TheGVValue);
  else 
    cerr<<"!! rangeStudyRangeStudy::OverrideGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
}


//******************************************************
//set the value of all global variables to the given exp
//******************************************************
void rangeStudyRangeStudy::SetGVs(int expNum) {
  SetGvValue(attacker, attackerValues[expNum]);
  SetGvValue(costWeight, costWeightValues[expNum]);
}


//******************************************************
//static class method called by solvers to create study 
//(and thus create all of the model)
//******************************************************
BaseStudyClass* GlobalStudyPtr = NULL;
BaseStudyClass * GenerateStudy() {
  if (GlobalStudyPtr == NULL)
    GlobalStudyPtr = new rangeStudyRangeStudy();
  return GlobalStudyPtr;
}

void DestructStudy() {
  delete GlobalStudyPtr;
  GlobalStudyPtr = NULL;
}
//******************************************************
//get and create the PVModel
//******************************************************
PVModel* rangeStudyRangeStudy::GetPVModel(bool expandTimeArrays) {
  if (ThePVModel!=NULL)
    delete ThePVModel;
  // create the PV model
  ThePVModel=new RewardPVModel(expandTimeArrays);
  return ThePVModel;
}


