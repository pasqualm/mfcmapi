// Stand alone MAPI Store functions
#pragma once

namespace mapi
{
	namespace store
	{
		extern std::function<std::string()> promptServerName;

		_Check_return_ LPMDB
		CallOpenMsgStore(_In_ LPMAPISESSION lpSession, _In_ ULONG_PTR ulUIParam, _In_ LPSBinary lpEID, ULONG ulFlags);
		std::string BuildServerDN(const std::string& szServerName, const std::string& szPost);
		_Check_return_ LPMAPITABLE GetMailboxTable(_In_ LPMDB lpMDB, const std::string& szServerName, ULONG ulOffset);
		_Check_return_ LPMAPITABLE GetMailboxTable1(_In_ LPMDB lpMDB, const std::string& szServerDN, ULONG ulFlags);
		_Check_return_ LPMAPITABLE
		GetMailboxTable3(_In_ LPMDB lpMDB, const std::string& szServerDN, ULONG ulOffset, ULONG ulFlags);
		_Check_return_ LPMAPITABLE GetMailboxTable5(
			_In_ LPMDB lpMDB,
			const std::string& szServerDN,
			ULONG ulOffset,
			ULONG ulFlags,
			_In_opt_ LPGUID lpGuidMDB);
		_Check_return_ LPMAPITABLE
		GetPublicFolderTable1(_In_ LPMDB lpMDB, const std::string& szServerDN, ULONG ulFlags);
		_Check_return_ LPMAPITABLE
		GetPublicFolderTable4(_In_ LPMDB lpMDB, const std::string& szServerDN, ULONG ulOffset, ULONG ulFlags);
		_Check_return_ LPMAPITABLE GetPublicFolderTable5(
			_In_ LPMDB lpMDB,
			const std::string& szServerDN,
			ULONG ulOffset,
			ULONG ulFlags,
			_In_opt_ LPGUID lpGuidMDB);
		std::string GetServerName(_In_ LPMAPISESSION lpSession);
		_Check_return_ LPMDB MailboxLogon(
			_In_ LPMAPISESSION lpMAPISession, // ptr to MAPI session handle
			_In_ LPMDB lpMDB, // ptr to message store
			const std::string& lpszMsgStoreDN, // message store DN
			const std::string& lpszMailboxDN, // mailbox DN
			const std::wstring&
				smtpAddress, // SMTP Address of the target user. Optional but Required if using MAPI / HTTP
			ULONG ulFlags, // desired flags for CreateStoreEntryID
			bool bForceServer); // Use CreateStoreEntryID2
		_Check_return_ LPMDB OpenDefaultMessageStore(_In_ LPMAPISESSION lpMAPISession);
		_Check_return_ LPMDB OpenOtherUsersMailbox(
			_In_ LPMAPISESSION lpMAPISession,
			_In_ LPMDB lpMDB,
			const std::string& szServerName,
			const std::string& szMailboxDN,
			const std::wstring& smtpAddress,
			ULONG ulFlags, // desired flags for CreateStoreEntryID
			bool bForceServer); // Use CreateStoreEntryID2
		_Check_return_ LPMDB OpenMessageStoreGUID(
			_In_ LPMAPISESSION lpMAPISession,
			_In_z_ LPCSTR lpGUID); // Do not migrate this to wstring/std::string
		_Check_return_ LPMDB OpenPublicMessageStore(
			_In_ LPMAPISESSION lpMAPISession,
			const std::string& szServerName,
			ULONG ulFlags); // Flags for CreateStoreEntryID
		_Check_return_ LPMDB OpenStoreFromMAPIProp(_In_ LPMAPISESSION lpMAPISession, _In_ LPMAPIPROP lpMAPIProp);

		_Check_return_ bool StoreSupportsManageStore(_In_ LPMDB lpMDB);
		_Check_return_ bool StoreSupportsManageStoreEx(_In_ LPMDB lpMDB);

		_Check_return_ LPMDB HrUnWrapMDB(_In_ LPMDB lpMDBIn);
	} // namespace store
} // namespace mapi