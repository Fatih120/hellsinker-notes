// Location: 007f614c
// Sets the amount of STELLA carryover between segments
// Big thanks to beetle
void SetSTELLA_SegmentClear(void)

{
  uint StellaTier;
  int LifeMod;
  int KeptStellaPercentage;
  
  TotalSpirits = TotalSpirits + CurrentSpirits;
  TotalKills = TotalKills + CurrentKills;
  TotalTokens = TotalTokens + CurrentTokens;
  CurrentSpirits = 0;
  CurrentKills = 0;
  CurrentTokens = 0;
  KeptStellaPercentage = LifeCount - 3;
  if (KeptStellaPercentage < 0) {
    KeptStellaPercentage = 0;
  }
  StellaLowLimit =
       (undefined *)
       ((int)StellaLowLimit + (Player_Survivability * 0x29aaa) / 100 + KeptStellaPercentage * 0xde38
       );
  if (LifeCount == 0) {
    StellaLowLimit = (undefined *)((int)StellaLowLimit / 2);
  }
  if ((int)StellaLowLimit < 0) {
    StellaLowLimit = (undefined *)0;
  }
  if ((int)StellaLowLimit > 0x465000) {
    StellaLowLimit = &StellaHighLimit;
  }
  StellaTier = LifeCount * 10 + ExtendCount * 6;
  LifeMod = (int)StageStellaMod >> 1;
  if (LifeMod < 0) {
    LifeMod = LifeMod + (uint)((StageStellaMod & 1) != 0);
  }
  if (MissCount < LifeMod + 1) {
    StellaTier = StellaTier + StageStellaMod * 2 + 0x10;
  }
  if ((int)StellaTier < 60) {
    if (StellaTier < 20) {
      StellaTier = 5;
    }
    else if (StellaTier - 20 < 20) {
      StellaTier = 4;
    }
    else if (StellaTier - 40 < 20) {
      StellaTier = 3;
    }
  }
  else if (StellaTier - 60 < 10) {
    StellaTier = 2;
  }
  else if (StellaTier - 70 < 10) {
    StellaTier = 1;
  }
  else if (StellaTier - 80 < 421) {
    StellaTier = 0;
  }
  switch(StellaTier) {
  case 0:
    KeptStellaPercentage = 20;
    break;
  case 1:
    KeptStellaPercentage = 30;
    break;
  case 2:
    KeptStellaPercentage = 40;
    break;
  case 3:
    KeptStellaPercentage = 50;
    break;
  case 4:
    KeptStellaPercentage = 60;
    break;
  case 5:
    KeptStellaPercentage = 70;
  }
  LifeMod = 4 - LifeCount;
  if (LifeMod < 1) {
    LifeMod = 1;
  }
  StellaCount = (undefined *)(((int)StellaCount * KeptStellaPercentage) / 100 + LifeMod * -0x7d000);
  if ((int)StellaCount < 0) {
    StellaCount = (undefined *)0x0;
  }
  if ((int)StellaCount < (int)StellaLowLimit) {
    StellaCount = StellaLowLimit;
  }
  if (DipSwLevelDiff == 1) {
    if ((int)StellaCount > 0x2edd80) { // These are just the kind of random high values used
      StellaCount = (undefined *)0x2edd80;
    }
  }
  else if (DipSwLevelDiff == 2) {
    if ((int)StellaCount < 0x177000) {
      StellaCount = (undefined *)0x177002;
    }
  }
  else if ((DipSwLevelDiff == 3) && ((int)StellaCount < 0x2ee000)) {
    StellaCount = (undefined *)0x2ee002;
  }
  StellaRanking = (int)StellaCount / 0x7d000;
  if (StellaRanking > 9) {
    StellaRanking = 9;
  }
  return;
}

