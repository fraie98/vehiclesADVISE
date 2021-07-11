
#ifndef rangeStudyRangeSTUDY_H_
#define rangeStudyRangeSTUDY_H_

#include "Reward/Reward/RewardPVNodes.h"
#include "Reward/Reward/RewardPVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"

extern Char attacker;
extern Float costWeight;

class rangeStudyRangeStudy : public BaseStudyClass {
public:

rangeStudyRangeStudy();
~rangeStudyRangeStudy();

private:

char *attackerValues;
float *costWeightValues;

void SetValues_attacker();
void SetValues_costWeight();

void PrintGlobalValues(int);
void *GetGVValue(char *TheGVName);
void OverrideGVValue(char *TheGVName, void *TheGVValue);
void SetGVs(int expnum);
PVModel *GetPVModel(bool expandTimeArrays);
};

#endif

