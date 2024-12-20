// Shoot Them Up demo game project. Evgenii Esaulenko, 2024

#pragma once

#include "CoreMinimal.h"
#include "STUBaseWidget.h"
#include "STUGameModeBase.h"
#include "STUGameEndWidget.generated.h"

class USTUButtonWidget;
class USTUPlayerStatsWidget;
class UVerticalBox;

UCLASS()
class SHOOTTHEMUP_API USTUGameEndWidget : public USTUBaseWidget
{
    GENERATED_BODY()

public:
    virtual bool Initialize() override;
    virtual void SetVisibility(ESlateVisibility InVisibility) override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<USTUPlayerStatsWidget> PlayerStatsWidgetClass;
    
    UPROPERTY(meta = (BindWidget))
    UVerticalBox* PlayerStatsBox;

    UPROPERTY(meta = (BindWidget))
    USTUButtonWidget* RestartButton = nullptr;

    UPROPERTY(meta = (BindWidget))
    USTUButtonWidget* ExitButton = nullptr;

    virtual void NativeConstruct() override;

private:
    void OnGameStateChange(EGameState NewState);
    void DisplayPlayersStats();

    UFUNCTION()
    void RestartLevel();

    UFUNCTION()
    void ExitLevel();
};
