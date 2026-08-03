// Copyright Epic Games, Inc. All Rights Reserved.

#include "SuperMarioGameMode.h"
#include "SuperMarioCharacter.h"

ASuperMarioGameMode::ASuperMarioGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = ASuperMarioCharacter::StaticClass();	
}
