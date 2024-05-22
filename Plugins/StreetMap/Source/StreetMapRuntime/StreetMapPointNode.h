// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StreetMap.h"
#include "GameFramework/Actor.h"
#include "StreetMapPointNode.generated.h"

UCLASS()
class STREETMAPRUNTIME_API AStreetMapPointNode : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStreetMapPointNode();

	void SetStreetMapNode(const FStreetMapNode& NewStreetMapRoad) { StreetMapNode = NewStreetMapRoad; };

	/*UFUNCTION(BlueprintCallable)
	FStreetMapNode& GenerateStreetMapNode();*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Geo Data")
	FStreetMapNode StreetMapNode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Geo Data")
	bool bLocationByGeoData = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Geo Data")
	bool bPerimeterByGeoData = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Geo Data")
	bool bFloorCountByGeoData = true;

	UPROPERTY()
	TArray<AStreetMapSplineRoads*> RoadActors;
};
