
#include "Study/rangeStudy/rangeStudyRangeStudy.h"

//******************************************************
//Global Variables
//******************************************************
Char attacker;
Float costWeight;
Float detectionWeight;
Float payoffWeight;

//********************************************************
//rangeStudyRangeStudy Constructor
//********************************************************
rangeStudyRangeStudy::rangeStudyRangeStudy() {

  // define arrays of global variable names and types
  NumGVs = 4;
  NumExps = 81;

  GVNames = new char*[NumGVs];
  GVTypes = new char*[NumGVs];
  GVNames[0]=strdup("attacker");
  GVTypes[0]=strdup("char");
  GVNames[1]=strdup("costWeight");
  GVTypes[1]=strdup("float");
  GVNames[2]=strdup("detectionWeight");
  GVTypes[2]=strdup("float");
  GVNames[3]=strdup("payoffWeight");
  GVTypes[3]=strdup("float");

  // create the arrays to store the values of each gv
  attackerValues = new char[NumExps];
  costWeightValues = new float[NumExps];
  detectionWeightValues = new float[NumExps];
  payoffWeightValues = new float[NumExps];

  // call methods to assign values to each gv
  SetValues_attacker();
  SetValues_costWeight();
  SetValues_detectionWeight();
  SetValues_payoffWeight();
  SetDefaultMobiusRoot(MOBIUSROOT);
}


//******************************************************
//rangeStudyRangeStudy Destructor
//******************************************************
rangeStudyRangeStudy::~rangeStudyRangeStudy() {
  delete [] attackerValues;
  delete [] costWeightValues;
  delete [] detectionWeightValues;
  delete [] payoffWeightValues;
  delete ThePVModel;
}


//******************************************************
// set values for attacker
//******************************************************
void rangeStudyRangeStudy::SetValues_attacker() {
  attackerValues[0] = 'H';
  attackerValues[1] = 'I';
  attackerValues[2] = 'P';
  attackerValues[3] = 'H';
  attackerValues[4] = 'I';
  attackerValues[5] = 'P';
  attackerValues[6] = 'H';
  attackerValues[7] = 'I';
  attackerValues[8] = 'P';
  attackerValues[9] = 'H';
  attackerValues[10] = 'I';
  attackerValues[11] = 'P';
  attackerValues[12] = 'H';
  attackerValues[13] = 'I';
  attackerValues[14] = 'P';
  attackerValues[15] = 'H';
  attackerValues[16] = 'I';
  attackerValues[17] = 'P';
  attackerValues[18] = 'H';
  attackerValues[19] = 'I';
  attackerValues[20] = 'P';
  attackerValues[21] = 'H';
  attackerValues[22] = 'I';
  attackerValues[23] = 'P';
  attackerValues[24] = 'H';
  attackerValues[25] = 'I';
  attackerValues[26] = 'P';
  attackerValues[27] = 'H';
  attackerValues[28] = 'I';
  attackerValues[29] = 'P';
  attackerValues[30] = 'H';
  attackerValues[31] = 'I';
  attackerValues[32] = 'P';
  attackerValues[33] = 'H';
  attackerValues[34] = 'I';
  attackerValues[35] = 'P';
  attackerValues[36] = 'H';
  attackerValues[37] = 'I';
  attackerValues[38] = 'P';
  attackerValues[39] = 'H';
  attackerValues[40] = 'I';
  attackerValues[41] = 'P';
  attackerValues[42] = 'H';
  attackerValues[43] = 'I';
  attackerValues[44] = 'P';
  attackerValues[45] = 'H';
  attackerValues[46] = 'I';
  attackerValues[47] = 'P';
  attackerValues[48] = 'H';
  attackerValues[49] = 'I';
  attackerValues[50] = 'P';
  attackerValues[51] = 'H';
  attackerValues[52] = 'I';
  attackerValues[53] = 'P';
  attackerValues[54] = 'H';
  attackerValues[55] = 'I';
  attackerValues[56] = 'P';
  attackerValues[57] = 'H';
  attackerValues[58] = 'I';
  attackerValues[59] = 'P';
  attackerValues[60] = 'H';
  attackerValues[61] = 'I';
  attackerValues[62] = 'P';
  attackerValues[63] = 'H';
  attackerValues[64] = 'I';
  attackerValues[65] = 'P';
  attackerValues[66] = 'H';
  attackerValues[67] = 'I';
  attackerValues[68] = 'P';
  attackerValues[69] = 'H';
  attackerValues[70] = 'I';
  attackerValues[71] = 'P';
  attackerValues[72] = 'H';
  attackerValues[73] = 'I';
  attackerValues[74] = 'P';
  attackerValues[75] = 'H';
  attackerValues[76] = 'I';
  attackerValues[77] = 'P';
  attackerValues[78] = 'H';
  attackerValues[79] = 'I';
  attackerValues[80] = 'P';
}


