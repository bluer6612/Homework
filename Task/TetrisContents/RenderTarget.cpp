#include "RenderTarget.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/ConsoleWindow.h>


void RenderTarget::BeginPlay()
{
	Super::BeginPlay();

	UConsoleWindow* Window = ConsoleEngine::GetEngine().GetWindow();
	FIntPoint ScreenSize = Window->GetScreenSize();


	// 이미지도 => 배열메모리 덩어리.
	TargetRender = CreateDefaultSubObject();
	TargetRender->RenderImage.Create({ ScreenSize.X, ScreenSize.Y + 1 }, '-');

	for (int i = 0; i < ScreenSize.X; i++)
	{
		TargetRender->RenderImage.SetPixel({ i, ScreenSize.Y }, '@');
	}
}

ConsoleImage* RenderTarget::GetImage()
{
	return &TargetRender->RenderImage;
}


void RenderTarget::SetPixel(FIntPoint _Point, char _Value)
{
	TargetRender->RenderImage.SetPixel(_Point, _Value);
}

void RenderTarget::Tick()
{

}