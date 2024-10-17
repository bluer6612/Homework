#include "TetrisInit.h"
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/ConsoleWindow.h>

#include "Block.h"
#include "RenderTarget.h"

void TetrisInit::UserBeginPlay(ConsoleEngine* _MainEngine)
{
	// 시작을 합니다.
	_MainEngine->GetWindow()->SetScreenSize({3, 5});

	RenderTarget* RenderValue = _MainEngine->SpawnActor<RenderTarget>();
	Block* BlockValue = _MainEngine->SpawnActor<Block>();
	BlockValue->SetRenderTarget(RenderValue);

}