//******************************************************
// set values for costWeight
//******************************************************
void rangeStudyRangeStudy::SetValues_costWeight() {
  costWeightValues[0] = 0;
  costWeightValues[1] = 0;
  costWeightValues[2] = 0;
  costWeightValues[3] = 0.2;
  costWeightValues[4] = 0.2;
  costWeightValues[5] = 0.2;
  costWeightValues[6] = 0.1;
  costWeightValues[7] = 0.1;
  costWeightValues[8] = 0.1;
  costWeightValues[9] = 0;
  costWeightValues[10] = 0;
  costWeightValues[11] = 0;
  costWeightValues[12] = 0.2;
  costWeightValues[13] = 0.2;
  costWeightValues[14] = 0.2;
  costWeightValues[15] = 0.1;
  costWeightValues[16] = 0.1;
  costWeightValues[17] = 0.1;
  costWeightValues[18] = 0;
  costWeightValues[19] = 0;
  costWeightValues[20] = 0;
  costWeightValues[21] = 0.2;
  costWeightValues[22] = 0.2;
  costWeightValues[23] = 0.2;
  costWeightValues[24] = 0.1;
  costWeightValues[25] = 0.1;
  costWeightValues[26] = 0.1;
  costWeightValues[27] = 0;
  costWeightValues[28] = 0;
  costWeightValues[29] = 0;
  costWeightValues[30] = 0.2;
  costWeightValues[31] = 0.2;
  costWeightValues[32] = 0.2;
  costWeightValues[33] = 0.1;
  costWeightValues[34] = 0.1;
  costWeightValues[35] = 0.1;
  costWeightValues[36] = 0;
  costWeightValues[37] = 0;
  costWeightValues[38] = 0;
  costWeightValues[39] = 0.2;
  costWeightValues[40] = 0.2;
  costWeightValues[41] = 0.2;
  costWeightValues[42] = 0.1;
  costWeightValues[43] = 0.1;
  costWeightValues[44] = 0.1;
  costWeightValues[45] = 0;
  costWeightValues[46] = 0;
  costWeightValues[47] = 0;
  costWeightValues[48] = 0.2;
  costWeightValues[49] = 0.2;
  costWeightValues[50] = 0.2;
  costWeightValues[51] = 0.1;
  costWeightValues[52] = 0.1;
  costWeightValues[53] = 0.1;
  costWeightValues[54] = 0;
  costWeightValues[55] = 0;
  costWeightValues[56] = 0;
  costWeightValues[57] = 0.2;
  costWeightValues[58] = 0.2;
  costWeightValues[59] = 0.2;
  costWeightValues[60] = 0.1;
  costWeightValues[61] = 0.1;
  costWeightValues[62] = 0.1;
  costWeightValues[63] = 0;
  costWeightValues[64] = 0;
  costWeightValues[65] = 0;
  costWeightValues[66] = 0.2;
  costWeightValues[67] = 0.2;
  costWeightValues[68] = 0.2;
  costWeightValues[69] = 0.1;
  costWeightValues[70] = 0.1;
  costWeightValues[71] = 0.1;
  costWeightValues[72] = 0;
  costWeightValues[73] = 0;
  costWeightValues[74] = 0;
  costWeightValues[75] = 0.2;
  costWeightValues[76] = 0.2;
  costWeightValues[77] = 0.2;
  costWeightValues[78] = 0.1;
  costWeightValues[79] = 0.1;
  costWeightValues[80] = 0.1;
}


