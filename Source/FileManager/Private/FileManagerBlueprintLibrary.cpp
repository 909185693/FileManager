// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "FileManagerBlueprintLibrary.h"
#include "HAL/FileManager.h"
#include "Misc/FileHelper.h"

bool UFileManager::Delete(FString Filename, bool bRequireExists, bool bEvenReadOnly, bool bQuiet)
{
	return IFileManager::Get().Delete(*Filename, bRequireExists, bEvenReadOnly, bQuiet);
}

bool UFileManager::Move(FString Dest, FString Src, bool bReplace, bool bEvenIfReadOnly, bool bAttributes, bool bDoNotRetryOrError)
{
	return IFileManager::Get().Move(*Dest, *Src, bReplace, bEvenIfReadOnly, bAttributes, bDoNotRetryOrError);
}

bool UFileManager::Copy(FString Dest, FString Src, bool bReplace, bool bEvenIfReadOnly, bool bAttributes)
{
	return !!IFileManager::Get().Copy(*Dest, *Src, bReplace, bEvenIfReadOnly, bAttributes);
}

bool UFileManager::FileExists(FString Filename)
{
	return IFileManager::Get().FileExists(*Filename);
}

bool UFileManager::DirectoryExists(FString InDirectory)
{
	return IFileManager::Get().FileExists(*InDirectory);
}

bool UFileManager::MakeDirectory(FString Path, bool bTree)
{
	return IFileManager::Get().MakeDirectory(*Path, bTree);
}

bool UFileManager::DeleteDirectory(FString Path, bool bRequireExists, bool bTree)
{
	return IFileManager::Get().DeleteDirectory(*Path, bRequireExists, bTree);
}

TArray<FString> UFileManager::FindFiles(FString Filename, bool bFiles, bool bDirectories)
{
	TArray<FString> OutString;

	IFileManager::Get().FindFiles(OutString, *Filename, bFiles, bDirectories);

	return OutString;
}

TArray<FString> UFileManager::FindFilesExtension(FString Directory, FString FileExtension)
{
	TArray<FString> OutString;

	IFileManager::Get().FindFiles(OutString, *Directory, *FileExtension);

	return OutString;
}

TArray<FString> UFileManager::FindFilesRecursive(FString DirectoryPath, FString Extension, bool bInFiles, bool bInDirectory, bool bClearFileNames)
{
	TArray<FString> OutString;

	IFileManager::Get().FindFilesRecursive(OutString, *DirectoryPath, *Extension, bInFiles, bInDirectory, bClearFileNames);

	return OutString;
}

bool UFileManager::LoadFileToString(const FString& InFile, FString& OutString)
{
	return FFileHelper::LoadFileToString(OutString, *InFile);
}