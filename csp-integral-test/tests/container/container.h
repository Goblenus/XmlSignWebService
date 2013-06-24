/// @file
/// @brief ���� �������� ����������� ������, ������������ ������ � ������������ �� ����������.
///
/// Copyright (c) InfoTeCS. All Rights Reserved.
#ifndef CONTAINER_H__
#define container_h__


#include "../test-base.h"


/// @brief ��������� ������ � ������������ �� ����������
class ContainerOnTheDevice: public TestBase
{
public:
     /// @brief ������ �����.
     virtual void Run();
private:
     ///@brief ��������� ���������� ����������
     void CryptGetProvParamToVector( HCRYPTPROV _prov, DWORD _paramType, std::vector<BYTE>& _param, DWORD _flags ) const throw( csp_exception );
     void CryptGetProvParamToString( HCRYPTPROV _prov, DWORD _paramType, tstring& _param, DWORD _flags ) const throw( csp_exception );
};


#endif // container_h__