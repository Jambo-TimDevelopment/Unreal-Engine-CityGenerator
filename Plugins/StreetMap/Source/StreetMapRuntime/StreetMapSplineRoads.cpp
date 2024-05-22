// Fill out your copyright notice in the Description page of Project Settings.


#include "StreetMapSplineRoads.h"

#include "Components/SplineComponent.h"

// Sets default values
AStreetMapSplineRoads::AStreetMapSplineRoads()
{
	Spline = CreateDefaultSubobject<USplineComponent>("Spline");
	Spline->SetupAttachment(GetRootComponent());
}

FStreetMapRoad& AStreetMapSplineRoads::GenerateStreetMapRoad()
{
	if (StreetMapRoad.RoadPoints.IsEmpty()) { return StreetMapRoad; }

	if (bLocationByGeoData && IsValid(GetOwner()))
	{
		const FVector BuildingLocation = GetOwner()->GetActorLocation();
		//SetActorLocation(BuildingLocation);
	}

	if (bPerimeterByGeoData)
	{
		if (StreetMapRoad.RoadPoints.Num() <= 1)
		{
			return StreetMapRoad;
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
		for (const FVector2D& SplinePoint : StreetMapRoad.RoadPoints)
		{
			FVector PointLocation = FVector(SplinePoint.X, SplinePoint.Y, 0);
			FSplinePoint NewSplinePoint = FSplinePoint(Key, PointLocation);
			NewSplinePoint.Type = ESplinePointType::Curve;
			NewSplinePoint.InputKey = Key;
			//if (Spline->SplineCurves.Position.Points.Num() == Key - 1)
			//{
			if (Spline->SplineCurves.Position.Points.IsValidIndex(Key))
			{
				Spline->SetLocationAtSplinePoint(Key, PointLocation, ESplineCoordinateSpace::World);
				Key++;
				continue;
			}
			SplinePoints.Add(NewSplinePoint);
			//}
			Key++;
		}
		Spline->AddPoints(SplinePoints, false);
		Spline->SetClosedLoop(false);

		bPerimeterByGeoData = false;
	}

	return StreetMapRoad;
}
