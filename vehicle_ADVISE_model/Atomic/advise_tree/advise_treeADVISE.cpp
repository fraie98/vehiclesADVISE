
#include "Atomic/advise_tree/advise_treeADVISE.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>


advise_treeADVISE::advise_treeADVISE() {
  QueryFloodingAD.setParent(this);
  FirmwareReversingAD.setParent(this);
  DoNothingAD.setParent(this);
  PortScanAD.setParent(this);
  DatabaseDumpAD.setParent(this);
  TamperingAD.setParent(this);
  ExploitAD.setParent(this);
  QueryFloodingFailure.setParent(this);
  QueryFloodingSuccess.setParent(this);
  FirmwareReversingFailure.setParent(this);
  FirmwareReversingObtainall.setParent(this);
  FirmwareReversingObtainaddressonly.setParent(this);
  DoNothingOutcome1.setParent(this);
  PortScanFailure.setParent(this);
  PortScanSuccess.setParent(this);
  DatabaseDumpFailure.setParent(this);
  DatabaseDumpSuccess.setParent(this);
  TamperingFailure.setParent(this);
  TamperingSuccess.setParent(this);
  ExploitFailure.setParent(this);
  ExploitSuccess.setParent(this);
  QueryFloodingGroup.initialize(2, "QueryFloodingGroup");
  QueryFloodingGroup.appendGroup((BaseGroupClass*) &QueryFloodingFailure);
  QueryFloodingGroup.appendGroup((BaseGroupClass*) &QueryFloodingSuccess);

  FirmwareReversingGroup.initialize(3, "FirmwareReversingGroup");
  FirmwareReversingGroup.appendGroup((BaseGroupClass*) &FirmwareReversingFailure);
  FirmwareReversingGroup.appendGroup((BaseGroupClass*) &FirmwareReversingObtainall);
  FirmwareReversingGroup.appendGroup((BaseGroupClass*) &FirmwareReversingObtainaddressonly);

  PortScanGroup.initialize(2, "PortScanGroup");
  PortScanGroup.appendGroup((BaseGroupClass*) &PortScanFailure);
  PortScanGroup.appendGroup((BaseGroupClass*) &PortScanSuccess);

  DatabaseDumpGroup.initialize(2, "DatabaseDumpGroup");
  DatabaseDumpGroup.appendGroup((BaseGroupClass*) &DatabaseDumpFailure);
  DatabaseDumpGroup.appendGroup((BaseGroupClass*) &DatabaseDumpSuccess);

  TamperingGroup.initialize(2, "TamperingGroup");
  TamperingGroup.appendGroup((BaseGroupClass*) &TamperingFailure);
  TamperingGroup.appendGroup((BaseGroupClass*) &TamperingSuccess);

  ExploitGroup.initialize(2, "ExploitGroup");
  ExploitGroup.appendGroup((BaseGroupClass*) &ExploitFailure);
  ExploitGroup.appendGroup((BaseGroupClass*) &ExploitSuccess);

  AdversaryDecisionGroup.initialize(7, "AdversaryDecisionGroup");
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &QueryFloodingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &FirmwareReversingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &DoNothingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &PortScanAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &DatabaseDumpAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &TamperingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &ExploitAD);

  BaseADVISEAction* InitialActions[21] = {
    &QueryFloodingAD, // 0
    &FirmwareReversingAD, // 1
    &DoNothingAD, // 2
    &PortScanAD, // 3
    &DatabaseDumpAD, // 4
    &TamperingAD, // 5
    &ExploitAD, // 6
    &QueryFloodingFailure, // 7
    &QueryFloodingSuccess, // 8
    &FirmwareReversingFailure, // 9
    &FirmwareReversingObtainall, // 10
    &FirmwareReversingObtainaddressonly, // 11
    &DoNothingOutcome1, // 12
    &PortScanFailure, // 13
    &PortScanSuccess, // 14
    &DatabaseDumpFailure, // 15
    &DatabaseDumpSuccess, // 16
    &TamperingFailure, // 17
    &TamperingSuccess, // 18
    &ExploitFailure, // 19
    &ExploitSuccess // 20
  };

  Step* InitialSteps[14] = {
      &QueryFloodingFailure,
      &QueryFloodingSuccess,
      &FirmwareReversingFailure,
      &FirmwareReversingObtainall,
      &FirmwareReversingObtainaddressonly,
      &DoNothingOutcome1,
      &PortScanFailure,
      &PortScanSuccess,
      &DatabaseDumpFailure,
      &DatabaseDumpSuccess,
      &TamperingFailure,
      &TamperingSuccess,
      &ExploitFailure,
      &ExploitSuccess
  };

  BaseGroupClass* InitialGroups[8] = {
    (BaseGroupClass*) &QueryFloodingGroup, // 0
    (BaseGroupClass*) &FirmwareReversingGroup, // 1
    (BaseGroupClass*) &DoNothingOutcome1, // 2
    (BaseGroupClass*) &PortScanGroup, // 3
    (BaseGroupClass*) &DatabaseDumpGroup, // 4
    (BaseGroupClass*) &TamperingGroup, // 5
    (BaseGroupClass*) &ExploitGroup, // 6
    (BaseGroupClass*) &AdversaryDecisionGroup
  };

  VehicleServerRootAccess = new Access("VehicleServerRootAccess", 0);
  HandshakeProtocol = new Knowledge("HandshakeProtocol", 0);
  VulnerabilityAwareness = new Knowledge("VulnerabilityAwareness", 0);
  SocketAddress = new Knowledge("SocketAddress", 0);
  BinaryDump = new Knowledge("BinaryDump", 1);
  ReverseEngineering = new Skill("ReverseEngineering", 5);
  Script = new Skill("Script", 7);
  DataBreach = new Goal("DataBreach", 0);
  DataBreach->setPayoff(0);
  VehicleUndesideredBehaviour = new Goal("VehicleUndesideredBehaviour", 0);
  VehicleUndesideredBehaviour->setPayoff(300);
  DoS = new Goal("DoS", 0);
  DoS->setPayoff(0);
  MakeDecision = new BeginAdversaryDecision("MakeDecision", 0);
  QueryFloodingWeight = new StepWeight("QueryFloodingWeight", 0);
  QueryFloodingChosen = new StepChosen("QueryFloodingChosen", 0);
  FirmwareReversingWeight = new StepWeight("FirmwareReversingWeight", 0);
  FirmwareReversingChosen = new StepChosen("FirmwareReversingChosen", 0);
  DoNothingWeight = new StepWeight("DoNothingWeight", 0);
  DoNothingChosen = new StepChosen("DoNothingChosen", 0);
  PortScanWeight = new StepWeight("PortScanWeight", 0);
  PortScanChosen = new StepChosen("PortScanChosen", 0);
  DatabaseDumpWeight = new StepWeight("DatabaseDumpWeight", 0);
  DatabaseDumpChosen = new StepChosen("DatabaseDumpChosen", 0);
  TamperingWeight = new StepWeight("TamperingWeight", 0);
  TamperingChosen = new StepChosen("TamperingChosen", 0);
  ExploitWeight = new StepWeight("ExploitWeight", 0);
  ExploitChosen = new StepChosen("ExploitChosen", 0);

  Goal* InitialGoals[3] = {
      DataBreach,
      VehicleUndesideredBehaviour,
      DoS
  };

  ADVISEStateVariable* InitialSVs[25] = {
    VehicleServerRootAccess, // 0
    HandshakeProtocol, // 1
    VulnerabilityAwareness, // 2
    SocketAddress, // 3
    BinaryDump, // 4
    ReverseEngineering, // 5
    Script, // 6
    DataBreach, // 7
    VehicleUndesideredBehaviour, // 8
    DoS, // 9
    QueryFloodingChosen, // 10
    FirmwareReversingChosen, // 11
    DoNothingChosen, // 12
    PortScanChosen, // 13
    DatabaseDumpChosen, // 14
    TamperingChosen, // 15
    ExploitChosen, // 16
    QueryFloodingWeight, // 17
    FirmwareReversingWeight, // 18
    DoNothingWeight, // 19
    PortScanWeight, // 20
    DatabaseDumpWeight, // 21
    TamperingWeight, // 22
    ExploitWeight, // 23
    MakeDecision // 24
};

  int outCounts[7] = { 2, 3, 1, 2, 2, 2, 2 };

  commonInit("advise_tree", 25, InitialSVs, 21, InitialActions, 8, InitialGroups, 7, outCounts, InitialSteps, 3, InitialGoals);

  advCostPref = 0;
  advDetectPref = 0.1;
  advPayPref = 0.9;

  planningHorizon = 4;
  costDiscount = 1.0;
  detectionDiscount = 1.0;
  payoffDiscount = 1.0;

  assignSVsToAttackSteps();

  int AffectArcs[178][2] = {
    {24,0}, {10,0}, {17,0}, {24,1}, {11,1}, {18,1}, {24,2}, {12,2}, 
    {19,2}, {24,3}, {13,3}, {20,3}, {24,4}, {14,4}, {21,4}, {24,5}, 
    {15,5}, {22,5}, {24,6}, {16,6}, {23,6}, {24,7}, {10,7}, {17,7}, 
    {18,7}, {19,7}, {20,7}, {21,7}, {22,7}, {23,7}, {9,7}, {1,7}, 
    {3,7}, {24,8}, {10,8}, {17,8}, {18,8}, {19,8}, {20,8}, {21,8}, 
    {22,8}, {23,8}, {9,8}, {1,8}, {3,8}, {24,9}, {11,9}, {17,9}, 
    {18,9}, {19,9}, {20,9}, {21,9}, {22,9}, {23,9}, {1,9}, {3,9}, 
    {4,9}, {24,10}, {11,10}, {17,10}, {18,10}, {19,10}, {20,10}, {21,10}, 
    {22,10}, {23,10}, {1,10}, {3,10}, {4,10}, {24,11}, {11,11}, {17,11}, 
    {18,11}, {19,11}, {20,11}, {21,11}, {22,11}, {23,11}, {1,11}, {3,11}, 
    {4,11}, {24,12}, {12,12}, {17,12}, {18,12}, {19,12}, {20,12}, {21,12}, 
    {22,12}, {23,12}, {24,13}, {13,13}, {17,13}, {18,13}, {19,13}, {20,13}, 
    {21,13}, {22,13}, {23,13}, {2,13}, {3,13}, {24,14}, {13,14}, {17,14}, 
    {18,14}, {19,14}, {20,14}, {21,14}, {22,14}, {23,14}, {2,14}, {3,14}, 
    {24,15}, {14,15}, {17,15}, {18,15}, {19,15}, {20,15}, {21,15}, {22,15}, 
    {23,15}, {7,15}, {0,15}, {24,16}, {14,16}, {17,16}, {18,16}, {19,16}, 
    {20,16}, {21,16}, {22,16}, {23,16}, {7,16}, {0,16}, {24,17}, {15,17}, 
    {17,17}, {18,17}, {19,17}, {20,17}, {21,17}, {22,17}, {23,17}, {8,17}, 
    {0,17}, {24,18}, {15,18}, {17,18}, {18,18}, {19,18}, {20,18}, {21,18}, 
    {22,18}, {23,18}, {8,18}, {0,18}, {24,19}, {16,19}, {17,19}, {18,19}, 
    {19,19}, {20,19}, {21,19}, {22,19}, {23,19}, {0,19}, {2,19}, {24,20}, 
    {16,20}, {17,20}, {18,20}, {19,20}, {20,20}, {21,20}, {22,20}, {23,20}, 
    {0,20}, {2,20}
};
  for(int n = 0; n < 178;n++)
    AddAffectArc(InitialSVs[AffectArcs[n][0]], InitialActions[AffectArcs[n][1]]);
  int EnableArcs[37][2] = {
    {24,0}, {24,1}, {24,2}, {24,3}, {24,4}, {24,5}, {24,6}, {10,7}, 
    {9,7}, {10,8}, {9,8}, {11,9}, {1,9}, {3,9}, {11,10}, {1,10}, 
    {3,10}, {11,11}, {1,11}, {3,11}, {12,12}, {13,13}, {2,13}, {13,14}, 
    {2,14}, {14,15}, {7,15}, {14,16}, {7,16}, {15,17}, {8,17}, {15,18}, 
    {8,18}, {16,19}, {0,19}, {16,20}, {0,20}
};
  for(int n = 0; n < 37;n++)
    AddEnableArc(InitialSVs[EnableArcs[n][0]], InitialActions[EnableArcs[n][1]]);
  for(int x = 0; x < 21; x++) {
    InitialActions[x]->LinkVariables();
  }

  customInitialization();

  recalculateAdversaryDecisionWeights();

}

