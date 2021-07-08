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
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
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
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
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
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
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
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
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
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
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
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
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

class PortScanFailureStep : public Step {
public:

  Knowledge *VulnerabilityAwareness;
  short* VulnerabilityAwareness_Mobius_Mark;
  Knowledge *SocketAddress;
  short* SocketAddress_Mobius_Mark;
  StepChosen *PortScanChosen;
  short *PortScanChosen_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
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
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
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

class DatabaseDumpFailureStep : public Step {
public:

  Goal *DataBreach;
  short* DataBreach_Mobius_Mark;
  Access *VehicleServerRootAccess;
  short* VehicleServerRootAccess_Mobius_Mark;
  StepChosen *DatabaseDumpChosen;
  short *DatabaseDumpChosen_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
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
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
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

class TamperingFailureStep : public Step {
public:

  Goal *VehicleUndesideredBehaviour;
  short* VehicleUndesideredBehaviour_Mobius_Mark;
  Access *VehicleServerRootAccess;
  short* VehicleServerRootAccess_Mobius_Mark;
  StepChosen *TamperingChosen;
  short *TamperingChosen_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
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
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
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

class ExploitFailureStep : public Step {
public:

  Access *VehicleServerRootAccess;
  short* VehicleServerRootAccess_Mobius_Mark;
  Knowledge *VulnerabilityAwareness;
  short* VulnerabilityAwareness_Mobius_Mark;
  StepChosen *ExploitChosen;
  short *ExploitChosen_Mobius_Mark;
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
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
  StepWeight *QueryFloodingWeight;
  short *QueryFloodingWeight_Mobius_Mark;
  StepWeight *FirmwareReversingWeight;
  short *FirmwareReversingWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *PortScanWeight;
  short *PortScanWeight_Mobius_Mark;
  StepWeight *DatabaseDumpWeight;
  short *DatabaseDumpWeight_Mobius_Mark;
  StepWeight *TamperingWeight;
  short *TamperingWeight_Mobius_Mark;
  StepWeight *ExploitWeight;
  short *ExploitWeight_Mobius_Mark;
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

  //List of user-specified state variables
  Access *VehicleServerRootAccess;
  Knowledge *HandshakeProtocol;
  Knowledge *VulnerabilityAwareness;
  Knowledge *SocketAddress;
  Knowledge *BinaryDump;
  Skill *ReverseEngineering;
  Skill *Script;
  Goal *DataBreach;
  Goal *VehicleUndesideredBehaviour;
  Goal *DoS;
  //List of attack step weight state variables
  StepWeight *QueryFloodingWeight;
  StepWeight *FirmwareReversingWeight;
  StepWeight *DoNothingWeight;
  StepWeight *PortScanWeight;
  StepWeight *DatabaseDumpWeight;
  StepWeight *TamperingWeight;
  StepWeight *ExploitWeight;
  //List of attack step chosen state variables
  StepChosen *QueryFloodingChosen;
  StepChosen *FirmwareReversingChosen;
  StepChosen *DoNothingChosen;
  StepChosen *PortScanChosen;
  StepChosen *DatabaseDumpChosen;
  StepChosen *TamperingChosen;
  StepChosen *ExploitChosen;
  //List of attack steps
  QueryFloodingFailureStep QueryFloodingFailure;
  QueryFloodingSuccessStep QueryFloodingSuccess;
  FirmwareReversingFailureStep FirmwareReversingFailure;
  FirmwareReversingObtainallStep FirmwareReversingObtainall;
  FirmwareReversingObtainaddressonlyStep FirmwareReversingObtainaddressonly;
  DoNothingOutcome1Step DoNothingOutcome1;
  PortScanFailureStep PortScanFailure;
  PortScanSuccessStep PortScanSuccess;
  DatabaseDumpFailureStep DatabaseDumpFailure;
  DatabaseDumpSuccessStep DatabaseDumpSuccess;
  TamperingFailureStep TamperingFailure;
  TamperingSuccessStep TamperingSuccess;
  ExploitFailureStep ExploitFailure;
  ExploitSuccessStep ExploitSuccess;
  QueryFloodingAdversaryDecision QueryFloodingAD;
  FirmwareReversingAdversaryDecision FirmwareReversingAD;
  DoNothingAdversaryDecision DoNothingAD;
  PortScanAdversaryDecision PortScanAD;
  DatabaseDumpAdversaryDecision DatabaseDumpAD;
  TamperingAdversaryDecision TamperingAD;
  ExploitAdversaryDecision ExploitAD;
  //Groups for attack steps
  PreselectGroup ImmediateGroup;
  PostselectGroup QueryFloodingGroup;
  PostselectGroup FirmwareReversingGroup;
  PostselectGroup PortScanGroup;
  PostselectGroup DatabaseDumpGroup;
  PostselectGroup TamperingGroup;
  PostselectGroup ExploitGroup;
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
