// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "E2EBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class E2ETEST_API UE2EBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
    static void PressLeftClick(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable)
    static void ReleaseLeftClick(APlayerController* PlayerController);
};