advise_treeADVISE::~advise_treeADVISE() {
}

void advise_treeADVISE::assignSVsToAttackSteps() {
  QueryFloodingFailure.DoS = DoS;
  QueryFloodingFailure.Script = Script;
  QueryFloodingFailure.HandshakeProtocol = HandshakeProtocol;
  QueryFloodingFailure.SocketAddress = SocketAddress;
  QueryFloodingFailure.QueryFloodingChosen = QueryFloodingChosen;
  QueryFloodingFailure.QueryFloodingWeight = QueryFloodingWeight;
  QueryFloodingFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  QueryFloodingFailure.DoNothingWeight = DoNothingWeight;
  QueryFloodingFailure.PortScanWeight = PortScanWeight;
  QueryFloodingFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  QueryFloodingFailure.TamperingWeight = TamperingWeight;
  QueryFloodingFailure.ExploitWeight = ExploitWeight;
  QueryFloodingFailure.MakeDecision = MakeDecision;
  QueryFloodingFailure.setSVs(QueryFloodingChosen, QueryFloodingWeight);
  QueryFloodingSuccess.DoS = DoS;
  QueryFloodingSuccess.Script = Script;
  QueryFloodingSuccess.HandshakeProtocol = HandshakeProtocol;
  QueryFloodingSuccess.SocketAddress = SocketAddress;
  QueryFloodingSuccess.QueryFloodingChosen = QueryFloodingChosen;
  QueryFloodingSuccess.QueryFloodingWeight = QueryFloodingWeight;
  QueryFloodingSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  QueryFloodingSuccess.DoNothingWeight = DoNothingWeight;
  QueryFloodingSuccess.PortScanWeight = PortScanWeight;
  QueryFloodingSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  QueryFloodingSuccess.TamperingWeight = TamperingWeight;
  QueryFloodingSuccess.ExploitWeight = ExploitWeight;
  QueryFloodingSuccess.MakeDecision = MakeDecision;
  QueryFloodingSuccess.setSVs(QueryFloodingChosen, QueryFloodingWeight);
  FirmwareReversingFailure.HandshakeProtocol = HandshakeProtocol;
  FirmwareReversingFailure.SocketAddress = SocketAddress;
  FirmwareReversingFailure.BinaryDump = BinaryDump;
  FirmwareReversingFailure.ReverseEngineering = ReverseEngineering;
  FirmwareReversingFailure.FirmwareReversingChosen = FirmwareReversingChosen;
  FirmwareReversingFailure.QueryFloodingWeight = QueryFloodingWeight;
  FirmwareReversingFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  FirmwareReversingFailure.DoNothingWeight = DoNothingWeight;
  FirmwareReversingFailure.PortScanWeight = PortScanWeight;
  FirmwareReversingFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  FirmwareReversingFailure.TamperingWeight = TamperingWeight;
  FirmwareReversingFailure.ExploitWeight = ExploitWeight;
  FirmwareReversingFailure.MakeDecision = MakeDecision;
  FirmwareReversingFailure.setSVs(FirmwareReversingChosen, FirmwareReversingWeight);
  FirmwareReversingObtainall.HandshakeProtocol = HandshakeProtocol;
  FirmwareReversingObtainall.SocketAddress = SocketAddress;
  FirmwareReversingObtainall.BinaryDump = BinaryDump;
  FirmwareReversingObtainall.ReverseEngineering = ReverseEngineering;
  FirmwareReversingObtainall.FirmwareReversingChosen = FirmwareReversingChosen;
  FirmwareReversingObtainall.QueryFloodingWeight = QueryFloodingWeight;
  FirmwareReversingObtainall.FirmwareReversingWeight = FirmwareReversingWeight;
  FirmwareReversingObtainall.DoNothingWeight = DoNothingWeight;
  FirmwareReversingObtainall.PortScanWeight = PortScanWeight;
  FirmwareReversingObtainall.DatabaseDumpWeight = DatabaseDumpWeight;
  FirmwareReversingObtainall.TamperingWeight = TamperingWeight;
  FirmwareReversingObtainall.ExploitWeight = ExploitWeight;
  FirmwareReversingObtainall.MakeDecision = MakeDecision;
  FirmwareReversingObtainall.setSVs(FirmwareReversingChosen, FirmwareReversingWeight);
  FirmwareReversingObtainaddressonly.HandshakeProtocol = HandshakeProtocol;
  FirmwareReversingObtainaddressonly.SocketAddress = SocketAddress;
  FirmwareReversingObtainaddressonly.BinaryDump = BinaryDump;
  FirmwareReversingObtainaddressonly.ReverseEngineering = ReverseEngineering;
  FirmwareReversingObtainaddressonly.FirmwareReversingChosen = FirmwareReversingChosen;
  FirmwareReversingObtainaddressonly.QueryFloodingWeight = QueryFloodingWeight;
  FirmwareReversingObtainaddressonly.FirmwareReversingWeight = FirmwareReversingWeight;
  FirmwareReversingObtainaddressonly.DoNothingWeight = DoNothingWeight;
  FirmwareReversingObtainaddressonly.PortScanWeight = PortScanWeight;
  FirmwareReversingObtainaddressonly.DatabaseDumpWeight = DatabaseDumpWeight;
  FirmwareReversingObtainaddressonly.TamperingWeight = TamperingWeight;
  FirmwareReversingObtainaddressonly.ExploitWeight = ExploitWeight;
  FirmwareReversingObtainaddressonly.MakeDecision = MakeDecision;
  FirmwareReversingObtainaddressonly.setSVs(FirmwareReversingChosen, FirmwareReversingWeight);
  DoNothingOutcome1.DoNothingChosen = DoNothingChosen;
  DoNothingOutcome1.QueryFloodingWeight = QueryFloodingWeight;
  DoNothingOutcome1.FirmwareReversingWeight = FirmwareReversingWeight;
  DoNothingOutcome1.DoNothingWeight = DoNothingWeight;
  DoNothingOutcome1.PortScanWeight = PortScanWeight;
  DoNothingOutcome1.DatabaseDumpWeight = DatabaseDumpWeight;
  DoNothingOutcome1.TamperingWeight = TamperingWeight;
  DoNothingOutcome1.ExploitWeight = ExploitWeight;
  DoNothingOutcome1.MakeDecision = MakeDecision;
  DoNothingOutcome1.setSVs(DoNothingChosen, DoNothingWeight);
  PortScanFailure.VulnerabilityAwareness = VulnerabilityAwareness;
  PortScanFailure.SocketAddress = SocketAddress;
  PortScanFailure.PortScanChosen = PortScanChosen;
  PortScanFailure.QueryFloodingWeight = QueryFloodingWeight;
  PortScanFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  PortScanFailure.DoNothingWeight = DoNothingWeight;
  PortScanFailure.PortScanWeight = PortScanWeight;
  PortScanFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  PortScanFailure.TamperingWeight = TamperingWeight;
  PortScanFailure.ExploitWeight = ExploitWeight;
  PortScanFailure.MakeDecision = MakeDecision;
  PortScanFailure.setSVs(PortScanChosen, PortScanWeight);
  PortScanSuccess.VulnerabilityAwareness = VulnerabilityAwareness;
  PortScanSuccess.SocketAddress = SocketAddress;
  PortScanSuccess.PortScanChosen = PortScanChosen;
  PortScanSuccess.QueryFloodingWeight = QueryFloodingWeight;
  PortScanSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  PortScanSuccess.DoNothingWeight = DoNothingWeight;
  PortScanSuccess.PortScanWeight = PortScanWeight;
  PortScanSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  PortScanSuccess.TamperingWeight = TamperingWeight;
  PortScanSuccess.ExploitWeight = ExploitWeight;
  PortScanSuccess.MakeDecision = MakeDecision;
  PortScanSuccess.setSVs(PortScanChosen, PortScanWeight);
  DatabaseDumpFailure.DataBreach = DataBreach;
  DatabaseDumpFailure.VehicleServerRootAccess = VehicleServerRootAccess;
  DatabaseDumpFailure.DatabaseDumpChosen = DatabaseDumpChosen;
  DatabaseDumpFailure.QueryFloodingWeight = QueryFloodingWeight;
  DatabaseDumpFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  DatabaseDumpFailure.DoNothingWeight = DoNothingWeight;
  DatabaseDumpFailure.PortScanWeight = PortScanWeight;
  DatabaseDumpFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  DatabaseDumpFailure.TamperingWeight = TamperingWeight;
  DatabaseDumpFailure.ExploitWeight = ExploitWeight;
  DatabaseDumpFailure.MakeDecision = MakeDecision;
  DatabaseDumpFailure.setSVs(DatabaseDumpChosen, DatabaseDumpWeight);
  DatabaseDumpSuccess.DataBreach = DataBreach;
  DatabaseDumpSuccess.VehicleServerRootAccess = VehicleServerRootAccess;
  DatabaseDumpSuccess.DatabaseDumpChosen = DatabaseDumpChosen;
  DatabaseDumpSuccess.QueryFloodingWeight = QueryFloodingWeight;
  DatabaseDumpSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  DatabaseDumpSuccess.DoNothingWeight = DoNothingWeight;
  DatabaseDumpSuccess.PortScanWeight = PortScanWeight;
  DatabaseDumpSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  DatabaseDumpSuccess.TamperingWeight = TamperingWeight;
  DatabaseDumpSuccess.ExploitWeight = ExploitWeight;
  DatabaseDumpSuccess.MakeDecision = MakeDecision;
  DatabaseDumpSuccess.setSVs(DatabaseDumpChosen, DatabaseDumpWeight);
  TamperingFailure.VehicleUndesideredBehaviour = VehicleUndesideredBehaviour;
  TamperingFailure.VehicleServerRootAccess = VehicleServerRootAccess;
  TamperingFailure.TamperingChosen = TamperingChosen;
  TamperingFailure.QueryFloodingWeight = QueryFloodingWeight;
  TamperingFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  TamperingFailure.DoNothingWeight = DoNothingWeight;
  TamperingFailure.PortScanWeight = PortScanWeight;
  TamperingFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  TamperingFailure.TamperingWeight = TamperingWeight;
  TamperingFailure.ExploitWeight = ExploitWeight;
  TamperingFailure.MakeDecision = MakeDecision;
  TamperingFailure.setSVs(TamperingChosen, TamperingWeight);
  TamperingSuccess.VehicleUndesideredBehaviour = VehicleUndesideredBehaviour;
  TamperingSuccess.VehicleServerRootAccess = VehicleServerRootAccess;
  TamperingSuccess.TamperingChosen = TamperingChosen;
  TamperingSuccess.QueryFloodingWeight = QueryFloodingWeight;
  TamperingSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  TamperingSuccess.DoNothingWeight = DoNothingWeight;
  TamperingSuccess.PortScanWeight = PortScanWeight;
  TamperingSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  TamperingSuccess.TamperingWeight = TamperingWeight;
  TamperingSuccess.ExploitWeight = ExploitWeight;
  TamperingSuccess.MakeDecision = MakeDecision;
  TamperingSuccess.setSVs(TamperingChosen, TamperingWeight);
  ExploitFailure.VehicleServerRootAccess = VehicleServerRootAccess;
  ExploitFailure.VulnerabilityAwareness = VulnerabilityAwareness;
  ExploitFailure.ExploitChosen = ExploitChosen;
  ExploitFailure.QueryFloodingWeight = QueryFloodingWeight;
  ExploitFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  ExploitFailure.DoNothingWeight = DoNothingWeight;
  ExploitFailure.PortScanWeight = PortScanWeight;
  ExploitFailure.DatabaseDumpWeight = DatabaseDumpWeight;
  ExploitFailure.TamperingWeight = TamperingWeight;
  ExploitFailure.ExploitWeight = ExploitWeight;
  ExploitFailure.MakeDecision = MakeDecision;
  ExploitFailure.setSVs(ExploitChosen, ExploitWeight);
  ExploitSuccess.VehicleServerRootAccess = VehicleServerRootAccess;
  ExploitSuccess.VulnerabilityAwareness = VulnerabilityAwareness;
  ExploitSuccess.ExploitChosen = ExploitChosen;
  ExploitSuccess.QueryFloodingWeight = QueryFloodingWeight;
  ExploitSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  ExploitSuccess.DoNothingWeight = DoNothingWeight;
  ExploitSuccess.PortScanWeight = PortScanWeight;
  ExploitSuccess.DatabaseDumpWeight = DatabaseDumpWeight;
  ExploitSuccess.TamperingWeight = TamperingWeight;
  ExploitSuccess.ExploitWeight = ExploitWeight;
  ExploitSuccess.MakeDecision = MakeDecision;
  ExploitSuccess.setSVs(ExploitChosen, ExploitWeight);

  QueryFloodingAD.MakeDecision = MakeDecision;
  QueryFloodingAD.QueryFloodingChosen = QueryFloodingChosen;
  QueryFloodingAD.QueryFloodingWeight = QueryFloodingWeight;
  FirmwareReversingAD.MakeDecision = MakeDecision;
  FirmwareReversingAD.FirmwareReversingChosen = FirmwareReversingChosen;
  FirmwareReversingAD.FirmwareReversingWeight = FirmwareReversingWeight;
  DoNothingAD.MakeDecision = MakeDecision;
  DoNothingAD.DoNothingChosen = DoNothingChosen;
  DoNothingAD.DoNothingWeight = DoNothingWeight;
  PortScanAD.MakeDecision = MakeDecision;
  PortScanAD.PortScanChosen = PortScanChosen;
  PortScanAD.PortScanWeight = PortScanWeight;
  DatabaseDumpAD.MakeDecision = MakeDecision;
  DatabaseDumpAD.DatabaseDumpChosen = DatabaseDumpChosen;
  DatabaseDumpAD.DatabaseDumpWeight = DatabaseDumpWeight;
  TamperingAD.MakeDecision = MakeDecision;
  TamperingAD.TamperingChosen = TamperingChosen;
  TamperingAD.TamperingWeight = TamperingWeight;
  ExploitAD.MakeDecision = MakeDecision;
  ExploitAD.ExploitChosen = ExploitChosen;
  ExploitAD.ExploitWeight = ExploitWeight;
}

