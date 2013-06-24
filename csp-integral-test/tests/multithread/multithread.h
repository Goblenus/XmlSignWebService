/// @file
/// @brief ���� �������� ����������� ������, ������������ ������ � ������������� ������.
///
/// Copyright (c) InfoTeCS. All Rights Reserved.
#ifndef multithread_h__
#define multithread_h__

#include "../test-base.h"


/// @brief ��������� ������ � ������������� ������.
class Multithread: public TestBase
{
public:
     /// @brief ������ �����.
	virtual void Run();
};



namespace multithread_test_internal
{
     /// @brief ��������� ��������� �������������� �����.
	struct ThreadInfo
	{
		HANDLE handle;
		int threadNum;
		const Settings* parentSettings;
	};

     /// @brief ��������� ����� �������������� �����.
	class ThreadSettingsBuilder
	{
	public:
		ThreadSettingsBuilder( ThreadInfo* info );
		~ThreadSettingsBuilder();
		const Settings* GetSettings() const{ return settings_; }
	private:
		tstring ThreadName() const;
	private:
		ThreadInfo* info_;
		Settings* settings_;
		tstring containerName_;
		tstring logName_;
	};

} // namespace multithread_test_internal

#endif // multithread_h__
