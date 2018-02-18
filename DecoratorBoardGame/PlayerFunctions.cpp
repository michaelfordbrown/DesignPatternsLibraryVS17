#include "stdafx.h"
#include "PlayerFunctions.h"

void PlayerTurn(Player *p,  rotation rotate) {
	switch (rotate)
	{
	case LEFT:
		p->facingDirection = static_cast<compassPoints>((p->facingDirection - 1 + COMPASSMAX) % COMPASSMAX);
		break;
	case RIGHT:
		p->facingDirection = static_cast<compassPoints>((p->facingDirection + 1 + COMPASSMAX) % COMPASSMAX);
		break;
	default:
		break;
	}
};