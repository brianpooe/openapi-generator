/**
 * OpenAPI Petstore
 * This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.
 *
 * OpenAPI spec version: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */
#include "OpenAPIPet.h"

#include "OpenAPIModule.h"
#include "OpenAPIHelpers.h"

#include "Templates/SharedPointer.h"

namespace OpenAPI 
{

inline FString ToString(const OpenAPIPet::StatusEnum& Value)
{
	switch (Value)
	{
	case OpenAPIPet::StatusEnum::Available:
		return TEXT("available");
	case OpenAPIPet::StatusEnum::Pending:
		return TEXT("pending");
	case OpenAPIPet::StatusEnum::Sold:
		return TEXT("sold");
	}

	UE_LOG(LogOpenAPI, Error, TEXT("Invalid OpenAPIPet::StatusEnum Value (%d)"), (int)Value);	
	return TEXT("");
}

inline FStringFormatArg ToStringFormatArg(const OpenAPIPet::StatusEnum& Value)
{
	return FStringFormatArg(ToString(Value));
}

inline void WriteJsonValue(JsonWriter& Writer, const OpenAPIPet::StatusEnum& Value)
{
	WriteJsonValue(Writer, ToString(Value));
}

inline bool TryGetJsonValue(const TSharedPtr<FJsonValue>& JsonValue, OpenAPIPet::StatusEnum& Value)
{
	FString TmpValue;
	if (JsonValue->TryGetString(TmpValue))
	{
		static TMap<FString, OpenAPIPet::StatusEnum> StringToEnum = {  };

		const auto Found = StringToEnum.Find(TmpValue);
		if(Found)
		{
			Value = *Found;
			return true;
		}
	}
	return false;
}

void OpenAPIPet::WriteJson(JsonWriter& Writer) const
{
	Writer->WriteObjectStart();
	if (Id.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("id")); WriteJsonValue(Writer, Id.GetValue());	
	}
	if (Category.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("category")); WriteJsonValue(Writer, Category.GetValue());	
	}
	Writer->WriteIdentifierPrefix(TEXT("name")); WriteJsonValue(Writer, Name);
	Writer->WriteIdentifierPrefix(TEXT("photoUrls")); WriteJsonValue(Writer, PhotoUrls);
	if (Tags.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("tags")); WriteJsonValue(Writer, Tags.GetValue());	
	}
	if (Status.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("status")); WriteJsonValue(Writer, Status.GetValue());	
	}
	Writer->WriteObjectEnd();
}

bool OpenAPIPet::FromJson(const TSharedPtr<FJsonObject>& JsonObject)
{
	bool ParseSuccess = true;

	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("id"), Id);
	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("category"), Category);
	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("name"), Name);
	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("photoUrls"), PhotoUrls);
	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("tags"), Tags);
	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("status"), Status);

	return ParseSuccess;
}
}