double advise_treeADVISE::convertCostToUtility(double cost) {
  const double esquared = 7.389056099; // e^(2)
  if(cost < 0)
    return 1.0;
  else if(cost > 100)
    return 0.0;
  else {
    return (esquared - exp(cost/50))/(-1 + esquared);
  }
}

double advise_treeADVISE::convertPayoffToUtility(double payoff) {
  const double etoten = 28.031624895; // e^(10/3)
  if(payoff < 0)
    return 0;
  else if(payoff > 1000)
    return 1;
  else {
    return (etoten - (etoten/exp(payoff/300)))/(-1 + etoten);
  }
}

double advise_treeADVISE::convertDetectionToUtility(double detection) {
  const double esquared = 7.389056099; // e^(2)
  if(detection < 0)
    return 1;
  else if(detection > 1)
    return 0;
  else {
    return (1-(esquared/exp(2*detection)))/(1-esquared);
  }
}

void advise_treeADVISE::customInitialization() {

}

/*****************************************************************/
/*                   Attack Step Definitions                     */
/*****************************************************************/

/*====================== QueryFloodingFailureStep ========================*/

advise_treeADVISE::QueryFloodingFailureStep::QueryFloodingFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("QueryFloodingFailureStep", 0, Deterministic, RaceEnabled, 13, 1, false);}

