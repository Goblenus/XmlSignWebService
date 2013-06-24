/// @file
/// @brief ���� �������� ����������� ������, ������������ ������ ��������� �����-��������.
///
/// Copyright (c) InfoTeCS. All Rights Reserved.
#ifndef diffie_hellman_h__
#define diffie_hellman_h__


#include "../test-base.h"


/// @brief ��������� ������ ��������� �����-��������
class DiffieHellman: public TestBase
{
public:
     DiffieHellman();
     ~DiffieHellman();

     /// @brief ������ �����.
     virtual void Run(); 

private:
     /// @brief ����������� ����� ������.
     void MakeDhKeys();
     /// @brief ��������� ������������ �������������� ������ ������.
     void CheckDhKeys();

     void SetNullInitVector( HCRYPTKEY _key );

private:
          HCRYPTPROV prov1;
          HCRYPTPROV prov2;
          HCRYPTKEY exchangeKey1;
          HCRYPTKEY exchangeKey2; 
          HCRYPTKEY sessionKey; 
          HCRYPTKEY importedSessionKey;
};


#endif // diffie_hellman_h__