//******************************************************
// set values for detectionWeight
//******************************************************
void rangeStudyRangeStudy::SetValues_detectionWeight() {
  detectionWeightValues[0] = 0.1;
  detectionWeightValues[1] = 0.1;
  detectionWeightValues[2] = 0.1;
  detectionWeightValues[3] = 0.1;
  detectionWeightValues[4] = 0.1;
  detectionWeightValues[5] = 0.1;
  detectionWeightValues[6] = 0.1;
  detectionWeightValues[7] = 0.1;
  detectionWeightValues[8] = 0.1;
  detectionWeightValues[9] = 0.5;
  detectionWeightValues[10] = 0.5;
  detectionWeightValues[11] = 0.5;
  detectionWeightValues[12] = 0.5;
  detectionWeightValues[13] = 0.5;
  detectionWeightValues[14] = 0.5;
  detectionWeightValues[15] = 0.5;
  detectionWeightValues[16] = 0.5;
  detectionWeightValues[17] = 0.5;
  detectionWeightValues[18] = 0.5;
  detectionWeightValues[19] = 0.5;
  detectionWeightValues[20] = 0.5;
  detectionWeightValues[21] = 0.5;
  detectionWeightValues[22] = 0.5;
  detectionWeightValues[23] = 0.5;
  detectionWeightValues[24] = 0.5;
  detectionWeightValues[25] = 0.5;
  detectionWeightValues[26] = 0.5;
  detectionWeightValues[27] = 0.1;
  detectionWeightValues[28] = 0.1;
  detectionWeightValues[29] = 0.1;
  detectionWeightValues[30] = 0.1;
  detectionWeightValues[31] = 0.1;
  detectionWeightValues[32] = 0.1;
  detectionWeightValues[33] = 0.1;
  detectionWeightValues[34] = 0.1;
  detectionWeightValues[35] = 0.1;
  detectionWeightValues[36] = 0.5;
  detectionWeightValues[37] = 0.5;
  detectionWeightValues[38] = 0.5;
  detectionWeightValues[39] = 0.5;
  detectionWeightValues[40] = 0.5;
  detectionWeightValues[41] = 0.5;
  detectionWeightValues[42] = 0.5;
  detectionWeightValues[43] = 0.5;
  detectionWeightValues[44] = 0.5;
  detectionWeightValues[45] = 0.5;
  detectionWeightValues[46] = 0.5;
  detectionWeightValues[47] = 0.5;
  detectionWeightValues[48] = 0.5;
  detectionWeightValues[49] = 0.5;
  detectionWeightValues[50] = 0.5;
  detectionWeightValues[51] = 0.5;
  detectionWeightValues[52] = 0.5;
  detectionWeightValues[53] = 0.5;
  detectionWeightValues[54] = 0.1;
  detectionWeightValues[55] = 0.1;
  detectionWeightValues[56] = 0.1;
  detectionWeightValues[57] = 0.1;
  detectionWeightValues[58] = 0.1;
  detectionWeightValues[59] = 0.1;
  detectionWeightValues[60] = 0.1;
  detectionWeightValues[61] = 0.1;
  detectionWeightValues[62] = 0.1;
  detectionWeightValues[63] = 0.5;
  detectionWeightValues[64] = 0.5;
  detectionWeightValues[65] = 0.5;
  detectionWeightValues[66] = 0.5;
  detectionWeightValues[67] = 0.5;
  detectionWeightValues[68] = 0.5;
  detectionWeightValues[69] = 0.5;
  detectionWeightValues[70] = 0.5;
  detectionWeightValues[71] = 0.5;
  detectionWeightValues[72] = 0.5;
  detectionWeightValues[73] = 0.5;
  detectionWeightValues[74] = 0.5;
  detectionWeightValues[75] = 0.5;
  detectionWeightValues[76] = 0.5;
  detectionWeightValues[77] = 0.5;
  detectionWeightValues[78] = 0.5;
  detectionWeightValues[79] = 0.5;
  detectionWeightValues[80] = 0.5;
}


