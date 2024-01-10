// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstanceSubsystem.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"

UMyGameInstanceSubsystem::UMyGameInstanceSubsystem():
	CreateSessionCompleteDelegate(FOnCreateSessionCompleteDelegate::CreateUObject(this,&ThisClass::OnCreateSessionCopmplete)),
	FindSessionCompleteDelegate(FOnFindSessionsCompleteDelegate::CreateUObject(this,&ThisClass::OnFindSessionsComplete)),
	JoinSessionCompleteDelegate(FOnJoinSessionCompleteDelegate::CreateUObject(this,&ThisClass::OnJoinSessionComplete)),
	DestroySessionCompleteDelegate(FOnDestroySessionCompleteDelegate::CreateUObject(this,&ThisClass::OnDestroySessionComplete)),
	StartSessionCompleteDelegate(FOnStartSessionCompleteDelegate::CreateUObject(this,&ThisClass::OnStartSessionComplete))

{
	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
	if (Subsystem) {
		SessionInterface = Subsystem->GetSessionInterface();
	}
}

void UMyGameInstanceSubsystem::CreateSession(int32 NumPublicConnections, FString MatchType)
{
	if (!SessionInterface.IsValid()) return;
	auto ExistringSession = SessionInterface->GetNamedSession(NAME_GameSession);
	if (ExistringSession != nullptr) {
		SessionInterface->DestroySession(NAME_GameSession);
	}
	// Store the delegate in a FDelegateHandle so we can remove it from the delegate list
	CreateSessionCompleteDelegateHandle = SessionInterface->AddOnCreateSessionCompleteDelegate_Handle(CreateSessionCompleteDelegate);
	
	LastSessionSettings = MakeShareable(new FOnlineSessionSettings());
	LastSessionSettings->bIsLANMatch = IOnlineSubsystem::Get()->GetSubsystemName() == "NULL" ? true : false;
	LastSessionSettings->NumPublicConnections = NumPublicConnections;
	LastSessionSettings->bAllowJoinInProgress = true;
	LastSessionSettings->bAllowJoinViaPresence = true;
	LastSessionSettings->bShouldAdvertise = true;
	LastSessionSettings->bUsesPresence = true;
	LastSessionSettings->Set(FName("MatchType"), MatchType, EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);

	const ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();
	if (!SessionInterface->CreateSession(*LocalPlayer->GetPreferredUniqueNetId(), NAME_GameSession, *LastSessionSettings)) {
		SessionInterface->ClearOnCreateSessionCompleteDelegate_Handle(CreateSessionCompleteDelegateHandle);
	}



}

void UMyGameInstanceSubsystem::FindSessions(int32 MaxSearchResults)
{

}

void UMyGameInstanceSubsystem::JoinSession(const FOnlineSessionSearchResult& SessionResult)
{

}

void UMyGameInstanceSubsystem::DestroySession()
{

}

void UMyGameInstanceSubsystem::StartSession()
{

}

void UMyGameInstanceSubsystem::OnCreateSessionCopmplete(FName SessioNName, bool bWasSuccessful)
{

}

void UMyGameInstanceSubsystem::OnFindSessionsComplete(bool bWasSuccessful)
{

}

void UMyGameInstanceSubsystem::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{

}

void UMyGameInstanceSubsystem::OnDestroySessionComplete(FName SessioNName, bool bWasSuccessful)
{

}

void UMyGameInstanceSubsystem::OnStartSessionComplete(FName SessioNName, bool bWasSuccessful)
{
}
