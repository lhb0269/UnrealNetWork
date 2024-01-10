// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstanceSubsystem.h"
#include "OnlineSubsystem.h"

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
