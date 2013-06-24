/// @file
/// @brief ���� �������� ����������� ������, ������������ ���.
///
/// Copyright (c) InfoTeCS. All Rights Reserved.
#ifndef signing_h__
#define signing_h__


#include "../test-base.h"


/// @brief ��������� ������ ��������� �������
class Hash: public TestBase
{
public:
     Hash(){}
     ~Hash(){}

     void GetMyMessage( std::vector<BYTE>& _buffer ) const;

     /// @brief ������ �����.
     virtual void Run();
};

/// @brief ��������� ������ ��������� �������
class Signing: public TestBase
{
public:
     Signing(){}
     ~Signing(){}

     /// @brief ������ �����.
     virtual void Run();
};


#endif // signing_h__
