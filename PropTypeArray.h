#pragma once
#define PTYPE_ENTRY(num) {(num),L#num},

vector<NAME_ARRAY_ENTRY> PropTypeArray =
{
	PTYPE_ENTRY(PT_UNSPECIFIED)
	PTYPE_ENTRY(PT_NULL)
	PTYPE_ENTRY(PT_I2)
	PTYPE_ENTRY(PT_LONG)
	PTYPE_ENTRY(PT_R4)
	PTYPE_ENTRY(PT_DOUBLE)
	PTYPE_ENTRY(PT_CURRENCY)
	PTYPE_ENTRY(PT_APPTIME)
	PTYPE_ENTRY(PT_ERROR)
	PTYPE_ENTRY(PT_BOOLEAN)
	PTYPE_ENTRY(PT_OBJECT)
	PTYPE_ENTRY(PT_I8)
	PTYPE_ENTRY(PT_STRING8)
	PTYPE_ENTRY(PT_UNICODE)
	PTYPE_ENTRY(PT_SYSTIME)
	PTYPE_ENTRY(PT_CLSID)
	PTYPE_ENTRY(PT_SVREID)
	PTYPE_ENTRY(PT_SRESTRICTION)
	PTYPE_ENTRY(PT_ACTIONS)
	PTYPE_ENTRY(PT_BINARY)
	PTYPE_ENTRY(PT_FILE_HANDLE)
	PTYPE_ENTRY(PT_FILE_EA)
	PTYPE_ENTRY(PT_VIRTUAL)
	PTYPE_ENTRY(PT_MV_I2)
	PTYPE_ENTRY(PT_MV_LONG)
	PTYPE_ENTRY(PT_MV_R4)
	PTYPE_ENTRY(PT_MV_DOUBLE)
	PTYPE_ENTRY(PT_MV_CURRENCY)
	PTYPE_ENTRY(PT_MV_APPTIME)
	PTYPE_ENTRY(PT_MV_I8)
	PTYPE_ENTRY(PT_MV_STRING8)
	PTYPE_ENTRY(PT_MV_UNICODE)
	PTYPE_ENTRY(PT_MV_SYSTIME)
	PTYPE_ENTRY(PT_MV_CLSID)
	PTYPE_ENTRY(PT_MV_BINARY)
};
