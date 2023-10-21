// Fill out your copyright notice in the Description page of Project Settings.


#include "MathFunctions.h"

bool MathFunctions::RandomBoolWithWeight(float TrueWeight)
{
	float RandomValue = FMath::FRand();
	return RandomValue <= TrueWeight;
}

MathFunctions::MathFunctions()
{
}

MathFunctions::~MathFunctions()
{
}
