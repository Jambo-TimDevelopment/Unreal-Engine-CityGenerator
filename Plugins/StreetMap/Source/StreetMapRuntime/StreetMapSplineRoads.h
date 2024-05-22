// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StreetMap.h"
#include "GameFramework/Actor.h"
#include "StreetMapSplineRoads.generated.h"

UCLASS()
class STREETMAPRUNTIME_API AStreetMapSplineRoads : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AStreetMapSplineRoads();

	void SetStreetMapRoad(const FStreetMapRoad& NewStreetMapRoad) { StreetMapRoad = NewStreetMapRoad; };

	UFUNCTION(BlueprintCallable)
	FStreetMapRoad& GenerateStreetMapRoad();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Geo Data")
	FStreetMapRoad StreetMapRoad;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Geo Data")
	bool bLocationByGeoData = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Geo Data")
	bool bPerimeterByGeoData = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Geo Data")
	bool bFloorCountByGeoData = true;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	class USplineComponent* Spline;
};