advise_treeADVISE::QueryFloodingFailureStep::~QueryFloodingFailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::QueryFloodingFailureStep::LinkVariables() {
  DoS->Register(&DoS_Mobius_Mark);
  Script->Register(&Script_Mobius_Mark);
  HandshakeProtocol->Register(&HandshakeProtocol_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  QueryFloodingChosen->Register(&QueryFloodingChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::QueryFloodingFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(QueryFloodingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::QueryFloodingFailureStep::timeDistributionParameter0() {
return 10;
}

double advise_treeADVISE::QueryFloodingFailureStep::Weight() {
if( HandshakeProtocol->Mark()) return 0.4;
else return 0.9;
}

bool advise_treeADVISE::QueryFloodingFailureStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::QueryFloodingFailureStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::QueryFloodingFailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::QueryFloodingFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::QueryFloodingFailureStep::Rank() {
  return 1;
}

bool advise_treeADVISE::QueryFloodingFailureStep::preconditionsMet() {
return ((Script->Mark()>2) && SocketAddress->Mark() && !DoS->Mark());
  return true;
}

void advise_treeADVISE::QueryFloodingFailureStep::executeEffects() {

}

double advise_treeADVISE::QueryFloodingFailureStep::getCost() {
return 0;
}

double advise_treeADVISE::QueryFloodingFailureStep::getOutcomeProbability() {
if( HandshakeProtocol->Mark()) return 0.4;
else return 0.9;
}

double advise_treeADVISE::QueryFloodingFailureStep::getDetection() {
return 0.6;
}

/*====================== QueryFloodingSuccessStep ========================*/

advise_treeADVISE::QueryFloodingSuccessStep::QueryFloodingSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("QueryFloodingSuccessStep", 0, Deterministic, RaceEnabled, 13, 1, false);}

advise_treeADVISE::QueryFloodingSuccessStep::~QueryFloodingSuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::QueryFloodingSuccessStep::LinkVariables() {
  DoS->Register(&DoS_Mobius_Mark);
  Script->Register(&Script_Mobius_Mark);
  HandshakeProtocol->Register(&HandshakeProtocol_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  QueryFloodingChosen->Register(&QueryFloodingChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::QueryFloodingSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(QueryFloodingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::QueryFloodingSuccessStep::timeDistributionParameter0() {
return 10;
}

double advise_treeADVISE::QueryFloodingSuccessStep::Weight() {
if( HandshakeProtocol->Mark()) return 0.6;
else return 0.1;
}

bool advise_treeADVISE::QueryFloodingSuccessStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::QueryFloodingSuccessStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::QueryFloodingSuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::QueryFloodingSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::QueryFloodingSuccessStep::Rank() {
  return 1;
}

bool advise_treeADVISE::QueryFloodingSuccessStep::preconditionsMet() {
return ((Script->Mark()>2) && SocketAddress->Mark() && !DoS->Mark());
  return true;
}

void advise_treeADVISE::QueryFloodingSuccessStep::executeEffects() {
DoS->Mark() = 1;
}

double advise_treeADVISE::QueryFloodingSuccessStep::getCost() {
return 0;
}

double advise_treeADVISE::QueryFloodingSuccessStep::getOutcomeProbability() {
if( HandshakeProtocol->Mark()) return 0.6;
else return 0.1;
}

double advise_treeADVISE::QueryFloodingSuccessStep::getDetection() {
return 0.5;
}

/*====================== FirmwareReversingFailureStep ========================*/

advise_treeADVISE::FirmwareReversingFailureStep::FirmwareReversingFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("FirmwareReversingFailureStep", 1, Deterministic, RaceEnabled, 13, 2, false);}

advise_treeADVISE::FirmwareReversingFailureStep::~FirmwareReversingFailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::FirmwareReversingFailureStep::LinkVariables() {
  HandshakeProtocol->Register(&HandshakeProtocol_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  BinaryDump->Register(&BinaryDump_Mobius_Mark);
  ReverseEngineering->Register(&ReverseEngineering_Mobius_Mark);
  FirmwareReversingChosen->Register(&FirmwareReversingChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::FirmwareReversingFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(FirmwareReversingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::FirmwareReversingFailureStep::timeDistributionParameter0() {
return 5;
}

double advise_treeADVISE::FirmwareReversingFailureStep::Weight() {
return 0.2;
}

bool advise_treeADVISE::FirmwareReversingFailureStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::FirmwareReversingFailureStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::FirmwareReversingFailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::FirmwareReversingFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::FirmwareReversingFailureStep::Rank() {
  return 1;
}

bool advise_treeADVISE::FirmwareReversingFailureStep::preconditionsMet() {
return (BinaryDump->Mark() && (ReverseEngineering->Mark()>1) && !HandshakeProtocol->Mark() && !SocketAddress->Mark());
	
  return true;
}

void advise_treeADVISE::FirmwareReversingFailureStep::executeEffects() {

}

double advise_treeADVISE::FirmwareReversingFailureStep::getCost() {
return 0;
}

double advise_treeADVISE::FirmwareReversingFailureStep::getOutcomeProbability() {
return 0.2;
}

double advise_treeADVISE::FirmwareReversingFailureStep::getDetection() {
return 0;
}

/*====================== FirmwareReversingObtainallStep ========================*/

advise_treeADVISE::FirmwareReversingObtainallStep::FirmwareReversingObtainallStep() {
  TheDistributionParameters = new double[1];
  commonInit("FirmwareReversingObtainallStep", 1, Deterministic, RaceEnabled, 13, 2, false);}

advise_treeADVISE::FirmwareReversingObtainallStep::~FirmwareReversingObtainallStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::FirmwareReversingObtainallStep::LinkVariables() {
  HandshakeProtocol->Register(&HandshakeProtocol_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  BinaryDump->Register(&BinaryDump_Mobius_Mark);
  ReverseEngineering->Register(&ReverseEngineering_Mobius_Mark);
  FirmwareReversingChosen->Register(&FirmwareReversingChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::FirmwareReversingObtainallStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(FirmwareReversingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::FirmwareReversingObtainallStep::timeDistributionParameter0() {
return 5;
}

double advise_treeADVISE::FirmwareReversingObtainallStep::Weight() {
return 0.1;
}

bool advise_treeADVISE::FirmwareReversingObtainallStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::FirmwareReversingObtainallStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::FirmwareReversingObtainallStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::FirmwareReversingObtainallStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::FirmwareReversingObtainallStep::Rank() {
  return 1;
}

bool advise_treeADVISE::FirmwareReversingObtainallStep::preconditionsMet() {
return (BinaryDump->Mark() && (ReverseEngineering->Mark()>1) && !HandshakeProtocol->Mark() && !SocketAddress->Mark());
	
  return true;
}

void advise_treeADVISE::FirmwareReversingObtainallStep::executeEffects() {
HandshakeProtocol->Mark() = 1;
SocketAddress->Mark() = 1;
}

double advise_treeADVISE::FirmwareReversingObtainallStep::getCost() {
return 0;
}

double advise_treeADVISE::FirmwareReversingObtainallStep::getOutcomeProbability() {
return 0.1;
}

double advise_treeADVISE::FirmwareReversingObtainallStep::getDetection() {
return 0;
}

/*====================== FirmwareReversingObtainaddressonlyStep ========================*/

advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::FirmwareReversingObtainaddressonlyStep() {
  TheDistributionParameters = new double[1];
  commonInit("FirmwareReversingObtainaddressonlyStep", 1, Deterministic, RaceEnabled, 13, 2, false);}

advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::~FirmwareReversingObtainaddressonlyStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::LinkVariables() {
  HandshakeProtocol->Register(&HandshakeProtocol_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  BinaryDump->Register(&BinaryDump_Mobius_Mark);
  ReverseEngineering->Register(&ReverseEngineering_Mobius_Mark);
  FirmwareReversingChosen->Register(&FirmwareReversingChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(FirmwareReversingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::timeDistributionParameter0() {
return 5;
}

double advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::Weight() {
return 0.7;
}

bool advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::Rank() {
  return 1;
}

bool advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::preconditionsMet() {
return (BinaryDump->Mark() && (ReverseEngineering->Mark()>1) && !HandshakeProtocol->Mark() && !SocketAddress->Mark());
	
  return true;
}

void advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::executeEffects() {
SocketAddress->Mark() = 1;
}

double advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::getCost() {
return 0;
}

double advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::getOutcomeProbability() {
return 0.7;
}

double advise_treeADVISE::FirmwareReversingObtainaddressonlyStep::getDetection() {
return 0;
}

/*====================== DoNothingOutcome1Step ========================*/

advise_treeADVISE::DoNothingOutcome1Step::DoNothingOutcome1Step() {
  TheDistributionParameters = new double[1];
  commonInit("DoNothingOutcome1Step", 2, Deterministic, RaceEnabled, 9, 0, false);}

advise_treeADVISE::DoNothingOutcome1Step::~DoNothingOutcome1Step() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::DoNothingOutcome1Step::LinkVariables() {
  DoNothingChosen->Register(&DoNothingChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::DoNothingOutcome1Step::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(DoNothingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::DoNothingOutcome1Step::timeDistributionParameter0() {
return 1;
}

double advise_treeADVISE::DoNothingOutcome1Step::Weight() {
  return 1;
}

bool advise_treeADVISE::DoNothingOutcome1Step::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::DoNothingOutcome1Step::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::DoNothingOutcome1Step::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::DoNothingOutcome1Step::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::DoNothingOutcome1Step::Rank() {
  return 1;
}

bool advise_treeADVISE::DoNothingOutcome1Step::preconditionsMet() {

  return true;
}

void advise_treeADVISE::DoNothingOutcome1Step::executeEffects() {

}

double advise_treeADVISE::DoNothingOutcome1Step::getCost() {
return 0;
}

double advise_treeADVISE::DoNothingOutcome1Step::getOutcomeProbability() {
return 1;
}

double advise_treeADVISE::DoNothingOutcome1Step::getDetection() {
return 0;
}

/*====================== PortScanFailureStep ========================*/

advise_treeADVISE::PortScanFailureStep::PortScanFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("PortScanFailureStep", 3, Deterministic, RaceEnabled, 11, 1, false);}

advise_treeADVISE::PortScanFailureStep::~PortScanFailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::PortScanFailureStep::LinkVariables() {
  VulnerabilityAwareness->Register(&VulnerabilityAwareness_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  PortScanChosen->Register(&PortScanChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::PortScanFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(PortScanChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::PortScanFailureStep::timeDistributionParameter0() {
return 5;
}

double advise_treeADVISE::PortScanFailureStep::Weight() {
return 0.3;
}

bool advise_treeADVISE::PortScanFailureStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::PortScanFailureStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::PortScanFailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::PortScanFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::PortScanFailureStep::Rank() {
  return 1;
}

bool advise_treeADVISE::PortScanFailureStep::preconditionsMet() {
return (SocketAddress->Mark() && !VulnerabilityAwareness->Mark());
  return true;
}

void advise_treeADVISE::PortScanFailureStep::executeEffects() {

}

double advise_treeADVISE::PortScanFailureStep::getCost() {
return 0;
}

double advise_treeADVISE::PortScanFailureStep::getOutcomeProbability() {
return 0.3;
}

double advise_treeADVISE::PortScanFailureStep::getDetection() {
return 0.1;
}

/*====================== PortScanSuccessStep ========================*/

advise_treeADVISE::PortScanSuccessStep::PortScanSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("PortScanSuccessStep", 3, Deterministic, RaceEnabled, 11, 1, false);}

advise_treeADVISE::PortScanSuccessStep::~PortScanSuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::PortScanSuccessStep::LinkVariables() {
  VulnerabilityAwareness->Register(&VulnerabilityAwareness_Mobius_Mark);
  SocketAddress->Register(&SocketAddress_Mobius_Mark);
  PortScanChosen->Register(&PortScanChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::PortScanSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(PortScanChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::PortScanSuccessStep::timeDistributionParameter0() {
return 5;
}

double advise_treeADVISE::PortScanSuccessStep::Weight() {
return 0.7;
}

bool advise_treeADVISE::PortScanSuccessStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::PortScanSuccessStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::PortScanSuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::PortScanSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::PortScanSuccessStep::Rank() {
  return 1;
}

bool advise_treeADVISE::PortScanSuccessStep::preconditionsMet() {
return (SocketAddress->Mark() && !VulnerabilityAwareness->Mark());
  return true;
}

void advise_treeADVISE::PortScanSuccessStep::executeEffects() {
VulnerabilityAwareness->Mark()=1;
}

double advise_treeADVISE::PortScanSuccessStep::getCost() {
return 0;
}

double advise_treeADVISE::PortScanSuccessStep::getOutcomeProbability() {
return 0.7;
}

double advise_treeADVISE::PortScanSuccessStep::getDetection() {
return 0.1;
}

/*====================== DatabaseDumpFailureStep ========================*/

advise_treeADVISE::DatabaseDumpFailureStep::DatabaseDumpFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("DatabaseDumpFailureStep", 4, Deterministic, RaceEnabled, 11, 1, false);}

advise_treeADVISE::DatabaseDumpFailureStep::~DatabaseDumpFailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::DatabaseDumpFailureStep::LinkVariables() {
  DataBreach->Register(&DataBreach_Mobius_Mark);
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  DatabaseDumpChosen->Register(&DatabaseDumpChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::DatabaseDumpFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(DatabaseDumpChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::DatabaseDumpFailureStep::timeDistributionParameter0() {
return 5;
}

double advise_treeADVISE::DatabaseDumpFailureStep::Weight() {
return 0.1;
}

bool advise_treeADVISE::DatabaseDumpFailureStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::DatabaseDumpFailureStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::DatabaseDumpFailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::DatabaseDumpFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::DatabaseDumpFailureStep::Rank() {
  return 1;
}

bool advise_treeADVISE::DatabaseDumpFailureStep::preconditionsMet() {
return (VehicleServerRootAccess->Mark() && !DataBreach->Mark());
  return true;
}

void advise_treeADVISE::DatabaseDumpFailureStep::executeEffects() {

}

double advise_treeADVISE::DatabaseDumpFailureStep::getCost() {
return 0;
}

double advise_treeADVISE::DatabaseDumpFailureStep::getOutcomeProbability() {
return 0.1;
}

double advise_treeADVISE::DatabaseDumpFailureStep::getDetection() {
return 0.1;
}

/*====================== DatabaseDumpSuccessStep ========================*/

advise_treeADVISE::DatabaseDumpSuccessStep::DatabaseDumpSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("DatabaseDumpSuccessStep", 4, Deterministic, RaceEnabled, 11, 1, false);}

advise_treeADVISE::DatabaseDumpSuccessStep::~DatabaseDumpSuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::DatabaseDumpSuccessStep::LinkVariables() {
  DataBreach->Register(&DataBreach_Mobius_Mark);
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  DatabaseDumpChosen->Register(&DatabaseDumpChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::DatabaseDumpSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(DatabaseDumpChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::DatabaseDumpSuccessStep::timeDistributionParameter0() {
return 5;
}

double advise_treeADVISE::DatabaseDumpSuccessStep::Weight() {
return 0.9;
}

bool advise_treeADVISE::DatabaseDumpSuccessStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::DatabaseDumpSuccessStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::DatabaseDumpSuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::DatabaseDumpSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::DatabaseDumpSuccessStep::Rank() {
  return 1;
}

bool advise_treeADVISE::DatabaseDumpSuccessStep::preconditionsMet() {
return (VehicleServerRootAccess->Mark() && !DataBreach->Mark());
  return true;
}

void advise_treeADVISE::DatabaseDumpSuccessStep::executeEffects() {
DataBreach->Mark()=1;
}

double advise_treeADVISE::DatabaseDumpSuccessStep::getCost() {
return 0;
}

double advise_treeADVISE::DatabaseDumpSuccessStep::getOutcomeProbability() {
return 0.9;
}

double advise_treeADVISE::DatabaseDumpSuccessStep::getDetection() {
return 0.2;
}

/*====================== TamperingFailureStep ========================*/

advise_treeADVISE::TamperingFailureStep::TamperingFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("TamperingFailureStep", 5, Deterministic, RaceEnabled, 11, 1, false);}

advise_treeADVISE::TamperingFailureStep::~TamperingFailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::TamperingFailureStep::LinkVariables() {
  VehicleUndesideredBehaviour->Register(&VehicleUndesideredBehaviour_Mobius_Mark);
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  TamperingChosen->Register(&TamperingChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::TamperingFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(TamperingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::TamperingFailureStep::timeDistributionParameter0() {
return 5;
}

double advise_treeADVISE::TamperingFailureStep::Weight() {
return 0.1;
}

bool advise_treeADVISE::TamperingFailureStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::TamperingFailureStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::TamperingFailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::TamperingFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::TamperingFailureStep::Rank() {
  return 1;
}

bool advise_treeADVISE::TamperingFailureStep::preconditionsMet() {
return (VehicleServerRootAccess->Mark() && !VehicleUndesideredBehaviour->Mark());
  return true;
}

void advise_treeADVISE::TamperingFailureStep::executeEffects() {

}

double advise_treeADVISE::TamperingFailureStep::getCost() {
return 0;
}

double advise_treeADVISE::TamperingFailureStep::getOutcomeProbability() {
return 0.1;
}

double advise_treeADVISE::TamperingFailureStep::getDetection() {
return 0.3;
}

/*====================== TamperingSuccessStep ========================*/

advise_treeADVISE::TamperingSuccessStep::TamperingSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("TamperingSuccessStep", 5, Deterministic, RaceEnabled, 11, 1, false);}

advise_treeADVISE::TamperingSuccessStep::~TamperingSuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::TamperingSuccessStep::LinkVariables() {
  VehicleUndesideredBehaviour->Register(&VehicleUndesideredBehaviour_Mobius_Mark);
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  TamperingChosen->Register(&TamperingChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::TamperingSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(TamperingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::TamperingSuccessStep::timeDistributionParameter0() {
return 5;
}

double advise_treeADVISE::TamperingSuccessStep::Weight() {
return 0.9;
}

bool advise_treeADVISE::TamperingSuccessStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::TamperingSuccessStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::TamperingSuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::TamperingSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::TamperingSuccessStep::Rank() {
  return 1;
}

bool advise_treeADVISE::TamperingSuccessStep::preconditionsMet() {
return (VehicleServerRootAccess->Mark() && !VehicleUndesideredBehaviour->Mark());
  return true;
}

void advise_treeADVISE::TamperingSuccessStep::executeEffects() {
VehicleUndesideredBehaviour->Mark()=1;
}

double advise_treeADVISE::TamperingSuccessStep::getCost() {
return 0;
}

double advise_treeADVISE::TamperingSuccessStep::getOutcomeProbability() {
return 0.9;
}

double advise_treeADVISE::TamperingSuccessStep::getDetection() {
return 0.2;
}

/*====================== ExploitFailureStep ========================*/

advise_treeADVISE::ExploitFailureStep::ExploitFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("ExploitFailureStep", 6, Deterministic, RaceEnabled, 11, 1, false);}

advise_treeADVISE::ExploitFailureStep::~ExploitFailureStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::ExploitFailureStep::LinkVariables() {
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  VulnerabilityAwareness->Register(&VulnerabilityAwareness_Mobius_Mark);
  ExploitChosen->Register(&ExploitChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::ExploitFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(ExploitChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::ExploitFailureStep::timeDistributionParameter0() {
return 5;
}

double advise_treeADVISE::ExploitFailureStep::Weight() {
return 0.2;
}

bool advise_treeADVISE::ExploitFailureStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::ExploitFailureStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::ExploitFailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::ExploitFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::ExploitFailureStep::Rank() {
  return 1;
}

bool advise_treeADVISE::ExploitFailureStep::preconditionsMet() {
return (VulnerabilityAwareness->Mark() && !VehicleServerRootAccess->Mark());
  return true;
}

void advise_treeADVISE::ExploitFailureStep::executeEffects() {

}

double advise_treeADVISE::ExploitFailureStep::getCost() {
return 0;
}

double advise_treeADVISE::ExploitFailureStep::getOutcomeProbability() {
return 0.2;
}

double advise_treeADVISE::ExploitFailureStep::getDetection() {
return 0.6;
}

/*====================== ExploitSuccessStep ========================*/

advise_treeADVISE::ExploitSuccessStep::ExploitSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("ExploitSuccessStep", 6, Deterministic, RaceEnabled, 11, 1, false);}

advise_treeADVISE::ExploitSuccessStep::~ExploitSuccessStep() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::ExploitSuccessStep::LinkVariables() {
  VehicleServerRootAccess->Register(&VehicleServerRootAccess_Mobius_Mark);
  VulnerabilityAwareness->Register(&VulnerabilityAwareness_Mobius_Mark);
  ExploitChosen->Register(&ExploitChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool advise_treeADVISE::ExploitSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(ExploitChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::ExploitSuccessStep::timeDistributionParameter0() {
return 5;
}

double advise_treeADVISE::ExploitSuccessStep::Weight() {
return 0.8;
}

bool advise_treeADVISE::ExploitSuccessStep::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::ExploitSuccessStep::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::ExploitSuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *advise_treeADVISE::ExploitSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int advise_treeADVISE::ExploitSuccessStep::Rank() {
  return 1;
}

bool advise_treeADVISE::ExploitSuccessStep::preconditionsMet() {
return (VulnerabilityAwareness->Mark() && !VehicleServerRootAccess->Mark());
  return true;
}

void advise_treeADVISE::ExploitSuccessStep::executeEffects() {
VehicleServerRootAccess->Mark()=1;
}

double advise_treeADVISE::ExploitSuccessStep::getCost() {
return 0;
}

double advise_treeADVISE::ExploitSuccessStep::getOutcomeProbability() {
return 0.8;
}

double advise_treeADVISE::ExploitSuccessStep::getDetection() {
return 0.2;
}

/*****************************************************************/
/*                   Adversary Decisions                         */
/*****************************************************************/

/*====================== QueryFloodingAdversaryDecision ========================*/

advise_treeADVISE::QueryFloodingAdversaryDecision::QueryFloodingAdversaryDecision() {
  commonInit("QueryFloodingAdversaryDecision", 7, Instantaneous, RaceEnabled, 2, 1, false);
}

advise_treeADVISE::QueryFloodingAdversaryDecision::~QueryFloodingAdversaryDecision() {
}

void advise_treeADVISE::QueryFloodingAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  QueryFloodingChosen->Register(&QueryFloodingChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
}

bool advise_treeADVISE::QueryFloodingAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::QueryFloodingAdversaryDecision::Weight() {
  return QueryFloodingWeight->Mark();
}

bool advise_treeADVISE::QueryFloodingAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::QueryFloodingAdversaryDecision::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::QueryFloodingAdversaryDecision::SampleDistribution() {
  return 0;
}

double* advise_treeADVISE::QueryFloodingAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int advise_treeADVISE::QueryFloodingAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* advise_treeADVISE::QueryFloodingAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(QueryFloodingWeight_Mobius_Mark))--;
  (*(QueryFloodingChosen_Mobius_Mark))++;
  return this;
}

/*====================== FirmwareReversingAdversaryDecision ========================*/

advise_treeADVISE::FirmwareReversingAdversaryDecision::FirmwareReversingAdversaryDecision() {
  commonInit("FirmwareReversingAdversaryDecision", 7, Instantaneous, RaceEnabled, 2, 1, false);
}

advise_treeADVISE::FirmwareReversingAdversaryDecision::~FirmwareReversingAdversaryDecision() {
}

void advise_treeADVISE::FirmwareReversingAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  FirmwareReversingChosen->Register(&FirmwareReversingChosen_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
}

bool advise_treeADVISE::FirmwareReversingAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::FirmwareReversingAdversaryDecision::Weight() {
  return FirmwareReversingWeight->Mark();
}

bool advise_treeADVISE::FirmwareReversingAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::FirmwareReversingAdversaryDecision::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::FirmwareReversingAdversaryDecision::SampleDistribution() {
  return 0;
}

double* advise_treeADVISE::FirmwareReversingAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int advise_treeADVISE::FirmwareReversingAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* advise_treeADVISE::FirmwareReversingAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(FirmwareReversingWeight_Mobius_Mark))--;
  (*(FirmwareReversingChosen_Mobius_Mark))++;
  return this;
}

/*====================== DoNothingAdversaryDecision ========================*/

advise_treeADVISE::DoNothingAdversaryDecision::DoNothingAdversaryDecision() {
  commonInit("DoNothingAdversaryDecision", 7, Instantaneous, RaceEnabled, 2, 1, false);
}

advise_treeADVISE::DoNothingAdversaryDecision::~DoNothingAdversaryDecision() {
}

void advise_treeADVISE::DoNothingAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  DoNothingChosen->Register(&DoNothingChosen_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
}

bool advise_treeADVISE::DoNothingAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::DoNothingAdversaryDecision::Weight() {
  return DoNothingWeight->Mark();
}

bool advise_treeADVISE::DoNothingAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::DoNothingAdversaryDecision::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::DoNothingAdversaryDecision::SampleDistribution() {
  return 0;
}

double* advise_treeADVISE::DoNothingAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int advise_treeADVISE::DoNothingAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* advise_treeADVISE::DoNothingAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(DoNothingWeight_Mobius_Mark))--;
  (*(DoNothingChosen_Mobius_Mark))++;
  return this;
}

/*====================== PortScanAdversaryDecision ========================*/

advise_treeADVISE::PortScanAdversaryDecision::PortScanAdversaryDecision() {
  commonInit("PortScanAdversaryDecision", 7, Instantaneous, RaceEnabled, 2, 1, false);
}

advise_treeADVISE::PortScanAdversaryDecision::~PortScanAdversaryDecision() {
}

void advise_treeADVISE::PortScanAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  PortScanChosen->Register(&PortScanChosen_Mobius_Mark);
  PortScanWeight->Register(&PortScanWeight_Mobius_Mark);
}

bool advise_treeADVISE::PortScanAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::PortScanAdversaryDecision::Weight() {
  return PortScanWeight->Mark();
}

bool advise_treeADVISE::PortScanAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::PortScanAdversaryDecision::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::PortScanAdversaryDecision::SampleDistribution() {
  return 0;
}

double* advise_treeADVISE::PortScanAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int advise_treeADVISE::PortScanAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* advise_treeADVISE::PortScanAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(PortScanWeight_Mobius_Mark))--;
  (*(PortScanChosen_Mobius_Mark))++;
  return this;
}

/*====================== DatabaseDumpAdversaryDecision ========================*/

advise_treeADVISE::DatabaseDumpAdversaryDecision::DatabaseDumpAdversaryDecision() {
  commonInit("DatabaseDumpAdversaryDecision", 7, Instantaneous, RaceEnabled, 2, 1, false);
}

advise_treeADVISE::DatabaseDumpAdversaryDecision::~DatabaseDumpAdversaryDecision() {
}

void advise_treeADVISE::DatabaseDumpAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  DatabaseDumpChosen->Register(&DatabaseDumpChosen_Mobius_Mark);
  DatabaseDumpWeight->Register(&DatabaseDumpWeight_Mobius_Mark);
}

bool advise_treeADVISE::DatabaseDumpAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::DatabaseDumpAdversaryDecision::Weight() {
  return DatabaseDumpWeight->Mark();
}

bool advise_treeADVISE::DatabaseDumpAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::DatabaseDumpAdversaryDecision::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::DatabaseDumpAdversaryDecision::SampleDistribution() {
  return 0;
}

double* advise_treeADVISE::DatabaseDumpAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int advise_treeADVISE::DatabaseDumpAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* advise_treeADVISE::DatabaseDumpAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(DatabaseDumpWeight_Mobius_Mark))--;
  (*(DatabaseDumpChosen_Mobius_Mark))++;
  return this;
}

/*====================== TamperingAdversaryDecision ========================*/

advise_treeADVISE::TamperingAdversaryDecision::TamperingAdversaryDecision() {
  commonInit("TamperingAdversaryDecision", 7, Instantaneous, RaceEnabled, 2, 1, false);
}

advise_treeADVISE::TamperingAdversaryDecision::~TamperingAdversaryDecision() {
}

void advise_treeADVISE::TamperingAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  TamperingChosen->Register(&TamperingChosen_Mobius_Mark);
  TamperingWeight->Register(&TamperingWeight_Mobius_Mark);
}

bool advise_treeADVISE::TamperingAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::TamperingAdversaryDecision::Weight() {
  return TamperingWeight->Mark();
}

bool advise_treeADVISE::TamperingAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::TamperingAdversaryDecision::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::TamperingAdversaryDecision::SampleDistribution() {
  return 0;
}

double* advise_treeADVISE::TamperingAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int advise_treeADVISE::TamperingAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* advise_treeADVISE::TamperingAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(TamperingWeight_Mobius_Mark))--;
  (*(TamperingChosen_Mobius_Mark))++;
  return this;
}

/*====================== ExploitAdversaryDecision ========================*/

advise_treeADVISE::ExploitAdversaryDecision::ExploitAdversaryDecision() {
  commonInit("ExploitAdversaryDecision", 7, Instantaneous, RaceEnabled, 2, 1, false);
}

advise_treeADVISE::ExploitAdversaryDecision::~ExploitAdversaryDecision() {
}

void advise_treeADVISE::ExploitAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  ExploitChosen->Register(&ExploitChosen_Mobius_Mark);
  ExploitWeight->Register(&ExploitWeight_Mobius_Mark);
}

bool advise_treeADVISE::ExploitAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double advise_treeADVISE::ExploitAdversaryDecision::Weight() {
  return ExploitWeight->Mark();
}

bool advise_treeADVISE::ExploitAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool advise_treeADVISE::ExploitAdversaryDecision::ReactivationFunction() {
  return false;
}

double advise_treeADVISE::ExploitAdversaryDecision::SampleDistribution() {
  return 0;
}

double* advise_treeADVISE::ExploitAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int advise_treeADVISE::ExploitAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* advise_treeADVISE::ExploitAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(ExploitWeight_Mobius_Mark))--;
  (*(ExploitChosen_Mobius_Mark))++;
  return this;
}

