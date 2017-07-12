// Fill out your copyright notice in the Description page of Project Settings.

#include "Task_ChooseNextWaypoint.h"
#include "AIController.h"
#include "PatrolPointComponent.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UTask_ChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get the patrol route
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolPointComp = ControlledPawn->FindComponentByClass<UPatrolPointComponent>();
	if (!ensure(PatrolPointComp)) { return EBTNodeResult::Failed; } // protect against no patrol point component
	auto PatrolPoints = PatrolPointComp->GetPatrolPoints();
	if (PatrolPoints.Num() == 0) // protect against no patrol points
	{
		UE_LOG(LogTemp, Warning, TEXT("A Guard is missing patrol points"));
			return EBTNodeResult::Failed;
	}

	// Set the next waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	// cycle the index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);


	
	return EBTNodeResult::Succeeded;
}

