#ifndef advise_treeADVISE_H_
#define advise_treeADVISE_H_

#include "Cpp/Simulator/UserDistributions.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/BaseClasses/PostselectGroup.h"
#include "Cpp/BaseClasses/PreselectGroup.h"
#include "Cpp/BaseClasses/atomic/advise/ADVISEModel.h"
#include "Cpp/BaseClasses/atomic/advise/Access.h"
#include "Cpp/BaseClasses/atomic/advise/AdversaryDecision.h"
#include "Cpp/BaseClasses/atomic/advise/BeginAdversaryDecision.h"
#include "Cpp/BaseClasses/atomic/advise/Goal.h"
#include "Cpp/BaseClasses/atomic/advise/Knowledge.h"
#include "Cpp/BaseClasses/atomic/advise/Skill.h"
#include "Cpp/BaseClasses/atomic/advise/Step.h"
#include "Cpp/BaseClasses/atomic/advise/StepChosen.h"
#include "Cpp/BaseClasses/atomic/advise/StepWeight.h"
#include <limits.h>
#include <cmath>
extern UserDistributions* TheDistribution;

/*********************************************************************
               advise_treeADVISE Submodel Definition                   
*********************************************************************/

class advise_treeADVISE : public ADVISEModel {
public:

class QueryFloodingAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *QueryFloodingChosen;
  short *QueryFloodingChosen_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  double *TheDistributionParameters;

  QueryFloodingAdversaryDecision();
  ~QueryFloodingAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // QueryFloodingAdversaryDecision

class DoNothingAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *DoNothingChosen;
  short *DoNothingChosen_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  double *TheDistributionParameters;

  DoNothingAdversaryDecision();
  ~DoNothingAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // DoNothingAdversaryDecision

class FirmwareReversingAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *FirmwareReversingChosen;
  short *FirmwareReversingChosen_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  double *TheDistributionParameters;

  FirmwareReversingAdversaryDecision();
  ~FirmwareReversingAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // FirmwareReversingAdversaryDecision

class QueryFloodingFailureStep : public Step {
public:

  Goal *DoS;
  short* DoS_Mobius_Mark;
  Skill *Script;
  short* Script_Mobius_Mark;
  Knowledge *HandshakeProtocol;
  short* HandshakeProtocol_Mobius_Mark;
  Knowledge *SocketAddress;
  short* SocketAddress_Mobius_Mark;
  StepChosen *QueryFloodingChosen;
  short *QueryFloodingChosen_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  QueryFloodingFailureStep();
  ~QueryFloodingFailureStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // QueryFloodingFailureStep

class QueryFloodingSuccessStep : public Step {
public:

  Goal *DoS;
  short* DoS_Mobius_Mark;
  Skill *Script;
  short* Script_Mobius_Mark;
  Knowledge *HandshakeProtocol;
  short* HandshakeProtocol_Mobius_Mark;
  Knowledge *SocketAddress;
  short* SocketAddress_Mobius_Mark;
  StepChosen *QueryFloodingChosen;
  short *QueryFloodingChosen_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  QueryFloodingSuccessStep();
  ~QueryFloodingSuccessStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // QueryFloodingSuccessStep

class DoNothingOutcome1Step : public Step {
public:

  StepChosen *DoNothingChosen;
  short *DoNothingChosen_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  DoNothingOutcome1Step();
  ~DoNothingOutcome1Step();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // DoNothingOutcome1Step

class FirmwareReversingFailureStep : public Step {
public:

  Knowledge *HandshakeProtocol;
  short* HandshakeProtocol_Mobius_Mark;
  Knowledge *SocketAddress;
  short* SocketAddress_Mobius_Mark;
  Knowledge *BinaryDump;
  short* BinaryDump_Mobius_Mark;
  Skill *ReverseEngineering;
  short* ReverseEngineering_Mobius_Mark;
  StepChosen *FirmwareReversingChosen;
  short *FirmwareReversingChosen_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  FirmwareReversingFailureStep();
  ~FirmwareReversingFailureStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // FirmwareReversingFailureStep

class FirmwareReversingObtainallStep : public Step {
public:

  Knowledge *HandshakeProtocol;
  short* HandshakeProtocol_Mobius_Mark;
  Knowledge *SocketAddress;
  short* SocketAddress_Mobius_Mark;
  Knowledge *BinaryDump;
  short* BinaryDump_Mobius_Mark;
  Skill *ReverseEngineering;
  short* ReverseEngineering_Mobius_Mark;
  StepChosen *FirmwareReversingChosen;
  short *FirmwareReversingChosen_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  FirmwareReversingObtainallStep();
  ~FirmwareReversingObtainallStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // FirmwareReversingObtainallStep

class FirmwareReversingObtainaddressonlyStep : public Step {
public:

  Knowledge *HandshakeProtocol;
  short* HandshakeProtocol_Mobius_Mark;
  Knowledge *SocketAddress;
  short* SocketAddress_Mobius_Mark;
  Knowledge *BinaryDump;
  short* BinaryDump_Mobius_Mark;
  Skill *ReverseEngineering;
  short* ReverseEngineering_Mobius_Mark;
  StepChosen *FirmwareReversingChosen;
  short *FirmwareReversingChosen_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  FirmwareReversingObtainaddressonlyStep();
  ~FirmwareReversingObtainaddressonlyStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // FirmwareReversingObtainaddressonlyStep

  //List of user-specified state variables
  Knowledge *BinaryDump;
  Knowledge *SocketAddress;
  Knowledge *HandshakeProtocol;
  Skill *ReverseEngineering;
  Skill *Script;
  Goal *DoS;
  //List of attack step weight state variables
  StepWeight *QueryFloodingWeight;
  StepWeight *DoNothingWeight;
  StepWeight *FirmwareReversingWeight;
  //List of attack step chosen state variables
  StepChosen *QueryFloodingChosen;
  StepChosen *DoNothingChosen;
  StepChosen *FirmwareReversingChosen;
  //List of attack steps
  QueryFloodingFailureStep QueryFloodingFailure;
  QueryFloodingSuccessStep QueryFloodingSuccess;
  DoNothingOutcome1Step DoNothingOutcome1;
  FirmwareReversingFailureStep FirmwareReversingFailure;
  FirmwareReversingObtainallStep FirmwareReversingObtainall;
  FirmwareReversingObtainaddressonlyStep FirmwareReversingObtainaddressonly;
  QueryFloodingAdversaryDecision QueryFloodingAD;
  DoNothingAdversaryDecision DoNothingAD;
  FirmwareReversingAdversaryDecision FirmwareReversingAD;
  //Groups for attack steps
  PreselectGroup ImmediateGroup;
  PostselectGroup QueryFloodingGroup;
  PostselectGroup FirmwareReversingGroup;
  PostselectGroup AdversaryDecisionGroup;
  advise_treeADVISE();
  ~advise_treeADVISE();
  void assignSVsToAttackSteps();
  double convertCostToUtility(double cost);
  double convertDetectionToUtility(double detections);
  double convertPayoffToUtility(double payoff);
  void customInitialization();

protected:
}; // end advise_treeADVISE

#endif // advise_treeADVISE_H_
