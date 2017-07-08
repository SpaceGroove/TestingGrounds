// Fill out your copyright notice in the Description page of Project Settings.

#include "Task_ChooseNextWaypoint.h"


EBTNodeResult::Type UTask_ChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("Donkey"))
	return EBTNodeResult::Succeeded;
}

