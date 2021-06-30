
#ifndef rangeStudyRangeSTUDY_H_
#define rangeStudyRangeSTUDY_H_

#include "Reward/Reward/RewardPVNodes.h"
#include "Reward/Reward/RewardPVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"


class rangeStudyRangeStudy : public BaseStudyClass {
public:

rangeStudyRangeStudy();
~rangeStudyRangeStudy();

private:



void PrintGlobalValues(int);
void *GetGVValue(char *TheGVName);
void OverrideGVValue(char *TheGVName, void *TheGVValue);
void SetGVs(int expnum);
PVModel *GetPVModel(bool expandTimeArrays);
};

#endif

