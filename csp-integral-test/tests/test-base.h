/// @file
/// @brief ���� �������� ����������� �������� ��������� ������.
///
/// Copyright (c) InfoTeCS. All Rights Reserved.
#ifndef test_base_h__
#define test_base_h__


#include "../defines.h"
#include "../tools/settings.h"


/// @brief ������� ����� ��� ������.
class TestBase
{
public:
     /// @brief ������ �����.
     virtual void Run() = 0;
     virtual ~TestBase(){}

     TestBase();
     
     /// @brief ������ ����� � ���������� ���������� � ������� ��������� �� ������.
     void SafeRun();

     /// @brief ������ ��������� ��� �����.
     /// @param _settings ��������� ��� �����.
     void SetSettings( const Settings* _settings );

     /// @brief �������� ��������� ��� �����.
     /// @return ��������� ��� �����.
     const Settings* GetSettings() const;

protected:
     /// @brief �������� �������� ����������������. 
     /// ���� �������� ���������, �� ������� ��������� ��������, �� ����������, �� �� ����� ������.
     /// @param[out] _prov ����� ���������.
     /// @param _withGui ������������� ����� ������ � ���������� ����������������.
     void CreateContainerIfNotExists( HCRYPTPROV& _prov, bool _withGui = false  ) const;

     /// @brief �������� ���� �� ����������, ���� ���� �� ���������� - �������.
     /// @param _prov ����� ���������, ���������� � �������� �����������.
     /// @param _alg ������������� ��������� �����.
     /// @param[out] _key ����� �����
     void CreateKeyIfNotExists( HCRYPTKEY _prov, ALG_ID _alg, HCRYPTKEY& _key ) const;

     void GetMessage( std::vector<BYTE>& _buffer ) const;
     
private:
     const Settings* settings_;
};


#endif // test_base_h__