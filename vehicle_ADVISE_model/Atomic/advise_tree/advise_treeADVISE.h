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

class ExploitAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *ExploitChosen;
  short *ExploitChosen_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  double *TheDistributionParameters;

  ExploitAdversaryDecision();
  ~ExploitAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // ExploitAdversaryDecision

class UnauthorizedRemoteLoginAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *UnauthorizedRemoteLoginChosen;
  short *UnauthorizedRemoteLoginChosen_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  double *TheDistributionParameters;

  UnauthorizedRemoteLoginAdversaryDecision();
  ~UnauthorizedRemoteLoginAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // UnauthorizedRemoteLoginAdversaryDecision

class TamperingAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *TamperingChosen;
  short *TamperingChosen_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  double *TheDistributionParameters;

  TamperingAdversaryDecision();
  ~TamperingAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // TamperingAdversaryDecision

class WebIntrusionAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *WebIntrusionChosen;
  short *WebIntrusionChosen_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  double *TheDistributionParameters;

  WebIntrusionAdversaryDecision();
  ~WebIntrusionAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // WebIntrusionAdversaryDecision

class PivotingAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *PivotingChosen;
  short *PivotingChosen_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  double *TheDistributionParameters;

  PivotingAdversaryDecision();
  ~PivotingAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // PivotingAdversaryDecision

class PrivilegeEscalationAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *PrivilegeEscalationChosen;
  short *PrivilegeEscalationChosen_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  double *TheDistributionParameters;

  PrivilegeEscalationAdversaryDecision();
  ~PrivilegeEscalationAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // PrivilegeEscalationAdversaryDecision

class DatabaseDumpAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *DatabaseDumpChosen;
  short *DatabaseDumpChosen_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  double *TheDistributionParameters;

  DatabaseDumpAdversaryDecision();
  ~DatabaseDumpAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // DatabaseDumpAdversaryDecision

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

class NetworkAttackAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *NetworkAttackChosen;
  short *NetworkAttackChosen_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  double *TheDistributionParameters;

  NetworkAttackAdversaryDecision();
  ~NetworkAttackAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // NetworkAttackAdversaryDecision

class MalwareIntroductionAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *MalwareIntroductionChosen;
  short *MalwareIntroductionChosen_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  double *TheDistributionParameters;

  MalwareIntroductionAdversaryDecision();
  ~MalwareIntroductionAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // MalwareIntroductionAdversaryDecision

class PortScanAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *PortScanChosen;
  short *PortScanChosen_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  double *TheDistributionParameters;

  PortScanAdversaryDecision();
  ~PortScanAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // PortScanAdversaryDecision

class ExploitFailureStep : public Step {
public:

  Access *VehicleServerRootAccess;
  short* VehicleServerRootAccess_Mobius_Mark;
  Knowledge *VulnerabilityAwareness;
  short* VulnerabilityAwareness_Mobius_Mark;
  StepChosen *ExploitChosen;
  short *ExploitChosen_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  ExploitFailureStep();
  ~ExploitFailureStep();
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
}; // ExploitFailureStep

class ExploitSuccessStep : public Step {
public:

  Access *VehicleServerRootAccess;
  short* VehicleServerRootAccess_Mobius_Mark;
  Knowledge *VulnerabilityAwareness;
  short* VulnerabilityAwareness_Mobius_Mark;
  StepChosen *ExploitChosen;
  short *ExploitChosen_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  ExploitSuccessStep();
  ~ExploitSuccessStep();
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
}; // ExploitSuccessStep

class UnauthorizedRemoteLoginFaliureStep : public Step {
public:

  Access *CorporateNetworkAccess;
  short* CorporateNetworkAccess_Mobius_Mark;
  Knowledge *EmoployeePersonalInfo;
  short* EmoployeePersonalInfo_Mobius_Mark;
  StepChosen *UnauthorizedRemoteLoginChosen;
  short *UnauthorizedRemoteLoginChosen_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  UnauthorizedRemoteLoginFaliureStep();
  ~UnauthorizedRemoteLoginFaliureStep();
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
}; // UnauthorizedRemoteLoginFaliureStep

class UnauthorizedRemoteLoginSuccessStep : public Step {
public:

  Access *CorporateNetworkAccess;
  short* CorporateNetworkAccess_Mobius_Mark;
  Knowledge *EmoployeePersonalInfo;
  short* EmoployeePersonalInfo_Mobius_Mark;
  StepChosen *UnauthorizedRemoteLoginChosen;
  short *UnauthorizedRemoteLoginChosen_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  UnauthorizedRemoteLoginSuccessStep();
  ~UnauthorizedRemoteLoginSuccessStep();
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
}; // UnauthorizedRemoteLoginSuccessStep

