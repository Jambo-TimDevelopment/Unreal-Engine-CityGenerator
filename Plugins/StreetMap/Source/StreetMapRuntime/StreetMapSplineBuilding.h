// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StreetMap.h"
#include "GameFramework/Actor.h"
#include "StreetMapSplineBuilding.generated.h"

UCLASS(Blueprintable, BlueprintType)
class STREETMAPRUNTIME_API AStreetMapSplineBuilding : public AActor
{
	GENERATED_BODY()

	AStreetMapSplineBuilding(const FObjectInitializer& ObjectInitializer);

public:
	UFUNCTION(BlueprintCallable)
	FStreetMapBuilding& GenerateStreetMapBuilding();

	void SetStreetMapBuilding(const FStreetMapBuilding& NewStreetMapBuilding) { StreetMapBuilding = NewStreetMapBuilding; };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Geo Data")
	FStreetMapBuilding StreetMapBuilding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Geo Data")
	bool bLocationByGeoData = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Geo Data")
	bool bPerimeterByGeoData = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Geo Data")
	bool bFloorCountByGeoData = true;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	class USplineComponent* Spline;
};
