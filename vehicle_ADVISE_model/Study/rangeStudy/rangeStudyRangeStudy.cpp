
#include "Study/rangeStudy/rangeStudyRangeStudy.h"

//******************************************************
//Global Variables
//******************************************************
Short IDSsensitivity;
Char attacker;
Short codeObfuscation;
Short firewallSensitivity;

//********************************************************
//rangeStudyRangeStudy Constructor
//********************************************************
rangeStudyRangeStudy::rangeStudyRangeStudy() {

  // define arrays of global variable names and types
  NumGVs = 4;
  NumExps = 36;

  GVNames = new char*[NumGVs];
  GVTypes = new char*[NumGVs];
  GVNames[0]=strdup("IDSsensitivity");
  GVTypes[0]=strdup("short");
  GVNames[1]=strdup("attacker");
  GVTypes[1]=strdup("char");
  GVNames[2]=strdup("codeObfuscation");
  GVTypes[2]=strdup("short");
  GVNames[3]=strdup("firewallSensitivity");
  GVTypes[3]=strdup("short");

  // create the arrays to store the values of each gv
  IDSsensitivityValues = new short[NumExps];
  attackerValues = new char[NumExps];
  codeObfuscationValues = new short[NumExps];
  firewallSensitivityValues = new short[NumExps];

  // call methods to assign values to each gv
  SetValues_IDSsensitivity();
  SetValues_attacker();
  SetValues_codeObfuscation();
  SetValues_firewallSensitivity();
  SetDefaultMobiusRoot(MOBIUSROOT);
}


//******************************************************
//rangeStudyRangeStudy Destructor
//******************************************************
rangeStudyRangeStudy::~rangeStudyRangeStudy() {
  delete [] IDSsensitivityValues;
  delete [] attackerValues;
  delete [] codeObfuscationValues;
  delete [] firewallSensitivityValues;
  delete ThePVModel;
}


//******************************************************
// set values for IDSsensitivity
//******************************************************
void rangeStudyRangeStudy::SetValues_IDSsensitivity() {
  IDSsensitivityValues[0] = 0;
  IDSsensitivityValues[1] = 1;
  IDSsensitivityValues[2] = 0;
  IDSsensitivityValues[3] = 1;
  IDSsensitivityValues[4] = 0;
  IDSsensitivityValues[5] = 1;
  IDSsensitivityValues[6] = 0;
  IDSsensitivityValues[7] = 1;
  IDSsensitivityValues[8] = 0;
  IDSsensitivityValues[9] = 1;
  IDSsensitivityValues[10] = 0;
  IDSsensitivityValues[11] = 1;
  IDSsensitivityValues[12] = 0;
  IDSsensitivityValues[13] = 1;
  IDSsensitivityValues[14] = 0;
  IDSsensitivityValues[15] = 1;
  IDSsensitivityValues[16] = 0;
  IDSsensitivityValues[17] = 1;
  IDSsensitivityValues[18] = 0;
  IDSsensitivityValues[19] = 1;
  IDSsensitivityValues[20] = 0;
  IDSsensitivityValues[21] = 1;
  IDSsensitivityValues[22] = 0;
  IDSsensitivityValues[23] = 1;
  IDSsensitivityValues[24] = 0;
  IDSsensitivityValues[25] = 1;
  IDSsensitivityValues[26] = 0;
  IDSsensitivityValues[27] = 1;
  IDSsensitivityValues[28] = 0;
  IDSsensitivityValues[29] = 1;
  IDSsensitivityValues[30] = 0;
  IDSsensitivityValues[31] = 1;
  IDSsensitivityValues[32] = 0;
  IDSsensitivityValues[33] = 1;
  IDSsensitivityValues[34] = 0;
  IDSsensitivityValues[35] = 1;
}


//******************************************************
// set values for attacker
//******************************************************
void rangeStudyRangeStudy::SetValues_attacker() {
  attackerValues[0] = 'H';
  attackerValues[1] = 'H';
  attackerValues[2] = 'I';
  attackerValues[3] = 'I';
  attackerValues[4] = 'P';
  attackerValues[5] = 'P';
  attackerValues[6] = 'H';
  attackerValues[7] = 'H';
  attackerValues[8] = 'I';
  attackerValues[9] = 'I';
  attackerValues[10] = 'P';
  attackerValues[11] = 'P';
  attackerValues[12] = 'H';
  attackerValues[13] = 'H';
  attackerValues[14] = 'I';
  attackerValues[15] = 'I';
  attackerValues[16] = 'P';
  attackerValues[17] = 'P';
  attackerValues[18] = 'H';
  attackerValues[19] = 'H';
  attackerValues[20] = 'I';
  attackerValues[21] = 'I';
  attackerValues[22] = 'P';
  attackerValues[23] = 'P';
  attackerValues[24] = 'H';
  attackerValues[25] = 'H';
  attackerValues[26] = 'I';
  attackerValues[27] = 'I';
  attackerValues[28] = 'P';
  attackerValues[29] = 'P';
  attackerValues[30] = 'H';
  attackerValues[31] = 'H';
  attackerValues[32] = 'I';
  attackerValues[33] = 'I';
  attackerValues[34] = 'P';
  attackerValues[35] = 'P';
}


