/// @file
/// @brief ���� �������� ����������� ������, ������������ ����������.
///
/// Copyright (c) InfoTeCS. All Rights Reserved.
#ifndef encryption_h__
#define encryption_h__


#include "../test-base.h"


/// @brief ��������� ������ ��������� ����������
class Encryption: public TestBase
{
public:
     Encryption(){}
     ~Encryption(){}

     /// @brief ������ �����.
     virtual void Run();
};


#endif // encryption_h__
