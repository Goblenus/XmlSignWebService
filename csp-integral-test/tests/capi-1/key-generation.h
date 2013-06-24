/// @file
/// @brief ���� �������� ����������� ������, ������������ ��������� ������.
///
/// Copyright (c) InfoTeCS. All Rights Reserved.
#ifndef key_generation_h__
#define key_generation_h__


#include "../test-base.h"


/// @brief ��������� ������ ��������� ������
class KeyGeneration: public TestBase
{
public:
     KeyGeneration(){}
     ~KeyGeneration(){}

     /// @brief ������ �����.
     virtual void Run();
};


#endif // key_generation_h__
