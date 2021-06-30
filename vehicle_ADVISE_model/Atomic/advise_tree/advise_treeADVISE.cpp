
#include "Atomic/advise_tree/advise_treeADVISE.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>


advise_treeADVISE::advise_treeADVISE() {
  QueryFloodingAD.setParent(this);
  DoNothingAD.setParent(this);
  FirmwareReversingAD.setParent(this);
  QueryFloodingFailure.setParent(this);
  QueryFloodingSuccess.setParent(this);
  DoNothingOutcome1.setParent(this);
  FirmwareReversingFailure.setParent(this);
  FirmwareReversingObtainall.setParent(this);
  FirmwareReversingObtainaddressonly.setParent(this);
  QueryFloodingGroup.initialize(2, "QueryFloodingGroup");
  QueryFloodingGroup.appendGroup((BaseGroupClass*) &QueryFloodingFailure);
  QueryFloodingGroup.appendGroup((BaseGroupClass*) &QueryFloodingSuccess);

  FirmwareReversingGroup.initialize(3, "FirmwareReversingGroup");
  FirmwareReversingGroup.appendGroup((BaseGroupClass*) &FirmwareReversingFailure);
  FirmwareReversingGroup.appendGroup((BaseGroupClass*) &FirmwareReversingObtainall);
  FirmwareReversingGroup.appendGroup((BaseGroupClass*) &FirmwareReversingObtainaddressonly);

  AdversaryDecisionGroup.initialize(3, "AdversaryDecisionGroup");
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &QueryFloodingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &DoNothingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &FirmwareReversingAD);

  BaseADVISEAction* InitialActions[9] = {
    &QueryFloodingAD, // 0
    &DoNothingAD, // 1
    &FirmwareReversingAD, // 2
    &QueryFloodingFailure, // 3
    &QueryFloodingSuccess, // 4
    &DoNothingOutcome1, // 5
    &FirmwareReversingFailure, // 6
    &FirmwareReversingObtainall, // 7
    &FirmwareReversingObtainaddressonly // 8
  };

  Step* InitialSteps[6] = {
      &QueryFloodingFailure,
      &QueryFloodingSuccess,
      &DoNothingOutcome1,
      &FirmwareReversingFailure,
      &FirmwareReversingObtainall,
      &FirmwareReversingObtainaddressonly
  };

  BaseGroupClass* InitialGroups[4] = {
    (BaseGroupClass*) &QueryFloodingGroup, // 0
    (BaseGroupClass*) &DoNothingOutcome1, // 1
    (BaseGroupClass*) &FirmwareReversingGroup, // 2
    (BaseGroupClass*) &AdversaryDecisionGroup
  };

  BinaryDump = new Knowledge("BinaryDump", 1);
  SocketAddress = new Knowledge("SocketAddress", 0);
  HandshakeProtocol = new Knowledge("HandshakeProtocol", 0);
  ReverseEngineering = new Skill("ReverseEngineering", 5);
  Script = new Skill("Script", 7);
  DoS = new Goal("DoS", 0);
  DoS->setPayoff(500);
  MakeDecision = new BeginAdversaryDecision("MakeDecision", 0);
  QueryFloodingWeight = new StepWeight("QueryFloodingWeight", 0);
  QueryFloodingChosen = new StepChosen("QueryFloodingChosen", 0);
  DoNothingWeight = new StepWeight("DoNothingWeight", 0);
  DoNothingChosen = new StepChosen("DoNothingChosen", 0);
  FirmwareReversingWeight = new StepWeight("FirmwareReversingWeight", 0);
  FirmwareReversingChosen = new StepChosen("FirmwareReversingChosen", 0);

  Goal* InitialGoals[1] = {
      DoS
  };

  ADVISEStateVariable* InitialSVs[13] = {
    BinaryDump, // 0
    SocketAddress, // 1
    HandshakeProtocol, // 2
    ReverseEngineering, // 3
    Script, // 4
    DoS, // 5
    QueryFloodingChosen, // 6
    DoNothingChosen, // 7
    FirmwareReversingChosen, // 8
    QueryFloodingWeight, // 9
    DoNothingWeight, // 10
    FirmwareReversingWeight, // 11
    MakeDecision // 12
};

  int outCounts[3] = { 2, 1, 3 };

  commonInit("advise_tree", 13, InitialSVs, 9, InitialActions, 4, InitialGroups, 3, outCounts, InitialSteps, 1, InitialGoals);

  advCostPref = 0.1;
  advDetectPref = 0.1;
  advPayPref = 0.8;

  planningHorizon = 2;
  costDiscount = 1.0;
  detectionDiscount = 1.0;
  payoffDiscount = 1.0;

  assignSVsToAttackSteps();

  int AffectArcs[54][2] = {
    {12,0}, {6,0}, {9,0}, {12,1}, {7,1}, {10,1}, {12,2}, {8,2}, 
    {11,2}, {12,3}, {6,3}, {9,3}, {10,3}, {11,3}, {5,3}, {2,3}, 
    {1,3}, {12,4}, {6,4}, {9,4}, {10,4}, {11,4}, {5,4}, {2,4}, 
    {1,4}, {12,5}, {7,5}, {9,5}, {10,5}, {11,5}, {12,6}, {8,6}, 
    {9,6}, {10,6}, {11,6}, {2,6}, {1,6}, {0,6}, {12,7}, {8,7}, 
    {9,7}, {10,7}, {11,7}, {2,7}, {1,7}, {0,7}, {12,8}, {8,8}, 
    {9,8}, {10,8}, {11,8}, {2,8}, {1,8}, {0,8}
};
  for(int n = 0; n < 54;n++)
    AddAffectArc(InitialSVs[AffectArcs[n][0]], InitialActions[AffectArcs[n][1]]);
  int EnableArcs[17][2] = {
    {12,0}, {12,1}, {12,2}, {6,3}, {5,3}, {6,4}, {5,4}, {7,5}, 
    {8,6}, {2,6}, {1,6}, {8,7}, {2,7}, {1,7}, {8,8}, {2,8}, 
    {1,8}
};
  for(int n = 0; n < 17;n++)
    AddEnableArc(InitialSVs[EnableArcs[n][0]], InitialActions[EnableArcs[n][1]]);
  for(int x = 0; x < 9; x++) {
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
  QueryFloodingFailure.DoNothingWeight = DoNothingWeight;
  QueryFloodingFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  QueryFloodingFailure.MakeDecision = MakeDecision;
  QueryFloodingFailure.setSVs(QueryFloodingChosen, QueryFloodingWeight);
  QueryFloodingSuccess.DoS = DoS;
  QueryFloodingSuccess.Script = Script;
  QueryFloodingSuccess.HandshakeProtocol = HandshakeProtocol;
  QueryFloodingSuccess.SocketAddress = SocketAddress;
  QueryFloodingSuccess.QueryFloodingChosen = QueryFloodingChosen;
  QueryFloodingSuccess.QueryFloodingWeight = QueryFloodingWeight;
  QueryFloodingSuccess.DoNothingWeight = DoNothingWeight;
  QueryFloodingSuccess.FirmwareReversingWeight = FirmwareReversingWeight;
  QueryFloodingSuccess.MakeDecision = MakeDecision;
  QueryFloodingSuccess.setSVs(QueryFloodingChosen, QueryFloodingWeight);
  DoNothingOutcome1.DoNothingChosen = DoNothingChosen;
  DoNothingOutcome1.QueryFloodingWeight = QueryFloodingWeight;
  DoNothingOutcome1.DoNothingWeight = DoNothingWeight;
  DoNothingOutcome1.FirmwareReversingWeight = FirmwareReversingWeight;
  DoNothingOutcome1.MakeDecision = MakeDecision;
  DoNothingOutcome1.setSVs(DoNothingChosen, DoNothingWeight);
  FirmwareReversingFailure.HandshakeProtocol = HandshakeProtocol;
  FirmwareReversingFailure.SocketAddress = SocketAddress;
  FirmwareReversingFailure.BinaryDump = BinaryDump;
  FirmwareReversingFailure.ReverseEngineering = ReverseEngineering;
  FirmwareReversingFailure.FirmwareReversingChosen = FirmwareReversingChosen;
  FirmwareReversingFailure.QueryFloodingWeight = QueryFloodingWeight;
  FirmwareReversingFailure.DoNothingWeight = DoNothingWeight;
  FirmwareReversingFailure.FirmwareReversingWeight = FirmwareReversingWeight;
  FirmwareReversingFailure.MakeDecision = MakeDecision;
  FirmwareReversingFailure.setSVs(FirmwareReversingChosen, FirmwareReversingWeight);
  FirmwareReversingObtainall.HandshakeProtocol = HandshakeProtocol;
  FirmwareReversingObtainall.SocketAddress = SocketAddress;
  FirmwareReversingObtainall.BinaryDump = BinaryDump;
  FirmwareReversingObtainall.ReverseEngineering = ReverseEngineering;
  FirmwareReversingObtainall.FirmwareReversingChosen = FirmwareReversingChosen;
  FirmwareReversingObtainall.QueryFloodingWeight = QueryFloodingWeight;
  FirmwareReversingObtainall.DoNothingWeight = DoNothingWeight;
  FirmwareReversingObtainall.FirmwareReversingWeight = FirmwareReversingWeight;
  FirmwareReversingObtainall.MakeDecision = MakeDecision;
  FirmwareReversingObtainall.setSVs(FirmwareReversingChosen, FirmwareReversingWeight);
  FirmwareReversingObtainaddressonly.HandshakeProtocol = HandshakeProtocol;
  FirmwareReversingObtainaddressonly.SocketAddress = SocketAddress;
  FirmwareReversingObtainaddressonly.BinaryDump = BinaryDump;
  FirmwareReversingObtainaddressonly.ReverseEngineering = ReverseEngineering;
  FirmwareReversingObtainaddressonly.FirmwareReversingChosen = FirmwareReversingChosen;
  FirmwareReversingObtainaddressonly.QueryFloodingWeight = QueryFloodingWeight;
  FirmwareReversingObtainaddressonly.DoNothingWeight = DoNothingWeight;
  FirmwareReversingObtainaddressonly.FirmwareReversingWeight = FirmwareReversingWeight;
  FirmwareReversingObtainaddressonly.MakeDecision = MakeDecision;
  FirmwareReversingObtainaddressonly.setSVs(FirmwareReversingChosen, FirmwareReversingWeight);

  QueryFloodingAD.MakeDecision = MakeDecision;
  QueryFloodingAD.QueryFloodingChosen = QueryFloodingChosen;
  QueryFloodingAD.QueryFloodingWeight = QueryFloodingWeight;
  DoNothingAD.MakeDecision = MakeDecision;
  DoNothingAD.DoNothingChosen = DoNothingChosen;
  DoNothingAD.DoNothingWeight = DoNothingWeight;
  FirmwareReversingAD.MakeDecision = MakeDecision;
  FirmwareReversingAD.FirmwareReversingChosen = FirmwareReversingChosen;
  FirmwareReversingAD.FirmwareReversingWeight = FirmwareReversingWeight;
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
  commonInit("QueryFloodingFailureStep", 0, Deterministic, RaceEnabled, 9, 1, false);}

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
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
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
  commonInit("QueryFloodingSuccessStep", 0, Deterministic, RaceEnabled, 9, 1, false);}

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
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
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