class TamperingFailureStep : public Step {
public:

  Goal *VehicleUndesideredBehaviour;
  short* VehicleUndesideredBehaviour_Mobius_Mark;
  Access *VehicleServerRootAccess;
  short* VehicleServerRootAccess_Mobius_Mark;
  StepChosen *TamperingChosen;
  short *TamperingChosen_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  TamperingFailureStep();
  ~TamperingFailureStep();
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
}; // TamperingFailureStep

class TamperingSuccessStep : public Step {
public:

  Goal *VehicleUndesideredBehaviour;
  short* VehicleUndesideredBehaviour_Mobius_Mark;
  Access *VehicleServerRootAccess;
  short* VehicleServerRootAccess_Mobius_Mark;
  StepChosen *TamperingChosen;
  short *TamperingChosen_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  TamperingSuccessStep();
  ~TamperingSuccessStep();
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
}; // TamperingSuccessStep

class WebIntrusionFaliureStep : public Step {
public:

  Access *CorporateNetworkAccess;
  short* CorporateNetworkAccess_Mobius_Mark;
  Knowledge *CorporateInternetAddress;
  short* CorporateInternetAddress_Mobius_Mark;
  StepChosen *WebIntrusionChosen;
  short *WebIntrusionChosen_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  WebIntrusionFaliureStep();
  ~WebIntrusionFaliureStep();
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
}; // WebIntrusionFaliureStep

class WebIntrusionSuccessStep : public Step {
public:

  Access *CorporateNetworkAccess;
  short* CorporateNetworkAccess_Mobius_Mark;
  Knowledge *CorporateInternetAddress;
  short* CorporateInternetAddress_Mobius_Mark;
  StepChosen *WebIntrusionChosen;
  short *WebIntrusionChosen_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  WebIntrusionSuccessStep();
  ~WebIntrusionSuccessStep();
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
}; // WebIntrusionSuccessStep

class PivotingfaliureStep : public Step {
public:

  Access *vehicleServerUnprivAccess;
  short* vehicleServerUnprivAccess_Mobius_Mark;
  Access *CorporateNetworkAccess;
  short* CorporateNetworkAccess_Mobius_Mark;
  StepChosen *PivotingChosen;
  short *PivotingChosen_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  PivotingfaliureStep();
  ~PivotingfaliureStep();
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
}; // PivotingfaliureStep

class PivotingsuccessStep : public Step {
public:

  Access *vehicleServerUnprivAccess;
  short* vehicleServerUnprivAccess_Mobius_Mark;
  Access *CorporateNetworkAccess;
  short* CorporateNetworkAccess_Mobius_Mark;
  StepChosen *PivotingChosen;
  short *PivotingChosen_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  PivotingsuccessStep();
  ~PivotingsuccessStep();
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
}; // PivotingsuccessStep

class PrivilegeEscalationfaliureStep : public Step {
public:

  Access *VehicleServerRootAccess;
  short* VehicleServerRootAccess_Mobius_Mark;
  Access *vehicleServerUnprivAccess;
  short* vehicleServerUnprivAccess_Mobius_Mark;
  StepChosen *PrivilegeEscalationChosen;
  short *PrivilegeEscalationChosen_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  PrivilegeEscalationfaliureStep();
  ~PrivilegeEscalationfaliureStep();
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
}; // PrivilegeEscalationfaliureStep

class PrivilegeEscalationsuccessStep : public Step {
public:

  Access *VehicleServerRootAccess;
  short* VehicleServerRootAccess_Mobius_Mark;
  Access *vehicleServerUnprivAccess;
  short* vehicleServerUnprivAccess_Mobius_Mark;
  StepChosen *PrivilegeEscalationChosen;
  short *PrivilegeEscalationChosen_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  PrivilegeEscalationsuccessStep();
  ~PrivilegeEscalationsuccessStep();
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
}; // PrivilegeEscalationsuccessStep

class DatabaseDumpFailureStep : public Step {
public:

  Goal *DataBreach;
  short* DataBreach_Mobius_Mark;
  Access *VehicleServerRootAccess;
  short* VehicleServerRootAccess_Mobius_Mark;
  StepChosen *DatabaseDumpChosen;
  short *DatabaseDumpChosen_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  DatabaseDumpFailureStep();
  ~DatabaseDumpFailureStep();
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
}; // DatabaseDumpFailureStep

class DatabaseDumpSuccessStep : public Step {
public:

