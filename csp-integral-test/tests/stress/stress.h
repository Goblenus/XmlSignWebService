/// @file
/// @brief ���� �������� ����������� ������, ������������ ���������� ������.
///
/// Copyright (c) InfoTeCS. All Rights Reserved.
#ifndef STRESS_H__
#define STRESS_H__
#if defined(_WIN32)
#include "../../tools/certificate-search.h"
#endif
#include "../test-base.h"
#include "../integral-test.h"



/// @brief ��������� ������ � ���������� ������.
class Stress: public TestBase
{
public:
     Stress(){}
     ~Stress(){}

     /// @brief ������ �����.
     virtual void Run();

private:
     void diffieHellman();
     void getTestPlainText( std::vector<BYTE>& _out ) const;
     void diffieHellmanOneTestIteration( const std::vector<BYTE>& _inPublicKeyBlob, const std::vector<BYTE>& _data ) const;
     void generatePublicKey( std::vector<BYTE>& _outBlob ) const;
     void pkcs7() const;
#if defined(_WIN32)
     void pkcs7OneIteration( CertificateGuiSearch& _certificateSearch, const std::vector<BYTE>& _data ) const;
     void pkcs7SignOneIteration( CertificateGuiSearch& _certificateSearch, const std::vector<BYTE>& _data ) const;
#endif
     void pkcs7Sign() const;
     void progress( int _iteration ) const;
};


#endif // STRESS_H__