//******************************************************
// set values for payoffWeight
//******************************************************
void rangeStudyRangeStudy::SetValues_payoffWeight() {
  payoffWeightValues[0] = 0.9;
  payoffWeightValues[1] = 0.9;
  payoffWeightValues[2] = 0.9;
  payoffWeightValues[3] = 0.9;
  payoffWeightValues[4] = 0.9;
  payoffWeightValues[5] = 0.9;
  payoffWeightValues[6] = 0.9;
  payoffWeightValues[7] = 0.9;
  payoffWeightValues[8] = 0.9;
  payoffWeightValues[9] = 0.9;
  payoffWeightValues[10] = 0.9;
  payoffWeightValues[11] = 0.9;
  payoffWeightValues[12] = 0.9;
  payoffWeightValues[13] = 0.9;
  payoffWeightValues[14] = 0.9;
  payoffWeightValues[15] = 0.9;
  payoffWeightValues[16] = 0.9;
  payoffWeightValues[17] = 0.9;
  payoffWeightValues[18] = 0.9;
  payoffWeightValues[19] = 0.9;
  payoffWeightValues[20] = 0.9;
  payoffWeightValues[21] = 0.9;
  payoffWeightValues[22] = 0.9;
  payoffWeightValues[23] = 0.9;
  payoffWeightValues[24] = 0.9;
  payoffWeightValues[25] = 0.9;
  payoffWeightValues[26] = 0.9;
  payoffWeightValues[27] = 0.3;
  payoffWeightValues[28] = 0.3;
  payoffWeightValues[29] = 0.3;
  payoffWeightValues[30] = 0.3;
  payoffWeightValues[31] = 0.3;
  payoffWeightValues[32] = 0.3;
  payoffWeightValues[33] = 0.3;
  payoffWeightValues[34] = 0.3;
  payoffWeightValues[35] = 0.3;
  payoffWeightValues[36] = 0.3;
  payoffWeightValues[37] = 0.3;
  payoffWeightValues[38] = 0.3;
  payoffWeightValues[39] = 0.3;
  payoffWeightValues[40] = 0.3;
  payoffWeightValues[41] = 0.3;
  payoffWeightValues[42] = 0.3;
  payoffWeightValues[43] = 0.3;
  payoffWeightValues[44] = 0.3;
  payoffWeightValues[45] = 0.3;
  payoffWeightValues[46] = 0.3;
  payoffWeightValues[47] = 0.3;
  payoffWeightValues[48] = 0.3;
  payoffWeightValues[49] = 0.3;
  payoffWeightValues[50] = 0.3;
  payoffWeightValues[51] = 0.3;
  payoffWeightValues[52] = 0.3;
  payoffWeightValues[53] = 0.3;
  payoffWeightValues[54] = 0.4;
  payoffWeightValues[55] = 0.4;
  payoffWeightValues[56] = 0.4;
  payoffWeightValues[57] = 0.4;
  payoffWeightValues[58] = 0.4;
  payoffWeightValues[59] = 0.4;
  payoffWeightValues[60] = 0.4;
  payoffWeightValues[61] = 0.4;
  payoffWeightValues[62] = 0.4;
  payoffWeightValues[63] = 0.4;
  payoffWeightValues[64] = 0.4;
  payoffWeightValues[65] = 0.4;
  payoffWeightValues[66] = 0.4;
  payoffWeightValues[67] = 0.4;
  payoffWeightValues[68] = 0.4;
  payoffWeightValues[69] = 0.4;
  payoffWeightValues[70] = 0.4;
  payoffWeightValues[71] = 0.4;
  payoffWeightValues[72] = 0.4;
  payoffWeightValues[73] = 0.4;
  payoffWeightValues[74] = 0.4;
  payoffWeightValues[75] = 0.4;
  payoffWeightValues[76] = 0.4;
  payoffWeightValues[77] = 0.4;
  payoffWeightValues[78] = 0.4;
  payoffWeightValues[79] = 0.4;
  payoffWeightValues[80] = 0.4;
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
  cout << "detectionWeight\tfloat\t" << detectionWeight << endl;
  cout << "payoffWeight\tfloat\t" << payoffWeight << endl;
}


//******************************************************
//retrieve the value of a global variable
//******************************************************
void *rangeStudyRangeStudy::GetGVValue(char *TheGVName) {
  if (strcmp("attacker", TheGVName) == 0)
    return &attacker;
  else if (strcmp("costWeight", TheGVName) == 0)
    return &costWeight;
  else if (strcmp("detectionWeight", TheGVName) == 0)
    return &detectionWeight;
  else if (strcmp("payoffWeight", TheGVName) == 0)
    return &payoffWeight;
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
  else if (strcmp("detectionWeight", TheGVName) == 0)
    SetGvValue(detectionWeight, *(float *)TheGVValue);
  else if (strcmp("payoffWeight", TheGVName) == 0)
    SetGvValue(payoffWeight, *(float *)TheGVValue);
  else 
    cerr<<"!! rangeStudyRangeStudy::OverrideGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
}


//******************************************************
//set the value of all global variables to the given exp
//******************************************************
void rangeStudyRangeStudy::SetGVs(int expNum) {
  SetGvValue(attacker, attackerValues[expNum]);
  SetGvValue(costWeight, costWeightValues[expNum]);
  SetGvValue(detectionWeight, detectionWeightValues[expNum]);
  SetGvValue(payoffWeight, payoffWeightValues[expNum]);
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


