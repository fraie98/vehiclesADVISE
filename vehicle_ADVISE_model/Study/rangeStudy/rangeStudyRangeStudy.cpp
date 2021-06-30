
#include "Study/rangeStudy/rangeStudyRangeStudy.h"

//******************************************************
//Global Variables
//******************************************************

//********************************************************
//rangeStudyRangeStudy Constructor
//********************************************************
rangeStudyRangeStudy::rangeStudyRangeStudy() {

  // define arrays of global variable names and types
  NumGVs = 0;
  NumExps = 1;

  GVNames = new char*[NumGVs];
  GVTypes = new char*[NumGVs];

  // create the arrays to store the values of each gv

  // call methods to assign values to each gv
  SetDefaultMobiusRoot(MOBIUSROOT);
}


//******************************************************
//rangeStudyRangeStudy Destructor
//******************************************************
rangeStudyRangeStudy::~rangeStudyRangeStudy() {
  delete ThePVModel;
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
}


//******************************************************
//retrieve the value of a global variable
//******************************************************
void *rangeStudyRangeStudy::GetGVValue(char *TheGVName) {
  
    cerr<<"!! rangeStudyRangeStudy::GetGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
  return NULL;
}


//******************************************************
//override the value of a global variable
//******************************************************
void rangeStudyRangeStudy::OverrideGVValue(char *TheGVName,void *TheGVValue) {
  
    cerr<<"!! rangeStudyRangeStudy::OverrideGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
}


//******************************************************
//set the value of all global variables to the given exp
//******************************************************
void rangeStudyRangeStudy::SetGVs(int expNum) {
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


