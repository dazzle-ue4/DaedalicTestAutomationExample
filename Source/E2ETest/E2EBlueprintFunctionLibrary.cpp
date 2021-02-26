// Fill out your copyright notice in the Description page of Project Settings.


#include "E2EBlueprintFunctionLibrary.h"

void UE2EBlueprintFunctionLibrary::PressLeftClick(APlayerController* PlayerController)
{
    //trigger the mouse click event. This will fire any lmb click events within blueprints.
    FViewportClient* Client = GEngine->GameViewport->Viewport->GetClient();
    FKey MouseLMB = EKeys::LeftMouseButton;
    Client->InputKey(GEngine->GameViewport->Viewport, 0, MouseLMB, EInputEvent::IE_Pressed);
 
    //Trigger mouse clicks in UI
    //Get our slate application
    FSlateApplication& SlateApp = FSlateApplication::Get();
 
    //create a pointer event
    FPointerEvent MouseDownEvent(
        0,
        SlateApp.CursorPointerIndex,
        SlateApp.GetCursorPos(),
        SlateApp.GetLastCursorPos(),
        SlateApp.GetPressedMouseButtons(),
        EKeys::LeftMouseButton,
        0,
        SlateApp.GetPlatformApplication()->GetModifierKeys()
    );
     
    //send the mouse event to the slate handler
    TSharedPtr<FGenericWindow> GenWindow;
    SlateApp.ProcessMouseButtonDownEvent(GenWindow, MouseDownEvent);
}

void UE2EBlueprintFunctionLibrary::ReleaseLeftClick(APlayerController* PlayerController)
{
    //trigger the mouse click release event
    FViewportClient* Client = GEngine->GameViewport->Viewport->GetClient();
    FKey MouseLMB = EKeys::LeftMouseButton;
    Client->InputKey(GEngine->GameViewport->Viewport, 0, MouseLMB, EInputEvent::IE_Released);
 
    //trigger the UI mouse click
    FSlateApplication& SlateApp = FSlateApplication::Get();
 
    FPointerEvent MouseUpEvent(
        0,
        SlateApp.CursorPointerIndex,
        SlateApp.GetCursorPos(),
        SlateApp.GetLastCursorPos(),
        SlateApp.GetPressedMouseButtons(),
        EKeys::LeftMouseButton,
        0,
        SlateApp.GetPlatformApplication()->GetModifierKeys()
    );
 
    TSharedPtr<FGenericWindow> GenWindow;
    SlateApp.ProcessMouseButtonUpEvent(MouseUpEvent);
}
