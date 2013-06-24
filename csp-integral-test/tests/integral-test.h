/// @file
/// @brief ���� �������� ����������� ������������� ������ ������.
///
/// Copyright (c) InfoTeCS. All Rights Reserved.
#ifndef integral_test_h__
#define integral_test_h__


#include "test-base.h"


/// @brief ��������������� ������������ ����� � ��������� ��.
class IntegralTest: public TestBase
{
     typedef std::list< TestBase* > TestList;

public:
     IntegralTest( const Settings& _settings );
     ~IntegralTest();

     /// @brief ������ ������ �� ������.
     virtual void Run();

     /// @brief �������� ���� � ������ ����������
     /// @param _newTest ������ �����, ��������� � ����. ����� ��� ��������� ������,
     /// ���������� ��� _newTest, ���������� ��� ����� ������ �� ������!
     /// @throw std::invalid_argument ���� ���� �������� ���������� ������
     void AddTest( TestBase* _newTest );

private:
     const Settings& settings_;
     TestList testList_;
};


#endif // integral_test_h__
