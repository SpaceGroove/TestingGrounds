// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolPointComponent.generated.h"

/**
* A "route card" to help AI choose their next waypoint
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_API UPatrolPointComponent : public UActorComponent
{
	GENERATED_BODY()



public:	
	TArray<AActor*> GetPatrolPoints() const;

	UPROPERTY(EditInstanceOnly, Category = "Patrol Route CPP")
		TArray<AActor*> PatrolPointsCPP;
		
	
};
