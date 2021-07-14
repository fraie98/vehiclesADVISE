
#ifndef rangeStudyRangeSTUDY_H_
#define rangeStudyRangeSTUDY_H_

#include "Reward/Reward/RewardPVNodes.h"
#include "Reward/Reward/RewardPVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"

extern Short IDSsensitivity;
extern Char attacker;
extern Short codeObfuscation;
extern Short firewallSensitivity;

class rangeStudyRangeStudy : public BaseStudyClass {
public:

rangeStudyRangeStudy();
~rangeStudyRangeStudy();

private:

short *IDSsensitivityValues;
char *attackerValues;
short *codeObfuscationValues;
short *firewallSensitivityValues;

void SetValues_IDSsensitivity();
void SetValues_attacker();
void SetValues_codeObfuscation();
void SetValues_firewallSensitivity();

void PrintGlobalValues(int);
void *GetGVValue(char *TheGVName);
void OverrideGVValue(char *TheGVName, void *TheGVValue);
void SetGVs(int expnum);
PVModel *GetPVModel(bool expandTimeArrays);
};

#endif

