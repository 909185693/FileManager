// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FileManagerBlueprintLibrary.generated.h"

/**
 * 文件相关操作操作管理
 */
UCLASS()
class FILEMANAGER_API UFileManager : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Deletes a file. */
	UFUNCTION(BlueprintCallable, Category = FileManage)
	static bool Delete(FString Filename, bool bRequireExists = false, bool bEvenReadOnly = false, bool bQuiet = false);

	/** Moves/renames a file. */
	UFUNCTION(BlueprintCallable, Category = FileManage)
	static bool Move(FString Dest, FString Src, bool bReplace = true, bool bEvenIfReadOnly = false, bool bAttributes = false, bool bDoNotRetryOrError = false);

	/** Copies a file. */
	UFUNCTION(BlueprintCallable, Category = FileManage)
	static bool Copy(FString Dest, FString Src, bool bReplace = true, bool bEvenIfReadOnly = false, bool bAttributes = false);

	/** Checks if a file exists */
	UFUNCTION(BlueprintCallable, Category = FileManage)
	static bool FileExists(FString Filename);

	/** Checks if a directory exists. */
	UFUNCTION(BlueprintCallable, Category = FileManage)
	static bool DirectoryExists(FString InDirectory);

	/** Creates a directory. */
	UFUNCTION(BlueprintCallable, Category = FileManage)
	static bool MakeDirectory(FString Path, bool bTree = false);

	/** Deletes a directory. */
	UFUNCTION(BlueprintCallable, Category = FileManage)
	static bool DeleteDirectory(FString Path, bool bRequireExists = false, bool bTree = false);

	/** Finds file or directories. */
	UFUNCTION(BlueprintCallable, Category = FileManage)
	static TArray<FString> FindFiles(FString Filename, bool bFiles, bool bDirectories);

	/**
	 * Finds all the files within the given directory, with optional file extension filter.
	 *
	 * @param Directory, the absolute path to the directory to search. Ex: "C:\UE4\Pictures"
	 *
	 * @param FileExtension, If FileExtension is NULL, or an empty string "" then all files are found.
	 * 			Otherwise FileExtension can be of the form .EXT or just EXT and only files with that extension will be returned.
	 *
	 * @return FoundFiles, All the files that matched the optional FileExtension filter, or all files if none was specified.
	 */
	UFUNCTION(BlueprintCallable, Category = FileManage)
	static TArray<FString> FindFilesExtension(FString Directory, FString FileExtension = TEXT(""));

	/** Finds file or directories recursively. */
	UFUNCTION(BlueprintCallable, Category = FileManage)
	static TArray<FString> FindFilesRecursive(FString DirectoryPath, FString Extension, bool bInFiles, bool bInDirectory, bool bClearFileNames = true);

	/**
	 * Load a text file to an FString. Supports all combination of ANSI/Unicode files and platforms.
	 *
	 * @param Result       String representation of the loaded file
	 * @param Filename     Name of the file to load
	 * @param VerifyFlags  Flags controlling the hash verification behavior ( see EHashOptions )
	 */
	UFUNCTION(BlueprintCallable, Category = FileManage)
	static bool LoadFileToString(const FString& InFile, FString& OutString);
};