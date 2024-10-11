#include "FightUnit.h"
#include "StatusUnit.h"
#include <iostream>

int UFightUnit::GetDamage() const
{
	// minAtt ~ MaxAtt 사이의 숫자가 리턴되는 함수를 만드세요.
	return  ThisUnit->GetMinAtt() + (rand() % (ThisUnit->GetMaxAtt() - ThisUnit->GetMinAtt() + 1));
}

// 내가 데미지 받는 함수
void UFightUnit::DamageLogic(class UFightUnit& _Unit)
{
	UStatusUnit* Def = this->ThisUnit;
	UStatusUnit* Att = _Unit.ThisUnit;

	PrevDamage = _Unit.GetDamage();
	int CurHp = Def->GetHp() - PrevDamage;
	Def->SetHp(CurHp);
}

bool UFightUnit::IsDeath() const
{
	return 0 >= ThisUnit->GetHp();
}
