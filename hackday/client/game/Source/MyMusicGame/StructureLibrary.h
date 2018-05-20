// JackMyth Personal

#pragma once

#include "GameFramework/Actor.h"
#include "StructureLibrary.generated.h"

USTRUCT(BlueprintType)
struct FRhythmData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="DataS")
		int Time;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataS")
		int Position;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataS")
		int Type;
};


UCLASS()
class MYMUSICGAME_API AStructureLibrary : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStructureLibrary();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
