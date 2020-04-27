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
#include "OpenAPIOrder.h"

#include "OpenAPIModule.h"
#include "OpenAPIHelpers.h"

#include "Templates/SharedPointer.h"

namespace OpenAPI 
{

inline FString ToString(const OpenAPIOrder::StatusEnum& Value)
{
	switch (Value)
	{
	case OpenAPIOrder::StatusEnum::Placed:
		return TEXT("placed");
	case OpenAPIOrder::StatusEnum::Approved:
		return TEXT("approved");
	case OpenAPIOrder::StatusEnum::Delivered:
		return TEXT("delivered");
	}

	UE_LOG(LogOpenAPI, Error, TEXT("Invalid OpenAPIOrder::StatusEnum Value (%d)"), (int)Value);	
	return TEXT("");
}

inline FStringFormatArg ToStringFormatArg(const OpenAPIOrder::StatusEnum& Value)
{
	return FStringFormatArg(ToString(Value));
}

inline void WriteJsonValue(JsonWriter& Writer, const OpenAPIOrder::StatusEnum& Value)
{
	WriteJsonValue(Writer, ToString(Value));
}

inline bool TryGetJsonValue(const TSharedPtr<FJsonValue>& JsonValue, OpenAPIOrder::StatusEnum& Value)
{
	FString TmpValue;
	if (JsonValue->TryGetString(TmpValue))
	{
		static TMap<FString, OpenAPIOrder::StatusEnum> StringToEnum = {  };

		const auto Found = StringToEnum.Find(TmpValue);
		if(Found)
		{
			Value = *Found;
			return true;
		}
	}
	return false;
}

void OpenAPIOrder::WriteJson(JsonWriter& Writer) const
{
	Writer->WriteObjectStart();
	if (Id.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("id")); WriteJsonValue(Writer, Id.GetValue());	
	}
	if (PetId.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("petId")); WriteJsonValue(Writer, PetId.GetValue());	
	}
	if (Quantity.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("quantity")); WriteJsonValue(Writer, Quantity.GetValue());	
	}
	if (ShipDate.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("shipDate")); WriteJsonValue(Writer, ShipDate.GetValue());	
	}
	if (Status.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("status")); WriteJsonValue(Writer, Status.GetValue());	
	}
	if (Complete.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("complete")); WriteJsonValue(Writer, Complete.GetValue());	
	}
	Writer->WriteObjectEnd();
}

bool OpenAPIOrder::FromJson(const TSharedPtr<FJsonObject>& JsonObject)
{
	bool ParseSuccess = true;

	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("id"), Id);
	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("petId"), PetId);
	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("quantity"), Quantity);
	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("shipDate"), ShipDate);
	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("status"), Status);
	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("complete"), Complete);

	return ParseSuccess;
}
}