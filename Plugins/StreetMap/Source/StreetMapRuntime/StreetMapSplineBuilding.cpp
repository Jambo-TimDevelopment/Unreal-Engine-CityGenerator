// Fill out your copyright notice in the Description page of Project Settings.

#include "StreetMapSplineBuilding.h"
#include "Components/SplineComponent.h"

AStreetMapSplineBuilding::AStreetMapSplineBuilding(const FObjectInitializer& ObjectInitializer)
{
	Spline = CreateDefaultSubobject<USplineComponent>("Spline");
	Spline->SetupAttachment(GetRootComponent());
}

FStreetMapBuilding& AStreetMapSplineBuilding::GenerateStreetMapBuilding()
{
	if (StreetMapBuilding.BuildingPoints.IsEmpty()) { return StreetMapBuilding; }
	
	if (bLocationByGeoData && IsValid(GetOwner()))
	{
		const FVector BuildingLocation = GetOwner()->GetActorLocation();
		//SetActorLocation(BuildingLocation);
	}

	if (bPerimeterByGeoData)
	{
		if (StreetMapBuilding.BuildingPoints.Num() <= 2)
		{
			return StreetMapBuilding;
		}

		bool flag = false;
		for (int i = 0; i < Spline->GetNumberOfSplinePoints(); i++)
		{
			Spline->RemoveSplinePoint(i);
			flag = true;
		}

		if (flag)
		{
			Spline->UpdateSpline();
		}

		int32 Key = 0;
		TArray<FSplinePoint> SplinePoints;
		for (const FVector2D& SplinePoint : StreetMapBuilding.BuildingPoints)
		{
			if (Spline->SplineCurves.Position.Points.IsValidIndex(Key))
			{
				continue;
			}
			FSplinePoint NewSplinePoint = FSplinePoint(Key, FVector(SplinePoint.X, SplinePoint.Y, 0));
			NewSplinePoint.Type = ESplinePointType::Linear;
			NewSplinePoint.InputKey = Key;
			//if (Spline->SplineCurves.Position.Points.Num() == Key - 1)
			//{
			SplinePoints.Add(NewSplinePoint);
			//}
			Key++;
		}
		Spline->AddPoints(SplinePoints, false);
		Spline->SetClosedLoop(true);

		bPerimeterByGeoData = false;
	}

	return StreetMapBuilding;
}
