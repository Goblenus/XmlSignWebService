/// @file
/// @brief ���� �������� ����������� �������, ������������ ������� ������.
///
/// Copyright (c) InfoTeCS. All Rights Reserved.
#ifndef exportation_h__
#define exportation_h__


#include "../test-base.h"


/// @brief ��������� ������ �������� ������
class Exportation: public TestBase
{
public:
     Exportation(){}
     ~Exportation(){}

     /// @brief ������ �����.
     virtual void Run();
};


#endif // exportation_h__