  Goal *DataBreach;
  short* DataBreach_Mobius_Mark;
  Access *VehicleServerRootAccess;
  short* VehicleServerRootAccess_Mobius_Mark;
  StepChosen *DatabaseDumpChosen;
  short *DatabaseDumpChosen_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  DatabaseDumpSuccessStep();
  ~DatabaseDumpSuccessStep();
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
}; // DatabaseDumpSuccessStep

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
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
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
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
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
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
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
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
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
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
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

class DoNothingOutcome1Step : public Step {
public:

  StepChosen *DoNothingChosen;
  short *DoNothingChosen_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
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

class NetworkAttackfaliureStep : public Step {
public:

  Access *CorporateNetworkAccess;
  short* CorporateNetworkAccess_Mobius_Mark;
  Knowledge *CorporateServerLocation;
  short* CorporateServerLocation_Mobius_Mark;
  StepChosen *NetworkAttackChosen;
  short *NetworkAttackChosen_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  NetworkAttackfaliureStep();
  ~NetworkAttackfaliureStep();
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
}; // NetworkAttackfaliureStep

class NetworkAttacksuccessStep : public Step {
public:

  Access *CorporateNetworkAccess;
  short* CorporateNetworkAccess_Mobius_Mark;
  Knowledge *CorporateServerLocation;
  short* CorporateServerLocation_Mobius_Mark;
  StepChosen *NetworkAttackChosen;
  short *NetworkAttackChosen_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  NetworkAttacksuccessStep();
  ~NetworkAttacksuccessStep();
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
}; // NetworkAttacksuccessStep

class MalwareIntroductionfaliureStep : public Step {
public:

  Access *vehicleServerUnprivAccess;
  short* vehicleServerUnprivAccess_Mobius_Mark;
  Access *PhysicalAccess;
  short* PhysicalAccess_Mobius_Mark;
  StepChosen *MalwareIntroductionChosen;
  short *MalwareIntroductionChosen_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  MalwareIntroductionfaliureStep();
  ~MalwareIntroductionfaliureStep();
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
}; // MalwareIntroductionfaliureStep

class MalwareIntroductionsuccessStep : public Step {
public:

  Access *vehicleServerUnprivAccess;
  short* vehicleServerUnprivAccess_Mobius_Mark;
  Access *PhysicalAccess;
  short* PhysicalAccess_Mobius_Mark;
  StepChosen *MalwareIntroductionChosen;
  short *MalwareIntroductionChosen_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  MalwareIntroductionsuccessStep();
  ~MalwareIntroductionsuccessStep();
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
}; // MalwareIntroductionsuccessStep

class PortScanFailureStep : public Step {
public:

  Knowledge *VulnerabilityAwareness;
  short* VulnerabilityAwareness_Mobius_Mark;
  Knowledge *SocketAddress;
  short* SocketAddress_Mobius_Mark;
  StepChosen *PortScanChosen;
  short *PortScanChosen_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  PortScanFailureStep();
  ~PortScanFailureStep();
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
}; // PortScanFailureStep

class PortScanSuccessStep : public Step {
public:

  Knowledge *VulnerabilityAwareness;
  short* VulnerabilityAwareness_Mobius_Mark;
  Knowledge *SocketAddress;
  short* SocketAddress_Mobius_Mark;
  StepChosen *PortScanChosen;
  short *PortScanChosen_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
  StepWeight *UnauthorizedRemoteLoginWeight;
  short *UnauthorizedRemoteLoginWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *WebIntrusionWeight;
  short *WebIntrusionWeight_Mobius_Mark;
  StepWeight *PivotingWeight;
  short *PivotingWeight_Mobius_Mark;
  StepWeight *PrivilegeEscalationWeight;
  short *PrivilegeEscalationWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *NetworkAttackWeight;
  short *NetworkAttackWeight_Mobius_Mark;
  StepWeight *MalwareIntroductionWeight;
  short *MalwareIntroductionWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  PortScanSuccessStep();
  ~PortScanSuccessStep();
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
}; // PortScanSuccessStep