/*====================== DoNothingOutcome1Step ========================*/

advise_treeADVISE::DoNothingOutcome1Step::DoNothingOutcome1Step() {
  TheDistributionParameters = new double[1];
  commonInit("DoNothingOutcome1Step", 1, Deterministic, RaceEnabled, 5, 0, false);}

advise_treeADVISE::DoNothingOutcome1Step::~DoNothingOutcome1Step() {
  delete[] TheDistributionParameters;
}

void advise_treeADVISE::DoNothingOutcome1Step::LinkVariables() {
  DoNothingChosen->Register(&DoNothingChosen_Mobius_Mark);
  QueryFloodingWeight->Register(&QueryFloodingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
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

/*====================== FirmwareReversingFailureStep ========================*/

advise_treeADVISE::FirmwareReversingFailureStep::FirmwareReversingFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("FirmwareReversingFailureStep", 2, Deterministic, RaceEnabled, 9, 2, false);}

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
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
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
  commonInit("FirmwareReversingObtainallStep", 2, Deterministic, RaceEnabled, 9, 2, false);}

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
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
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
  commonInit("FirmwareReversingObtainaddressonlyStep", 2, Deterministic, RaceEnabled, 9, 2, false);}

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
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  FirmwareReversingWeight->Register(&FirmwareReversingWeight_Mobius_Mark);
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

/*****************************************************************/
/*                   Adversary Decisions                         */
/*****************************************************************/

/*====================== QueryFloodingAdversaryDecision ========================*/

advise_treeADVISE::QueryFloodingAdversaryDecision::QueryFloodingAdversaryDecision() {
  commonInit("QueryFloodingAdversaryDecision", 3, Instantaneous, RaceEnabled, 2, 1, false);
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

/*====================== DoNothingAdversaryDecision ========================*/

advise_treeADVISE::DoNothingAdversaryDecision::DoNothingAdversaryDecision() {
  commonInit("DoNothingAdversaryDecision", 3, Instantaneous, RaceEnabled, 2, 1, false);
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

/*====================== FirmwareReversingAdversaryDecision ========================*/

advise_treeADVISE::FirmwareReversingAdversaryDecision::FirmwareReversingAdversaryDecision() {
  commonInit("FirmwareReversingAdversaryDecision", 3, Instantaneous, RaceEnabled, 2, 1, false);
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