//******************************************************
// set values for codeObfuscation
//******************************************************
void rangeStudyRangeStudy::SetValues_codeObfuscation() {
  codeObfuscationValues[0] = 0;
  codeObfuscationValues[1] = 0;
  codeObfuscationValues[2] = 0;
  codeObfuscationValues[3] = 0;
  codeObfuscationValues[4] = 0;
  codeObfuscationValues[5] = 0;
  codeObfuscationValues[6] = 1;
  codeObfuscationValues[7] = 1;
  codeObfuscationValues[8] = 1;
  codeObfuscationValues[9] = 1;
  codeObfuscationValues[10] = 1;
  codeObfuscationValues[11] = 1;
  codeObfuscationValues[12] = 0;
  codeObfuscationValues[13] = 0;
  codeObfuscationValues[14] = 0;
  codeObfuscationValues[15] = 0;
  codeObfuscationValues[16] = 0;
  codeObfuscationValues[17] = 0;
  codeObfuscationValues[18] = 1;
  codeObfuscationValues[19] = 1;
  codeObfuscationValues[20] = 1;
  codeObfuscationValues[21] = 1;
  codeObfuscationValues[22] = 1;
  codeObfuscationValues[23] = 1;
  codeObfuscationValues[24] = 0;
  codeObfuscationValues[25] = 0;
  codeObfuscationValues[26] = 0;
  codeObfuscationValues[27] = 0;
  codeObfuscationValues[28] = 0;
  codeObfuscationValues[29] = 0;
  codeObfuscationValues[30] = 1;
  codeObfuscationValues[31] = 1;
  codeObfuscationValues[32] = 1;
  codeObfuscationValues[33] = 1;
  codeObfuscationValues[34] = 1;
  codeObfuscationValues[35] = 1;
}


//******************************************************
// set values for firewallSensitivity
//******************************************************
void rangeStudyRangeStudy::SetValues_firewallSensitivity() {
  firewallSensitivityValues[0] = 0;
  firewallSensitivityValues[1] = 0;
  firewallSensitivityValues[2] = 0;
  firewallSensitivityValues[3] = 0;
  firewallSensitivityValues[4] = 0;
  firewallSensitivityValues[5] = 0;
  firewallSensitivityValues[6] = 0;
  firewallSensitivityValues[7] = 0;
  firewallSensitivityValues[8] = 0;
  firewallSensitivityValues[9] = 0;
  firewallSensitivityValues[10] = 0;
  firewallSensitivityValues[11] = 0;
  firewallSensitivityValues[12] = 1;
  firewallSensitivityValues[13] = 1;
  firewallSensitivityValues[14] = 1;
  firewallSensitivityValues[15] = 1;
  firewallSensitivityValues[16] = 1;
  firewallSensitivityValues[17] = 1;
  firewallSensitivityValues[18] = 1;
  firewallSensitivityValues[19] = 1;
  firewallSensitivityValues[20] = 1;
  firewallSensitivityValues[21] = 1;
  firewallSensitivityValues[22] = 1;
  firewallSensitivityValues[23] = 1;
  firewallSensitivityValues[24] = 2;
  firewallSensitivityValues[25] = 2;
  firewallSensitivityValues[26] = 2;
  firewallSensitivityValues[27] = 2;
  firewallSensitivityValues[28] = 2;
  firewallSensitivityValues[29] = 2;
  firewallSensitivityValues[30] = 2;
  firewallSensitivityValues[31] = 2;
  firewallSensitivityValues[32] = 2;
  firewallSensitivityValues[33] = 2;
  firewallSensitivityValues[34] = 2;
  firewallSensitivityValues[35] = 2;
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
  cout << "IDSsensitivity\tshort\t" << IDSsensitivity << endl;
  cout << "attacker\tchar\t" << attacker << endl;
  cout << "codeObfuscation\tshort\t" << codeObfuscation << endl;
  cout << "firewallSensitivity\tshort\t" << firewallSensitivity << endl;
}


//******************************************************
//retrieve the value of a global variable
//******************************************************
void *rangeStudyRangeStudy::GetGVValue(char *TheGVName) {
  if (strcmp("IDSsensitivity", TheGVName) == 0)
    return &IDSsensitivity;
  else if (strcmp("attacker", TheGVName) == 0)
    return &attacker;
  else if (strcmp("codeObfuscation", TheGVName) == 0)
    return &codeObfuscation;
  else if (strcmp("firewallSensitivity", TheGVName) == 0)
    return &firewallSensitivity;
  else 
    cerr<<"!! rangeStudyRangeStudy::GetGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
  return NULL;
}


//******************************************************
//override the value of a global variable
//******************************************************
void rangeStudyRangeStudy::OverrideGVValue(char *TheGVName,void *TheGVValue) {
  if (strcmp("IDSsensitivity", TheGVName) == 0)
    SetGvValue(IDSsensitivity, *(short *)TheGVValue);
  else if (strcmp("attacker", TheGVName) == 0)
    SetGvValue(attacker, *(char *)TheGVValue);
  else if (strcmp("codeObfuscation", TheGVName) == 0)
    SetGvValue(codeObfuscation, *(short *)TheGVValue);
  else if (strcmp("firewallSensitivity", TheGVName) == 0)
    SetGvValue(firewallSensitivity, *(short *)TheGVValue);
  else 
    cerr<<"!! rangeStudyRangeStudy::OverrideGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
}


//******************************************************
//set the value of all global variables to the given exp
//******************************************************
void rangeStudyRangeStudy::SetGVs(int expNum) {
  SetGvValue(IDSsensitivity, IDSsensitivityValues[expNum]);
  SetGvValue(attacker, attackerValues[expNum]);
  SetGvValue(codeObfuscation, codeObfuscationValues[expNum]);
  SetGvValue(firewallSensitivity, firewallSensitivityValues[expNum]);
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