  //List of user-specified state variables
  Access *VehicleServerRootAccess;
  Access *vehicleServerUnprivAccess;
  Access *PhysicalAccess;
  Access *CorporateNetworkAccess;
  Knowledge *SocketAddress;
  Knowledge *VulnerabilityAwareness;
  Knowledge *BinaryDump;
  Knowledge *EmoployeePersonalInfo;
  Knowledge *HandshakeProtocol;
  Knowledge *CorporateServerLocation;
  Knowledge *CorporateInternetAddress;
  Skill *ReverseEngineering;
  Skill *Script;
  Goal *DataBreach;
  Goal *VehicleUndesideredBehaviour;
  Goal *DoS;
  //List of attack step weight state variables
  StepWeight *ExploitWeight;
  StepWeight *UnauthorizedRemoteLoginWeight;
  StepWeight *TamperingWeight;
  StepWeight *WebIntrusionWeight;
  StepWeight *PivotingWeight;
  StepWeight *PrivilegeEscalationWeight;
  StepWeight *DatabaseDumpWeight;
  StepWeight *QueryFloodingWeight;
  StepWeight *FirmwareReversingWeight;
  StepWeight *DoNothingWeight;
  StepWeight *NetworkAttackWeight;
  StepWeight *MalwareIntroductionWeight;
  StepWeight *PortScanWeight;
  //List of attack step chosen state variables
  StepChosen *ExploitChosen;
  StepChosen *UnauthorizedRemoteLoginChosen;
  StepChosen *TamperingChosen;
  StepChosen *WebIntrusionChosen;
  StepChosen *PivotingChosen;
  StepChosen *PrivilegeEscalationChosen;
  StepChosen *DatabaseDumpChosen;
  StepChosen *QueryFloodingChosen;
  StepChosen *FirmwareReversingChosen;
  StepChosen *DoNothingChosen;
  StepChosen *NetworkAttackChosen;
  StepChosen *MalwareIntroductionChosen;
  StepChosen *PortScanChosen;
  //List of attack steps
  ExploitFailureStep ExploitFailure;
  ExploitSuccessStep ExploitSuccess;
  UnauthorizedRemoteLoginFaliureStep UnauthorizedRemoteLoginFaliure;
  UnauthorizedRemoteLoginSuccessStep UnauthorizedRemoteLoginSuccess;
  TamperingFailureStep TamperingFailure;
  TamperingSuccessStep TamperingSuccess;
  WebIntrusionFaliureStep WebIntrusionFaliure;
  WebIntrusionSuccessStep WebIntrusionSuccess;
  PivotingfaliureStep Pivotingfaliure;
  PivotingsuccessStep Pivotingsuccess;
  PrivilegeEscalationfaliureStep PrivilegeEscalationfaliure;
  PrivilegeEscalationsuccessStep PrivilegeEscalationsuccess;
  DatabaseDumpFailureStep DatabaseDumpFailure;
  DatabaseDumpSuccessStep DatabaseDumpSuccess;
  QueryFloodingFailureStep QueryFloodingFailure;
  QueryFloodingSuccessStep QueryFloodingSuccess;
  FirmwareReversingFailureStep FirmwareReversingFailure;
  FirmwareReversingObtainallStep FirmwareReversingObtainall;
  FirmwareReversingObtainaddressonlyStep FirmwareReversingObtainaddressonly;
  DoNothingOutcome1Step DoNothingOutcome1;
  NetworkAttackfaliureStep NetworkAttackfaliure;
  NetworkAttacksuccessStep NetworkAttacksuccess;
  MalwareIntroductionfaliureStep MalwareIntroductionfaliure;
  MalwareIntroductionsuccessStep MalwareIntroductionsuccess;
  PortScanFailureStep PortScanFailure;
  PortScanSuccessStep PortScanSuccess;
  ExploitAdversaryDecision ExploitAD;
  UnauthorizedRemoteLoginAdversaryDecision UnauthorizedRemoteLoginAD;
  TamperingAdversaryDecision TamperingAD;
  WebIntrusionAdversaryDecision WebIntrusionAD;
  PivotingAdversaryDecision PivotingAD;
  PrivilegeEscalationAdversaryDecision PrivilegeEscalationAD;
  DatabaseDumpAdversaryDecision DatabaseDumpAD;
  QueryFloodingAdversaryDecision QueryFloodingAD;
  FirmwareReversingAdversaryDecision FirmwareReversingAD;
  DoNothingAdversaryDecision DoNothingAD;
  NetworkAttackAdversaryDecision NetworkAttackAD;
  MalwareIntroductionAdversaryDecision MalwareIntroductionAD;
  PortScanAdversaryDecision PortScanAD;
  //Groups for attack steps
  PreselectGroup ImmediateGroup;
  PostselectGroup ExploitGroup;
  PostselectGroup UnauthorizedRemoteLoginGroup;
  PostselectGroup TamperingGroup;
  PostselectGroup WebIntrusionGroup;
  PostselectGroup PivotingGroup;
  PostselectGroup PrivilegeEscalationGroup;
  PostselectGroup DatabaseDumpGroup;
  PostselectGroup QueryFloodingGroup;
  PostselectGroup FirmwareReversingGroup;
  PostselectGroup NetworkAttackGroup;
  PostselectGroup MalwareIntroductionGroup;
  PostselectGroup PortScanGroup;
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
