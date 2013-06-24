/// @file
/// @brief ���� �������� ����������� ������� ������ ����� ��������� ������.
///
/// Copyright (c) InfoTeCS. All Rights Reserved.
#include "stdafx.h"
#include "flag.h"

namespace cmdlineparser{

namespace flag{

template<>
void FlagImpl<int>::Parse( Args & args )
{
     for( Args::iterator arg = args.begin(); arg != args.end(); ++arg )
     {
          if( !arg->compare( GetFlag() ))
          {
               if( IsAlreadySet() ) // ���� ���� �����( ��� ���������� ����� ���������� ���������� )
				   throw exception::ErrBadArgs();
               Args::iterator flag = arg; // ������ �������� - ����
               Args::iterator opt = ++arg; // �������� �� ��� �������� - ����� 
               if( opt == args.end() )
                    throw exception::ErrBadArgs();
               SetVal( atoi( opt->c_str() ));
               SetIsAlreadySet(); // ���������� ������� ����, ��� ������ ���� ��� �����( ������ �� ������������ )
               // ������� �� ������ ���������� ��������� ���� � �����
               args.erase( flag ); 
               args.erase( opt );
               break;
          }
     }
}

template<>
void FlagImpl<std::string>::Parse( Args & args )
{
     for( Args::iterator arg = args.begin(); arg != args.end(); ++arg )
     {
          if( !arg->compare( GetFlag() ))
          {
               if( IsAlreadySet() ) // ���� ���� �����( ��� ���������� ����� ���������� ���������� )
                    throw exception::ErrBadArgs();
               Args::iterator flag = arg; // ������ �������� - ����
               Args::iterator opt = ++arg; // �������� �� ��� �������� - ����� 
               if( opt == args.end() )
                    throw exception::ErrBadArgs();
               SetVal( *opt );
               SetIsAlreadySet(); // ���������� ������� ����, ��� ������ ���� ��� �����( ������ �� ������������ )
               // ������� �� ������ ���������� ��������� ���� � �����
               args.erase( flag ); 
               args.erase( opt );
               break;
          }
     }
}

template<>
void FlagImpl<bool>::Parse( Args & args )
{
     for( Args::iterator arg = args.begin(); arg != args.end(); ++arg )
     {
          if( !arg->compare( GetFlag() ))
          {
               if( IsAlreadySet() ) // ���� ���� �����( ��� ���������� ����� ���������� ���������� )
                    throw exception::ErrBadArgs();
               // ��������, ���������� ������� ������, �� ������������ ��������� �� ��� �����
               SetVal( true ); 
               SetIsAlreadySet(); // ���������� ������� ����, ��� ������ ���� ��� �����( ������ �� ������������ )
               // ������� �� ������ ���������� ��������� ����
               args.erase( arg ); 
               break;
          }
     }
}

std::ostream& operator<<( std::ostream& s, const flag::IFlagImpl * flag )
{
     return flag->PrintHelp( s );
}

std::ostream& operator<<( std::ostream& s, const flag::IFlag * flag )
{
     return flag->PrintHelp( s );
}

} // namespace flag

} // namespace cmdlineparser{
